% JULIO CESAR GARCIA RIBEIRO - RA: 1994484

% vetor para conter os tempos (500 pontos de 0s ate 3s)
t = linspace(0,3,500);

% ciclos por segundo
f_ft1 = 2;
% defasagem de 30 graus (em rad pi/6)
lag_ft1 = pi/6;
% deslocamento vertical
vert_shift_ft1 = 5;
% amplitude
a_ft1 = 5;
% gera a funcao
ft1 = vert_shift_ft1 + a_ft1*sin(2*pi*f_ft1*t + lag_ft1);
figure;
% plota a primeira funcao na figura
plot(t, ft1);
% espera o proximo plot
hold on;

% ciclos por segundo
f_ft2 = 3;
% amplitude
a_ft2 = 15;
% gera a funcao
ft2 = a_ft2*sin(2*pi*f_ft2*t);
% plota a segunda funcao na figura
plot(t, ft2);