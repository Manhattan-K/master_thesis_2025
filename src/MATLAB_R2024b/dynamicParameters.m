%% System parameters

sys.Ts = opt.Ts;
sys.d_fl = loadParams.d_FL;

%% ALGORITHM PARAMETERS

    % Proximity parameter to the goal position (tolleranza per il goal)
delta = opt.delta;

    % Predictive horizon
N = opt.N;

goal.N = repmat(goal.single, [N, 1]);


%% Feasibility-Aware Recovery Policy

policy_halt = opt.policy_halt;
k_loose_grip = opt.k_loose_grip;
eps_loose_grip = opt.eps_loose_grip;

%% Avoidance Policy 

policy_avoid = opt.policy_avoid;

avoid_policy.goal = goal.single;
avoid_policy.goal_N = goal.N;
avoid_policy.single = goal.single;
avoid_policy.N = goal.N;

avoid_policy.on = false;
avoid_policy.used = false;
avoid_policy.times = 0;

avoid_policy.pos = 0;
avoid_policy.dir = 0;
avoid_policy.n = [0;0];

avoid_policy.theta = 0;
avoid_policy.cos = 0;
avoid_policy.sin = 0;

avoid_policy.margin = opt.margin + sys.obs_margin;
avoid_policy.dev_ang = opt.dev_ang;
avoid_policy.k_block = opt.k_block;

%% LEADER PARAMETERS

leaderParams.W = diag([opt.W_pos, opt.W_pos, opt.W_angle]);      
leaderParams.Z = diag([opt.Z_pos, opt.Z_pos, opt.W_angle]); 
leaderParams.R = diag([opt.R_lin, opt.R_ang]);
leaderParams.D = opt.D;
leaderParams.K = opt.K;

leaderParams.d_FL_sq = repmat(followerParams.d_FL^2, [1,N-1]);
leaderParams.beta = opt.beta;
leaderParams.beta_N = leaderParams.beta.^(1:N-1);

[leaderParams.W_hat, leaderParams.R_hat] = costWeights( ...
                     sys, leaderParams.W, leaderParams.R, leaderParams.Z, N);

leaderParams.alg = opt.alg;

leaderParams.Px_N = kron(eye(N), Px);

    % Linear and angular velocities limits
[leaderParams.lb, leaderParams.ub] = inputBounds( ...
    leaderParams.v_max, leaderParams.w_max, N);

%% FOLLOWER PARAMETERS

followerParams.d_FL_sq = repmat(followerParams.d_FL^2, [1,N]);
    % Relative cost for distance errors
followerParams.C = opt.C;

    % Exponential decay of tracking quality over the prediction
followerParams.beta = opt.beta;
followerParams.beta_N = followerParams.beta.^(1:N);

followerParams.alg = opt.alg;

    % Linear and angular velocities limits
[followerParams.lb, followerParams.ub] = inputBounds( ...
    followerParams.v_max, followerParams.w_max, N);

%% MPC loop

    % Loop variables
max_iter = opt.max_iter;
goal_reached = false;
i = 1;

    % Variables allocation and inizialization
real_d = zeros(max_iter + 1, 1);
real_d(1) = loadParams.d_FL;
step_time = zeros(max_iter, 1);
dist_error = zeros(max_iter + 1, 1);

    % Initialization of the leader and follower STATES and INPUTS
x_l = zeros(sys.n, max_iter);
x_f = zeros(sys.n, max_iter);
u_l = zeros(sys.m, max_iter);
u_f = zeros(sys.m, max_iter);

x_l(:,i) = x0;
x_f(:,i) = x0 + [followerParams.d_FL; 0; 0];
u_l(:,i) = zeros(sys.m, 1);
u_f(:,i) = zeros(sys.m, 1);

    % Initial guesses for optimal inputs
X_L = zeros(sys.n, N);
X_F = zeros(sys.n, N);
X_L_stacked = zeros(sys.n*N, 1);
X_F_stacked = repmat(x_f(:,i), [N, 1]);
U_l_old = zeros([sys.m*N,1]);
U_f_old = zeros([sys.m*N,1]);

    % Plot variables
X_L_plot = zeros(sys.n,N,max_iter);
X_F_plot = zeros(sys.n,N,max_iter);
loadTheta_p = zeros(max_iter, 1);