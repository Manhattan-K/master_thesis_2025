function [cost] = leaderCost(U, x0, use_lf_dist, x_f, sys, params, N, goal, obs)

    % LEADER COST FUNCTION as 
    %   J = q(0)'Wq(0) + q_staked' W_hat q_stacked + ...
    %       u_stacked' R_hat u_stacked

%% Base calculations

    x_pred = stateEvolution(U, x0, sys, N);

%% Initial condition cost

    cost_ic = (x0 - goal.single)' * params.W * (x0 - goal.single);

%% Prediction cost

    cost_state = (x_pred - goal.N)' * params.W_hat * (x_pred - goal.N);

%% Input cost

    cost_input = U' * params.R_hat * U;

%% Cost to keep some distance from the obstacles

    %     % x_N - qi for each obstacle and state in the predition horizon
    % L = obs.L;
    % if L ~= 0
    %     x_pred_pos = params.Px_N * x_pred;
    %     x_pos_stacked = repmat(x_pred_pos, [L, 1]);
    % 
    %     diff = x_pos_stacked - obs.qi_l_stack;
    %     diff_sq = diff.*diff;
    %     dim = N*L;
    %     diff_reshape = reshape(diff_sq,[2, dim]);
    %     diff_sum = sum(diff_reshape, 1);
    % 
    %         % Cost evaluation
    %     cost_obs = params.D*dim + obs.relative*diff_sum';
    % else
    %     cost_obs = 0;
    % end

%% Cost to keep the two robots at distance d_fl

    if use_lf_dist == true
                % q_L - q_F
        stateDiff_stacked = x_pred(1:(N-1)*sys.n) - x_f(sys.n+1:sys.n*N);
        stateDiff = reshape(stateDiff_stacked, [sys.n, N - 1]);
    
            % Px * stateDiff
        projDiff = params.Px * stateDiff;
    
            % Cost evaluation
        cost_dist = params.beta_N * ((sum(projDiff.^2, 1) - params.d_FL_sq) .^ 2)';
    else
        cost_dist = 0;
    end

%%  FINAL COST

    cost = cost_ic + cost_state + cost_input + params.K * cost_dist;

end

