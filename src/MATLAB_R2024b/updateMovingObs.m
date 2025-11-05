function obstacles = updateMovingObs(obstacles)
    for i = 1:size(obstacles, 2)
        obs = obstacles{i};
        if obs.type == "move"
            theta = obs.theta;
            c = obs.center + [obs.vel*cos(theta); obs.vel*sin(theta)];
            obstacles{i}.center = c;
            
            if norm(obs.a - c) <= 1e-4 || norm(obs.b - c) <= 1e-4
                obstacles{i}.theta = wrapTo2Pi(theta + pi);
            end
        end
    end

end