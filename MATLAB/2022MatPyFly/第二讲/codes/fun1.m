function [y,f] = fun1(x)
    temp = fact(x);
    y = log(temp);
    f = @fact;          %返回表示函数fact的函数句柄f
end

function y = fact(x)
    y = 1;
    for index = 2:1:x
        y = y * index;
    end
end