function [c, ceq] = constraints(U, x0, params, M, q_stacked, margins, sys, ...
                    use_load, X_L_stack, M_load, loadParams, q_load)
    
        % Obtain the number of states n and number of inputs m
    n = sys.n;

%% Obstacle avoidance
% c(x) = r^2 - [q-x][q-x]' s.t  c(x) <= 0

    if M >= 1
    
        x_pred = stateEvolution(U, x0, sys, sys.N);
        x_pred_pos = params.Px_N * x_pred;
        x_pos_stacked = repmat(x_pred_pos, [M, 1]);
        diff = q_stacked - x_pos_stacked;
       
        diff_re = reshape(diff, 2, size(diff, 1) / 2)';
        diff_norm = vecnorm(diff_re, 2, 2);

        c_obst_av = margins - diff_norm;


        if use_load == true
            mat_ind = loadParams.k_pred*n;
            lf_diff = x_pred(1:mat_ind, 1) - X_L_stack(1:mat_ind, 1);
            
            load_A = zeros(2,loadParams.k_pred);
            load_B = zeros(2,loadParams.k_pred);
            load_D = zeros(2,loadParams.k_pred);
            
            for i = 0:loadParams.k_pred - 1
                load_pred = x_pred(i*n+1:i*n + 2, 1) + Rmat(atan2(lf_diff(i*n+2),lf_diff(i*n+1)))*loadParams.center(:,2:end);
                load_A(:,i+1) = load_pred(:,1);
                load_B(:,i+1) = load_pred(:,2);
                load_D(:,i+1) = load_pred(:,3);
            end

            load_A_st = repmat(load_A, [1, M_load]);
            load_B_st = repmat(load_B, [1, M_load]);
            load_D_st = repmat(load_D, [1, M_load]);
            
            const_num = size(load_A_st, 2);
            c_load = zeros(const_num, 1);
            q_ABD = reshape(q_load, 2, const_num);
            for i = 1:const_num
                c_load(i) = pointInsideLoad(q_ABD(:, i), load_A_st(:,i), load_B_st(:,i), load_D_st(:,i));
            end
            
            c_obst_av(end+1:end+size(c_load, 1)) = c_load;
        end

    else % If there are no constraints
        c_obst_av = [];
    end


%% Input constraints
% Defined in the fmincon function

%% Final output

    c = c_obst_av;
    ceq = [];

end