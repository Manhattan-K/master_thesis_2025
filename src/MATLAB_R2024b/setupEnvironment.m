function [x0, obstacles] = setupEnvironment(setupString)
    switch setupString
        case "no_obs"
            % Setup 01: No obstacles and p(0) = (20, 20)
            x0 = [20; 10; -pi/2];
            obstacles = {};

%----------------------------------------------------------------------------------------------------------------%

        case "test"
            x0 = [0; 10; -pi/2];

            obs.type = "wall";
            obs.center = [0, 3]';
            obs.length = 3;
            obs.width = 0.5;
            obs.theta = 0;
            obs.radius = 4;

            obs.vertices = repmat([obs.center(1); obs.center(2)], [1 5]) + ...
                        Rmat(obs.theta)*([-0.5, 0.5, 1, 0, -1; -1,-1,0,1,0]);

            obstacles = {obs};
            
%----------------------------------------------------------------------------------------------------------------%

        case "one_obs"
            %Setup 02 one obstacles and p(0) = (10, 14)
            x0 = [10; 14; -pi/2];
            obstacle1.type = "circle";
            obstacle1.center = [5, 7]';
            obstacle1.radius = 3;
            obstacles = {obstacle1};
            
%----------------------------------------------------------------------------------------------------------------%

        case "two_obs"
            % Setup 03 LF one obstacles and p(0) = (10, 14)
            x0 = [10; 14; -pi/2];
            obstacle1.type = "circle";
            obstacle1.center = [3, 12]';
            obstacle1.radius = 3;
            
            obstacle2.type = "circle";
            obstacle2.center = [6, 5]';
            obstacle2.radius = 3;
            
            obstacles = {obstacle1,obstacle2};
            
%----------------------------------------------------------------------------------------------------------------%

        case "three_obs"
            % Setup 03 one obstacles and p(0) = (10, 14)
            x0 = [10; 14; -pi/2];
            obstacle1.type = "circle";
            obstacle1.center = [5, 11]';
            obstacle1.radius = 3;

            obstacle2.type = "circle";
            obstacle2.center = [7, 4]';
            obstacle2.radius = 3;

            obstacle3.type = "circle";
            obstacle3.center = [1, 3]';
            obstacle3.radius = 1;

            obstacles = {obstacle1,obstacle2,obstacle3};

%----------------------------------------------------------------------------------------------------------------%

        case "pathological"
            % Pathological cases
            x0 = [10; 10; -pi/2];
            obstacle1.type = "circle";
            obstacle1.center = [5, 5]';
            obstacle1.radius = 2;
            obstacles = {obstacle1};

%----------------------------------------------------------------------------------------------------------------%

        case "six_obs"
            % Complex Map, six obstacles
            x0 = [40; 5; -pi/2];
            obstacle1.type = "circle";
            obstacle1.center = [35, 4]';
            obstacle1.radius = 2;
            
            obstacle2.type = "circle";
            obstacle2.center = [30, -1]';
            obstacle2.radius = 3;
            
            obstacle3.type = "circle";
            obstacle3.center = [25, 5]';
            obstacle3.radius = 3;
            
            obstacle4.type = "circle";
            obstacle4.center = [18, 0]';
            obstacle4.radius = 1;
            
            obstacle5.type = "circle";
            obstacle5.center = [5, -1]';
            obstacle5.radius = 1;
            
            obstacle6.type = "circle";
            obstacle6.center = [10, 4]';
            obstacle6.radius = 3;
            
            obstacles = {obstacle1, obstacle2, obstacle3, obstacle4, obstacle5, obstacle6};

%----------------------------------------------------------------------------------------------------------------%

        case "valzer"
            % Complex Map-variable
            x0 = [39.5; 22; -pi/2];

            %corridor circle 1st wall
            obstacle1.type = "circle";
            obstacle1.center = [40, 20]';
            obstacle1.radius = 1;
            obstacle2.type = "circle";
            obstacle2.center = [39.5, 18.5]';
            obstacle2.radius = 1;
            obstacle3.type = "circle";
            obstacle3.center = [39,17]';
            obstacle3.radius = 1;
            obstacle4.type = "circle";
            obstacle4.center = [38.5,15.5]';
            obstacle4.radius = 1;
            obstacle5.type = "circle";
            obstacle5.center = [38, 14]';
            obstacle5.radius = 1;
            obstacle6.type = "circle";
            obstacle6.center = [37, 13]';
            obstacle6.radius = 1;
            obstacle7.type = "circle";
            obstacle7.center = [36, 12]';
            obstacle7.radius = 1;
            obstacle8.type = "circle";
            obstacle8.center = [34.5, 12]';
            obstacle8.radius = 1;
            obstacle9.type = "circle";
            obstacle9.center = [33, 12]';
            obstacle9.radius = 1;
            
            %corridor circle 2nd wall
            obstacle10.type = "circle";
            obstacle10.center = [38-1, 23]';
            obstacle10.radius = 1;
            obstacle11.type = "circle";
            obstacle11.center = [37.5-1, 21.5]';
            obstacle11.radius = 1;
            obstacle12.type = "circle";
            obstacle12.center = [37-1,20]';
            obstacle12.radius = 1;
            obstacle13.type = "circle";
            obstacle13.center = [36.5-1,18.5]';
            obstacle13.radius = 1;
            obstacle14.type = "circle";
            obstacle14.center = [36-1, 17]';
            obstacle14.radius = 1;
            obstacle15.type = "circle";
            obstacle15.center = [35-1, 16]';
            obstacle15.radius = 1;
            obstacle16.type = "circle";
            obstacle16.center = [33.5-1, 16]';
            obstacle16.radius = 1;
            obstacle17.type = "circle";
            obstacle17.center = [32-1, 16]';
            obstacle17.radius = 1;

            %Machinery1
            obstacle18.type = "circle";
            obstacle18.center = [25, 13]';
            obstacle18.radius = 4;
            %Machinery2
            obstacle19.type = "circle";
            obstacle19.center = [25, 2]';
            obstacle19.radius = 4;
            %person
            % obstacle20.type = "circle";
            % obstacle20.center = [12, 23]';
            % obstacle20.radius = 1;

            %stock 1
            obstacle21.type = "circle";
            obstacle21.center = [0, 2]';
            obstacle21.radius = 1;
            %stock2
            obstacle22.type = "circle";
            obstacle22.center = [0, 4]';
            obstacle22.radius = 1;
            %stock3
            obstacle23.type = "circle";
            obstacle23.center = [0, -2]';
            obstacle23.radius = 1;
            %stock3
            obstacle24.type = "circle";
            obstacle24.center = [0, -4]';
            obstacle24.radius = 1;
            obstacles = {obstacle1, obstacle2, obstacle3, obstacle4, obstacle5, obstacle6, obstacle7,...
                obstacle8, obstacle9,obstacle10, obstacle11, obstacle12, obstacle13, obstacle14,...
                obstacle15, obstacle16, obstacle17, obstacle18, obstacle19, obstacle21,...
                obstacle22, obstacle23, obstacle24};
        
%----------------------------------------------------------------------------------------------------------------%
%                                       EDGE CASES

        case "ec_direct_obs"
            x0 = [0; 10; -pi/2];

            obs.type = "circle";
            obs.center = [0, 5]';
            obs.radius = 1;

            obstacles = {obs};

%----------------------------------------------------------------------------------------------------------------%


        case "ec_direct_wall"
            x0 = [0; 10; -pi/2];

            obs.type = "wall";
            obs.center = [0, 0.5]';
            obs.length = 5;
            obs.width = 0.1;
            obs.theta = 0;
            obs.radius = norm([obs.length; obs.width]) / 2;

            obs.vertices = repmat([obs.center(1); obs.center(2)], [1 4]) + ...
                        Rmat(obs.theta)*([-1, 1, 1, -1; -1, -1, 1, 1].*...
                        repmat([obs.length/2; obs.width/2], [1 4]));

            obstacles = {obs};

%----------------------------------------------------------------------------------------------------------------%

        case "ec_elbow"
            x0 = [9.5; 10; -pi/2];

            obs1.type = "wall";
            obs1.center = [10, 0]';
            obs1.theta = 0;
            obs1.radius = 11;
            obs1.vertices = repmat([obs1.center(1); obs1.center(2)], [1 12]) + Rmat(obs1.theta)* ...
                            [-11,1.5,1.5,-1.5,-1.5,-11,-11,-1,-1,1,1,-11;...
                             -1.5,-1.5,11.5,11.5,1.5,1.5,1,1,11,11,-1,-1];

            obstacles = {obs1};

%----------------------------------------------------------------------------------------------------------------%

        case "ec_goal_boxed" 
            x0 = [0; 10; -pi/2];

            obs1.type = "wall";
            obs1.center = [0, 0]';
            obs1.theta = 0;
            obs1.radius = 1.5;
            obs1.vertices = repmat([obs1.center(1); obs1.center(2)], [1 8]) + ...
                        Rmat(obs1.theta)*([-1.25,-1,-1,1,1,1.25,1.25,-1.25;...
                                           -1,-1,1,1,-1,-1,1.25,1.25]);

            obstacles = {obs1};

%----------------------------------------------------------------------------------------------------------------%
%                               TESTS
        case "test_no_obs"
            x0 = [10; 10; -pi/2];
            obstacles = {};

%----------------------------------------------------------------------------------------------------------------%

        case "test_one_obs"
            x0 = [10; 10; -pi/2];
            obstacle1.type = "circle";
            obstacle1.center = [6, 5]';
            obstacle1.radius = 1;
            obstacles = {obstacle1};

%----------------------------------------------------------------------------------------------------------------%

        case "test_corridor"

            x0 = [9; 12; -pi/2];

            % obs1.type = "circle";
            % obs1.center = [1.75, 3]';
            % obs1.radius = 0.75;
            % obs2.type = "circle";
            % obs2.center = [3, 4]';
            % obs2.radius = 0.75;
            % obs3.type = "circle";
            % obs3.center = [3.5, 5]';
            % obs3.radius = 0.75;
            % obs4.type = "circle";
            % obs4.center = [4, 6]';
            % obs4.radius = 0.75;
            % 
            % 
            % obs5.type = "circle";
            % obs5.center = [5, 2]';
            % obs5.radius = 0.75;
            % obs6.type = "circle";
            % obs6.center = [5.5, 3]';
            % obs6.radius = 0.75;
            % obs7.type = "circle";
            % obs7.center = [6, 4]';
            % obs7.radius = 0.75;
            % obs8.type = "circle";
            % obs8.center = [6.5, 5]';
            % obs8.radius = 0.75;
            % obs9.type = "circle";
            % obs9.center = [7, 6]';
            % obs9.radius = 0.75;

            obstacle3.type = "circle";
            obstacle3.center = [9, 6]'; % [9, 8 - 2]'
            obstacle3.radius = 1;
            
            obstacle4.type = "circle";
            obstacle4.center = [8.5, 4.5]'; % [8.5, 6.5 - 2]'
            obstacle4.radius = 1;
            
            obstacle5.type = "circle";
            obstacle5.center = [8, 3]'; % [8, 5 - 2]'
            obstacle5.radius = 1;
            
            obstacle6.type = "circle";
            obstacle6.center = [7, 2]'; % [7, 4 - 2]'
            obstacle6.radius = 1;
            
            obstacle7.type = "circle";
            obstacle7.center = [6, 1]'; % [6, 3 - 2]'
            obstacle7.radius = 1;
                        
            %---------------------------------------------------------------------
            
            % corridor circle 2nd wall
            obstacle12.type = "circle";
            obstacle12.center = [6, 9]'; % [6, 11 - 2]'
            obstacle12.radius = 1;
            
            obstacle13.type = "circle";
            obstacle13.center = [5.5, 7.5]'; % [5.5, 9.5 - 2]'
            obstacle13.radius = 1;
            
            obstacle14.type = "circle";
            obstacle14.center = [5, 6]'; % [5, 8 - 2]'
            obstacle14.radius = 1;
            
            obstacle15.type = "circle";
            obstacle15.center = [4, 5]'; % [4, 7 - 2]'
            obstacle15.radius = 1;

            % obstacles = {obs1,obs2,obs3,obs4,obs5,obs6,obs7,obs8,obs9};
            obstacles = {obstacle3, obstacle4, obstacle5, obstacle6, obstacle7,...
                obstacle12, obstacle13, obstacle14,...
                obstacle15};

%----------------------------------------------------------------------------------------------------------------%

        case "test_direct"
            x0 = [10; 10; -pi/2];

            obs1.type = "wall";
            obs1.center = [1, 1]';
            obs1.length = 3;
            obs1.width = 0.1;
            obs1.theta = -pi/4;
            obs1.radius = norm([obs1.length; obs1.width]) / 2;

            obs1.vertices = repmat([obs1.center(1); obs1.center(2)], [1 4]) + ...
                        Rmat(obs1.theta)*([-1, 1, 1, -1; -1, -1, 1, 1].*...
                        repmat([obs1.length/2; obs1.width/2], [1 4]));

            obstacles = {obs1};

%----------------------------------------------------------------------------------------------------------------%

        otherwise
            x0 = [0 0 -pi/2]';
            obstacles = {};
    end
end

