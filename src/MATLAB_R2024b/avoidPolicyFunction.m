function [avoid_policy] = avoidPolicyFunction( ...
                            avoid_policy, x_pred, N, obs, sys, leaderParams, U_center)
%%  START A NEW POLICY

    if avoid_policy.on == false
        
            % Policy's metrics update
        avoid_policy.on = true;
        avoid_policy.used = avoid_policy.used + 1;
        avoid_policy.times = avoid_policy.times + 1;
        
            % Direction of the prediction
        x_N_pos = x_pred(1:2,N);
        x_N_ang = x_pred(3,N);

            % Direction to the goal
        diff = avoid_policy.goal(1:2) - x_N_pos;
        goal_dir = atan2(diff(2), diff(1));
        ang_diff = goal_dir - x_N_ang;

            % Select the right direction
        if abs(ang_diff) <= pi/4
            dir = goal_dir;
        else
            dir = x_N_ang;
        end

            % If we are in the edge case "CAN BE REMOVED"
        if norm(diff) <= 2
            dir = goal_dir;
        end

            % Generation of the reset zone
        avoid_policy.n(:,:) = [cos(dir); sin(dir)];
        avoid_policy.pos = x_N_pos + avoid_policy.margin * avoid_policy.n; 
        avoid_policy.dir = dir;

    % --- MPC prediction ---
            % Left direction
        t1 = dir + avoid_policy.dev_ang;
        c1 = cos(t1);
        s1 = sin(t1); 
        g1.final = [x_N_pos + [c1; s1]; 0];
        g1.single = [x_N_pos + avoid_policy.pred.dist .* [c1; s1]; 0];
        g1.N = repmat(g1.single, [N, 1]);
        g1.lenght = 0;

            % Right direction
        t2 = dir - avoid_policy.dev_ang;
        c2 = cos(t2);
        s2 = sin(t2); 
        g2.final = [x_N_pos + [c2; s2]; 0];
        g2.single = [x_N_pos + avoid_policy.pred.dist .* [c2; s2]; 0];
        g2.N = repmat(g2.single, [N, 1]);
        g2.lenght = 0;
        
        U_left = U_center;
        X_left = x_pred;
            
            % MPC for the leader with left direction
        [~, X_left, ~, ~, ~, U_left] = leaderMPCandUpdate( ...
                        sys, X_left(:,1), N, leaderParams, obs, U_left, false, [], g1);

        U_right = U_center;
        X_right = x_pred;

            % MPC for the leader with right direction
        [~, X_right, ~, ~, ~, U_right] = leaderMPCandUpdate( ...
                        sys, X_right(:,1), N, leaderParams, obs, U_right, false, [], g2);
        
            % Check for obstructions in the prediction
        done = false;
        j = 1;
        while done == false && j < N

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

            j = j + 1;
        end
            
    % --- Choosing the direction ---

            % Going left
        if g1.lenght > g2.lenght
            avoid_policy.single = g1.final;
            avoid_policy.N = repmat(avoid_policy.single, [N, 1]);
            avoid_policy.theta = t1;
            avoid_policy.cos = c1;
            avoid_policy.sin = s1;

            % Going right
        elseif g1.lenght < g2.lenght
            avoid_policy.single = g2.final;
            avoid_policy.N = repmat(avoid_policy.single, [N, 1]);
            avoid_policy.theta = t2;
            avoid_policy.cos = c2;
            avoid_policy.sin = s2;

            % Going on the robot direction
        else
            if ang_diff < 0
                avoid_policy.single = g1.final;
                avoid_policy.N = repmat(avoid_policy.single, [N, 1]);
                avoid_policy.theta = t1;
                avoid_policy.cos = c1;
                avoid_policy.sin = s1;
            else
                avoid_policy.single = g2.final;
                avoid_policy.N = repmat(avoid_policy.single, [N, 1]);
                avoid_policy.theta = t2;
                avoid_policy.cos = c2;
                avoid_policy.sin = s2;
            end


        end

%% UPDATE THE POLICY GOAL

    elseif avoid_policy.on == true

        dot_prod = (avoid_policy.n)' * (x_pred(1:2, 1) - avoid_policy.pos); 
        if dot_prod <= 0
            avoid_policy.single = [avoid_policy.single(1:2) + [avoid_policy.cos; avoid_policy.sin]; 0];
            avoid_policy.N = repmat(avoid_policy.single, [N, 1]);

            avoid_policy.times = avoid_policy.times + 1;
        else
            avoid_policy.on = false;
            avoid_policy.single = avoid_policy.goal;
            avoid_policy.N = avoid_policy.goal_N;
        end

    end

end



% function [avoid_policy] = avoidPolicyFunction(avoid_policy, x_pred, N, obs)
% 
%     if avoid_policy.on == true
%         dot_prod = (avoid_policy.n)' * (x_pred(1:2, 1) - avoid_policy.pos); 
%         if dot_prod <= 0
%             avoid_policy.single = [avoid_policy.single(1:2) + [avoid_policy.cos; avoid_policy.sin]; 0];
%             avoid_policy.N = repmat(avoid_policy.single, [N, 1]);
% 
%             avoid_policy.times = avoid_policy.times + 1;
%         else
%             avoid_policy.on = false;
%             avoid_policy.single = avoid_policy.goal;
%             avoid_policy.N = avoid_policy.goal_N;
%         end
% 
% 
%     elseif avoid_policy.on == false
% 
%         x_N_pos = x_pred(1:2,N);
%         x_N_ang = x_pred(3,N);
%         diff = avoid_policy.goal(1:2) - x_N_pos;
%         x_N_dir = atan2(diff(2), diff(1));
%         ang_diff = x_N_dir - x_N_ang;
% 
%         if abs(ang_diff) > pi/4
%             dir = x_N_ang;
%         else
%             dir = x_N_dir;
%         end
% 
%         if norm(diff) <= 2
%             dir = x_N_dir;
%         end
% 
%         avoid_policy.on = true;
%         avoid_policy.used = true;
%         avoid_policy.times = avoid_policy.times + 1;
% 
% 
% 
%         avoid_policy.n(:,:) = [cos(dir); sin(dir)];
%         avoid_policy.pos = x_N_pos + avoid_policy.margin * avoid_policy.n; 
%         avoid_policy.dir = dir;
% 
%         if ang_diff >= 0
%             avoid_policy.theta = dir - avoid_policy.dev_ang;
%             avoid_policy.cos = cos(avoid_policy.theta);
%             avoid_policy.sin = sin(avoid_policy.theta);
%             avoid_policy.single = [x_N_pos + [avoid_policy.cos; avoid_policy.sin]; 0];
%             avoid_policy.N = repmat(avoid_policy.single, [N, 1]);
%         else
%             avoid_policy.theta = dir + avoid_policy.dev_ang;
%             avoid_policy.cos = cos(avoid_policy.theta);
%             avoid_policy.sin = sin(avoid_policy.theta);
%             avoid_policy.single = [x_N_pos + [avoid_policy.cos; avoid_policy.sin]; 0];
%             avoid_policy.N = repmat(avoid_policy.single, [N, 1]);
%         end
% 
% 
%         %     % find theta +- dev_ang
%         % t1 = dir + avoid_policy.dev_ang;
%         % c1 = cos(t1);
%         % s1 = sin(t1); 
%         % g1 = x_N_pos + [c1; s1];
%         % 
%         % t2 = dir - avoid_policy.dev_ang;
%         % c2 = cos(t2);
%         % s2 = sin(t2); 
%         % g2 = x_N_pos + [c2; s2];
%         % 
%         % if norm(g1 - avoid_policy.goal(1:2)) < norm(g2 - avoid_policy.goal(1:2))
%         %     avoid_policy.single = [g1; 0];
%         %     avoid_policy.N = repmat(avoid_policy.single, [N, 1]);
%         %     avoid_policy.theta = t1;
%         %     avoid_policy.cos = c1;
%         %     avoid_policy.sin = s1;
%         % else
%         %     avoid_policy.single = [g2; 0];
%         %     avoid_policy.N = repmat(avoid_policy.single, [N, 1]);
%         %     avoid_policy.theta = t2;
%         %     avoid_policy.cos = c2;
%         %     avoid_policy.sin = s2;
%         % end
% 
% 
% 
%     end
% 
% end

