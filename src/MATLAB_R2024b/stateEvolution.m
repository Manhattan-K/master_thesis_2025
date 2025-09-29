function [x_pred] = stateEvolution(U, x0, sys, N)

    % Given the initial state, the prediction horizon N and the input
    % values, the function evaluate and create a stacked matrix of the next
    % N states of the system

    % n = sys.n;
    % Ts = sys.Ts;
    % 
    % x_pred = zeros([n*N, 1]);
    % 
    % x_pred(1) = x0(1) + U(1) * cos(x0(3)) * Ts;
    % x_pred(2) = x0(2) + U(1) * sin(x0(3)) * Ts;
    % x_pred(3) = x0(3) + U(2) * Ts;
    % 
    % for i = 1 : ( N-1 )
    %     prev_i = (i-1)*3;
    %     curr_i = i*3;
    %     input_i = i*2;
    % 
    %     x_pred(curr_i + 1) = x_pred(prev_i + 1) + U(input_i + 1) * cos(x_pred(prev_i + 3)) * Ts;
    %     x_pred(curr_i + 2) = x_pred(prev_i + 2) + U(input_i + 1) * sin(x_pred(prev_i + 3)) * Ts;
    %     x_pred(curr_i + 3) = x_pred(prev_i + 3) + U(input_i + 2) * Ts;
    % end


    x_pred = zeros([sys.n*N, 1]);
    x_pred(1:3) = modelDynamics(x0, U(1:2), sys);

    for i = 1 : ( N-1 )
        prev_i = (i-1)*3;
        curr_i = i*3;
        input_i = i*2;

        x_pred((curr_i + 1) : (curr_i + 3), 1) = modelDynamics(x_pred((prev_i + 1) : (prev_i + 3)), ...
                                                            U((input_i + 1) : (input_i + 2)), sys);
    end

end

