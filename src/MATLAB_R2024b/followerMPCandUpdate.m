function [p_tp1, X_F, qi, error, u_opt] = followerMPCandUpdate(XL, x0, N, params, obstacles, U_f_old, Ts)

    [qi, ~] = getObstacleInfo(obstacles, x0(1:2));
    %material point:
    %[G,W,S] = constraints(plant.A, plant.B, x0, qi, N, params.u_lim, params.v_lim);
    %rigidBody:
    %[G,W,S] = rigidBodyConstraints(plant.A, plant.B, x0, qi, N, params.u_lim, params.v_lim, params.robotShape);
    
    pe = params.precompiledElements;
    h = XL;
    leader_pos = XL(1:2, :);

    options = optimoptions('fmincon','Algorithm','interior-point',...
        'OptimalityTolerance',1e-1, 'SpecifyObjectiveGradient',false,...
        'Display', 'none'); 
    [u_opt] = fmincon(...
         @(U) followerCost(reshape(U,2,N), x0, h, pe, Ts, N, leader_pos),...
         U_f_old, [], [], [], [], [], [], ...
         @(U) nonLinearConst(U, x0, qi, N, params.robotShape, Ts), options);
    u_opt_reshaped = reshape(u_opt,[2,N]);

    % model dynamics update, needed to give path intention to plotter
    p_pred = zeros([3, N]); % will have x(1)..x(N)
    p_pred(:,1) = x0;
    for j=2:N
        p_pred(:,j) = modelDynamics(p_pred(:,j-1), u_opt_reshaped(:,j-1), Ts);
    end

    % Output
    p_tp1 = p_pred(:,2);
    X_F = p_pred;
    error = 0;

end