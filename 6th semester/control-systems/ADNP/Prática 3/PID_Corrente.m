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

wc = (2*pi*fs)/16                                               %Frequencia de cruzamento de ganho

PHIp = atand(-(wc*Leq)/Req)                                     %Angulo de fase da planta

MFpi = 59;
GAMMApi = MFpi - 180 - PHIp

Tpi = -1/(tand(GAMMApi)*wc)

MFpd = 67;
GAMMApd = MFpd - MFpi

Tpd = tand(GAMMApd)/wc

absGs = abs((Kpwm*Vcc)/((Leq*wc*j) + Req))
absGc = abs(((-1*Tpi*Tpd*wc*wc)+(Tpi*wc*j)+(Tpd*wc*j)+1)/(wc*j))
Kc = 1/(absGs*absGc)                                            %Ganho PID

numc = [Kc*Tpi*Tpd Kc*(Tpi+Tpd) Kc];
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
