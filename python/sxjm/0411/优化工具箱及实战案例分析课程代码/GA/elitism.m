function newPopulation = elitism(population, Er)

M = length(population.Chromosomes);
Elite_no = round(M * Er);

[~ , index] = sort(population.Chromosomes(:).fitness, 'descend');
    
for k = 1 : Elite_no
    newPopulation.Chromosomes(k).Gene  = population.Chromosomes(index(k)).Gene;
    newPopulation.Chromosomes(k).fitness  = population.Chromosomes(index(k)).fitness;
end
end