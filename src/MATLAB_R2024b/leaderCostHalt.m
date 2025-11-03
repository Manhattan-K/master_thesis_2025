function [cost] = leaderCostHalt(U, x0, sys, N, robotParams)

%% The cost accounts for the minimization of the travelled distance

        % q_F(1:N) - q_F(0:N-1)
    X_L_stacked = stateEvolution(U, x0, sys, N);
    X_L_N_1 = [x0; X_L_stacked(1:(sys.n * (N-1)))];
    distDiff_stacked = X_L_stacked - X_L_N_1;
    distDiff = reshape(distDiff_stacked, [sys.n, N]);

        % Px * distDiff
    projDiff = robotParams.Px * distDiff;

        % Cost evaluation
    cost = sum(sum(projDiff.^2, 1));

    
end

