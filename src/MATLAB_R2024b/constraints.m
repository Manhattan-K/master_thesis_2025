function [c, ceq] = constraints(U, x0, q_points, N, robotShape, sys)

        % Obtain the number of constraints
    [~,M] = size(q_points);
    
        % Obtain the number of vertices
    [~, L] = size(robotShape);
    
        % Obtain the number of states n and number of inputs m
    n = sys.n;
    m = sys.m;

%% Obstacle avoidance
% c(x) = A_bar * x_h - B_bar s.t    c(x) <= 0
    
    c_obst_av = zeros([N*M*L, 1]);

    if M >= 1
            % The constraints are linear as (qi-x0)' x(t) <= (qi-x0)'qi.
        A_constr = zeros([M*L, n]);
        b_constr = zeros([M*L, 1]);
        p0 = x0(1:2);
        for i = 1:M
            qi = q_points(:,i); 
            for j = 1:L
                vj = robotShape(:, j);
                A_constr((i-1)*L+j,:) = [(qi - p0)', 0];
                b_constr((i-1)*L+j) = (qi - p0)'*(qi-vj);
            end
        end
        
            % Stack diagonally to expand and make it a bound for all ts
        A_bar = kron(eye(N),A_constr);
        B_bar = repmat(b_constr, N, 1);
    
        x_pred = stateEvolution(U, x0, sys, N);

        c_obst_av = A_bar * x_pred - B_bar;

    else % If there are no constraints, just add Gu<=W+Sx0 to limit input
        c_obst_av = [];
    end

%% Input constraints
% Defined in the fmincon function

%% Final output

    c = c_obst_av;
    ceq = [];

end