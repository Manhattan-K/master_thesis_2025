function [x0, goal, obstacles] = setupEnvironment(setupString)
    switch setupString
%----------------------------------------------------------------------------------------------------------------%

        case "no_obs"

            x0 = [4; 2; -pi];
            goal.single = [0; 0; 0];
            goal.move = false;
            obstacles = {};
            
%----------------------------------------------------------------------------------------------------------------%

        case "one_obs"

            x0 = [3; 4; -pi];
            goal.single = [0; 0; 0];
            goal.move = false;

            obstacle1.type = "circle";
            obstacle1.center = [1.75, 2.25]';
            obstacle1.radius = 0.5;
            obstacles = {obstacle1};
            
%----------------------------------------------------------------------------------------------------------------%

        case "two_obs"

            x0 = [3; 4; -pi];
            goal.single = [0; 0; 0];
            goal.move = false;

            obstacle1.type = "circle";
            obstacle1.center = [1, 4.5]';
            obstacle1.radius = 1;
            
            obstacle2.type = "circle";
            obstacle2.center = [1.75, 2.25]';
            obstacle2.radius = 0.5;
            
            obstacles = {obstacle1,obstacle2};
            
%----------------------------------------------------------------------------------------------------------------%

        case "three_obs"

            x0 = [3; 4; -pi];
            goal.single = [0; 0; 0];
            goal.move = false;

            obstacle1.type = "circle";
            obstacle1.center = [1, 4.5]';
            obstacle1.radius = 1;

            obstacle2.type = "circle";
            obstacle2.center = [1.75, 2.25]';
            obstacle2.radius = 0.5;

            obstacle3.type = "circle";
            obstacle3.center = [0, 1.5]';
            obstacle3.radius = 0.5;

            obstacles = {obstacle1,obstacle2,obstacle3};

%----------------------------------------------------------------------------------------------------------------%

        case "pathological"

            x0 = [3; 3; -3*pi/4];
            goal.single = [0; 0; 0];
            goal.move = false;

            obstacle1.type = "circle";
            obstacle1.center = [1.5, 1.5]';
            obstacle1.radius = 0.5;
            obstacles = {obstacle1};

%----------------------------------------------------------------------------------------------------------------%

        case "six_obs"

            x0 = [15; 1.8; -pi];
            goal.single = [0; 0; 0];
            goal.move = false;

            obstacle1.type = "circle";
            obstacle1.center = [13, 2]';
            obstacle1.radius = 0.8;
            
            obstacle2.type = "circle";
            obstacle2.center = [10, -1]';
            obstacle2.radius = 1.5;
            
            obstacle3.type = "circle";
            obstacle3.center = [8, 3]';
            obstacle3.radius = 2;
            
            obstacle4.type = "circle";
            obstacle4.center = [5.5, 0]';
            obstacle4.radius = 0.5;
            
            obstacle5.type = "circle";
            obstacle5.center = [3, 1.5]';
            obstacle5.radius = 1;
            
            obstacle6.type = "circle";
            obstacle6.center = [1, -0.5]';
            obstacle6.radius = 0.5;
            
            obstacles = {obstacle1, obstacle2, obstacle3, obstacle4, obstacle5, obstacle6};

%----------------------------------------------------------------------------------------------------------------%

        case "valzer"

            x0 = [21; 13; -3*pi/4];
            goal.single = [0; 0; 0];
            goal.move = false;

                %corridor circle 1st wall
            obs1.type = "wall";
            obs1.center = [20.25, 9.25]';
            obs1.length = 5;
            obs1.width = 0.1;
            obs1.theta = pi/3;
            obs1.radius = obs1.length/2 + 0.1;
            obs1.vertices = repmat([obs1.center(1); obs1.center(2)], [1 4]) + ...
                        Rmat(obs1.theta)*([-1, 1, 1, -1; -1, -1, 1, 1].*...
                        repmat([obs1.length/2; obs1.width/2], [1 4]));

            obs2.type = "wall";
            obs2.center = [16.5, 7]';
            obs2.length = 5;
            obs2.width = 0.1;
            obs2.theta = 0;
            obs2.radius = obs2.length/2 + 0.1;
            obs2.vertices = repmat([obs2.center(1); obs2.center(2)], [1 4]) + ...
                        Rmat(obs2.theta)*([-1, 1, 1, -1; -1, -1, 1, 1].*...
                        repmat([obs2.length/2; obs2.width/2], [1 4]));
            

                %corridor circle 2nd wall
            obs3.type = "wall";
            obs3.center = [18.25, 11.25]';
            obs3.length = 5;
            obs3.width = 0.1;
            obs3.theta = pi/3;
            obs3.radius = obs3.length/2 + 0.1;
            obs3.vertices = repmat([obs3.center(1); obs3.center(2)], [1 4]) + ...
                        Rmat(obs3.theta)*([-1, 1, 1, -1; -1, -1, 1, 1].*...
                        repmat([obs3.length/2; obs3.width/2], [1 4]));

            obs4.type = "wall";
            obs4.center = [14.5, 9]';
            obs4.length = 5;
            obs4.width = 0.1;
            obs4.theta = 0;
            obs4.radius = obs4.length/2 + 0.1;
            obs4.vertices = repmat([obs4.center(1); obs4.center(2)], [1 4]) + ...
                        Rmat(obs4.theta)*([-1, 1, 1, -1; -1, -1, 1, 1].*...
                        repmat([obs4.length/2; obs4.width/2], [1 4]));

                %Machinery1
            obstacle18.type = "circle";
            obstacle18.center = [10, 8]';
            obstacle18.radius = 2.25;
            %Machinery2
            obstacle19.type = "circle";
            obstacle19.center = [10, 2]';
            obstacle19.radius = 2;
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
            %stock4
            obstacle24.type = "circle";
            obstacle24.center = [0, -4]';
            obstacle24.radius = 1;
            obstacles = {obs1, obs2, obs3, obs4,...
                obstacle18, obstacle19, obstacle21,...
                obstacle22, obstacle23, obstacle24};
        
%----------------------------------------------------------------------------------------------------------------%
%                                       EDGE CASES

        case "lab"
            x0 = [-2; -1; pi/2];
            goal.single = [2.125; 1.5; 0];
            goal.move = false;

            obs1.type = "wall";
            obs1.center = [0.1875, -2.34]';
            obs1.length = 5.705;
            obs1.width = 0.1;
            obs1.theta = 0;
            obs1.radius = obs1.length/2 + 0.1;
            obs1.vertices = repmat([obs1.center(1); obs1.center(2)], [1 4]) + ...
                        Rmat(obs1.theta)*([-1, 1, 1, -1; -1, -1, 1, 1].*...
                        repmat([obs1.length/2; obs1.width/2], [1 4]));

            obs2.type = "wall";
            obs2.center = [0.1875, 2.25]';
            obs2.length = 5.705;
            obs2.width = 0.1;
            obs2.theta = 0;
            obs2.radius = obs2.length/2 + 0.1;
            obs2.vertices = repmat([obs2.center(1); obs2.center(2)], [1 4]) + ...
                        Rmat(obs2.theta)*([-1, 1, 1, -1; -1, -1, 1, 1].*...
                        repmat([obs2.length/2; obs2.width/2], [1 4]));

            obs3.type = "wall";
            obs3.center = [3.09, -0.045]';
            obs3.length = 4.49;
            obs3.width = 0.1;
            obs3.theta = pi/2;
            obs3.radius = obs3.length/2 + 0.1;
            obs3.vertices = repmat([obs3.center(1); obs3.center(2)], [1 4]) + ...
                        Rmat(obs3.theta)*([-1, 1, 1, -1; -1, -1, 1, 1].*...
                        repmat([obs3.length/2; obs3.width/2], [1 4]));

            obs4.type = "wall";
            obs4.center = [-2.6825, -0.045]';
            obs4.length = 4.49;
            obs4.width = 0.035;
            obs4.theta = pi/2;
            obs4.radius = obs4.length/2 + 0.1;
            obs4.vertices = repmat([obs4.center(1); obs4.center(2)], [1 4]) + ...
                        Rmat(obs4.theta)*([-1, 1, 1, -1; -1, -1, 1, 1].*...
                        repmat([obs4.length/2; obs4.width/2], [1 4]));

            obs5.type = "wall";
            obs5.center = [2.6925, 0.075]';
            obs5.length = 0.695;
            obs5.width = 0.15;
            obs5.theta = 0;
            obs5.radius = obs5.length/2 + 0.15;
            obs5.vertices = repmat([obs5.center(1); obs5.center(2)], [1 4]) + ...
                        Rmat(obs5.theta)*([-1, 1, 1, -1; -1, -1, 1, 1].*...
                        repmat([obs5.length/2; obs5.width/2], [1 4]));

            obs6.type = "wall";
            obs6.center = [0.075, 0.3475]';
            obs6.length = 0.695;
            obs6.width = 0.15;
            obs6.theta = pi/2;
            obs6.radius = obs6.length/2 + 0.15;
            obs6.vertices = repmat([obs6.center(1); obs6.center(2)], [1 4]) + ...
                        Rmat(obs6.theta)*([-1, 1, 1, -1; -1, -1, 1, 1].*...
                        repmat([obs6.length/2; obs6.width/2], [1 4]));

            obs7.type = "wall";
            obs7.center = [0, 1.37]';
            obs7.length = 0.695;
            obs7.width = 0.15;
            obs7.theta = 0;
            obs7.radius = obs7.length/2 + 0.15;
            obs7.vertices = repmat([obs7.center(1); obs7.center(2)], [1 4]) + ...
                        Rmat(obs7.theta)*([-1, 1, 1, -1; -1, -1, 1, 1].*...
                        repmat([obs7.length/2; obs7.width/2], [1 4]));

            obs8.type = "wall";
            obs8.center = [-1.3825, -0.84]';
            obs8.length = 2.9;
            obs8.width = 0.035;
            obs8.theta = pi/2;
            obs8.radius = obs8.length/2 + 0.1;
            obs8.vertices = repmat([obs8.center(1); obs8.center(2)], [1 4]) + ...
                        Rmat(obs8.theta)*([-1, 1, 1, -1; -1, -1, 1, 1].*...
                        repmat([obs8.length/2; obs8.width/2], [1 4]));

            obs9.type = "wall";
            obs9.center = [1.4575, 0.75]';
            obs9.length = 2.9;
            obs9.width = 0.035;
            obs9.theta = pi/2;
            obs9.radius = obs9.length/2 + 0.1;
            obs9.vertices = repmat([obs9.center(1); obs9.center(2)], [1 4]) + ...
                        Rmat(obs9.theta)*([-1, 1, 1, -1; -1, -1, 1, 1].*...
                        repmat([obs9.length/2; obs9.width/2], [1 4]));

            obs10.type = "wall";
            obs10.center = [0.855, -0.7175]';
            obs10.length = 2.9;
            obs10.width = 0.035;
            obs10.theta = 0;
            obs10.radius = obs10.length/2 + 0.1;
            obs10.vertices = repmat([obs10.center(1); obs10.center(2)], [1 4]) + ...
                        Rmat(obs10.theta)*([-1, 1, 1, -1; -1, -1, 1, 1].*...
                        repmat([obs10.length/2; obs10.width/2], [1 4]));


                % All obstacles
            % obstacles = {obs1, obs2, obs3, obs4, obs5, obs6, obs7, obs8, obs9, obs10};
                % Just the walls
            obstacles = {obs1, obs2, obs3, obs4,obs6, obs7, obs8, obs9, obs10};

%----------------------------------------------------------------------------------------------------------------%

        case "ec_direct_obs"
            x0 = [0; 5; -pi/2];
            goal.single = [0; 0; 0];
            goal.move = false;

            obs.type = "circle";
            obs.center = [0, 2.5]';
            obs.radius = 0.75;

            obstacles = {obs};

%----------------------------------------------------------------------------------------------------------------%


        case "ec_direct_wall"
            x0 = [0; 5; -pi/2];
            goal.single = [0; 0; 0];
            goal.move = false;

            obs.type = "wall";
            obs.center = [0, 2.5]';
            obs.length = 1.5;
            obs.width = 0.1;
            obs.theta = 0;
            obs.radius = norm([obs.length; obs.width]) / 2;

            obs.vertices = repmat([obs.center(1); obs.center(2)], [1 4]) + ...
                        Rmat(obs.theta)*([-1, 1, 1, -1; -1, -1, 1, 1].*...
                        repmat([obs.length/2; obs.width/2], [1 4]));

            obstacles = {obs};

%----------------------------------------------------------------------------------------------------------------%

        case "ec_elbow"
            x0 = [4.25; 3.75; -pi/2];
            goal.single = [0; 0; 0];
            goal.move = false;

            obs1.type = "wall";
            obs1.center = [2, -0.75]';
            obs1.length = 6;
            obs1.width = 0.1;
            obs1.theta = 0;
            obs1.radius = obs1.length/2 + 0.1;
            obs1.vertices = repmat([obs1.center(1); obs1.center(2)], [1 4]) + ...
                        Rmat(obs1.theta)*([-1, 1, 1, -1; -1, -1, 1, 1].*...
                        repmat([obs1.length/2; obs1.width/2], [1 4]));

            obs2.type = "wall";
            obs2.center = [5, 2.5]';
            obs2.length = 6.5;
            obs2.width = 0.1;
            obs2.theta = pi/2;
            obs2.radius = obs2.length/2 + 0.1;
            obs2.vertices = repmat([obs2.center(1); obs2.center(2)], [1 4]) + ...
                        Rmat(obs2.theta)*([-1, 1, 1, -1; -1, -1, 1, 1].*...
                        repmat([obs2.length/2; obs2.width/2], [1 4]));

            obs3.type = "wall";
            obs3.center = [4.25, 5.75]';
            obs3.length = 1.5;
            obs3.width = 0.1;
            obs3.theta = 0;
            obs3.radius = obs3.length/2 + 0.1;
            obs3.vertices = repmat([obs3.center(1); obs3.center(2)], [1 4]) + ...
                        Rmat(obs3.theta)*([-1, 1, 1, -1; -1, -1, 1, 1].*...
                        repmat([obs3.length/2; obs3.width/2], [1 4]));

            obs4.type = "wall";
            obs4.center = [3.5, 3.25]';
            obs4.length = 5;
            obs4.width = 0.1;
            obs4.theta = pi/2;
            obs4.radius = obs4.length/2 + 0.1;
            obs4.vertices = repmat([obs4.center(1); obs4.center(2)], [1 4]) + ...
                        Rmat(obs4.theta)*([-1, 1, 1, -1; -1, -1, 1, 1].*...
                        repmat([obs4.length/2; obs4.width/2], [1 4]));

            obs5.type = "wall";
            obs5.center = [1.25, 0.75]';
            obs5.length = 4.5;
            obs5.width = 0.1;
            obs5.theta = 0;
            obs5.radius = obs5.length/2 + 0.1;
            obs5.vertices = repmat([obs5.center(1); obs5.center(2)], [1 4]) + ...
                        Rmat(obs5.theta)*([-1, 1, 1, -1; -1, -1, 1, 1].*...
                        repmat([obs5.length/2; obs5.width/2], [1 4]));

            obstacles = {obs1, obs2, obs3, obs4, obs5};

%----------------------------------------------------------------------------------------------------------------%

        case "ec_goal_boxed" 
            x0 = [0; 1.5; -pi/2];
            goal.single = [0; 0; 0];
            goal.move = false;

            obs1.type = "wall";
            obs1.center = [0, 0.5]';
            obs1.length = 2.1;
            obs1.width = 0.1;
            obs1.theta = 0;
            obs1.radius = obs1.length/2 + 0.1;
            obs1.vertices = repmat([obs1.center(1); obs1.center(2)], [1 4]) + ...
                        Rmat(obs1.theta)*([-1, 1, 1, -1; -1, -1, 1, 1].*...
                        repmat([obs1.length/2; obs1.width/2], [1 4]));

            obs2.type = "wall";
            obs2.center = [-1, 0]';
            obs2.length = 0.9;
            obs2.width = 0.1;
            obs2.theta = pi/2;
            obs2.radius = obs2.length/2 + 0.1;
            obs2.vertices = repmat([obs2.center(1); obs2.center(2)], [1 4]) + ...
                        Rmat(obs2.theta)*([-1, 1, 1, -1; -1, -1, 1, 1].*...
                        repmat([obs2.length/2; obs2.width/2], [1 4]));

            obs3.type = "wall";
            obs3.center = [1, 0]';
            obs3.length = 0.9;
            obs3.width = 0.1;
            obs3.theta = pi/2;
            obs3.radius = obs3.length/2 + 0.1;
            obs3.vertices = repmat([obs3.center(1); obs3.center(2)], [1 4]) + ...
                        Rmat(obs3.theta)*([-1, 1, 1, -1; -1, -1, 1, 1].*...
                        repmat([obs3.length/2; obs3.width/2], [1 4]));

            obstacles = {obs1, obs2, obs3};

%----------------------------------------------------------------------------------------------------------------%

        case "ec_block_left" 
            x0 = [0; 1.5; -pi/2];
            goal.single = [0; 0; 0];
            goal.move = false;

            obs1.type = "wall";
            obs1.center = [0, 0.5]';
            obs1.length = 2.1;
            obs1.width = 0.1;
            obs1.theta = 0;
            obs1.radius = obs1.length/2 + 0.1;
            obs1.vertices = repmat([obs1.center(1); obs1.center(2)], [1 4]) + ...
                        Rmat(obs1.theta)*([-1, 1, 1, -1; -1, -1, 1, 1].*...
                        repmat([obs1.length/2; obs1.width/2], [1 4]));

            obs2.type = "wall";
            obs2.center = [-1, 0]';
            obs2.length = 0.9;
            obs2.width = 0.1;
            obs2.theta = pi/2;
            obs2.radius = obs2.length/2 + 0.1;
            obs2.vertices = repmat([obs2.center(1); obs2.center(2)], [1 4]) + ...
                        Rmat(obs2.theta)*([-1, 1, 1, -1; -1, -1, 1, 1].*...
                        repmat([obs2.length/2; obs2.width/2], [1 4]));

            obs3.type = "wall";
            obs3.center = [1, 0]';
            obs3.length = 0.9;
            obs3.width = 0.1;
            obs3.theta = pi/2;
            obs3.radius = obs3.length/2 + 0.1;
            obs3.vertices = repmat([obs3.center(1); obs3.center(2)], [1 4]) + ...
                        Rmat(obs3.theta)*([-1, 1, 1, -1; -1, -1, 1, 1].*...
                        repmat([obs3.length/2; obs3.width/2], [1 4]));

            obs4.type = "wall";
            obs4.center = [0.75, 1]';
            obs4.length = 0.9;
            obs4.width = 0.1;
            obs4.theta = pi/2;
            obs4.radius = obs4.length/2 + 0.1;
            obs4.vertices = repmat([obs4.center(1); obs4.center(2)], [1 4]) + ...
                        Rmat(obs4.theta)*([-1, 1, 1, -1; -1, -1, 1, 1].*...
                        repmat([obs4.length/2; obs4.width/2], [1 4]));

            obstacles = {obs1, obs2, obs3, obs4};

%----------------------------------------------------------------------------------------------------------------%

        case "ec_block_right" 
            x0 = [0; 1.5; -pi/2];
            goal.single = [0; 0; 0];
            goal.move = false;

            obs1.type = "wall";
            obs1.center = [0, 0.5]';
            obs1.length = 2.1;
            obs1.width = 0.1;
            obs1.theta = 0;
            obs1.radius = obs1.length/2 + 0.1;
            obs1.vertices = repmat([obs1.center(1); obs1.center(2)], [1 4]) + ...
                        Rmat(obs1.theta)*([-1, 1, 1, -1; -1, -1, 1, 1].*...
                        repmat([obs1.length/2; obs1.width/2], [1 4]));

            obs2.type = "wall";
            obs2.center = [-1, 0]';
            obs2.length = 0.9;
            obs2.width = 0.1;
            obs2.theta = pi/2;
            obs2.radius = obs2.length/2 + 0.1;
            obs2.vertices = repmat([obs2.center(1); obs2.center(2)], [1 4]) + ...
                        Rmat(obs2.theta)*([-1, 1, 1, -1; -1, -1, 1, 1].*...
                        repmat([obs2.length/2; obs2.width/2], [1 4]));

            obs3.type = "wall";
            obs3.center = [1, 0]';
            obs3.length = 0.9;
            obs3.width = 0.1;
            obs3.theta = pi/2;
            obs3.radius = obs3.length/2 + 0.1;
            obs3.vertices = repmat([obs3.center(1); obs3.center(2)], [1 4]) + ...
                        Rmat(obs3.theta)*([-1, 1, 1, -1; -1, -1, 1, 1].*...
                        repmat([obs3.length/2; obs3.width/2], [1 4]));

            obs4.type = "wall";
            obs4.center = [-0.75, 1]';
            obs4.length = 0.9;
            obs4.width = 0.1;
            obs4.theta = pi/2;
            obs4.radius = obs4.length/2 + 0.1;
            obs4.vertices = repmat([obs4.center(1); obs4.center(2)], [1 4]) + ...
                        Rmat(obs4.theta)*([-1, 1, 1, -1; -1, -1, 1, 1].*...
                        repmat([obs4.length/2; obs4.width/2], [1 4]));

            obstacles = {obs1, obs2, obs3, obs4};

%----------------------------------------------------------------------------------------------------------------%

        case "ec_navigation" 
            x0 = [0; 2.5; -pi/2];
            goal.single = [0; 0; 0];
            goal.move = false;

            obs1.type = "wall";
            obs1.center = [0.5, 1]';
            obs1.length = 3;
            obs1.width = 0.1;
            obs1.theta = 0;
            obs1.radius = obs1.length/2 + 0.1;
            obs1.vertices = repmat([obs1.center(1); obs1.center(2)], [1 4]) + ...
                        Rmat(obs1.theta)*([-1, 1, 1, -1; -1, -1, 1, 1].*...
                        repmat([obs1.length/2; obs1.width/2], [1 4]));
            
            obs2.type = "wall";
            obs2.center = [2, 2]';
            obs2.length = 2;
            obs2.width = 0.1;
            obs2.theta = pi/2;
            obs2.radius = obs2.length/2 + 0.1;
            obs2.vertices = repmat([obs2.center(1); obs2.center(2)], [1 4]) + ...
                        Rmat(obs2.theta)*([-1, 1, 1, -1; -1, -1, 1, 1].*...
                        repmat([obs2.length/2; obs2.width/2], [1 4]));

            obs3.type = "wall";
            obs3.center = [2, 4]';
            obs3.length = 3;
            obs3.width = 0.1;
            obs3.theta = 0;
            obs3.radius = obs3.length/2 + 0.1;
            obs3.vertices = repmat([obs3.center(1); obs3.center(2)], [1 4]) + ...
                        Rmat(obs3.theta)*([-1, 1, 1, -1; -1, -1, 1, 1].*...
                        repmat([obs3.length/2; obs3.width/2], [1 4]));

            obs4.type = "wall";
            obs4.center = [3.5, 1.5]';
            obs4.length = 5;
            obs4.width = 0.1;
            obs4.theta = pi/2;
            obs4.radius = obs4.length/2 + 0.1;
            obs4.vertices = repmat([obs4.center(1); obs4.center(2)], [1 4]) + ...
                        Rmat(obs4.theta)*([-1, 1, 1, -1; -1, -1, 1, 1].*...
                        repmat([obs4.length/2; obs4.width/2], [1 4]));

            obstacles = {obs1, obs2, obs3, obs4};

%----------------------------------------------------------------------------------------------------------------%
%                               TESTS
        case "test_no_obs"
            x0 = [3; 3; -3*pi/4];
            goal.single = [0; 0; 0];
            goal.move = false;
            obstacles = {};

%----------------------------------------------------------------------------------------------------------------%

        case "test_two_obs"

            x0 = [3; 4; -pi];
            goal.single = [0; 0; 0];
            goal.move = false;

            obstacle1.type = "circle";
            obstacle1.center = [1, 4.5]';
            obstacle1.radius = 1;
            
            obstacle2.type = "circle";
            obstacle2.center = [1.75, 2.25]';
            obstacle2.radius = 0.5;
            
            obstacles = {obstacle1,obstacle2};

%----------------------------------------------------------------------------------------------------------------%

        case "test_direct"

            x0 = [2.5; 2.5; -3*pi/4];
            goal.single = [0; 0; 0];
            goal.move = false;

            obs1.type = "wall";
            obs1.center = [1, 1]';
            obs1.length = 1.5;
            obs1.width = 0.1;
            obs1.theta = -pi/4;
            obs1.radius = norm([obs1.length; obs1.width]) / 2;

            obs1.vertices = repmat([obs1.center(1); obs1.center(2)], [1 4]) + ...
                        Rmat(obs1.theta)*([-1, 1, 1, -1; -1, -1, 1, 1].*...
                        repmat([obs1.length/2; obs1.width/2], [1 4]));

            obstacles = {obs1};

%----------------------------------------------------------------------------------------------------------------%

        case "test_boxed"
            x0 = [0; 1.5; -pi/2];
            goal.single = [0; 0; 0];
            goal.move = false;

            obs1.type = "wall";
            obs1.center = [0, 0.5]';
            obs1.length = 2.1;
            obs1.width = 0.1;
            obs1.theta = 0;
            obs1.radius = obs1.length/2 + 0.1;
            obs1.vertices = repmat([obs1.center(1); obs1.center(2)], [1 4]) + ...
                        Rmat(obs1.theta)*([-1, 1, 1, -1; -1, -1, 1, 1].*...
                        repmat([obs1.length/2; obs1.width/2], [1 4]));

            obs2.type = "wall";
            obs2.center = [-1, 0]';
            obs2.length = 0.9;
            obs2.width = 0.1;
            obs2.theta = pi/2;
            obs2.radius = obs2.length/2 + 0.1;
            obs2.vertices = repmat([obs2.center(1); obs2.center(2)], [1 4]) + ...
                        Rmat(obs2.theta)*([-1, 1, 1, -1; -1, -1, 1, 1].*...
                        repmat([obs2.length/2; obs2.width/2], [1 4]));

            obs3.type = "wall";
            obs3.center = [1, 0]';
            obs3.length = 0.9;
            obs3.width = 0.1;
            obs3.theta = pi/2;
            obs3.radius = obs3.length/2 + 0.1;
            obs3.vertices = repmat([obs3.center(1); obs3.center(2)], [1 4]) + ...
                        Rmat(obs3.theta)*([-1, 1, 1, -1; -1, -1, 1, 1].*...
                        repmat([obs3.length/2; obs3.width/2], [1 4]));

            obstacles = {obs1, obs2, obs3};

%----------------------------------------------------------------------------------------------------------------%

        case "moving"
            x0 = [7; 0; -pi];
            goal.single = [0; 0; 0];
            goal.move = true;

            obs.type = "move";
            obs.center = [1.5, 1]';
            obs.radius = 0.15;
            obs.a = [1.5; 1];
            obs.b = [1.5; -1];
            obs.theta = -pi/2;
            obs.vel = 0.1/20;

            obs2.type = "move";
            obs2.center = [2.5, -1]';
            obs2.radius = 0.15;
            obs2.a = [2.5; 1];
            obs2.b = [2.5; -1];
            obs2.theta = pi/2;
            obs2.vel = 0.1/20;

            obs3.type = "move";
            obs3.center = [3.5, 1]';
            obs3.radius = 0.15;
            obs3.a = [3.5; 1];
            obs3.b = [3.5; -1];
            obs3.theta = -pi/2;
            obs3.vel = 0.1/20;

            obstacles = {obs, obs2, obs3};

        otherwise
            x0 = [0 0 -pi/2]';
            goal.single = [0; 0; 0];
            goal.move = false;
            obstacles = {};
    end
end

