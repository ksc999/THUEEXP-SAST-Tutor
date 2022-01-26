function y = fmax(x)
    B = x.*exp(x) + 1./(x.^2 + x + 5) - x.^3;
    y = max(B);
end