Fs = 100;
t = 0:1/Fs:1;

Ht = sin(2*pi*10*t) + 2*sin(2*pi*30*t);
figure;
subplot(2, 1, 1);
plot(t, Ht);
title("Domínio do tempo");
xlabel('Tempo (s)');
ylabel('Tensão (V)');

fourier = fft(Ht);
subplot(2, 1, 2);
plot(linspace(0, Fs, length(fourier)), abs(fourier));
%xlim([0 Fs/2]);
title("Domínio da frequência");
xlabel('Frequência (Hz)');
ylabel('Magnitude');