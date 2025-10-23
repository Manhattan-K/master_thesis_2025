function [q, d] = closestPoint(A, B, x)
    AB = B - A;
    AP = x - A;
    t = (AP' * AB) / (AB' * AB);
    %t = max(0, min(1, t));
    
    if t >= 0 && t <= 1
        q = A + t * AB;
        d = norm(x - q);
    elseif t < 0
        q = A;
        d = norm(x - q);
    else
        q = B;
        d = norm(x - q);
    end
end