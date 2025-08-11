function cost = followerCost(U, x0, h, pe, Ts, N, leader_pos)
% U: [2, N] - input sequence (v, omega)
% x0: [3, 1] - initial state [x; y; theta]
% h: reference trajectory or offset (dimension [3, N])
% pe: struct with weights (e.g. Q, R, C, d_FL, beta_vec)
% Ts: sample time
% N: prediction horizon

    x = x0;
    cost = 0;
    for k = 1:N
        u = U(:,k);
        x = modelDynamics(x, u, Ts);

        % Tracking cost (distance from reference)
        % cost = cost + (x(1:2) - h(1:2,k))' * pe.Q * (x(1:2) - h(1:2,k));

        % Input cost
        % cost = cost + u' * pe.R * u;
        % Formation cost
        cost = cost + pe.C * (norm(x(1:2) - leader_pos(:,k)) - pe.d)^2;
    end
end