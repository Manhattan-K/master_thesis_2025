function [x_pred] = stateEvolution(U, x0, sys, N)

    % Given the initial state, the prediction horizon N and the input
    % values, the function evaluate and create a stacked matrix of the next
    % N states of the system


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

