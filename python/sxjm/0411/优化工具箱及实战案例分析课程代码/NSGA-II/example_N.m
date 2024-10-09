clear
clc

% MultiObj.fun = @(x) [-10.*(exp(-0.2.*sqrt(x(:,1).^2+x(:,2).^2)) + exp(-0.2.*sqrt(x(:,2).^2+x(:,3).^2))), ...
%                      sum(abs(x).^0.8 + 5.*sin(x.^3),2)];

MultiObj.fun = @(x) obj_fun(x);

MultiObj.nVar = 3;
MultiObj.var_min = [-5, -5, -5];
MultiObj.var_max = [5, 5, 5];

params.Np = 200;
params.pc = 0.9;
params.pm = 0.5;
params.maxgen = 100;
params.ms = 0.05;

REP = NSGAII(params, MultiObj);