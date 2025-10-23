function [cost] = leaderCost(U, x0, x_f, sys, W, W_hat, R_hat, K, N, goal)

    % LEADER COST FUNCTION as 
    %   J = q(0)'Wq(0) + q_staked' W_hat q_stacked + ...
    %       u_stacked' R_hat u_stacked

    x_pred = stateEvolution(U, x0, sys, N);

    cost_ic = (x0 - goal.single)' * W * (x0 - goal.single);
    cost_state = (x_pred - goal.N)' * W_hat * (x_pred - goal.N);
    cost_input = U' * R_hat * U;
    cost_dist = K*abs(sys.d_fl - (norm(x_pred(1:2) - x_f(1:2))));

    cost = cost_ic + cost_state + cost_input + cost_dist;

end

