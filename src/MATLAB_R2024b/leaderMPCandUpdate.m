function [p_tp1, X_L, qi, error, u_opt] = leaderMPCandUpdate(...
                                          sys, x0, N, robotParams, obstacles, U_l_old)
%% Variables definitions

    n = sys.n;

        % Get q points from obstacles
    [qi, ~] = getObstacleInfo(obstacles, x0(1:2));
    
        % Get optimization params
    W = robotParams.W;
    R = robotParams.R;
    Z = robotParams.Z;
    
        % Get cost weights matrices
    [W_hat, R_hat] = costWeights(sys, W, R, Z, N);
    
        % Get cost function
    costF = @(U) leaderCost(U, x0, sys, W, W_hat, R_hat, N);

        % Get constraints function
    [A_bar, B_bar] = constMatrices(x0, qi, N, robotParams.robotShape, sys);
    constraintsF = @(U) constraints(U, x0, qi, N, robotParams.robotShape, sys, A_bar, B_bar);

        % Get input bounds
    v_max = robotParams.v_max;
    w_max = robotParams.w_max;
    [lb, ub] = inputBounds(v_max, w_max, sys, N);
    
%% fmincon optimization

    options = optimoptions('fmincon','Algorithm','interior-point','Display','off');
    [u_opt, ~, exitflag, output] = fmincon(costF, U_l_old, [], [], [], [], lb, ub, constraintsF, options);
    
    error.QPexitflag = exitflag;
    error.QPoutput = output;
    
%% States and output

    x_pred_stacked = stateEvolution(u_opt, x0, sys, N);
    x_pred = reshape(x_pred_stacked,[n,N]);
    
    % Update the state and input with the first one predicted
    p_tp1 = x_pred(:,1);
    X_L = x_pred;
    
end

