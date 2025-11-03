function [c, ceq] = constraints(U, x0, M, A_bar, B_bar, N, sys, ...
                    use_load, X_L_stacked, A_bar_load, B_bar_load, loadParams)
    
        % Obtain the number of states n and number of inputs m
    n = sys.n;

%% Obstacle avoidance
% c(x) = A_bar * x_h - B_bar s.t    c(x) <= 0

    if M >= 1
    
        x_pred = stateEvolution(U, x0, sys, N);
        c_obst_av = A_bar * x_pred - B_bar + sys.obs_margin*ones([size(B_bar,1), 1]);
        
        if use_load == true
            mat_ind = loadParams.k_pred*n;
            diff = x_pred(1:mat_ind, 1) - X_L_stacked(1:mat_ind, 1);
            for i = 0:loadParams.k_pred - 1
                load_pred(i*n+1:i*n + 3, 1) = x_pred(i*n+1:i*n + 3, 1) + [Rmat(atan2(diff(i*n+2),diff(i*n+1)))*loadParams.center(:,1); 0];
            end

            c_load = A_bar_load * load_pred - B_bar_load + 0.01*ones([size(B_bar_load,1), 1]);
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