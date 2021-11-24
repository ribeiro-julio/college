clear all;
clc;

% Quantidade de componentes
n = 10;
% Amplitude
A = 5;
% Periodo
T = 2;
% Duty cycle (%)
Pw = 40;
Pw = (Pw/100)*T;
% Omega
w = 2*pi/T;
% Valores para t
t_values = -3:0.01:3;

i = 1;
for t = t_values
    % Somatoria da serie de fourier para todas as componentes -k ate k
    value = 0;
    for k = -n:n
        % Se k for zero deve usar a expressao x[0], pra nao ter divisao por
        % 0
        if k == 0
            value = value + A*Pw/T;
        % Caso controlario calcula com a expressao x[k]
        else
            value = value + exp(j*k*w*t)*((-A*exp(-1*j*k*w*Pw)/(T*j*k*w)) + ...
                A/(T*j*k*w));
        end
    end
    % Coloca no vetor de resultados
    res(i) = value;
    i = i + 1;
end

% Plota a funcao reconstruida
plot(t_values, res);
grid on;