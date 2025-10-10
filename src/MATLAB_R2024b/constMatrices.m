function [A_bar, B_bar] = constMatrices(x0, q_points, N, robotShape, sys)

        % Obtain the number of constraints
    [~,M] = size(q_points);
    
        % Obtain the number of vertices
    [~, L] = size(robotShape);
    
        % Obtain the number of states n and number of inputs m
    n = sys.n;

%% The constraints are linear as (qi-x0)' x(t) <= (qi-x0)'qi.
  
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

end

