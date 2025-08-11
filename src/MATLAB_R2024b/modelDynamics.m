function [y, x_k1] = modelDynamics(x_k, u_k, Ts)
% MODELDYNAMIC receives as input the system model, the state at time k and
% the input at time k, and give in output the state at time k+1 and the
% output at time k.
% 
% Unicycle model discrete step
% x_k = [x; y; theta], u_k = [v; omega]

x_k1 = zeros(3,1);
x_k1(1) = x_k(1) + Ts * u_k(1) * cos(x_k(3));
x_k1(2) = x_k(2) + Ts * u_k(1) * sin(x_k(3));
x_k1(3) = x_k(3) + Ts * u_k(2);

y = x_k1;
end

