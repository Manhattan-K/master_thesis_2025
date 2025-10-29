function [p_tp1, X_L, X_L_stacked, error, u_t, u_opt] = leaderMPCandUpdate(...
                                          sys, x0, N, robotParams, obstacles, U_l_old, x_f, avoid_policy)
%% Variables definitions

    n = sys.n;
    
        % Get cost function
    costF = @(U) leaderCost(U, x0, x_f, sys, robotParams, N, avoid_policy, obstacles);

        % Get constraints function
    constraintsF = @(U) constraints(U, x0, obstacles.M_l, obstacles.A_bar_l, obstacles.B_bar_l, N, robotParams.robotShape, sys);

%% fmincon optimization

    options = optimoptions('fmincon','Algorithm', robotParams.alg,'Display','off');
    [u_opt, ~, exitflag, output] = fmincon(costF, U_l_old, [], [], [], [], robotParams.lb, robotParams.ub, constraintsF, options);
    
    error.QPexitflag = exitflag;
    error.QPoutput = output;
    
%% States and output

    x_pred_stacked = stateEvolution(u_opt, x0, sys, N);
    x_pred = reshape(x_pred_stacked,[n,N]);
    
    % Update the state and input with the first one predicted
    p_tp1 = x_pred(:,1);
    X_L = x_pred;
    X_L_stacked = x_pred_stacked;
    u_t = u_opt(1:2);

end

