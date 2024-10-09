function Rfit = NSGAII(params,MultiObj)
    Np = params.Np;
    maxgen = params.maxgen;
    pc = params.pc;
    pm = params.pm;
    ms = params.ms;
    fun = MultiObj.fun;
    nVar = MultiObj.nVar;
    var_min = MultiObj.var_min(:);
    var_max = MultiObj.var_max(:);
        
    gen = 1;
    P = repmat((var_max - var_min)', Np, 1) .* rand(Np, nVar) + repmat(var_min', Np, 1);
    Pfit = fun(P);
    Prank = FastNonDominatedSorting_Vectorized(Pfit);
    [P, ~] = selectParentByRank(P, Prank);
    Q = applyCrossoverAndMutation(P, pc, pm, ms, var_max, var_min);

    h_fig = figure(1);
    scatter(Pfit(:, 1), Pfit(:, 2), 20, 'filled', 'markerFaceAlpha', 0.3, 'MarkerFaceColor', [128, 193, 219] ./ 255);
    hold on
    h_rep = plot(Pfit(:,1), Pfit(:,2), 'ok');
    hold on
    grid on
    xlabel('f1')
    ylabel('f2')
    drawnow
    axis square;
    display(['Generation #' num2str(gen) ' - First front size: ' num2str(sum(Prank==1))]);
    
    
    stopCondition = false;
    while ~stopCondition
        R = [P; Q];
        Rfit = fun(R);
        Rrank = FastNonDominatedSorting_Vectorized(Rfit);

        figure(h_fig)
        delete(h_rep)
        scatter(Rfit(1 : Np, 1), Rfit(1 : Np, 2), 20, 'filled', 'markerFaceAlpha', 0.3, 'MarkerFaceColor', [128, 193  219] ./ 255);
        hold on
        h_rep = plot(Rfit(1 : Np, 1), Rfit(1 : Np, 2),'ok');
        hold on;
        grid on
        xlabel('f1')
        ylabel('f2')
        drawnow;
        axis square;
        display(['Generation #' num2str(gen) ' - First front size: ' num2str(sum(Rrank==1))]);
        
        
        [Rrank,idx] = sort(Rrank, 'ascend');
        Rfit = Rfit(idx, :);
        R = R(idx, :);
        
        [Rcrowd, Rrank, ~, R] = crowdingDistances(Rrank, Rfit, R);
        
        P = selectParentByRankAndDistance(Rcrowd, Rrank, R);
        
        Q = applyCrossoverAndMutation(P, pc, pm, ms, var_max, var_min);
        
        gen = gen + 1;
        if(gen > maxgen)
            stopCondition = true;
        end
    end
end


function newParent = selectParentByRankAndDistance(Rcrowd, Rrank, R)
    N = length(Rcrowd) / 2;
    Npf = length(unique(Rrank));
    newParent = zeros(N, size(R, 2));
    
    pf = 1;
    numberOfSolutions = 0;
    while pf <= Npf
        if numberOfSolutions + sum(Rrank == pf) <= N
            newParent(numberOfSolutions + 1 : numberOfSolutions + sum(Rrank == pf), :) = R(Rrank == pf, :);
            numberOfSolutions = numberOfSolutions + sum(Rrank == pf);
        else
            rest = N - numberOfSolutions;
            lastPF = R(Rrank == pf,:);
            lastPFdist = Rcrowd(Rrank == pf);
            [~,idx] = sort(lastPFdist, 'descend');
            lastPF = lastPF(idx, :);
            newParent(numberOfSolutions + 1 : numberOfSolutions+rest, :) = lastPF(1 : rest, :);
            numberOfSolutions = numberOfSolutions + rest;
        end
        pf = pf + 1;
    end
end

function [sortCrowd, sortRank, sortFit, sortPop] = crowdingDistances(rank, fitness, pop)
    sortPop = [];
    sortFit = [];
    sortRank = [];
    sortCrowd = [];
    
    Npf = length(unique(rank));
    for pf = 1 : 1 : Npf
        index = find(rank == pf);
        temp_fit = fitness(index, :);
        temp_rank = rank(index, :);
        temp_pop = pop(index, :);
        
        [temp_fit, sort_idx] = sortrows(temp_fit, 1);
        temp_rank = temp_rank(sort_idx);
        sortFit = [sortFit; temp_fit];
        sortRank = [sortRank; temp_rank];
        sortPop = [sortPop; temp_pop(sort_idx, :)];
        
        temp_crowd = zeros(size(temp_rank));
        for m = 1 : 1 : size(fitness, 2)
            temp_max = max(temp_fit(:, m));
            temp_min = min(temp_fit(:, m));
            for l = 2 : 1 : length(temp_crowd) - 1
                temp_crowd(l) = temp_crowd(l) + (abs(temp_fit(l - 1, m) - temp_fit(l + 1, m))) ./ (temp_max - temp_min);
            end
        end
        temp_crowd(1) = Inf;
        temp_crowd(length(temp_crowd)) = Inf;
        sortCrowd = [sortCrowd; temp_crowd];
    end
end

function Q = applyCrossoverAndMutation(parent, pc, pm, ms, var_max, var_min)
    N = size(parent, 1);
    nVar = size(parent, 2);
    
    Q = parent;

    cross_idx = rand(N, 1) < pc;
    cross_idx = find(cross_idx);
    for c = 1 : 1 : length(cross_idx)
        selected = randi(N, 1, 1);
        while selected == c
            selected = randi(N, 1, 1);
        end
        cut = randi(nVar, 1, 1);
        Q(c, :) = [parent(c, 1 : cut), parent(selected, cut + 1 : nVar)];
    end

    mutatedPop = Q + ms .* repmat((var_max - var_min)', N, 1) .* randn(N, nVar);
    minVal = repmat(var_min', N, 1);
    maxVal = repmat(var_max', N, 1);
    mutatedPop(mutatedPop < minVal) = minVal(mutatedPop < minVal);
    mutatedPop(mutatedPop > maxVal) = maxVal(mutatedPop > maxVal);
    
    mut_idx = rand(N, nVar) < pm;
    Q(mut_idx) = mutatedPop(mut_idx);
end

function [P1, P1rank]   = selectParentByRank(P, Prank)
    N = length(Prank);    
    left_idx  = randi(N, N, 1);
    right_idx = randi(N, N, 1);
    while sum(left_idx == right_idx) > 0
        right_idx(left_idx == right_idx) = randi(N, sum(left_idx == right_idx), 1);
    end

    winners = zeros(N, 1);
    winners(Prank(left_idx) <= Prank(right_idx)) = left_idx(Prank(left_idx) <= Prank(right_idx));
    winners(Prank(right_idx) < Prank(left_idx)) = right_idx(Prank(right_idx) < Prank(left_idx));
    
    P1 = P(winners, :);
    P1rank = Prank(winners, :);
end


function RANK = FastNonDominatedSorting_Vectorized(fitness)
    Np = size(fitness, 1);
    RANK = zeros(Np, 1);
    current_vector = (1 : 1 : Np)';
    current_pf = 1;
    all_perm = [repmat((1 : 1 : Np)', Np', 1), reshape(repmat((1: 1: Np), Np, 1), Np ^ 2, 1)];
    all_perm(all_perm(:, 1) == all_perm(:, 2), :) = [];
    
    while ~isempty(current_vector)
        if length(current_vector) == 1
            RANK(current_vector) = current_pf;
            break;
        end
        d = dominates(fitness(all_perm(:, 1), :), fitness(all_perm(:, 2), :));
        dominated_particles = unique(all_perm(d == 1, 2));

        if sum(~ismember(current_vector,dominated_particles)) == 0
            break;
        end

        non_dom_idx = ~ismember(current_vector, dominated_particles);
        RANK(current_vector(non_dom_idx)) = current_pf;
        all_perm(ismember(all_perm(:, 1), current_vector(non_dom_idx)), :) = [];
        all_perm(ismember(all_perm(:, 2), current_vector(non_dom_idx)), :) = [];
        current_vector(non_dom_idx) = [];
        current_pf = current_pf + 1;
    end
end

function d = dominates(x,y)
    d = (all(x <= y, 2) & any(x < y, 2));
end
