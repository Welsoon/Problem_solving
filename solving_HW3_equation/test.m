f = @(x)x.^5+3*x.^3-6*x.^2;
df = @(x)5*x.^4+9*x.^2-12*x;
ddf = @(x)20*x.^3+18*x;
x = linspace(0.1,2,1000);
figure;
hold on;
zero = zeros(1,1000);
plot(x,f(x));
plot(x,zero);

figure;
hold on;
plot(x,df(x));
plot(x,zero);