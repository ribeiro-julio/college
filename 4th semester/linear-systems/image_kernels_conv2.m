% Matrizes retiradas de: Filtros Lineares - Alexandre Xavier Falcao

% Abre a imagem
img_data = imread("lenna.png");

% Deixa a imagem cinza
img_gray = double(rgb2gray(img_data));

% Compara a imagem colorida/cinza com ambas filtradas por gaussian_blur
figure;
subplot(2,2,1);
imshow(img_data);
title("Imagem original");
[r_gaussian, g_gaussian, b_gaussian] = color_gaussian_blur(img_data);
filtered_color_gaussian = cat(3, uint8(r_gaussian), uint8(g_gaussian), uint8(b_gaussian));
subplot(2,2,2);
imshow(filtered_color_gaussian);
title("Imagem com filtro Gaussian Blur");
subplot(2,2,3);
imshow(uint8(img_gray));
title("Imagem original em escala de cinza");
filtered_gray_gaussian = gray_gaussian_blur(img_gray);
subplot(2,2,4);
imshow(uint8(filtered_gray_gaussian));
title("Imagem em escala de cinza com filtro Gaussian Blur");

% Compara a imagem colorida/cinza com ambas filtradas por mean
figure;
subplot(2,2,1);
imshow(img_data);
title("Imagem original");
[r_mean, g_mean, b_mean] = color_mean(img_data);
filtered_color_mean = cat(3, uint8(r_mean), uint8(g_mean), uint8(b_mean));
subplot(2,2,2);
imshow(filtered_color_mean);
title("Imagem com filtro Media");
subplot(2,2,3);
imshow(uint8(img_gray));
title("Imagem original em escala de cinza");
filtered_gray_mean = gray_mean(img_gray);
subplot(2,2,4);
imshow(uint8(filtered_gray_mean));
title("Imagem em escala de cinza com filtro Média");

% Compara a imagem filtrada por sobel_x, sobel_y e canny
filtered_sobel_x = sobel_x(img_gray);
filtered_sobel_y = sobel_y(img_gray);
%filtered_canny = canny(img_gray);
figure;
subplot(1,4,1);
imshow(img_data);
title("Imagem original");
subplot(1,4,2);
imshow(uint8(filtered_sobel_x));
title("Imagem com filtro Sobel X");
subplot(1,4,3);
imshow(uint8(filtered_sobel_y));
title("Imagem com filtro Sobel Y");
%subplot(1,4,4);
%imshow(uint8(filtered_canny));
%title("Imagem com filtro Canny");


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


function filtered_img = canny(img_gray)
    % Aplica o filtro gaussian blur (para diminuir o ruido)
    bluered = gray_gaussian_blur(img_gray);

    % Faz as deteccoes das bordas em x e y 
    res_sobel_x = sobel_x(bluered);
    res_sobel_y = sobel_y(bluered);

    gradient = sqrt(res_sobel_x^2 + res_sobel_y^2);
    gradient = gradient / max(gradient) * 255
    theta = atan(res_sobel_y/res_sobel_x);
   
end