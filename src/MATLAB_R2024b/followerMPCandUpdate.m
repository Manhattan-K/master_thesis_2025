function [p_tp1, X_F, qi, error, u_opt] = followerMPCandUpdate(...
                            sys, x0, X_L_stacked, N, robotParams, obstacles, U_f_old)
%% Variables definitions

    n = sys.n;

        % Get q points from obstacles
    [qi, ~] = getObstacleInfo(obstacles, x0(1:2));
    
        % Get cost function
    costF = @(U) followerCost(U, x0, sys, N, X_L_stacked, robotParams);

        % Get constraints function
    [A_bar, B_bar] = constMatrices(x0, qi, N, robotParams.robotShape, sys);
    constraintsF = @(U) constraints(U, x0, qi, N, robotParams.robotShape, sys, A_bar, B_bar);

        % Get input bounds
    v_max = robotParams.v_max;
    w_max = robotParams.w_max;
    [lb, ub] = inputBounds(v_max, w_max, sys, N);
    

%% fmincon optimization

    options = optimoptions('fmincon','Algorithm','interior-point','Display','off');
    [u_opt, ~, exitflag, output] = fmincon(costF, U_f_old, [], [], [], [], lb, ub, constraintsF, options);
    
    error.QPexitflag = exitflag;
    error.QPoutput = output;
    
%% States and output

    x_pred_stacked = stateEvolution(u_opt, x0, sys, N);
    x_pred = reshape(x_pred_stacked,[n,N]);
    
    % Update the state and input with the first one predicted
    p_tp1 = x_pred(:,1);
    X_F = x_pred;

    % error = 0;

end

    %% With Gradient

    % options = optimoptions('fmincon','Algorithm','interior-point',...
    %     'OptimalityTolerance',1e-1, 'SpecifyObjectiveGradient',true,...
    %     'Display', 'none'); 
    % [u_opt] = fmincon(...
    %      @(U) followerCostGradientHessian(U,x0,h, pe),...
    %      U_f_old, G, W + S*x0, [], [], [], [], [], options);
    %  u_opt_reshaped = reshape(u_opt,[2,N]);
