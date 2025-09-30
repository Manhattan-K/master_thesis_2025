function [c, ceq] = constraints(U, x0, q_points, N, robotShape, sys, A_bar, B_bar)

        % Obtain the number of constraints
    [~,M] = size(q_points);
    
        % Obtain the number of vertices
    [~, L] = size(robotShape);
    
        % Obtain the number of states n and number of inputs m
    n = sys.n;

%% Obstacle avoidance
% c(x) = A_bar * x_h - B_bar s.t    c(x) <= 0
    
    c_obst_av = zeros([N*M*L, 1]);

    if M >= 1
    
        x_pred = stateEvolution(U, x0, sys, N);
        c_obst_av = A_bar * x_pred - B_bar;

    else % If there are no constraints
        c_obst_av = [];
    end

%% Input constraints
% Defined in the fmincon function

%% Final output

    c = c_obst_av;
    ceq = [];

end