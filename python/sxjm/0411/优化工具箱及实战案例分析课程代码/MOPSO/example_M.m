clear
clc

% MultiObj.fun = @(x) [-10.*(exp(-0.2.*sqrt(x(:,1).^2+x(:,2).^2)) + exp(-0.2.*sqrt(x(:,2).^2+x(:,3).^2))), ...
%                              sum(abs(x).^0.8 + 5.*sin(x.^3),2)];

MultiObj.fun = @(x) obj_fun(x);

MultiObj.nVar = 3;
MultiObj.var_min = -5 .* ones(1, MultiObj.nVar);
MultiObj.var_max = 5 .* ones(1, MultiObj.nVar);

params.Np = 200;
params.Nr = 150;
params.maxgen = 100;
params.W = 0.4;
params.C1 = 2;
params.C2 = 2;
params.ngrid = 20;
params.maxvel = 5;
params.u_mut = 0.5;

REP = MOPSO(params, MultiObj);