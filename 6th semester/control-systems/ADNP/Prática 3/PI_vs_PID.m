numPI = [11.59 4.277e04];
denPI = [0.001629 0.485 0];
GcGsPI = tf(numPI, denPI)
GcGsPIMF = feedback(GcGsPI, 1)
step(GcGsPIMF);
hold on;

numPID = [0.0001899 11.59 5.448e04];
denPID = [0.001629 0.485 0];
GcGsPID = tf(numPID, denPID)
GcGsPIDMF = feedback(GcGsPID, 1)
step(GcGsPIDMF);