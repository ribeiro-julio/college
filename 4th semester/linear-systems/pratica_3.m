hn = [0.5 0.5 0 0 0 0 0];
xn = [-2 0 2 4 4 8 4];
yn = conv(xn, hn)
subplot(3, 1, 1);
stem(hn);
title("Resposta ao Impulso");
subplot(3, 1, 2);
stem(xn);
title("Entrada");
subplot(3, 1, 3);
stem(yn);
title("Saida");