function [q, d] = closestPoint(A, B, x)
    AB = B - A;
    AP = x - A;
    t = (AP' * AB) / (AB' * AB);
    t = max(0, min(1, t));
    
    
    q = A + t * AB;
    d = norm(x - q);
end