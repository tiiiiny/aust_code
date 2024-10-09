clc
clear

% 参数设置
c1 = 1.49445;
c2 = 1.49445;
w = 1;

maxgen = 500;
sizepop = 500;
nVar = 6; % ！！变量个数
Vmax = 1;
Vmin = -1;
popmax = [5, 5, 5, 5, 5, 5]; % ！！每个变量最小值
popmin = [-5, -5, -5, -5, -5, -5]; % ！！每个变量最大值


% 生成初始种群
for i = 1 : sizepop
    pop(i, :) = (popmax - popmin) .* rands(1, nVar) + popmin;
    V(i, :) = (Vmax - Vmin) * rands(1, nVar) + Vmin;
    fitness(i) = fun(pop(i, :));
end

% 寻找全局最优和个体最优
[bestfitness, bestindex] = max(fitness);
gbest = pop(bestindex, :);
pbest = pop;
fitnesspbest = fitness;
fitnessgbest = bestfitness;

% 进化过程
for i = 1 : maxgen
    for j = 1 : sizepop
        % 更新速度
        w = 0.98 .^ i * w;
        V(j, :) = w .* V(j, :) + c1 * rand * (pbest(j, :) - pop(j, :)) + c2 * rand * (gbest - pop(j, :));
        V(j, find(V(j, :) > Vmax)) = Vmax;
        V(j, find(V(j, :) < Vmin)) = Vmin;
        
        % 更新位置
        pop(j, :) = pop(j, :) + V(j, :);
        pop(j, find(pop(j, :) > popmax)) = popmax(find(pop(j, :) > popmax));
        pop(j, find(pop(j, :) < popmin)) = popmin(find(pop(j, :) < popmin));
        
        fitness(j) = fun(pop(j, :)); 
   
    end
    
    % 更新个体最优和全局最优
    for j = 1 : sizepop
        if fitness(j) < fitnesspbest(j)
            pbest(j, :) = pop(j, :);
            fitnesspbest(j) = fitness(j);
        end

        if fitness(j) < fitnessgbest
            gbest = pop(j, :);
            fitnessgbest = fitness(j);
        end
    end 
    yy(i) = fitnessgbest;    
end

% 结果呈现
plot(yy)
title('最优个体适应度', 'fontsize', 12);
xlabel('进化代数', 'fontsize', 12);
ylabel('适应度', 'fontsize', 12);

disp('函数值                   变量');
disp([fitnessgbest, gbest]);

