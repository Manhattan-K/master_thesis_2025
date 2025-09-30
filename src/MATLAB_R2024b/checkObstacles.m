function [obstaclesInRange] = checkObstacles(obstacles, x0, N, v_max)

    predictionDist = N * v_max / 7.5;
    obstaclesInRange = {};
    ind = 1;
        
    for i = 1:size(obstacles, 2)
        
        obsDistance = norm(x0 - obstacles{i}.center) - obstacles{i}.radius; 
        
        if predictionDist >= obsDistance
            obstaclesInRange{ind} = obstacles{i};
            ind = ind + 1;
        end
    end
end

