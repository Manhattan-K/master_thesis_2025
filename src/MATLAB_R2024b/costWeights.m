function [W_hat, R_hat] = costWeights(sys, W,R,Z,N)
    
    % COST_WEIGHTS is a function that given the N predictive horizon and the
    % cost weight matrices W,R,Z of an optimal control problem with respect state x and input U return as output
    % new cost matrices in order to have a optimization prolem only respect input U. 
    
    n = sys.n;

    W_kron = kron(eye(N-1), W);
    W_hat = [W_kron, zeros(n*(N-1), n);
             zeros(n,n*(N-1)), Z];

    R_hat = kron(eye(N), R);

end
