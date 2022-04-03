clear;
clc;

%% Exercicio 1%%

%  Parametros %
Fs = 1;  % Frequencia de amostragem
N = 20;  % Periodo do sinal
w0 = 2*pi/N;  % w0 do sinal
n = 0:1/Fs:N-(1/Fs);  % Vetor de amostras para um período
K = -N/2:N/2;  % Vetor de K para plotar Serie de Fourier de -pi ate pi
x_n = 3*cos(n*(pi/2)) + sin(n*(pi/5));  % Sinal calculado nas amostras

% Série de Fourier %
x_k = getFourier(x_n, w0, N, n);

% Reconstruindo Sinal %
%x_n_rebuilt = getRebuiltFunc(x_k, w0, N, Fs);

% Resultados %
figure;

subplot(3, 2, [1, 3]);
stem(n, x_n);
title('Sinal original');
xlabel('n'); ylabel('x[n]');

subplot(3, 2, 2);
stem(K, abs(x_k));
title('Magnitude do sinal');
xlabel('k = n\omega_0'); ylabel('|x[n]|');

subplot(3, 2, 4);
stem(K, angle(x_k));
title('Fase do sinal');
xlabel('k = n\omega_0'); ylabel('\angle (rad)');

subplot(3, 2, [5, 6]);
%stem(x_n_rebuilt);
title('Sinal reconstruido');
xlabel('n'); ylabel('x[n]');


%% Exercicio 2 - a %%

%  Parametros %
Fs = 1;  % Frequencia de amostragem
N = 30;  % Periodo do sinal
w0 = 2*pi/N;  % w0 do sinal
n = 0:1/Fs:N-(1/Fs);  % Vetor de amostras para um período
n_truncado = 0:1/Fs:N-(2/Fs);  % Vetor de amostras truncado
K = -N/2:N/2;  % Vetor de K para plotar Serie de Fourier de -pi ate pi
x_n = sin(n*w0);  % Sinal calculado nas amostras
x_n_truncado = sin(n_truncado*w0);  % Sinal truncado calculado nas amostras

% Série de Fourier %
x_k = getFourier(x_n, w0, N, n);
x_k_truncado = getFourier(x_n_truncado, w0, N, n_truncado);

% Resultados %
figure;

subplot(3, 2, 1);
stem(n, x_n);
title('Sinal original');
xlabel('n'); ylabel('x[n]');

subplot(3, 2, 2);
stem(n_truncado, x_n_truncado);
title('Sinal truncado');
xlabel('n'); ylabel('x[n]');

subplot(3, 2, 3);
stem(K, abs(x_k));
title('Magnitude do sinal original');
xlabel('k = n\omega_0'); ylabel('|x[n]|');

subplot(3, 2, 5);
stem(K, angle(x_k));
title('Fase do sinal original');
xlabel('k = n\omega_0'); ylabel('\angle (rad)');

subplot(3, 2, 4);
stem(K, abs(x_k_truncado));
title('Magnitude do sinal truncado');
xlabel('k = n\omega_0'); ylabel('|x[n]|');

subplot(3, 2, 6);
stem(K, angle(x_k_truncado));
title('Fase do sinal truncado');
xlabel('k = n\omega_0'); ylabel('\angle (rad)');


%% Exercicio 2 - b %%

%  Parametros %
bin_word = [0 1 0 0 1 0 0];  % Palavra binaria
N = size(bin_word, 2);  % Periodo do sinal
w0 = 2*pi/N;  % w0 do sinal
n = 0:1/Fs:N-1;  % Vetor de amostras para um período
K = -N/2:N/2;  % Vetor de K para plotar Serie de Fourier de -pi ate pi

x_n = bin_word;

% Série de Fourier %
x_k = getFourier(x_n, w0, N, n);

% Resultados %
figure;

subplot(2, 2, [1, 3]);
stairs(n, x_n);
title('Sinal original');
xlabel('n'); ylabel('x[n]');
ylim([0 1.2]);

subplot(2, 2, 2);
stem(K, abs(x_k));
title('Magnitude do sinal');
xlabel('k = n\omega_0'); ylabel('|x[n]|');

subplot(2, 2, 4);
stem(K, angle(x_k));
title('Fase do sinal');
xlabel('k = n\omega_0'); ylabel('\angle (rad)');


%% Funcao para calcular a Serie de Fourier %%
function x_k = getFourier(x_n, w0, N, n)
    x_k = [];

    for k = -N/2:N/2
        x_k = [x_k sum(x_n.*exp(-1i*w0*k*n))];
    end

    % Arredondar valores muito proximos de zero
    x_k(abs(x_k) < 0.1) = 0;
end


function x_n_rebuilt = getRebuiltFunc(x_k, w0, N, Fs)
    n = 0:1/Fs:N;
    x_n_rebuilt = [];

    for k = -N/2:N/2
        x_n_rebuilt = [x_n_rebuilt 1/N*(sum(x_k.*exp(-1i*w0*k*n)))];
    end
end