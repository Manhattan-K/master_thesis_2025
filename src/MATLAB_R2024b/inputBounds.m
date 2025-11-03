function [lb, ub] = inputBounds(v_max, w_max, N)

    lb = repmat([0; -w_max], [N, 1]);
    ub = repmat([v_max; w_max], [N, 1]);

end