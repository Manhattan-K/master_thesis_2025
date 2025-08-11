function [p_tp1, X_L, qi, error, u_opt] = leaderMPCandUpdateHalt(x_0, N, optParams, obstacles, U_l_old, goal, Ts)

    % compute the MPC output
    [qi, ~] = getObstacleInfo(obstacles, x_0(1:2));
    
    % get params
    u_lim = optParams.u_lim;
    
    % Cost function for Unicycle
    ref_traj = repmat(goal, 1, N);
    cost = @(U) leaderCost(reshape(U,2,N), x_0, ref_traj, Ts, N);
    
    % Input bounds
    lb = repmat([-u_lim; -u_lim], N, 1);
    ub = repmat([u_lim; u_lim], N, 1);

    % Nonlinear optimization
    options = optimoptions('fmincon','Algorithm','interior-point','Display','none');
    [u_opt, ~, exitflag, output] = fmincon(cost, U_l_old(:), [], [], [], [], lb, ub, [], options);
    u_opt_reshaped = reshape(u_opt, [2, N]);

    error.exitflag = exitflag;
    error.output = output;

    % Simulate predicted trajectory with Unicycle model
    x_pred = zeros(3, N);
    x_pred(:,1) = x_0;
    for j = 2:N
        x_pred(:,j) = modelDynamics(x_pred(:,j-1), u_opt_reshaped(:,j-1), Ts);
    end

    % Output
    p_tp1 = x_pred(:,2); % next state
    X_L = x_pred;

    
end

