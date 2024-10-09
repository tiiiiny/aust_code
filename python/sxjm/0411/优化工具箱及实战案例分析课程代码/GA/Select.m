function ret = Select(individuals, sizepop)

individuals.fitness = 1 ./ (individuals.fitness);
sumfitness = sum(individuals.fitness);
sumf = individuals.fitness ./ sumfitness;
index=[];
for i = 1 : sizepop
    pick = rand;
    while pick == 0
        pick = rand;
    end
    for j = 1 : sizepop
        pick = pick - sumf(j);
        if pick < 0
            index = [index, j];
            break;
        end
    end
end
individuals.chrom = individuals.chrom(index, :);
individuals.fitness = 1 ./ individuals.fitness(index);
ret = individuals;