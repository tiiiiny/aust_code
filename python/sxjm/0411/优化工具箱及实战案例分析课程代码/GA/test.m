function flag = test(lenchrom, bound, code)
flag = 1;
[n, ~] = size(code);
for i = 1 : n
    if code(i) < bound(i, 1) || code(i) > bound(i, 2)
        flag = 0;
    end
end