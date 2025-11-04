function [q, d] = getObstacleInfo(obstacles, selector, obsNum, x0, noise)
%GETOBSTACLEINFO get qis from obstacles

    [~, obs_n] = size(obstacles);
    q = zeros(2, obsNum);
    d = zeros(obsNum, 1);
        % Index for the selected obstacles only
    j = 1;

    if isempty(obstacles) || obsNum == 0
        q = []; d = [];
    else
        for i = 1:obs_n
            if selector(i)
                [q(:,j), d(j)] = getqiFromShape(obstacles{i}, x0, noise);
                j = j + 1;
            end
        end
    end
end

