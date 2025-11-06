function obstaclesInRange = lidar( ...
            data, obstacles, x_l, x_f, leaderParams, followerParams, loadParams, sys, noise)
%% Select the obstacles closer to the leader 

    x_load = x_f(1:2) + loadParams.centerShape(:,1);
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
        obstaclesInRange.qi_l_stack = [];
        obstaclesInRange.qi_f_stack = [];
        obstaclesInRange.qi_load = [];
        obstaclesInRange.l_margin = [];
        obstaclesInRange.f_margin = [];
        return;
    end

%% Get the qi points for leader and follower

        % Get q points of leader from obstacles
    [qi_l, d_l] = getObstacleInfo(obstacles, selector, obsNum, x_l, data, noise);

        % Get q points of follower from obstacles
    [qi_f, d_f] = getObstacleInfo(obstacles, selector, obsNum, x_f, data, noise);

        % Get distance of load from obstacles
    diff = vecnorm([qi_l, qi_f] - x_load);
    d_load = min(diff);

    if d_load <= followerParams.d_FL/2
        obstaclesInRange.use_load = true;
    else
        obstaclesInRange.use_load = false;
    end
 
%% qi evaluations for the use in costs

    obstaclesInRange.qi_l = qi_l;
    obstaclesInRange.qi_f = qi_f;
    obstaclesInRange.d_l = d_l;
    obstaclesInRange.d_f = d_f;
    obstaclesInRange.d_load = d_load;

    [~,obstaclesInRange.M_l] = size(qi_l);
    [~,obstaclesInRange.M_f] = size(qi_f);

    points_l = size(qi_l, 2);
    obstaclesInRange.qi_l_stack = zeros(points_l*sys.N*2, 1);
    obstaclesInRange.l_margin = zeros(points_l*sys.N, 1);
    q_load_l = zeros(points_l*loadParams.k_pred*2, 1);
    for l = 1:points_l
        obstaclesInRange.qi_l_stack((l-1)*2*sys.N+1 : l*2*sys.N, 1) = repmat(qi_l(:,l), [sys.N, 1]);
        obstaclesInRange.l_margin((l-1)*sys.N+1 : l*sys.N, 1) = ...
            repmat((leaderParams.radius + 0.15*log(d_l(l))+0.26), sys.N, 1);
        q_load_l((l-1)*2*loadParams.k_pred+1 : l*2*loadParams.k_pred, 1) = repmat(qi_l(:,l), [loadParams.k_pred, 1]);
    end

    points_f = size(qi_f, 2);
    obstaclesInRange.qi_f_stack = zeros(points_f*sys.N*2, 1);
    obstaclesInRange.f_margin = zeros(points_f*sys.N, 1);
    q_load_f = zeros(points_f*loadParams.k_pred*2, 1);
    for l = 1:points_f
        obstaclesInRange.qi_f_stack((l-1)*2*sys.N+1 : l*2*sys.N, 1) = repmat(qi_f(:,l), [sys.N, 1]);
        obstaclesInRange.f_margin((l-1)*sys.N+1 : l*sys.N, 1) = ...
            repmat((followerParams.radius + 0.15*log(d_f(l))+0.26), sys.N, 1);
        q_load_f((l-1)*2*loadParams.k_pred+1 : l*2*loadParams.k_pred, 1) = repmat(qi_f(:,l), [loadParams.k_pred, 1]);
    end

    obstaclesInRange.qi_load = [q_load_l; q_load_f];
    obstaclesInRange.M_load = obstaclesInRange.M_l + obstaclesInRange.M_f;

 %% Create A_bar and B_bar matrices
% 
%         % Obtain the number of constraints
%     [~,obstaclesInRange.M_l] = size(qi_l);
%     [~,obstaclesInRange.M_f] = size(qi_f);
%     [~,obstaclesInRange.M_load] = size(qi_load);
% 
%         % A_bar and B_bar for leader
%     [obstaclesInRange.A_bar_l, obstaclesInRange.B_bar_l] = constMatrices(x_l(1:2), qi_l, sys.N, leaderParams.robotShape, sys, false, loadParams);
% 
%         % A_bar and B_bar for follower
%     [obstaclesInRange.A_bar_f, obstaclesInRange.B_bar_f] = constMatrices(x_f(1:2), qi_f, sys.N, followerParams.robotShape, sys, false, loadParams);
% 
%         % A_bar and B_bar for load
%     [obstaclesInRange.A_bar_load, obstaclesInRange.B_bar_load] = constMatrices(x_load(1:2), qi_load, sys.N, loadParams.centerShape(:,2:end), sys, true, loadParams);

end