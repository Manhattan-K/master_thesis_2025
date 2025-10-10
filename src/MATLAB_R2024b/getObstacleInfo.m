function [q, d] = getObstacleInfo(obstacles, selector, obsNum, x0)
%GETOBSTACLEINFO get qis from obstacles

    [~, obs_n] = size(obstacles);
    q = zeros(2, obsNum);
    d = zeros(obsNum);
        % Index for the selected obstacles only
    j = 1;

    if isempty(obstacles) || obsNum == 0
        q = []; d = [];
    else
        for i = 1:obs_n
            if selector(i)
                [q(:,j), d(j)] = getqiFromShape(obstacles{i}, x0);
                j = j + 1;
            end
        end
    end
end

