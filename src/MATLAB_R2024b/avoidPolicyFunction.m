function [avoid_policy] = avoidPolicyFunction( ...
                            avoid_policy, x_pred, N, obs, sys, leaderParams, U_center)
%%  START A NEW POLICY

    if avoid_policy.on == false || ...
       avoid_policy.on == true && avoid_policy.obstruction == true && ...   % If there is an obstraction
       avoid_policy.moved == true                                           % If the obstaction is different
       
        if avoid_policy.on == true
            avoid_policy.pointer = avoid_policy.pointer + 1;
        end

        policy = avoid_policy.stack(avoid_policy.pointer);

            % Policy's metrics update
        avoid_policy.on = true;
        avoid_policy.used = avoid_policy.used + 1;
        avoid_policy.times = avoid_policy.times + 1;
        
            % Direction of the prediction
        x_N_pos = x_pred(1:2,N);
        x_N_ang = x_pred(3,N);

            % Direction to nearest qi
        [~, ind] = min(vecnorm(obs.qi_l - x_N_pos));
        diff = obs.qi_l(:,ind) - x_pred(1:2,1);

            % Direction to the goal
        % diff = avoid_policy.goal(1:2) - x_N_pos;
        goal_dir = atan2(diff(2), diff(1));
        ang_diff = goal_dir - x_N_ang;

            % Select the right direction
        if abs(ang_diff) <= pi/4
            dir = goal_dir;
        else
            dir = x_N_ang;
        end

            % If we are in the edge case "CAN BE REMOVED"
        if norm(diff) <= 1.5
            dir = goal_dir;
        end

            % Generation of the reset zone
        policy.n(:,:) = [cos(dir); sin(dir)];
        policy.pos = x_N_pos + avoid_policy.margin * policy.n; 
        policy.dir = dir;

    % --- MPC prediction ---
            % Left direction
        t1 = dir + avoid_policy.dev_ang;
        c1 = cos(t1);
        s1 = sin(t1); 
        g1.single = [x_N_pos + avoid_policy.pred.dist .* [c1; s1]; 0];
        g1.N = repmat(g1.single, [N, 1]);
        g1.lenght = 0;

            % Right direction
        t2 = dir - avoid_policy.dev_ang;
        c2 = cos(t2);
        s2 = sin(t2); 
        g2.single = [x_N_pos + avoid_policy.pred.dist .* [c2; s2]; 0];
        g2.N = repmat(g2.single, [N, 1]);
        g2.lenght = 0;
        
            % MPC data
        U_left = U_center;
        X_left = x_pred;
        U_right = U_center;
        X_right = x_pred;

        for loop = 1:avoid_policy.pred.p_max 
            
            if loop == 1
                left_x = X_left(:,1);
                right_x = X_right(:,1);
            else
                left_x = X_left(:,N/2);
                right_x = X_right(:,N/2);
            end

                    % MPC for the leader with left direction
            [~, X_left, ~, ~, ~, U_left] = leaderMPCandUpdate( ...
                            sys, left_x, N, leaderParams, obs, U_left, false, [], g1);
            
    
                % MPC for the leader with right direction
            [~, X_right, ~, ~, ~, U_right] = leaderMPCandUpdate( ...
                            sys, right_x, N, leaderParams, obs, U_right, false, [], g2);
            
                % Check for obstructions in the prediction
            done = false;
            
            for j = 1:N - 1
                
                    % Left prediction
                if norm(X_left(1:2, j) - X_left(1:2, j + 1)) < 1e-5 
                    done = true;
                else
                    g1.lenght = g1.lenght + 1;
                end
                
                    % Right prediction
                if norm(X_right(1:2, j) - X_right(1:2, j + 1)) < 1e-5 
                    done = true;
                else
                    g2.lenght = g2.lenght + 1;
                end
    
                if done == true
                    break;
                end
            end

            if done == true
                break;
            end
        end


        


            
    % --- Choosing the direction ---

            % Going left
        if g1.lenght > g2.lenght
            policy.single = g1.single;
            policy.N = g1.N;
            policy.theta = t1;
            policy.cos = c1;
            policy.sin = s1;

            % Going right
        elseif g1.lenght < g2.lenght
            policy.single = g2.single;
            policy.N = g2.N;
            policy.theta = t2;
            policy.cos = c2;
            policy.sin = s2;

            % Going on the robot direction
        else
            if ang_diff < 0
                policy.single = g1.single;
                policy.N = g1.N;
                policy.theta = t1;
                policy.cos = c1;
                policy.sin = s1;
            else
                policy.single = g2.single;
                policy.N = g2.N;
                policy.theta = t2;
                policy.cos = c2;
                policy.sin = s2;
            end


        end
        avoid_policy.stack(avoid_policy.pointer) = policy;

%% UPDATE THE POLICY GOAL

    elseif avoid_policy.on == true

        policy = avoid_policy.stack(avoid_policy.pointer);
        dot_prod = (policy.n)' * (x_pred(1:2, 1) - policy.pos);
        
    % --- Away from reset zone ---
        if dot_prod <= 0 
            avoid_policy.times = avoid_policy.times + 1;
            
    % --- Inside reset zone ---
        else
            if avoid_policy.pointer > 1
                avoid_policy.pointer = avoid_policy.pointer - 1;
            else
                avoid_policy.on = false;
                policy.single = avoid_policy.goal;
                policy.N = avoid_policy.goal_N;
                avoid_policy.stack(avoid_policy.pointer) = policy;
            end
        end
    end

end