function [c, ceq] = nonLinearConst(U, x0, q_points, N, robotShape, Ts)

    % obtain the number of constraints
    [~,M] = size(q_points);
    
    % obtain the number of vertices
    [~, L] = size(robotShape);
    
    % obtain the number of states (n=4) and number of inputs (m=2)
    n = size(x0);
    m = 2;

% Obstacle avoidance Abar * S_ * u_k <= Bbar - Abar * T_ * x(0)
% c(x) = A_bar * x_h - B_bar
    
    c = zeros([N*M*L, 1]);

    if M >= 1
        % The constraints are linear as (qi-x0)' x(t) <= (qi-x0)'qi.
        % stack them to obtain the form Ac*x(t)<=bc -> this is for one t
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
        
        % stack diagonally to expand and make it a bound for all ts
        A_bar = kron(eye(N),A_constr);
        B_bar = repmat(b_constr, N, 1);
    
        % convert it to a request in U (all ts) and concat requests on inputs

        % x_h is a 3*n x 1 vector

        x_h = zeros([n*N, 1]);
    
        x_h(1) = x0(1) + U(1) * cos(x0(3)) * Ts;
        x_h(2) = x0(2) + U(1) * sin(x0(3)) * Ts;
        x_h(3) = x0(3) + U(2) * Ts;

        for i = 1 : ( N-1 )
            x_h(i*3 + 1) = x_h((i-1)*3 + 1) + U(i*2 + 1) * cos(x_h((i-1)*3 + 3)) * Ts;
            x_h(i*3 + 2) = x_h((i-1)*3 + 2) + U(i*2 + 1) * sin(x_h((i-1)*3 + 3)) * Ts;
            x_h(i*3 + 3) = x_h((i-1)*3 + 3) + U(i*2 + 2) * Ts;
        end

        c = A_bar * x_h - B_bar;

    else % if there are no constraints, just add Gu<=W+Sx0 to limit input
        c = [];
    end


    ceq = [];

end

