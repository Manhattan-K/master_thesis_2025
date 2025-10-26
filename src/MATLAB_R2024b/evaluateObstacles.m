function obstaclesInRange = evaluateObstacles(obstacles, x_l, x_f, ...
                    leaderParams, followerParams, loadParams, sys, N)
%% Select the obstacles closer to the leader 

    predictionDist = N * leaderParams.v_max / 7.5;
    selector = zeros(size(obstacles, 2));
    obsNum = 0;
        
    for i = 1:size(obstacles, 2)
        
        obsDistance = norm(x_l - obstacles{i}.center) - obstacles{i}.radius; 
        
        if predictionDist >= obsDistance
            selector(i) = 1;
            obsNum = obsNum + 1;
        end
    end

%% Get the qi points for leader and follower

        % Get q points of leader from obstacles
    [qi_l, d_l] = getObstacleInfo(obstacles, selector, obsNum, x_l);

        % Get q points of follower from obstacles
    [qi_f, d_f] = getObstacleInfo(obstacles, selector, obsNum, x_f);

    obstaclesInRange.qi_l = qi_l;
    obstaclesInRange.qi_f = qi_f;
    obstaclesInRange.d_l = d_l;
    obstaclesInRange.d_f = d_f;

%% Create A_bar and B_bar matrices

        % Obtain the number of constraints
    [~,obstaclesInRange.M_l] = size(qi_l);
    [~,obstaclesInRange.M_f] = size(qi_f);

        % A_bar and B_bar for leader
    [obstaclesInRange.A_bar_l, obstaclesInRange.B_bar_l] = constMatrices(x_l, qi_l, N, ...
                                [leaderParams.robotShape, loadParams.loadShape], sys);

        % A_bar and B_bar for follower
    [obstaclesInRange.A_bar_f, obstaclesInRange.B_bar_f] = constMatrices(x_f, qi_f, N, followerParams.robotShape, sys);

end

