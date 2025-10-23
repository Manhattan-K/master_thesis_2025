function [p_tp1, X_L, X_L_stacked, error, u_t, u_opt, avoid_policy] = leaderMPCandUpdate(...
                                          sys, x0, N, robotParams, obstacles, U_l_old, x_f, avoid_policy)
%% Variables definitions

    n = sys.n;
    
        % Get cost function
    costF = @(U) leaderCost(U, x0, x_f, sys, robotParams.W, robotParams.W_hat, robotParams.R_hat, robotParams.K, N, avoid_policy);

        % Get constraints function
    constraintsF = @(U) constraints(U, x0, obstacles.M_l, obstacles.A_bar_l, obstacles.B_bar_l, N, robotParams.robotShape, sys);

%% fmincon optimization

    options = optimoptions('fmincon','Algorithm', robotParams.alg,'Display','off');
    [u_opt, ~, exitflag, output] = fmincon(costF, U_l_old, [], [], [], [], robotParams.lb, robotParams.ub, constraintsF, options);
    
    error.QPexitflag = exitflag;
    error.QPoutput = output;
    
%% States and output

    x_pred_stacked = stateEvolution(u_opt, x0, sys, N);
    x_pred = reshape(x_pred_stacked,[n,N]);
    
    % Update the state and input with the first one predicted
    p_tp1 = x_pred(:,1);
    X_L = x_pred;
    X_L_stacked = x_pred_stacked;
    u_t = u_opt(1:2);

%%
   
    if avoid_policy.on == true
        if min(norm(obstacles.qi_l - x_pred(1:2,N - 1))) < avoid_policy.d
            g1 = avoid_policy.single(1:2) + [cos(avoid_policy.theta); sin(avoid_policy.theta)];
            avoid_policy.single = [g1; 0];
            avoid_policy.N = repmat(avoid_policy.single, [N, 1]);
        else
            avoid_policy.on = false;
            avoid_policy.single = avoid_policy.goal;
            avoid_policy.N = avoid_policy.goal_N;
        end
    elseif norm(x_pred(1:2,N) - avoid_policy.goal(1:2)) >= 0.5 && ... 
           norm(x_pred(1:2,N - 1) - x_pred(1:2,N)) <= 1e-10 && avoid_policy.on == false
        avoid_policy.on = true;
        avoid_policy.d = min(norm(obstacles.qi_l - x_pred(1:2,N))) + avoid_policy.margin;

            % find theta +- pi/2
        g1 = x_pred(1:2,N) + [cos(x_pred(3,N) + pi/4); sin(x_pred(3,N) + pi/4)];
        g2 = x_pred(1:2,N) + [cos(x_pred(3,N) - pi/4); sin(x_pred(3,N) - pi/4)];

        if norm(g1 - avoid_policy.goal(1:2)) < norm(g2 - avoid_policy.goal(1:2))
            avoid_policy.single = [g1; 0];
            avoid_policy.N = repmat(avoid_policy.single, [N, 1]);
            avoid_policy.theta = x_pred(3,N) + pi/4;
        else
            avoid_policy.single = [g2; 0];
            avoid_policy.N = repmat(avoid_policy.single, [N, 1]);
            avoid_policy.theta = x_pred(3,N) - pi/4;
        end
    end

end

