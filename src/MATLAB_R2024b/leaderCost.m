function [cost] = leaderCost(U, x0, ref_traj, Ts, N)

    x = x0;
    cost = 0;
    for k = 1:N
        u = U(:,k);
        x = modelDynamics(x, u, Ts);
        cost = cost + norm(x(1:2) - ref_traj(1:2,k))^2;
    end

end