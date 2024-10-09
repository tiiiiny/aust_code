clc
clear

% ��������
c1 = 1.49445;
c2 = 1.49445;
w = 1;

maxgen = 500;
sizepop = 500;
nVar = 6; % ������������
Vmax = 1;
Vmin = -1;
popmax = [5, 5, 5, 5, 5, 5]; % ����ÿ��������Сֵ
popmin = [-5, -5, -5, -5, -5, -5]; % ����ÿ���������ֵ


% ���ɳ�ʼ��Ⱥ
for i = 1 : sizepop
    pop(i, :) = (popmax - popmin) .* rands(1, nVar) + popmin;
    V(i, :) = (Vmax - Vmin) * rands(1, nVar) + Vmin;
    fitness(i) = fun(pop(i, :));
end

% Ѱ��ȫ�����ź͸�������
[bestfitness, bestindex] = max(fitness);
gbest = pop(bestindex, :);
pbest = pop;
fitnesspbest = fitness;
fitnessgbest = bestfitness;

% ��������
for i = 1 : maxgen
    for j = 1 : sizepop
        % �����ٶ�
        w = 0.98 .^ i * w;
        V(j, :) = w .* V(j, :) + c1 * rand * (pbest(j, :) - pop(j, :)) + c2 * rand * (gbest - pop(j, :));
        V(j, find(V(j, :) > Vmax)) = Vmax;
        V(j, find(V(j, :) < Vmin)) = Vmin;
        
        % ����λ��
        pop(j, :) = pop(j, :) + V(j, :);
        pop(j, find(pop(j, :) > popmax)) = popmax(find(pop(j, :) > popmax));
        pop(j, find(pop(j, :) < popmin)) = popmin(find(pop(j, :) < popmin));
        
        fitness(j) = fun(pop(j, :)); 
   
    end
    
    % ���¸������ź�ȫ������
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

% �������
plot(yy)
title('���Ÿ�����Ӧ��', 'fontsize', 12);
xlabel('��������', 'fontsize', 12);
ylabel('��Ӧ��', 'fontsize', 12);

disp('����ֵ                   ����');
disp([fitnessgbest, gbest]);

