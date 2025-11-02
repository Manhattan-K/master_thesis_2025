function [p_tp1, X_F, X_F_stacked, error, u_t, u_opt] = followerMPCandUpdate(...
                            sys, x0, X_L_stacked, N, robotParams, obstacles, U_f_old, use_load, loadParams)
%% Variables definitions

    n = sys.n;
    
        % Get cost function
    costF = @(U) followerCost(U, x0, sys, N, X_L_stacked, robotParams);

        % Get constraints function
    constraintsF = @(U) constraints(U, x0, obstacles.M_f, obstacles.A_bar_f, obstacles.B_bar_f, N, robotParams.robotShape, sys, ...
                                    use_load, X_L_stacked, obstacles.A_bar_load, obstacles.B_bar_load, loadParams.center);

%% fmincon optimization

    options = optimoptions('fmincon','Algorithm', robotParams.alg,'Display','off');
    [u_opt, ~, exitflag, output] = fmincon(costF, U_f_old, [], [], [], [], robotParams.lb, robotParams.ub, constraintsF, options);
    
    error.QPexitflag = exitflag;
    error.QPoutput = output;
    
%% States and output

    x_pred_stacked = stateEvolution(u_opt, x0, sys, N);
    x_pred = reshape(x_pred_stacked,[n,N]);
    
        % Update the state and input with the first one predicted
    p_tp1 = x_pred(:,1);
    X_F = x_pred;
    X_F_stacked = x_pred_stacked;
    u_t = u_opt(1:2);

end