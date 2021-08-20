fs = 20e3;
Lf = 0.547e-3;
Rlf = 0.22;
Ldt = 1.082e-3;
Rdt = 0.265;
Vcc = 230;
Kpwm = 5.333e-4;
Leq = Ldt + Lf;
Req = Rdt + Rlf;

nump = Kpwm*Vcc;
denp = [Leq Req];
Gs = tf(nump, denp)
hold on;
bode(Gs);

wc = (2*pi*fs)/16                           %Frequencia de cruzamento de ganho

PHIp = atand(-(wc*Leq)/Req)                 %Angulo de fase da planta

MF = 67;
PHIc = MF - 180 - PHIp                      %Contribuição angular do compensador

T = -1/(wc*tand(PHIc))                      %Parametro T do compenador

absGs = abs((Kpwm*Vcc)/((Leq*wc*j) + Req))
absGc = abs(((T*wc*j)+1)/(wc*j))
Kc = 1/(absGs*absGc)                        %Ganho PI

numc = [Kc*T Kc];
denc = [1 0];
Gc = tf(numc, denc)
hold on;
bode(Gc);

numGcGs = conv(nump, numc);
denGcGs = conv(denp, denc);
GcGs = tf(numGcGs, denGcGs)
bode(GcGs);
hold off;
GcGsMF = feedback(GcGs, 1)
figure(2);
step(GcGsMF)
BW = bandwidth(GcGsMF)