function y = obj_fun(x)

y(:, 1) = -10.*(exp(-0.2.*sqrt(x(:,1).^2+x(:,2).^2)) + exp(-0.2.*sqrt(x(:,2).^2+x(:,3).^2)));
y(:, 2) = sum(abs(x).^0.8 + 5.*sin(x.^3),2);

end