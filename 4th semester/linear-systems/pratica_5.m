% Quantidade de componentes
n = 3;
% Limites de integracao
Ta = -1;
Tb = 1;
% Periodo calculado com os limites especificados
T = Tb - Ta;
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
            value = value + 3*((Tb-Ta)*(Tb+Ta))/4*T^2;
        % Caso controlario calcula com a expressao x[k]
        else
            value = value + exp(j*k*w*t)*3*(((Ta*j*k*w)+1)*exp(-Ta*j*k*w) ...
                -((Tb*j*k*w)+1)*exp(-Tb*j*k*w))/(-2*(T^2)*(k^2)*w^2);
        end
    end
    % Coloca no vetor de resultados
    res(i) = value;
    i = i + 1;
end

% Plota a funcao reconstruida
plot(t_values, res);
grid on;