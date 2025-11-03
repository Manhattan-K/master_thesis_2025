function [A_bar, B_bar] = constMatrices(x0, q_points, N, robotShape, sys, is_load, loadParams)

        % Obtain the number of constraints
    [~,M] = size(q_points);
    
        % Obtain the number of vertices
    [~, L] = size(robotShape);

%% The constraints are linear as (qi-x0)' x(t) <= (qi-x0)'qi.
  
    A_constr = zeros([M*L, sys.n]);
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
    if is_load == false
        A_bar = kron(eye(N),A_constr);
        B_bar = repmat(b_constr, N, 1);
    else
        A_bar = kron(eye(loadParams.k_pred),A_constr);
        B_bar = repmat(b_constr, loadParams.k_pred, 1);
    end
end

