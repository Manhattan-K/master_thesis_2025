function [lb, ub] = inputBounds(v_max, w_max, sys, N)

    m = sys.m;
    lb = repmat([0; -w_max], m*N);
    ub = repmat([v_max; w_max], m*N);

end

