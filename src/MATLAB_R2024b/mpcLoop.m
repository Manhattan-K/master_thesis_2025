%% MPC algorithm

tic

while (~goal_reached) && (i < max_iter) % terminal condition: goal reach or maximum iteration

    disp("Starting iteration: " + num2str(i) + ", time: " + num2str(i*sys.Ts) + "s, Computational time: " + num2str(step_time(i)) + "s");

%--------------------------- Obstacle avoidanace matrices -------------

        % Evaluate the MPC only on the nearest obstacles
    obstaclesInRange = evaluateObstacles( ...
        obstacles, x_l(1:2,i), x_f(1:2,i), leaderParams, followerParams, loadParams, sys, N);

%--------------------------- MPC for Leader and Follower -------------

        % MPC for the leader
    [x_l(:,i+1), X_L, X_L_stacked, ~, u_l(:,i+1), U_l_old] = leaderMPCandUpdate( ...
                        sys, x_l(:,i), N, leaderParams, obstaclesInRange, U_l_old, x_f(:,i), avoid_policy);

    X_L_plot(:,:,i) = X_L;

        % MPC for the follower
    [x_f(:,i+1), X_F, ~, u_f(:,i+1), U_f_old] = followerMPCandUpdate(...
                        sys, x_f(:,i), X_L_stacked, N, followerParams, obstaclesInRange, U_f_old);

    X_F_plot(:,:,i) = X_F;

%--------------------------- Feasibility-Aware Recovery Policy -------------

    if policy_halt == true
            % Check if trajectory does not loose the load
        formation_error = abs(vecnorm(Px*(X_L-X_F))-followerParams.d_FL);
        if any(formation_error(1:k_loose_grip) > eps_loose_grip)

                % MPC for the leader using the new cost function
            [x_l(:,i+1), X_L, X_L_stacked, ~, u_l(:,i+1), U_l_old] = leaderMPCandUpdateHalt( ...
                        sys, x_l(:,i), N, leaderParams, obstaclesInRange, zeros([sys.m*N,1]));

                % MPC for the follower using the new leader states
            [x_f(:,i+1), X_F, ~, u_f(:,i+1), U_f_old] = followerMPCandUpdate(...
                        sys, x_f(:,i), X_L_stacked, N, followerParams, obstaclesInRange, zeros([sys.m*N,1]));
        end
    end

%--------------------------- Avoidance Policy ------------------------------

    if policy_avoid == true
        if avoid_policy.on == true || ...                                   % If the policy is on
           size(obstaclesInRange.qi_l, 1) ~= 0 && ...                       % If there are obstacles
           norm(X_L(1:2,N) - avoid_policy.goal(1:2)) >= 0.5 && ...          % If we are away from the goal
           norm(X_L(1:2,N - avoid_policy.k_block) - X_L(1:2,N)) <= 1e-10             % If we have an obstruction
            avoid_policy = avoidPolicyFunction(avoid_policy, X_L, N, obstaclesInRange);
        end
    end

%--------------------------- Other evaluations  ---------------------------

        % Get the instantaneous rotation of load and apply to load
    fl_diff = x_f(:,i+1) - x_l(:,i+1);
    loadTheta = atan2(fl_diff(2), fl_diff(1));
    loadTheta_p(i) = loadTheta;

    leaderParams.robotShape = Rmat(loadTheta)*leaderParams.initRobotShape;
    followerParams.robotShape = Rmat(loadTheta)*followerParams.initRobotShape;
    loadParams.loadShape = Rmat(loadTheta)*loadParams.vertices;

        % Check if goal was reached up to desired precision
    if norm(x_l(1:2,i+1) - goal.single(1:2)) < delta
        goal_reached = true;
    end

        % Distance between the 2 robots
    real_d(i + 1) = norm(x_l(1:2,i) - x_f(1:2,i));

        % Error
    dist_error(i + 1) = real_d(i + 1) - followerParams.d_FL;

        % Obstacle dynamics 
    % if size(obstacles, 2) >= 20
    %     obstacles{20}.center = obstacles{20}.center - [0, 0.1]'; 
    % end

    step_time(i + 1) = toc;

        % Update iteration
    i = i+1;

end