function [c, ceq] = constraints(U, x0, M, A_bar, B_bar, N, robotShape, sys)
    
        % Obtain the number of vertices
    [~, L] = size(robotShape);
    
        % Obtain the number of states n and number of inputs m
    n = sys.n;

%% Obstacle avoidance
% c(x) = A_bar * x_h - B_bar s.t    c(x) <= 0

    if M >= 1
    
        x_pred = stateEvolution(U, x0, sys, N);
        c_obst_av = A_bar * x_pred - B_bar + sys.obs_margin*ones([size(B_bar,1), 1]);

    else % If there are no constraints
        c_obst_av = [];
    end

%% Input constraints
% Defined in the fmincon function

%% Final output

    c = c_obst_av;
    ceq = [];

end