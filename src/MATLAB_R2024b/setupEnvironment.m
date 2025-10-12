function [x0, obstacles] = setupEnvironment(setupString)
    switch setupString
        case "no_obs"
            % Setup 01: No obstacles and p(0) = (20, 20)
            x0 = [20; 10; -pi/2];
            obstacles = {};
            
        case "one_obs"
            %Setup 02 one obstacles and p(0) = (10, 14)
            x0 = [10; 14; -pi/2];
            obstacle1.type = "circle";
            obstacle1.center = [5, 7]';
            obstacle1.radius = 3;
            obstacle1.is_x_wall = false;
            obstacle1.wall_pos = 0;
            obstacle1.a = 0;
            obstacle1.b = 0;
            obstacle1.theta = 0;
            obstacles = {obstacle1};
            
        case "two_obs"
            % Setup 03 LF one obstacles and p(0) = (10, 14)
            x0 = [10; 14; -pi/2];
            obstacle1.type = "circle";
            obstacle1.center = [3, 12]';
            obstacle1.radius = 3;
            obstacle1.is_x_wall = false;
            obstacle1.wall_pos = 0;
            obstacle1.a = 0;
            obstacle1.b = 0;
            obstacle1.theta = 0;
            
            obstacle2.type = "circle";
            obstacle2.center = [6, 5]';
            obstacle2.radius = 3;
            obstacle2.is_x_wall = false;
            obstacle2.wall_pos = 0;
            obstacle2.a = 0;
            obstacle2.b = 0;
            obstacle2.theta = 0;
            
            obstacles = {obstacle1,obstacle2};
            
        case "three_obs"
            % Setup 03 one obstacles and p(0) = (10, 14)
            x0 = [10; 14; -pi/2];
            obstacle1.type = "circle";
            obstacle1.center = [5, 11]';
            obstacle1.radius = 3;
            obstacle1.is_x_wall = false;
            obstacle1.wall_pos = 0;
            obstacle1.a = 0;
            obstacle1.b = 0;
            obstacle1.theta = 0;

            obstacle2.type = "circle";
            obstacle2.center = [7, 4]';
            obstacle2.radius = 3;obstacle1.is_x_wall = false;
            obstacle2.wall_pos = 0;
            obstacle2.a = 0;
            obstacle2.b = 0;
            obstacle2.theta = 0;

            obstacle3.type = "circle";
            obstacle3.center = [1, 3]';
            obstacle3.radius = 1;
            obstacle3.is_x_wall = false;
            obstacle3.wall_pos = 0;
            obstacle3.a = 0;
            obstacle3.b = 0;
            obstacle3.theta = 0;

            obstacles = {obstacle1,obstacle2,obstacle3};
            
        case "pathological"
            % Pathological cases
            x0 = [10; 10; -pi/2];
            obstacle1.type = "circle";
            obstacle1.center = [5, 5]';
            obstacle1.radius = 2;
            obstacle1.is_x_wall = false;
            obstacle1.wall_pos = 0;
            obstacle1.a = 0;
            obstacle1.b = 0;
            obstacle1.theta = 0;
            obstacles = {obstacle1};
            
        case "six_obs"
            % Complex Map, six obstacles
            x0 = [40; 5; -pi/2];
            obstacle1.type = "circle";
            obstacle1.center = [35, 4]';
            obstacle1.radius = 2;
            obstacle1.is_x_wall = false;
            obstacle1.wall_pos = 0;
            obstacle1.a = 0;
            obstacle1.b = 0;
            obstacle1.theta = 0;
            
            obstacle2.type = "circle";
            obstacle2.center = [30, -1]';
            obstacle2.radius = 3;
            obstacle2.is_x_wall = false;
            obstacle2.wall_pos = 0;
            obstacle2.a = 0;
            obstacle2.b = 0;
            obstacle2.theta = 0;
            
            obstacle3.type = "circle";
            obstacle3.center = [25, 5]';
            obstacle3.radius = 3;
            obstacle3.is_x_wall = false;
            obstacle3.wall_pos = 0;
            obstacle3.a = 0;
            obstacle3.b = 0;
            obstacle3.theta = 0;
            
            obstacle4.type = "circle";
            obstacle4.center = [18, 0]';
            obstacle4.radius = 1;
            obstacle4.is_x_wall = false;
            obstacle4.wall_pos = 0;
            obstacle4.a = 0;
            obstacle4.b = 0;
            obstacle4.theta = 0;
            
            obstacle5.type = "circle";
            obstacle5.center = [5, -1]';
            obstacle5.radius = 1;
            obstacle5.is_x_wall = false;
            obstacle5.wall_pos = 0;
            obstacle5.a = 0;
            obstacle5.b = 0;
            obstacle5.theta = 0;
            
            obstacle6.type = "circle";
            obstacle6.center = [10, 4]';
            obstacle6.radius = 3;
            obstacle6.is_x_wall = false;
            obstacle6.wall_pos = 0;
            obstacle6.a = 0;
            obstacle6.b = 0;
            obstacle6.theta = 0;
            
            obstacles = {obstacle1, obstacle2, obstacle3, obstacle4, obstacle5, obstacle6};

        case "valzer"
    % Complex Map-variable
    x0 = [39.5; 22; -pi/2];
    
    % corridor circle 1st wall
    
    % obstacle 1 e 2 già completi (li ho inclusi per completezza)
    obstacle1.type = "circle";
    obstacle1.center = [40, 20]';
    obstacle1.radius = 1;
    obstacle1.is_x_wall = false;
    obstacle1.wall_pos = 0;
    obstacle1.a = 0;
    obstacle1.b = 0;
    obstacle1.theta = 0;
    
    obstacle2.type = "circle";
    obstacle2.center = [39.5, 18.5]';
    obstacle2.radius = 1;
    obstacle2.is_x_wall = false;
    obstacle2.wall_pos = 0;
    obstacle2.a = 0;
    obstacle2.b = 0;
    obstacle2.theta = 0;
    
    obstacle3.type = "circle";
    obstacle3.center = [39,17]';
    obstacle3.radius = 1;
    obstacle3.is_x_wall = false;
    obstacle3.wall_pos = 0;
    obstacle3.a = 0;
    obstacle3.b = 0;
    obstacle3.theta = 0;
    
    obstacle4.type = "circle";
    obstacle4.center = [38.5,15.5]';
    obstacle4.radius = 1;
    obstacle4.is_x_wall = false;
    obstacle4.wall_pos = 0;
    obstacle4.a = 0;
    obstacle4.b = 0;
    obstacle4.theta = 0;

    obstacle5.type = "circle";
    obstacle5.center = [38, 14]';
    obstacle5.radius = 1;
    obstacle5.is_x_wall = false;
    obstacle5.wall_pos = 0;
    obstacle5.a = 0;
    obstacle5.b = 0;
    obstacle5.theta = 0;
    
    obstacle6.type = "circle";
    obstacle6.center = [37, 13]';
    obstacle6.radius = 1;
    obstacle6.is_x_wall = false;
    obstacle6.wall_pos = 0;
    obstacle6.a = 0;
    obstacle6.b = 0;
    obstacle6.theta = 0;
    
    obstacle7.type = "circle";
    obstacle7.center = [36, 12]';
    obstacle7.radius = 1;
    obstacle7.is_x_wall = false;
    obstacle7.wall_pos = 0;
    obstacle7.a = 0;
    obstacle7.b = 0;
    obstacle7.theta = 0;
    
    obstacle8.type = "circle";
    obstacle8.center = [34.5, 12]';
    obstacle8.radius = 1;
    obstacle8.is_x_wall = false;
    obstacle8.wall_pos = 0;
    obstacle8.a = 0;
    obstacle8.b = 0;
    obstacle8.theta = 0;
    
    obstacle9.type = "circle";
    obstacle9.center = [33, 12]';
    obstacle9.radius = 1;
    obstacle9.is_x_wall = false;
    obstacle9.wall_pos = 0;
    obstacle9.a = 0;
    obstacle9.b = 0;
    obstacle9.theta = 0;
    
    % corridor circle 2nd wall
    obstacle10.type = "circle";
    obstacle10.center = [38-1, 23]';
    obstacle10.radius = 1;
    obstacle10.is_x_wall = false;
    obstacle10.wall_pos = 0;
    obstacle10.a = 0;
    obstacle10.b = 0;
    obstacle10.theta = 0;

    obstacle11.type = "circle";
    obstacle11.center = [37.5-1, 21.5]';
    obstacle11.radius = 1;
    obstacle11.is_x_wall = false;
    obstacle11.wall_pos = 0;
    obstacle11.a = 0;
    obstacle11.b = 0;
    obstacle11.theta = 0;

    obstacle12.type = "circle";
    obstacle12.center = [37-1,20]';
    obstacle12.radius = 1;
    obstacle12.is_x_wall = false;
    obstacle12.wall_pos = 0;
    obstacle12.a = 0;
    obstacle12.b = 0;
    obstacle12.theta = 0;

    obstacle13.type = "circle";
    obstacle13.center = [36.5-1,18.5]';
    obstacle13.radius = 1;
    obstacle13.is_x_wall = false;
    obstacle13.wall_pos = 0;
    obstacle13.a = 0;
    obstacle13.b = 0;
    obstacle13.theta = 0;

    obstacle14.type = "circle";
    obstacle14.center = [36-1, 17]';
    obstacle14.radius = 1;
    obstacle14.is_x_wall = false;
    obstacle14.wall_pos = 0;
    obstacle14.a = 0;
    obstacle14.b = 0;
    obstacle14.theta = 0;

    obstacle15.type = "circle";
    obstacle15.center = [35-1, 16]';
    obstacle15.radius = 1;
    obstacle15.is_x_wall = false;
    obstacle15.wall_pos = 0;
    obstacle15.a = 0;
    obstacle15.b = 0;
    obstacle15.theta = 0;

    obstacle16.type = "circle";
    obstacle16.center = [33.5-1, 16]';
    obstacle16.radius = 1;
    obstacle16.is_x_wall = false;
    obstacle16.wall_pos = 0;
    obstacle16.a = 0;
    obstacle16.b = 0;
    obstacle16.theta = 0;

    obstacle17.type = "circle";
    obstacle17.center = [32-1, 16]';
    obstacle17.radius = 1;
    obstacle17.is_x_wall = false;
    obstacle17.wall_pos = 0;
    obstacle17.a = 0;
    obstacle17.b = 0;
    obstacle17.theta = 0;

    % Machinery1
    obstacle18.type = "circle";
    obstacle18.center = [25, 13]';
    obstacle18.radius = 4;
    obstacle18.is_x_wall = false;
    obstacle18.wall_pos = 0;
    obstacle18.a = 0;
    obstacle18.b = 0;
    obstacle18.theta = 0;

    % Machinery2
    obstacle19.type = "circle";
    obstacle19.center = [25, 2]';
    obstacle19.radius = 4;
    obstacle19.is_x_wall = false;
    obstacle19.wall_pos = 0;
    obstacle19.a = 0;
    obstacle19.b = 0;
    obstacle19.theta = 0;

    % person
    obstacle20.type = "circle";
    obstacle20.center = [12, 23]';
    obstacle20.radius = 1;
    obstacle20.is_x_wall = false;
    obstacle20.wall_pos = 0;
    obstacle20.a = 0;
    obstacle20.b = 0;
    obstacle20.theta = 0;

    % stock 1
    obstacle21.type = "circle";
    obstacle21.center = [0, 2]';
    obstacle21.radius = 1;
    obstacle21.is_x_wall = false;
    obstacle21.wall_pos = 0;
    obstacle21.a = 0;
    obstacle21.b = 0;
    obstacle21.theta = 0;

    % stock2
    obstacle22.type = "circle";
    obstacle22.center = [0, 4]';
    obstacle22.radius = 1;
    obstacle22.is_x_wall = false;
    obstacle22.wall_pos = 0;
    obstacle22.a = 0;
    obstacle22.b = 0;
    obstacle22.theta = 0;

    % stock3 (c'era un refuso, l'ho chiamato obstacle23)
    obstacle23.type = "circle";
    obstacle23.center = [0, -2]';
    obstacle23.radius = 1;
    obstacle23.is_x_wall = false;
    obstacle23.wall_pos = 0;
    obstacle23.a = 0;
    obstacle23.b = 0;
    obstacle23.theta = 0;

    % stock4 (l'ultimo stock)
    obstacle24.type = "circle";
    obstacle24.center = [0, -4]';
    obstacle24.radius = 1;
    obstacle24.is_x_wall = false;
    obstacle24.wall_pos = 0;
    obstacle24.a = 0;
    obstacle24.b = 0;
    obstacle24.theta = 0;

    obstacles = {obstacle1, obstacle2, obstacle3, obstacle4, obstacle5, obstacle6, obstacle7,...
        obstacle8, obstacle9, obstacle10, obstacle11, obstacle12, obstacle13, obstacle14,...
        obstacle15, obstacle16, obstacle17, obstacle18, obstacle19, obstacle20, obstacle21,...
        obstacle22, obstacle23, obstacle24};
        otherwise
            x0 = [0 0 -pi/2]';
            obstacles = {};
    end
end

