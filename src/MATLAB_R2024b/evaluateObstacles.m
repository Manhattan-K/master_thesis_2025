function obstaclesInRange = evaluateObstacles(obstacles, x_l, x_f, ...
                    leaderParams, followerParams, loadParams, sys, N, noise)
%% Select the obstacles closer to the leader 

    x_load = x_f + loadParams.centerShape(:,1);
    predictionDist = loadParams.d_FL + 0.5;
    selector = zeros(size(obstacles, 2));

    %% Select the nearest obstacles

    obsNum = 0;
        
    for i = 1:size(obstacles, 2)
        
        obsDistance = norm(x_load - obstacles{i}.center) - obstacles{i}.radius; 
        
        if predictionDist >= obsDistance
            selector(i) = 1;
            obsNum = obsNum + 1;
        end
    end

%% If there are no obstacles break

    if obsNum == 0
        obstaclesInRange.use_load = 0;
        obstaclesInRange.qi_l = [];
        obstaclesInRange.qi_f = [];
        obstaclesInRange.qi_load = [];
        obstaclesInRange.d_l = [];
        obstaclesInRange.d_f = [];
        obstaclesInRange.d_load = [];
        obstaclesInRange.M_l = 0;
        obstaclesInRange.M_f = 0;
        obstaclesInRange.M_load = 0;
        obstaclesInRange.A_bar_l = [];
        obstaclesInRange.A_bar_f = [];
        obstaclesInRange.A_bar_load = [];
        obstaclesInRange.B_bar_l = [];
        obstaclesInRange.B_bar_f = [];
        obstaclesInRange.B_bar_load = [];

        return;
    end

%% Get the qi points for leader and follower

        % Get q points of leader from obstacles
    [qi_l, d_l] = getObstacleInfo(obstacles, selector, obsNum, x_l, noise);

        % Get q points of follower from obstacles
    [qi_f, d_f] = getObstacleInfo(obstacles, selector, obsNum, x_f, noise);

        % Get q points of load from obstacles
    [qi_load, d_load] = getObstacleInfo(obstacles, selector, obsNum, x_load, noise);

    if any(d_load <= followerParams.d_FL/4) 
        obstaclesInRange.use_load = true;
    else
        obstaclesInRange.use_load = false;
    end
 
%% qi evaluations for the use in costs

    obstaclesInRange.qi_l = qi_l;
    obstaclesInRange.qi_f = qi_f;
    obstaclesInRange.qi_load = qi_load;
    obstaclesInRange.d_l = d_l;
    obstaclesInRange.d_f = d_f;
    obstaclesInRange.d_load = d_load;

    % obstaclesInRange.L = obsNum;
    % 
    % obstaclesInRange.qi_l_stack = zeros(obsNum*N*2, 1);
    % for l = 1:obsNum
    %     obstaclesInRange.qi_l_stack((l-1)*2*N+1 : l*2*N, 1) = repmat(qi_l(:,l), [N, 1]);
    % end
    % 
    % if obsNum ~= 0
    %     max_d = max(d_l);
    %     max_d_s = max_d(1)^2;
    %     obstaclesInRange.relative = repmat(-leaderParams.D/max_d_s, [1, obsNum*N]);
    % else
    %     obstaclesInRange.relative = 0;
    % end

%% Create A_bar and B_bar matrices

        % Obtain the number of constraints
    [~,obstaclesInRange.M_l] = size(qi_l);
    [~,obstaclesInRange.M_f] = size(qi_f);
    [~,obstaclesInRange.M_load] = size(qi_load);

        % A_bar and B_bar for leader
    [obstaclesInRange.A_bar_l, obstaclesInRange.B_bar_l] = constMatrices(x_l, qi_l, N, leaderParams.robotShape, sys, false, loadParams);

        % A_bar and B_bar for follower
    [obstaclesInRange.A_bar_f, obstaclesInRange.B_bar_f] = constMatrices(x_f, qi_f, N, followerParams.robotShape, sys, false, loadParams);

        % A_bar and B_bar for load
    [obstaclesInRange.A_bar_load, obstaclesInRange.B_bar_load] = constMatrices(x_load, qi_load, N, loadParams.centerShape(:,2:end), sys, true, loadParams);

end

