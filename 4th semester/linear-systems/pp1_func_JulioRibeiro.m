% JULIO CESAR GARCIA RIBEIRO - RA: 1994484

% gera trapezios
trapz(2, 1, 2);
trapz(3, 2, -2);

% calcula a energia do sinal 2 do outro exercicio
t = linspace(0,3, 500);
f_ft2 = 3;
a_ft2 = 15;
ft2 = a_ft2*sin(2*pi*f_ft2*t);
energy_fft2 = energy(ft2)

% funcao para plotar um trapezio
function trapz(A, B, C)
    % define os valores em x
    x = [-1*A -1*B B A];
    % define os valores em y
    y = [0 C C 0];
    % plota x e y
    figure;
    plot(x, y);
    % faz uma linha vertical e horizontal para indicar a origem do 
    % cartesiano
    yline(0);
    xline(0);
    % seta os limites do plano para mostrar apenas uma valor acima ou
    % abaixo do limte do trapezio
    if C > 0
        axis([-1*A-1 A+1 -1 C+1]);
    else
        axis([-1*A-1 A+1 C-1 1]);
    end
end

% funcao para calcular a energia de um sinal discreto
% deve receber os pontos do sinal
function en = energy(signal)
    res = 0;
    for i = 1:length(signal)
        res = res + signal(i)*signal(i);
    end
    en = res;
end