%% ROBOT DYNAMICS

    % System parameters
sys.n = 3;
sys.m = 2;

sys.obs_margin = 0.05;

%% ALGORITHM PARAMETERS

Px = [1 0 0; 0 1 0];

%% ROBOT DEFINITION

robot.diameter = 0.35;
robot.radius = robot.diameter/2;
robot.sides = 8;

robot.shape = nsidedpoly(robot.sides, 'Center', [0,0], ...
                        'Radius', robot.radius / cos(pi / robot.sides));
robot.vertices = robot.shape.Vertices';

%% LEADER PARAMETERS

leaderParams.Px = Px; % Px in the paper

    % Linear and angular velocities limits
leaderParams.v_max = 0.2; %0.3
leaderParams.w_max = pi*0.6;

    % Plotting parameters
leaderParams.pos_color = "red";
leaderParams.pred_color = "magenta";
leaderParams.constraint_color = "yellow";
leaderParams.show_predictions = true;
leaderParams.show_constraints = true;
leaderParams.keep_predictions = false;

    % Initial shape of leader
leaderParams.initRobotShape = robot.vertices;
leaderParams.robotShape = leaderParams.initRobotShape;

%% LOAD PARAMETERS

loadParams.d_FL = 1;
loadParams.width = 0.15;
% loadParams.vertices = [-loadParams.width/2, loadParams.d_FL + loadParams.width/2, ...
%                            loadParams.d_FL + loadParams.width/2, -loadParams.width/2; ...
%                            -loadParams.width/2, -loadParams.width/2, ...
%                            loadParams.width/2, loadParams.width/2];
loadParams.vertices = [ -loadParams.d_FL - loadParams.width/2, loadParams.width/2, ...
                        loadParams.width/2, -loadParams.d_FL - loadParams.width/2; ...
                        -loadParams.width/2, -loadParams.width/2, ...
                           loadParams.width/2, loadParams.width/2];

    % Shape on the follower side 
% loadParams.center = [-loadParams.d_FL/2, -3*loadParams.d_FL/4, -loadParams.d_FL/4, -loadParams.d_FL/4, -3*loadParams.d_FL/4;
%                      0, -loadParams.width/2, -loadParams.width/2, loadParams.width/2, loadParams.width/2];
    % Right shape on the load side - 4 vertices
% loadParams.center = [-loadParams.d_FL/2, -loadParams.d_FL/4, loadParams.d_FL/4, loadParams.d_FL/4, -loadParams.d_FL/4;
%                      0, -loadParams.width/2, -loadParams.width/2, loadParams.width/2, loadParams.width/2];

    % Right shape on the load side - 2 vertices
loadParams.center = [-loadParams.d_FL/2, 0, 0;
                     0, -loadParams.width/2, loadParams.width/2];
loadParams.centerShape = loadParams.center;

loadParams.k_pred = 10;

loadParams.color = "black";
loadParams.loadShape = loadParams.vertices;

%% FOLLOWER PARAMETERS

followerParams.d_FL = loadParams.d_FL;

followerParams.Px = Px; % Px in the paper

    % Linear and angular velocities limits
followerParams.v_max = 0.3; %0.4
followerParams.w_max = pi*0.9; 

    % Plotting parameters
followerParams.pos_color = "blue";
followerParams.pred_color = "cyan";
followerParams.constraint_color = "green";
followerParams.show_predictions = true;
followerParams.show_constraints = false;
followerParams.keep_predictions = false;

    % Initial shape of follower
followerParams.initRobotShape = robot.vertices;
followerParams.robotShape =followerParams.initRobotShape;