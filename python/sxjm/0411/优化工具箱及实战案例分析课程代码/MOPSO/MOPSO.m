function REP = MOPSO(params, MultiObj)
    Np = params.Np;
    Nr = params.Nr;
    maxgen = params.maxgen;
    W = params.W;
    C1 = params.C1;
    C2  = params.C2;
    ngrid = params.ngrid;
    maxvel = params.maxvel;
    u_mut = params.u_mut;
    fun = MultiObj.fun;
    nVar = MultiObj.nVar;
    var_min = MultiObj.var_min(:);
    var_max = MultiObj.var_max(:);
    
    POS = repmat((var_max-var_min)', Np, 1) .* rand(Np, nVar) + repmat(var_min', Np, 1);
    VEL = zeros(Np, nVar);
    POS_fit = fun(POS);
    PBEST = POS;
    PBEST_fit = POS_fit;
    DOMINATED = checkDomination(POS_fit);
    REP.pos = POS(~DOMINATED, :);
    REP.pos_fit = POS_fit(~DOMINATED, :);
    REP = updateGrid(REP, ngrid);
    maxvel = (var_max - var_min) .* maxvel ./ 100;
    gen = 1;

    display(['Generation #0 - Repository size: ' num2str(size(REP.pos,1))]);
    
    stopCondition = false;
    while ~stopCondition
        h = selectLeader(REP);
        VEL = W .* VEL + C1 * rand(Np, nVar) .* (PBEST - POS) ...
                       + C2 * rand(Np, nVar) .* (repmat(REP.pos(h, :), Np, 1) - POS);
        POS = POS + VEL;
        
        POS = mutation(POS, gen, maxgen, Np, var_max, var_min, nVar, u_mut);
        [POS, VEL] = checkBoundaries(POS, VEL, maxvel, var_max, var_min);       
        POS_fit = fun(POS);
        
        REP = updateRepository(REP, POS, POS_fit, ngrid);
        if(size(REP.pos, 1) > Nr)
             REP = deleteFromRepository(REP, size(REP.pos, 1) - Nr, ngrid);
        end
        
        pos_best = dominates(POS_fit, PBEST_fit);
        best_pos = ~dominates(PBEST_fit, POS_fit);
        best_pos(rand(Np, 1) >= 0.5) = 0;
        if(sum(pos_best) > 1)
            PBEST_fit(pos_best, :) = POS_fit(pos_best, :);
            PBEST(pos_best, :) = POS(pos_best, :);
        end
        if(sum(best_pos) > 1)
            PBEST_fit(best_pos, :) = POS_fit(best_pos, :);
            PBEST(best_pos, :) = POS(best_pos, :);
        end
        
        display(['Generation #' num2str(gen) ' - Repository size: ' num2str(size(REP.pos,1))]);
        
        gen = gen + 1;
        if(gen > maxgen)
            stopCondition = true;
        end
    end
    h_rep = plot(REP.pos_fit(:,1),REP.pos_fit(:,2),'ok');
    grid on
end

function REP = updateRepository(REP, POS, POS_fit, ngrid)
    DOMINATED = checkDomination(POS_fit);
    REP.pos = [REP.pos; POS(~DOMINATED, :)];
    REP.pos_fit = [REP.pos_fit; POS_fit(~DOMINATED, :)];
    DOMINATED = checkDomination(REP.pos_fit);
    REP.pos_fit = REP.pos_fit(~DOMINATED, :);
    REP.pos = REP.pos(~DOMINATED, :);
    REP = updateGrid(REP, ngrid);
end

function [POS, VEL] = checkBoundaries(POS, VEL, maxvel, var_max, var_min)
    Np = size(POS, 1);
    MAXLIM = repmat(var_max(:)', Np, 1);
    MINLIM = repmat(var_min(:)', Np, 1);
    MAXVEL = repmat(maxvel(:)', Np, 1);
    MINVEL = repmat(-maxvel(:)', Np, 1);
    
    VEL(VEL > MAXVEL) = MAXVEL(VEL > MAXVEL);
    VEL(VEL < MINVEL) = MINVEL(VEL < MINVEL);
    VEL(POS > MAXLIM) = (-1) .* VEL(POS > MAXLIM);
    POS(POS > MAXLIM) = MAXLIM(POS > MAXLIM);
    VEL(POS < MINLIM) = (-1) .* VEL(POS < MINLIM);
    POS(POS < MINLIM) = MINLIM(POS < MINLIM);
end

function dom_vector = checkDomination(fitness)
    Np = size(fitness, 1);
    dom_vector = zeros(Np, 1);
    all_perm = nchoosek(1 : Np, 2);
    all_perm = [all_perm; [all_perm(:, 2), all_perm(:, 1)]];
    
    d = dominates(fitness(all_perm(:, 1), :), fitness(all_perm(:, 2), :));
    dominated_particles = unique(all_perm(d == 1, 2));
    dom_vector(dominated_particles) = 1;
end

function d = dominates(x, y)
    d = all(x <= y, 2) & any(x < y, 2);
end

function REP = updateGrid(REP, ngrid)
    ndim = size(REP.pos_fit, 2);
    REP.hypercube_limits = zeros(ngrid + 1, ndim);
    for dim = 1 : ndim
        REP.hypercube_limits(:, dim) = linspace(min(REP.pos_fit(:, dim)), max(REP.pos_fit(:, dim)), ngrid + 1)';
    end
    
    npar = size(REP.pos_fit, 1);
    REP.grid_idx = zeros(npar, 1);
    REP.grid_subidx = zeros(npar, ndim);
    for n = 1 : 1 : npar
        idnames = [];
        for d = 1 : 1 : ndim
            REP.grid_subidx(n, d) = find(REP.pos_fit(n, d) <= REP.hypercube_limits(:, d)', 1, 'first') - 1;
            if(REP.grid_subidx(n,d) == 0)
                REP.grid_subidx(n,d) = 1;
            end
            idnames = [idnames ',' num2str(REP.grid_subidx(n, d))];
        end
        REP.grid_idx(n) = eval(['sub2ind(ngrid.*ones(1,ndim)' idnames ');']);
    end
    
    REP.quality = zeros(ngrid, 2);
    ids = unique(REP.grid_idx);
    for i = 1 : length(ids)
        REP.quality(i, 1) = ids(i);
        REP.quality(i, 2) = 10 / sum(REP.grid_idx == ids(i));
    end
end

function selected = selectLeader(REP)
    prob = cumsum(REP.quality(:,2));
    sel_hyp = REP.quality(find(rand(1, 1) * max(prob) <= prob, 1, 'first'), 1);
    idx = 1 : 1 : length(REP.grid_idx);
    selected = idx(REP.grid_idx == sel_hyp);
    selected = selected(randi(length(selected)));
end

function REP = deleteFromRepository(REP, n_extra, ngrid)
    crowding = zeros(size(REP.pos, 1), 1);
    for m = 1 : 1 : size(REP.pos_fit, 2)
        [m_fit, idx] = sort(REP.pos_fit(:, m), 'ascend');
        m_up = [m_fit(2 : end); Inf];
        m_down = [Inf; m_fit(1 : end - 1)];
        distance = (m_up - m_down) ./ (max(m_fit) - min(m_fit));
        [~, idx] = sort(idx, 'ascend');
        crowding = crowding + distance(idx);
    end
    crowding(isnan(crowding)) = Inf;
    
    [~, del_idx] = sort(crowding, 'ascend');
    del_idx = del_idx(1 : n_extra);
    REP.pos(del_idx, :) = [];
    REP.pos_fit(del_idx, :) = [];
    REP = updateGrid(REP, ngrid); 
end

function POS = mutation(POS, gen, maxgen, Np, var_max, var_min, nVar, u_mut)
    fract = Np / 3 - floor(Np / 3);
    if fract < 0.5
        sub_sizes =[ceil(Np / 3), round(Np / 3), round(Np / 3)];
    else
        sub_sizes =[round(Np / 3), round(Np / 3), floor(Np / 3)];
    end
    cum_sizes = cumsum(sub_sizes);
    
    nmut = round(u_mut * sub_sizes(2));
    if(nmut > 0)
        idx = cum_sizes(1) + randperm(sub_sizes(2), nmut);
        POS(idx, :) = repmat((var_max - var_min)', nmut, 1) .* rand(nmut, nVar) + repmat(var_min', nmut, 1);
    end
    
    per_mut = (1 - gen / maxgen) ^ (5 * nVar);
    nmut = round(per_mut * sub_sizes(3));
    if nmut > 0
        idx = cum_sizes(2) + randperm(sub_sizes(3), nmut);
        POS(idx, :) = repmat((var_max - var_min)', nmut, 1) .* rand(nmut, nVar) + repmat(var_min', nmut, 1);
    end
end