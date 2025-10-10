function [x_k1] = modelDynamics(x_k, u_k, sys)

    x_k1 = zeros(sys.n,1);

    x_k1(1) = x_k(1) + sys.Ts * u_k(1) * cos(x_k(3));
    x_k1(2) = x_k(2) + sys.Ts * u_k(1) * sin(x_k(3));
    x_k1(3) = wrapToPi(x_k(3) + sys.Ts * u_k(2));
    
end

