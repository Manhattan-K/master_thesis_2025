%% ROBOT DYNAMICS

    % System parameters
sys.n = int8(3);
sys.m = int8(2);

%% ALGORITHM PARAMETERS

Px = [int8(1) int8(0) int8(0); int8(0) int8(1) int8(0)];

%% LEADER PARAMETERS

leaderParams.Px = Px; % Px in the paper

    % Linear and angular velocities limits
leaderParams.v_max = 1; %0.3
leaderParams.w_max = pi/2;

    % Plotting parameters
leaderParams.pos_color = "red";
leaderParams.pred_color = "magenta";
leaderParams.constraint_color = "yellow";
leaderParams.show_predictions = true;
leaderParams.show_constraints = true;
leaderParams.keep_predictions = false;

    % Initial shape of leader
th = 0:0.3:2*pi;
leaderParams.initRobotShape = 0.32*[cos(th); sin(th)];
leaderParams.robotShape = leaderParams.initRobotShape;

%% FOLLOWER PARAMETERS

followerParams.d_FL = 1;

followerParams.Px = Px; % Px in the paper

    % Linear and angular velocities limits
followerParams.v_max = 1.5; %0.4
followerParams.w_max = pi; 

    % Plotting parameters
followerParams.pos_color = "blue";
followerParams.pred_color = "cyan";
followerParams.constraint_color = "green";
followerParams.show_predictions = true;
followerParams.show_constraints = false;
followerParams.keep_predictions = false;
followerParams.initRobotShape = (0.2*[-1, 1, 1, -1; -1, -1, 1, 1]...
                            +followerParams.d_FL*[-1,0, 0, -1; 0,0,0,0]);
followerParams.robotShape =followerParams.initRobotShape;