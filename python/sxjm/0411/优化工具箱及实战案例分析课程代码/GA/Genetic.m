% clc
% clear

% ��������
maxgen = 10;
sizepop = 10;
pcross = 0.7;
pmutation = 0.05;
lenchrom = [1, 1, 1, 1, 1]; % ������������
bound = [0, 1; 0, 1; 0, 1; 0, 1; 0, 1];% ����ÿ������ȡֵ��Χ

individuals = struct('fitness', zeros(1, sizepop), 'chrom', []);
avgfitness = [];
bestfitness = [];
bestchrom = [];

% ��ʼ����Ⱥ
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
    % ѡ�����
    individuals = Select(individuals, sizepop);
    avgfitness = sum(individuals.fitness) / sizepop;
    
    % �������
    individuals.chrom = Cross(pcross, lenchrom, individuals.chrom, sizepop, bound);
    % �������
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

% �������
figure
plot((1 : maxgen)', trace(:, 1), 'r-', (1: maxgen)', trace(:, 2), 'b--');
title(['����ֵ����  ' '��ֹ������' num2str(maxgen)], 'fontsize', 12);
xlabel('��������', 'fontsize', 12);
ylabel('����ֵ', 'fontsize', 12);
legend('����ƽ��ֵ', '�������ֵ', 'fontsize', 12);
ylim([3, 8])
disp('����ֵ                   ����');
disp([bestfitness, x]);
