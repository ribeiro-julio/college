%1
%num = 25;
%den = [1 4 25];
%bode(num, den)

%2
%num = [9 1.8 9];
%den = [1 1.2 9 0];
%w = logspace(-2,3,1000);
%bode(num, den, w)

%3 A
%num = [2.27 10];
%den = [0.054 1];
%bode(num, den)

%3 B
%num = [50 5];
%den = [100 1];
%bode(num, den)

%3 C
%num = [0.227 1];
%den = [0.054 1];
%bode(num, den)

%3 D
%num = [10 1];
%den = [100 1];
%bode(num, den)

%3 E
%num = [1 0.85 0.105];
%den = [1 7.015 0.105];
%bode(num, den)

%4
%num = [20 20];
%den = [1 7 20 50 0];
%Gs = tf(num, den);
%bode(Gs)
%[Gm, Pm, Wcp, Wcg] = margin(Gs)

%5
%num1 = 10;
%num2 = 100;
%den = [1 6 5 0];
%Gs1 = tf(num1, den);
%Gs2 = tf(num2, den);
%figure(1);
%bode(Gs1)
%hold on;
%bode(Gs2)
%figure(2);
%step(Gs1)
%hold on;
%step(Gs2)

%6
%num = 1;
%den = [0.5 1.5 1 1];
%Gs = tf(num, den);
%bode(num, den)
%[mag, phase, w] = bode(Gs);
%[Mp, k] = max(mag);
%pico_res = 20*log10(Mp)
%freq_res = w(k)
%i=1; 
%while 20*log10(mag(i))>=-3 
%    i=i+1; 
%end
%BW = w(i)

%7
%i = 0.1;
%while i<1
%    num = 100;
%    den = [1 2*i*10 100]
%    bode(num, den)
%    hold on;
%    i = i + 0.2;
%end
%legend('amortecimento = 0.1', 'amortecimento = 0.3', 'amortecimento = 0.5', 'amortecimento = 0.7', 'amortecimento = 0.9')

%8
num1 = 1;
den1 = [1 1 0];
Gs = tf(num1, den1)
bode(Gs)
hold on;
num2 = [1024 51.2];
den2 = [1000 1];
Cs = tf(num2, den2)
bode(Cs)
hold on;
num3 = [1024 51.2];
den3 = [1001 2000 0 0];
Rs = tf(num3, den3)
bode(Rs)
