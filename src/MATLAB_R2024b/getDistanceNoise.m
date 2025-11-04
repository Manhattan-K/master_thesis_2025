function n = getDistanceNoise(d, sigma_noise)

        % Define some values
    exp = 1.5;
    sigma_min = 1e-6; 

        % Find the sigma based on the distance
    err_max_3sigma = sigma_noise * (d ^ exp); 
    sigma = err_max_3sigma / 3;
    sigma = max(sigma_min, sigma);

        % Calculate the noise
    n = sigma * randn(1, 1);
end