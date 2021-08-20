num = 1;
den = [1 10 24 1];
Gs = tf(num, den)

Ts = 2.04;
overshoot = 0.272;
amortecimento = sqrt(1/(1+((pi^2)/(log(overshoot))^2)))
Wn = 4/(Ts*amortecimento)
Kv = 5.1942;
erro = 1/Kv
poloB = -amortecimento*Wn+((Wn*sqrt(1-(amortecimento^2))))*1i