clc
clear all

%% Dados
Vin=5;
L=1e-6;
C=1620e-6;
Rc=.004;
Rl=0.1;
fs=250e3;
Ts=1/fs;
Fm=1;
Vomax=2;
Kd=1/Vomax;
Vo=1.6;
Io=16;
Td=0.0*Ts;

%% Planta
num=[Rc*C 1];
den=[L*C*(1+Rc/Rl) Rc*C+L/Rl 1];
Gp=Vin*tf(num,den) % Planta

%% 2.2.1 Design by Emulation
%sisotool(Gp*Kd*Fm) % projeto por resposta em frequencia

Gc1=13.795*tf([1 45260 4.99656e8],[1 127900 0]); %compensador Gc1

Gpc=Gp*Kd*Fm*Gc1;
figure()
bode(Gpc) % resposta em frequencia com compensador
[Gm,Pm,Wcp,Wcg]=margin(Gpc);
margin(Gpc);
grid on

Gc1_z = c2d(Gc1,Ts, 'matched'); %compensador Gc1 discretizado

%% 2.2.2 Direct Digital Design

Gp_dly=Vin*tf(num,den,'inputdelay',Td) % planta sem atraso

Gpz=c2d(Gp_dly*Kd,Ts,'zoh') % planta discretizado sem atraso

% sisotool(Gpz); % projeto compensador Gc2(z) por resposta em frequencia

Gc2=zpk([0.935404991063745 0.869662618303448],[0.999825650013073 0.499720119854676],13.7595,Ts) %compensador Gc2(z)

Gpc2=Gpz*Gc2;
figure()
bode(Gpc2)
[Gm,Pm,Wcp,Wcg]=margin(Gpc2);
margin(Gpc2)
grid on

%% Case 1 : Computation Delay Td = 0.5Ts
Td=0.5*Ts;
Gp_dly2=Vin*tf(num,den,'inputdelay',Td) % planta com atraso 0.5

Gpz2=c2d(Gp_dly2*Kd,Ts,'zoh') % planta discretizado com atraso 0.5

figure()
bode(Gpz2*Gc2)
[Gm,Pm,Wcp,Wcg]=margin(Gpz2*Gc2);
margin(Gpz2*Gc2)
grid on

%% Case 2 : Computation Delay Td = 2.0Ts

Td=2*Ts;
Gp_dly3=Vin*tf(num,den,'inputdelay',Td) % planta com atraso 2

Gpz3=c2d(Gp_dly3*Kd,Ts,'zoh') % planta discretizado com atraso 2

figure()
bode(Gpz3*Gc2)
[Gm,Pm,Wcp,Wcg]=margin(Gpz3*Gc2);
margin(Gpz3*Gc2)
grid on

% figure()
% Gpz3=c2d(Gp_dly3*Kd,Ts,'foh')
% bode(Gpz3*Gc2)

% sisotool(Gpz3) %projetando terceiro controlador

Gc3=zpk([0.964430061268854 0.931243635473161 0.248670131350632],[0.999924874737262 0.223805684317391 0.0432139182637722],13.3918903688527,Ts)

figure()
bode(Gpz3*Gc3)
[Gm,Pm,Wcp,Wcg]=margin(Gpz3*Gc3);
margin(Gpz3*Gc3)
grid on

