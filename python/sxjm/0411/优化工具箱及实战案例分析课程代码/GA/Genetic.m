% clc
% clear

% 参数设置
maxgen = 10;
sizepop = 10;
pcross = 0.7;
pmutation = 0.05;
lenchrom = [1, 1, 1, 1, 1]; % ！！变量个数
bound = [0, 1; 0, 1; 0, 1; 0, 1; 0, 1];% ！！每个变量取值范围

individuals = struct('fitness', zeros(1, sizepop), 'chrom', []);
avgfitness = [];
bestfitness = [];
bestchrom = [];

% 初始化种群
for i = 1 : sizepop
    individuals.chrom(i,:) = Code(lenchrom, bound);
    x = individuals.chrom(i, :);
    individuals.fitness(i) = fun(x);
end

[bestfitness, bestindex] = min(individuals.fitness);
bestchrom = individuals.chrom(bestindex, :);
avgfitness = sum(individuals.fitness) / sizepop;

trace=[];
for i = 1 : maxgen
    % 选择操作
    individuals = Select(individuals, sizepop);
    avgfitness = sum(individuals.fitness) / sizepop;
    
    % 交叉操作
    individuals.chrom = Cross(pcross, lenchrom, individuals.chrom, sizepop, bound);
    % 变异操作
    individuals.chrom = Mutation(pmutation, lenchrom, individuals.chrom, sizepop, [i, maxgen], bound);

    for j = 1 : sizepop
        x = individuals.chrom(j, :);
        individuals.fitness(j) = fun(x);
    end
    
    [newbestfitness, newbestindex] = min(individuals.fitness);
    [worestfitness, worestindex] = max(individuals.fitness);
    if bestfitness > newbestfitness
        bestfitness = newbestfitness;
        bestchrom = individuals.chrom(newbestindex, :);
    end
    individuals.chrom(worestindex, :) = bestchrom;
    individuals.fitness(worestindex) = bestfitness;
    
    avgfitness=sum(individuals.fitness) / sizepop;
    
    trace = [trace; avgfitness, bestfitness];
end

% 结果呈现
figure
plot((1 : maxgen)', trace(:, 1), 'r-', (1: maxgen)', trace(:, 2), 'b--');
title(['函数值曲线  ' '终止代数＝' num2str(maxgen)], 'fontsize', 12);
xlabel('进化代数', 'fontsize', 12);
ylabel('函数值', 'fontsize', 12);
legend('各代平均值', '各代最佳值', 'fontsize', 12);
ylim([3, 8])
disp('函数值                   变量');
disp([bestfitness, x]);
