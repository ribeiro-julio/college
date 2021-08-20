num = 1048.18;
den = [1 1766.70 0 0];
Gs = tf(num, den);
%figure(1);
%step(Gs);
%figure(2);
%bode(Gs);

kc_IAE = 4;
ti_IAE = 8;
td_IAE = 1.6;

kc_ITAE = 5;
ti_ITAE = 10;
td_ITAE = 5;

kc_ISE = 20;
ti_ISE = 15;
td_ISE = 10;

kc_ITSE = 15;
ti_ITSE = 8;
td_ITSE = 6;

Cs_IAE = tf([kc_IAE*ti_IAE kc_IAE], [ti_IAE 0]);
Cs_ITAE = tf([kc_ITAE*ti_ITAE kc_ITAE], [ti_ITAE 0]);
Cs_ISE = tf([kc_ISE*ti_ISE kc_ISE], [ti_ISE 0]);
Cs_ITSE = tf([kc_ITSE*ti_ITSE kc_ITSE], [ti_ITSE 0]);
%figure(3);
%bode(Cs_IAE, Cs_ITAE, Cs_ISE, Cs_ITSE);

Cs_PID = tf([kc_IAE*ti_IAE*td_IAE kc_IAE*ti_IAE kc_IAE], [ti_IAE 0]);
figure(1);
bode(Cs_PID);

CsGs_IAE = Gs*Cs_IAE;
CsGs_ITAE = Gs*Cs_ITAE;
CsGs_ISE = Gs*Cs_ISE;
CsGs_ITSE = Gs*Cs_ITSE;
CsGs_PID = Gs*Cs_PID;
figure(2);
bode(CsGs_PID)
%figure(4);
%bode(CsGs_IAE, CsGs_ITAE, CsGs_ISE, CsGs_ITSE);