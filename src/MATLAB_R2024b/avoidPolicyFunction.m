function [avoid_policy] = avoidPolicyFunction(avoid_policy, x_pred, N,obstacles)

    if avoid_policy.on == true
        if size(obstacles.qi_l, 1) ~= 0 && ...
                min(norm(obstacles.qi_l - x_pred(1:2,N))) < avoid_policy.d
            avoid_policy.single = [avoid_policy.single(1:2) + [avoid_policy.cos; avoid_policy.sin]; 0];
            avoid_policy.N = repmat(avoid_policy.single, [N, 1]);

            avoid_policy.times = avoid_policy.times + 1;
        else
            avoid_policy.on = false;
            avoid_policy.single = avoid_policy.goal;
            avoid_policy.N = avoid_policy.goal_N;
        end
    elseif avoid_policy.on == false
        avoid_policy.on = true;
        avoid_policy.used = true;
        avoid_policy.times = avoid_policy.times + 1;

        x_N =  x_pred(:,N);
        avoid_policy.d = min(norm(obstacles.qi_l - x_N(1:2))) + avoid_policy.margin;
        
            % find theta +- pi/2
        t1 = x_N(3) + avoid_policy.dev_ang;
        c1 = cos(t1);
        s1 = sin(t1); 
        g1 = x_N(1:2) + [c1; s1];

        t2 = x_N(3) - avoid_policy.dev_ang;
        c2 = cos(t2);
        s2 = sin(t2); 
        g2 = x_N(1:2) + [c2; s2];

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

