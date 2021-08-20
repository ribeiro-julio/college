num = 1;
den = [1 10 24 1];
overshoot = 0.3;
amortecimento = sqrt(1/(1+((pi^2)/(log(overshoot))^2)));

Gs = tf(num, den)
figure(1);
rlocus(Gs)
sgrid (amortecimento,0)
[K,p]=rlocfind(Gs)

novonum = K;
novoden = [1 10 24 novonum];
novoGs = tf(novonum, novoden)

figure(2);
step(novoGs)

overshoot = 0.28;
amortecimento = sqrt(1/(1+((pi^2)/(log(overshoot))^2)))
Ts = 3.98;
Wn = 4/(Ts*amortecimento)
Kv = 63.30/24
erro = 1/Kv