num = 1;
den = [1 10 24 1];
Gs = tf(num, den)

Ts = 1.74;
overshoot = 0.129;
amortecimento = sqrt(1/(1+((pi^2)/(log(overshoot))^2)))
Wn = 4/(Ts*amortecimento)
Kv = 2.9137;
erro = 1/Kv
poloB = -amortecimento*Wn+((Wn*sqrt(1-(amortecimento^2))))*1i