function [p_tp1, X_F, X_F_stacked, error, u_t, u_act] = followerMPCandUpdate(...
                            sys, x0, X_L_stacked, N, robotParams, obstacles, U_f_old, use_load, loadParams, use_noise, noise)
%% Variables definitions
    
        % Get cost function
    costF = @(U) followerCost(U, x0, sys, N, X_L_stacked, robotParams);

        % Get constraints function
    constraintsF = @(U) constraints(U, x0, robotParams, obstacles.M_f, obstacles.qi_f_stack, obstacles.f_margin, sys, ...
                                    use_load, X_L_stacked, obstacles.M_load, loadParams, obstacles.qi_load);

%% fmincon optimization

    options = optimoptions('fmincon','Algorithm', robotParams.alg,'Display','off');
    [u_opt, ~, exitflag, output] = fmincon(costF, U_f_old, [], [], [], [], robotParams.lb, robotParams.ub, constraintsF, options);
    
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
    X_F = x_pred;
    X_F_stacked = x_pred_stacked;
    u_t = u_act(1:2);

end