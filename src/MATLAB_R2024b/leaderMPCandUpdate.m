function [p_tp1, X_L, X_L_stacked, error, u_t, u_act] = leaderMPCandUpdate(...
                                          sys, x0, N, robotParams, obstacles, U_l_old, use_lf_dist, x_f, goal, use_noise, noise)
%% Variables definitions

        % Get cost function
    costF = @(U) leaderCost(U, x0, use_lf_dist, x_f, sys, robotParams, N, goal, obstacles);

        % Get constraints function
    constraintsF = @(U) constraints(U, x0, obstacles.M_l, obstacles.A_bar_l, obstacles.B_bar_l, N, sys, ...
                                    false, [], [], [], []);

%% fmincon optimization

    options = optimoptions('fmincon','Algorithm', robotParams.alg,'Display','off');
    [u_opt, ~, exitflag, output] = fmincon(costF, U_l_old, [], [], [], [], robotParams.lb, robotParams.ub, constraintsF, options);
    
    error.QPexitflag = exitflag;
    error.QPoutput = output;
    
%% States and output

        % Add noise if needed
    if use_noise == true && noise.actuation.on == true
        n_v = noise.actuation.sigma_v * randn(1);
        n_w = noise.actuation.sigma_w * randn(1);
        u_act = u_opt + repmat([min(0, n_v); n_w], [N, 1]);

    else
        u_act = u_opt;
    end

    x_pred_stacked = stateEvolution(u_act, x0, sys, N);
    x_pred = reshape(x_pred_stacked,[sys.n,N]);
    
        % Update the state and input with the first one predicted
    p_tp1 = x_pred(:,1);
    X_L = x_pred;
    X_L_stacked = x_pred_stacked;
    u_t = u_act(1:2);

end

