% Matrizes retiradas de: Filtros Lineares - Alexandre Xavier Falcao

%canny = ;
%sobel = ;

% Abre a imagem
img_data = imread("lenna.png");

% Deixa a imagem cinza
img_gray = double(rgb2gray(img_data));

% Compara a imagem colorida sem filtro e com filtro
figure;
subplot(1,2,1);
imshow(img_data);
[r_gaussian, g_gaussian, b_gaussian] = color_mean(img_data);
color_gaussian = cat(3, uint8(r_gaussian), uint8(g_gaussian), uint8(b_gaussian));
subplot(1,2,2);
imshow(color_gaussian);

% Compara a imagem cinza sem filtro e com filtro
figure;
subplot(1,2,1);
imshow(uint8(img_gray));
gray_gaussian = gray_mean(img_gray);
subplot(1,2,2);
imshow(uint8(gray_gaussian));


function [filtered_r_channel, filtered_g_channel, filtered_b_channel] = color_gaussian_blur(img_data)
    % Separa os 3 canais (red, green, blue) pra nao perder a coloracao da figura
    r_channel = double(img_data(:, :, 1));
    g_channel = double(img_data(:, :, 2));
    b_channel = double(img_data(:, :, 3));

    % Pega as dimensoes do vetor da imagem
    dimensions = size(img_data);
    img_rows = dimensions(1);
    img_pixels = dimensions(2);

    % Define o kernel
    kernel = 1/16.*[1 2 1; 2 4 2; 1 2 1];

    % Define o centro da matriz do kernel
    kernel_center_x = 2;
    kernel_center_y = 2;
    
    for i_i = 1:img_rows
        for i_j = 1:img_pixels
            for k_i = 1:3
                for k_j = 1:3
                    i = i_i+(k_i-kernel_center_x);
                    j = i_j+(k_j-kernel_center_y);
                    if(i >= 1 && i <= img_rows && j >= 1 && j <= img_pixels)
                        r_channel(i_i, i_j) = r_channel(i_i, i_j) + r_channel(i, j)*kernel(k_i, k_j);
                        g_channel(i_i, i_j) = g_channel(i_i, i_j) + g_channel(i, j)*kernel(k_i, k_j);
                        b_channel(i_i, i_j) = b_channel(i_i, i_j) + b_channel(i, j)*kernel(k_i, k_j);
                    end
                end
            end
        end
    end

    filtered_r_channel = r_channel;
    filtered_g_channel = g_channel;
    filtered_b_channel = b_channel;
end


function filtered_img = gray_gaussian_blur(img_gray)
    % Pega as dimensoes do vetor da imagem
    dimensions = size(img_gray);
    img_rows = dimensions(1);
    img_pixels = dimensions(2);

    % Define o kernel
    kernel = 1/16.*[1 2 1; 2 4 2; 1 2 1];

    % Define o centro da matriz do kernel
    kernel_center_x = 2;
    kernel_center_y = 2;

    for i_i = 1:img_rows
        for i_j = 1:img_pixels
            for k_i = 1:3
                for k_j = 1:3
                    i = i_i+(k_i-kernel_center_x);
                    j = i_j+(k_j-kernel_center_y);
                    if(i >= 1 && i <= img_rows && j >= 1 && j <= img_pixels)
                        img_gray(i_i, i_j) = img_gray(i_i, i_j) + img_gray(i, j)*kernel(k_i, k_j);
                    end
                end
            end
        end
    end

    filtered_img = img_gray;
end


function [filtered_r_channel, filtered_g_channel, filtered_b_channel] = color_mean(img_data)
    % Separa os 3 canais (red, green, blue) pra nao perder a coloracao da figura
    r_channel = double(img_data(:, :, 1));
    g_channel = double(img_data(:, :, 2));
    b_channel = double(img_data(:, :, 3));

    % Pega as dimensoes do vetor da imagem
    dimensions = size(img_data);
    img_rows = dimensions(1);
    img_pixels = dimensions(2);

    % Define o kernel
    kernel = [1/9 1/9 1/9; 1/9 1/9 1/9; 1/9 1/9 1/9];

    % Define o centro da matriz do kernel
    kernel_center_x = 2;
    kernel_center_y = 2;
    
    for i_i = 1:img_rows
        for i_j = 1:img_pixels
            for k_i = 1:3
                for k_j = 1:3
                    i = i_i+(k_i-kernel_center_x);
                    j = i_j+(k_j-kernel_center_y);
                    if(i >= 1 && i <= img_rows && j >= 1 && j <= img_pixels)
                        r_channel(i_i, i_j) = r_channel(i_i, i_j) + r_channel(i, j)*kernel(k_i, k_j);
                        g_channel(i_i, i_j) = g_channel(i_i, i_j) + g_channel(i, j)*kernel(k_i, k_j);
                        b_channel(i_i, i_j) = b_channel(i_i, i_j) + b_channel(i, j)*kernel(k_i, k_j);
                    end
                end
            end
        end
    end

    filtered_r_channel = r_channel;
    filtered_g_channel = g_channel;
    filtered_b_channel = b_channel;
end


function filtered_img = gray_mean(img_gray)
    % Pega as dimensoes do vetor da imagem
    dimensions = size(img_gray);
    img_rows = dimensions(1);
    img_pixels = dimensions(2);

    % Define o kernel
    kernel = [1/9 1/9 1/9; 1/9 1/9 1/9; 1/9 1/9 1/9];

    % Define o centro da matriz do kernel
    kernel_center_x = 2;
    kernel_center_y = 2;

    for i_i = 1:img_rows
        for i_j = 1:img_pixels
            for k_i = 1:3
                for k_j = 1:3
                    i = i_i+(k_i-kernel_center_x);
                    j = i_j+(k_j-kernel_center_y);
                    if(i >= 1 && i <= img_rows && j >= 1 && j <= img_pixels)
                        img_gray(i_i, i_j) = img_gray(i_i, i_j) + img_gray(i, j)*kernel(k_i, k_j);
                    end
                end
            end
        end
    end

    filtered_img = img_gray;
end
