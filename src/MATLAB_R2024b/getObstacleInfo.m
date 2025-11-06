function [q, d] = getObstacleInfo(obstacles, selector, obsNum, x0, data, noise)
%GETOBSTACLEINFO get qis from obstacles

    [~, obs_n] = size(obstacles);
    q_all = zeros(2, size(data.FOV, 2));
    d_all = zeros(size(data.FOV, 2), 1);

%% Lidar data

    thetas = wrapToPi(data.FOV + x0(3));
    c = cos(thetas);
    s = sin(thetas);

%% For each obstacle

    if isempty(obstacles) || obsNum == 0
        q = []; d = [];
    else
        for i = 1:obs_n
            if selector(i)

                if obstacles{i}.type ~= "wall"
                    data.Dx = x0(1) - obstacles{i}.center(1);
                    data.Dy = x0(2) - obstacles{i}.center(2);
                end

                found = false;

                for ang = 1:size(thetas, 2)
                    
                    data.c = c(ang);
                    data.s = s(ang);
                    
                    [q_ang, d_ang] = getqiFromShape(obstacles{i}, x0, data, noise);
                    
                    if found == true && d_ang == Inf
                        break
                    end

                    if d_ang ~= Inf
                        found = true;

                        if d_all(ang) == 0
                            q_all(:,ang) = q_ang;
                            d_all(ang) = d_ang;
                        else
                            if d_ang < d_all(ang)
                                q_all(:,ang) = q_ang;
                                d_all(ang) = d_ang;
                            end
                        end
                    end
                end
            end
        end
    end

    q = [nonzeros(q_all(1,:))';nonzeros(q_all(2,:))'];
    d = nonzeros(d_all)';

end

