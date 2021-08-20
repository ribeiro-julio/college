frip = 120;
Ccc = 2.115e-3;
Vcc = 230;
vd = 180;

nump = 3*vd;
denp = [2*Ccc*Vcc 0];
Gs = tf(nump, denp)
figure(1);
hold on;
bode(Gs);

wc = (2*pi*frip)/5                  %Frequencia de cruzamento de ganho

PHIp = -90                          %Angulo de fase da planta

MF = 88;
PHIc = MF - 180 - PHIp              %Contribuição angular do compensador

T = -1/(wc*tand(PHIc))              %Parametro T do compenador

absGs = abs(3*vd/(2*Ccc*Vcc*wc*j))
absGc = abs(((T*wc*j)+1)/wc*j)
Kc = 1/(absGs*absGc)                    %Ganho PI

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