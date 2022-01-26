function [f,f1] = circle
    f.Curvature = @Curvature;
    f.Area = @Area;
    f.Cirumference = @Circumference;            %f以结构体形式返回
    f1 = {@Curvature,@Area,@Circumference};     %f1以元胞数组形式返回
end

%计算圆的曲率
function y = Curvature(R)
    y = 1./R;
end

%计算圆的面积
function y = Area(R)
    y = pi .* R.^2;
end

%计算圆的周长
function y = Circumference(R)
    y = 2 .* pi .* R;
end



