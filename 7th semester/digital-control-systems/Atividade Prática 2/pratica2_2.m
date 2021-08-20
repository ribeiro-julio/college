num = 1;
den = [58.86e-9 94e-6 1];
tf_c = tf(num, den);
Fs = 1000;
Ts = 1/Fs;
sys_d = c2d(tf_c, Ts);
step(10*tf_c, 10*sys_d)