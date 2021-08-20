%Fs = 22050;
%time = 3;

%recording = audiorecorder(Fs, 16, 1);
%disp('Recording');
%recordblocking(recording, time);
%disp('End of recording');

%data = getaudiodata(recording);

%figure;
%plot(linspace(0, time, length(data)), data, '-o');
%title("Domínio do tempo")
%xlabel('Tempo (s)');
%ylabel('w(nT)');

%fourier = fft(data);

%figure
%plot(linspace(0, Fs, length(fourier)), real(fourier));

%figure
%plot(linspace(0, Fs, length(fourier)), real(fourier));
%xlim([0 Fs/2])
%title("Domínio da frequência")
%xlabel('Frequência (Hz)');
%ylabel('Magnitude');

%play(recording);

%[P, Q] = rat(11025/22050);
%sound(resample(data, P, Q), 11025);

%sound(data, 22050)

%[P, Q] = rat(44100/22050);
%sound(resample(data, P, Q), 44100);
