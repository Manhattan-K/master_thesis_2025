function [avoid_policy] = avoidPolicyFunction(avoid_policy, x_pred, N, obs)

    if avoid_policy.on == true
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

    
    elseif avoid_policy.on == false

        x_N_pos = x_pred(1:2,N);
        x_N_ang = x_pred(3,N);
        diff = avoid_policy.goal(1:2) - x_N_pos;
        x_N_dir = atan2(diff(2), diff(1));

        if abs(x_N_dir - x_N_ang) > pi/4
            x_N_dir = x_N_ang;
        end

        avoid_policy.on = true;
        avoid_policy.used = true;
        avoid_policy.times = avoid_policy.times + 1;

        

        avoid_policy.n(:,:) = [cos(x_N_dir); sin(x_N_dir)];
        avoid_policy.pos = x_N_pos + avoid_policy.margin * avoid_policy.n; 
        avoid_policy.dir = x_N_dir;

            % find theta +- pi/2
        t1 = x_N_dir + avoid_policy.dev_ang;
        c1 = cos(t1);
        s1 = sin(t1); 
        g1 = x_N_pos + [c1; s1];

        t2 = x_N_dir - avoid_policy.dev_ang;
        c2 = cos(t2);
        s2 = sin(t2); 
        g2 = x_N_pos + [c2; s2];

        if norm(g1 - avoid_policy.goal(1:2)) < norm(g2 - avoid_policy.goal(1:2))
            avoid_policy.single = [g1; 0];
            avoid_policy.N = repmat(avoid_policy.single, [N, 1]);
            avoid_policy.theta = t1;
            avoid_policy.cos = c1;
            avoid_policy.sin = s1;
        else
            avoid_policy.single = [g2; 0];
            avoid_policy.N = repmat(avoid_policy.single, [N, 1]);
            avoid_policy.theta = t2;
            avoid_policy.cos = c2;
            avoid_policy.sin = s2;
        end
    end

end

