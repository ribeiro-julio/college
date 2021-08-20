%Malhas
%###############################################
s = tf('s');
SIC_004 = exp(-2*s)*(16.7808/(2.7174*s + 1))
FIC_013 = exp(-1.8*s)*(2.1045/(1.7895*s + 1))
LIC_001 = exp(-2.5*s)*(11.6279/(1.0668*s + 1))
SIC_001 = exp(-2*s)*(36.5620/(2.4522*s + 1))
%###############################################

%Malha SIC_004
%##################################################
%Variáveis
K = 16.7808;
tau = 2.7174;
theta = 2;
%Controlador PI
Kp_PI = (0.9+(0.083*(tau/theta)))*(tau/(K*theta))
Ti_PI = ((0.9+(0.083*(tau/theta)))/(1.27+(0.6*(tau/theta))))*theta
Cs_PI = Kp_PI + (Kp_PI/(Ti_PI*s))
SIC_004_PI = SIC_004*Cs_PI
SIC_004_PI_MF = feedback(SIC_004_PI, 1)
%Controlador PID
Kp_PID = (1.35+(0.25*(tau/theta)))*(tau/(K*theta))
Ti_PID = ((1.35+(0.25*(tau/theta)))/(0.54+(0.6*(tau/theta))))*theta
Td_PID = ((0.5*theta)/(1.35+(0.25*(tau/theta))))
Cs_PID = Kp_PID + (Kp_PID/(Ti_PID*s)) + (Kp_PID*Td_PID*s)
SIC_004_PID = SIC_004*Cs_PID
SIC_004_PID_MF = feedback(SIC_004_PID, 1)
%Plots
figure(1)
step(SIC_004_PI_MF, SIC_004_PID_MF);
figure(2)
bode(SIC_004_PI, SIC_004_PID);
%##################################################

%Malha FIC_013
%##################################################
%Variáveis
K = 2.1045;
tau = 1.7895;
theta = 1.8;
%Controlador PI
Kp_PI = (0.9+(0.083*(tau/theta)))*(tau/(K*theta))
Ti_PI = ((0.9+(0.083*(tau/theta)))/(1.27+(0.6*(tau/theta))))*theta
Cs_PI = Kp_PI + (Kp_PI/(Ti_PI*s))
FIC_013_PI = FIC_013*Cs_PI
FIC_013_PI_MF = feedback(FIC_013_PI, 1)
%Controlador PID
Kp_PID = (1.35+(0.25*(tau/theta)))*(tau/(K*theta))
Ti_PID = ((1.35+(0.25*(tau/theta)))/(0.54+(0.6*(tau/theta))))*theta
Td_PID = ((0.5*theta)/(1.35+(0.25*(tau/theta))))
Cs_PID = Kp_PID + (Kp_PID/(Ti_PID*s)) + (Kp_PID*Td_PID*s)
FIC_013_PID = FIC_013*Cs_PID
FIC_013_PID_MF = feedback(FIC_013_PID, 1)
%Plots
figure(3)
step(FIC_013_PI_MF, FIC_013_PID_MF);
figure(4)
bode(FIC_013_PI, FIC_013_PID);
%##################################################

%Malha LIC_001
%##################################################
%Variáveis
K = 11.6279;
tau = 1.0668;
theta = 2.5;
%Controlador PI
Kp_PI = (0.9+(0.083*(tau/theta)))*(tau/(K*theta))
Ti_PI = ((0.9+(0.083*(tau/theta)))/(1.27+(0.6*(tau/theta))))*theta
Cs_PI = Kp_PI + (Kp_PI/(Ti_PI*s))
LIC_001_PI = LIC_001*Cs_PI
LIC_001_PI_MF = feedback(LIC_001_PI, 1)
%Controlador PID
Kp_PID = (1.35+(0.25*(tau/theta)))*(tau/(K*theta))
Ti_PID = ((1.35+(0.25*(tau/theta)))/(0.54+(0.6*(tau/theta))))*theta
Td_PID = ((0.5*theta)/(1.35+(0.25*(tau/theta))))
Cs_PID = Kp_PID + (Kp_PID/(Ti_PID*s)) + (Kp_PID*Td_PID*s)
LIC_001_PID = LIC_001*Cs_PID
LIC_001_PID_MF = feedback(LIC_001_PID, 1)
%Plots
figure(5)
step(LIC_001_PI_MF, LIC_001_PID_MF);
figure(6)
bode(LIC_001_PI, LIC_001_PID);
%##################################################

%Malha SIC_004
%##################################################
%Variáveis
K = 36.5620;
tau = 2.4522;
theta = 2;
%Controlador PI
Kp_PI = (0.9+(0.083*(tau/theta)))*(tau/(K*theta))
Ti_PI = ((0.9+(0.083*(tau/theta)))/(1.27+(0.6*(tau/theta))))*theta
Cs_PI = Kp_PI + (Kp_PI/(Ti_PI*s))
SIC_004_PI = SIC_004*Cs_PI
SIC_004_PI_MF = feedback(SIC_004_PI, 1)
%Controlador PID
Kp_PID = (1.35+(0.25*(tau/theta)))*(tau/(K*theta))
Ti_PID = ((1.35+(0.25*(tau/theta)))/(0.54+(0.6*(tau/theta))))*theta
Td_PID = ((0.5*theta)/(1.35+(0.25*(tau/theta))))
Cs_PID = Kp_PID + (Kp_PID/(Ti_PID*s)) + (Kp_PID*Td_PID*s)
SIC_004_PID = SIC_004*Cs_PID
SIC_004_PID_MF = feedback(SIC_004_PID, 1)
%Plots
figure(7)
step(SIC_004_PI_MF, SIC_004_PID_MF);
figure(8)
bode(SIC_004_PI, SIC_004_PID);
%##################################################