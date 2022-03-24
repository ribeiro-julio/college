clc;
clear;

%% Função %%
% Paramentros de entrada
Fs = 1;  % Frequencia de amostragem
cicles = 3;  % Quantidade de ciclos
A1 = 3;  % Amplitude sinal 1
W1 = pi/2;  % Frequencia angular sinal 2
A2 = 1;  % Amplitude sinal 2
W2 = pi/5;  % Frequencia angular sinal 1

% Calculando período
T1 = 2*pi/W1;
T2 = 2*pi/W2;
T = lcm(T1, T2);    % MMC dos dois períodos

% Fazendo vetor de amostras
n = 0:1/Fs:(T*cicles)-1;

% Calculando valores da funcao para cada amostra
Xn = A1*cos(n*W1) + A2*sin(n*W2);

% Plotando
figure;
colorstring = 'kbgry';
stem(n, Xn);
title(['X[n] com \omega_1 = ', num2str(W1/pi), '\pi, A_1 = ', num2str(A1), ...
    '; \omega_2 = ', num2str(W2/pi), '\pi, A_2 = ', num2str(A2)]);
xlabel('n'); ylabel('X[n]');

%% Filtro %%
Wc = 7*pi/20;  % Frequencia de corte
W = 10;  % Tamanho da janela

% Fazendo vetor de amostras da janela do filtro
n_Hn = -1*W:1/Fs:W;

% Calculando valores do filtro para cada amostra
Hn = Wc/pi*sinc(Wc*n_Hn/pi);

% Resposta ao impulso do filtro
figure;
plot(n_Hn, Hn);
title(['Resposta ao impulso de H[n] com Fs = ', num2str(Fs), 'Hz']);
xlabel('n'); ylabel('H[n]');

% Encontrando sinal filtrado teórico
figure;
plot(abs(fft(Xn)));
title('Resposta em frequencia de X[n]');
xlabel('F(Hz)'); ylabel('A');
figure;
plot(abs(fft(Wc/pi*sinc(Wc*n/pi))));
title('Resposta em frequencia de H[n]');
xlabel('F(Hz)'); ylabel('A');
% O sinal filtrado terá apenas a componente de menor frequncia
if W1 < W2
    Xn_ideal = A1*cos(n*W1);
else
    Xn_ideal = A2*sin(n*W2);
end

%% Comparando sinais %%

% Comparaçao sinal original/filtrado teórico
figure;
subplot(2, 1, 1);
plot(n, Xn);
hold on;
plot(n, Xn_ideal);
title('Comparaçao sinal original e filtrado teórico');
xlabel('n'); ylabel('X[n]');
legend('Original', 'Filtrado teórico')

% Comparaçao sinal filtrado teorico/filtrado convoluçao
XnHn = conv(Xn, Hn, 'same');
subplot(2, 1, 2);
plot(n, Xn_ideal);
hold on;
plot(n, XnHn);
title('Comparaçao sinal filtrado teórico e filtrado');
xlabel('n'); ylabel('X[n]');
legend('Filtrado teórico', 'Filtrado')
