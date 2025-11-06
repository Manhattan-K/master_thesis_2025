function [q, d] = getqiFromShape(shape, x0, data, noise)
% GETQIFROMSHAPE is a function that tries to construct the distance and
% position of the line tangent to the shape and perpendicular to x0 (robot pos)
% shape is a structure holding information on the particular shape
% if shape.type = "circle", shape.center, shape.radius must be present
% if " = "ellipse", shape.a, shape.b, shape.center, shape.theta
% if " = "general_poly", shape.vertices as 2-by-l matrix (l number of vertices)
% if " = "wall" (thing which is perpendicular to axes), shape.is_x_wall,
% shape.wall_pos

switch shape.type
    case "circle"
        
        B = 2*(data.Dx*data.c+data.Dy*data.s);
        C = (data.Dx)^2 + (data.Dy)^2 - (shape.radius)^2;
        DELTA = B^2 - 4*C;
        
        if DELTA < 0
            d = Inf;
            q = [NaN; NaN];
        else
            d = abs((-B + sqrt(DELTA)) / 2);

            if noise.sensing.on == true
                n = getDistanceNoise(d, noise.sensing.sigma);
                d = d + n;
            end

            q = x0(1:2) + [data.c; data.s] .* d;
        end
        return;
    
    case "wall"
        
        d = Inf;
        q = [NaN; NaN];

        for i = 1:size(shape.vertices, 2)
            
            num = shape.A(:,i)*x0(1) + shape.B(:,i)*x0(2) + shape.C(:,i);
            den = shape.A(:,i)*data.c + shape.B(:,i)*data.s;
            t = - (num/den);
            
            if t >= 0
                
                inter = x0(1:2) + [data.c; data.s] .* t;
                if inter(1) >= shape.min_v(1,i) && inter(1) <= shape.max_v(1,i) && ...
                   inter(2) >= shape.min_v(2,i) && inter(2) <= shape.max_v(2,i)
                    
                    if t < d
                        d = abs(t);
                        q = inter;
                    end
                end
            end
        end

        if noise.sensing.on == true
            n = getDistanceNoise(d, noise.sensing.sigma);
            d = d + n;
            q = x0(1:2) + [data.c; data.s] .* d;
        end
        return;
        
    
    case "move"
        
        B = 2*(data.Dx*data.c+data.Dy*data.s);
        C = (data.Dx)^2 + (data.Dy)^2 - (shape.radius)^2;
        DELTA = B^2 - 4*C;
        
        if DELTA < 0
            d = Inf;
            q = [NaN; NaN];
        else
            d = abs((-B + sqrt(DELTA)) / 2);

            if noise.sensing.on == true
                n = getDistanceNoise(d, noise.sensing.sigma);
                d = d + n;
            end

            q = x0(1:2) + [data.c; data.s] .* d;
        end
        return;

end

