clc;

Jm = 3e-6;
Ja = 4.5e-4;
Ke = 0.0053;
Km = 0.0053;
Kt = 1.78e-3;
Rm = 0.5;
Rs = 0.5;
La = 0.15;

A = [0 1 0; 0 0 (La*Kt)/Ja; 0 0 -Ke/(Jm*(Rm+Rs))]
B = [0; 0; Km/(Jm*(Rm+Rs))]

C = ctrb(A, B)

rank(C)