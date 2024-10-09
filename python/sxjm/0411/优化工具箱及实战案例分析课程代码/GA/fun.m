function y = fun(x)

load('myANN.mat')
y = sim(net, x');

% y = x(1) ^ 2 + x(2) ^ 2 + x(3) ^ 2;
% 
% if x(1) + x(2) + x(3)> 3
%     y = y;
% else
%     y = y + 100000;
% end


end
    
