% Abre a imagem
img_data = imread("ambience.jpeg");

% Deixa a imagem cinza
img_gray = double(rgb2gray(img_data));


% Figura colorida com filtro gaussian blur e media
figure;

subplot(1,3,1);
imshow(img_data);
title("Imagem original");

[r_gaussian, g_gaussian, b_gaussian] = color_gaussian_blur(img_data);
filtered_gaussian = cat(3, uint8(r_gaussian), uint8(g_gaussian), uint8(b_gaussian));
subplot(1,3,2);
imshow(filtered_gaussian);
title("Imagem + Gaussian Blur");

[r_mean, g_mean, b_mean] = color_mean(img_data);
filtered_mean = cat(3, uint8(r_mean), uint8(g_mean), uint8(b_mean));
subplot(1,3,3);
imshow(filtered_mean);
title("Imagem + Média");


% Figura cinza com filtro gaussian blur e media
figure;

subplot(1,3,1);
imshow(uint8(img_gray));
title("Imagem original cinza");

filtered_gaussian = gray_gaussian_blur(img_gray);
subplot(1,3,2);
imshow(uint8(filtered_gaussian));
title("Imagem cinza + Gaussian Blur");

filtered_mean = gray_mean(img_gray);
subplot(1,3,3);
imshow(uint8(filtered_mean));
title("Imagem cinza + Média");


% Figura colorida com ruido e filtro gaussian blur e media
noisy_image = imnoise(img_data, 'gaussian');

figure;

subplot(1,3,1);
imshow(noisy_image);
title("Imagem + ruído gaussiano");

[r_gaussian, g_gaussian, b_gaussian] = color_gaussian_blur(noisy_image);
filtered_gaussian = cat(3, uint8(r_gaussian), uint8(g_gaussian), uint8(b_gaussian));
subplot(1,3,2);
imshow(filtered_gaussian);
title("Imagem + ruído + Gaussian Blur");

[r_mean, g_mean, b_mean] = color_mean(noisy_image);
filtered_mean = cat(3, uint8(r_mean), uint8(g_mean), uint8(b_mean));
subplot(1,3,3);
imshow(filtered_mean);
title("Imagem + ruído + Média");


% Figura sem ruido com filtros Sobel
figure;

subplot(1,3,1);
imshow(img_data);
title("Imagem original");

filtered_sobel_x = sobel_x(img_gray);
subplot(1,3,2);
imshow(uint8(filtered_sobel_x));
title("Imagem + Sobel X");

filtered_sobel_y = sobel_y(img_gray);
subplot(1,3,3);
imshow(uint8(filtered_sobel_y));
title("Imagem + Sobel Y");


% Figura sem ruido com filtros Canny e Outline
figure;

subplot(1,3,1);
imshow(img_data);
title("Imagem original");

filtered_outline = outline(img_gray);
subplot(1,3,2);
imshow(uint8(filtered_outline));
title("Imagem + Outline");

filtered_canny = canny(img_gray);
subplot(1,3,3);
imshow(filtered_canny);
title("Imagem + Canny");


% Figura com ruido e filtros de outline/canny
noisy_img_gray = double(rgb2gray(noisy_image));

figure;

subplot(1,3,1);
imshow(noisy_image);
title("Imagem + ruído gaussiano");

filtered_outline = outline(noisy_img_gray);
subplot(1,3,2);
imshow(uint8(filtered_outline));
title("Imagem + ruído + Outline");

filtered_canny = canny(noisy_img_gray);
subplot(1,3,3);
imshow(filtered_canny);
title("Imagem + ruído + Canny");


% Figura com ruido + gaussian + bordas
noisy_img_gray = double(rgb2gray(noisy_image));
filtered_noisy_img_gray = gray_gaussian_blur(noisy_img_gray);

figure;

subplot(1,3,1);
imshow(noisy_image);
title("Imagem + ruído gaussiano");

filtered_outline = outline(filtered_noisy_img_gray);
subplot(1,3,2);
imshow(uint8(filtered_outline));
title("Imagem + ruído + Gaussian Blur + Outline");

filtered_canny = canny(filtered_noisy_img_gray);
subplot(1,3,3);
imshow(filtered_canny);
title("Imagem + ruído + Gaussian Blur + Canny");


% ------------------------------------------ % FUNCOES % ------------------------------------------ %

function [filtered_r_channel, filtered_g_channel, filtered_b_channel] = color_gaussian_blur(img_data)
    % Separa os 3 canais (red, green, blue) pra nao perder a coloracao da figura
    r_channel = double(img_data(:, :, 1));
    g_channel = double(img_data(:, :, 2));
    b_channel = double(img_data(:, :, 3));

    % Define o kernel
    kernel = 1/16.*[1 2 1; 2 4 2; 1 2 1];

    % Faz a convoluca em cada canal
    filtered_r_channel = conv2(r_channel, kernel);
    filtered_g_channel = conv2(g_channel, kernel);
    filtered_b_channel = conv2(b_channel, kernel);
end


function filtered_img = gray_gaussian_blur(img_gray)
    % Define o kernel
    kernel = 1/16.*[1 2 1; 2 4 2; 1 2 1];

    % Faz a convolucao
    filtered_img = conv2(img_gray, kernel);
end


function [filtered_r_channel, filtered_g_channel, filtered_b_channel] = color_mean(img_data)
    % Separa os 3 canais (red, green, blue) pra nao perder a coloracao da figura
    r_channel = double(img_data(:, :, 1));
    g_channel = double(img_data(:, :, 2));
    b_channel = double(img_data(:, :, 3));

    % Define o kernel
    kernel = [1/9 1/9 1/9; 1/9 1/9 1/9; 1/9 1/9 1/9];

    % Faz a convoluca em cada canal
    filtered_r_channel = conv2(r_channel, kernel);
    filtered_g_channel = conv2(g_channel, kernel);
    filtered_b_channel = conv2(b_channel, kernel);
end


function filtered_img = gray_mean(img_gray)
    % Define o kernel
    kernel = [1/9 1/9 1/9; 1/9 1/9 1/9; 1/9 1/9 1/9];

    % Faz a convolucao
    filtered_img = conv2(img_gray, kernel);
end


function filtered_img = sobel_x(img_gray)
    % Define o kernel
    kernel = [-1 0 1; -2 0 2; -1 0 1];

    % Faz a convolucao
    filtered_img = conv2(img_gray, kernel);
end


function filtered_img = sobel_y(img_gray)
    % Define o kernel
    kernel = [-1 -2 -1; 0 0 0; 1 2 1];

    % Faz a convolucao
    filtered_img = conv2(img_gray, kernel);
end


function filtered_img = outline(img_gray)
    % Define o kernel
    kernel = [-1 -1 -1; -1 8 -1; -1 -1 -1];

    % Faz a convolucao
    filtered_img = conv2(img_gray, kernel);
end


function filtered_img = canny(img_gray)
    filtered_img = edge(img_gray, 'canny');
end