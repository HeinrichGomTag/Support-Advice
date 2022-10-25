%% 
clear; close all; clc;

%% LOAD IMAGE
img = imread('beluga.jpeg');
[rows, cols, channels] = size(img);

%% SPLIT RGB CHANNELS
R = img(:,:,1);
G = img(:,:,2);
B = img(:,:,3);

red_image = cat(3, R, zeros(size(R)), zeros(size(R)));
green_image = cat(3, zeros(size(G)), G, zeros(size(G)));
blue_image = cat(3, zeros(size(B)), zeros(size(B)), B);

%% SHOW IN SUBPLOT
figure(1);
subplot(2,2,1); imshow(img); title('Original Image');
subplot(2,2,2); imshow(red_image); title('Red Channel');
subplot(2,2,3); imshow(green_image); title('Green Channel');
subplot(2,2,4); imshow(blue_image); title('Blue Channel');

% %% SAVE IMAGES
% imwrite(red_image, 'red_channel.jpg');
% imwrite(green_image, 'green_channel.jpg');
% imwrite(blue_image, 'blue_channel.jpg');

% %% OBTAIN FOURIER TRANSFORM
% red_fourier = fft2(double(rgb2gray(red_image)));
% green_fourier = fft2(double(rgb2gray(green_image)));
% blue_fourier = fft2(double(rgb2gray(blue_image)));

% red_fourier_c = log(1+abs(fftshift(red_fourier)));
% green_fourier_c = log(1+abs(fftshift(green_fourier)));
% blue_fourier_c = log(1+abs(fftshift(blue_fourier)));

% figure(2);
% subplot(2,2,1); imshow(red_fourier_c, []); title('Red Channel');
% subplot(2,2,2); imshow(green_fourier_c, []); title('Green Channel');
% subplot(2,2,3); imshow(blue_fourier_c, []); title('Blue Channel');


% %% SHIFTED VERSION
% red_fourier_shifted = fftshift(red_fourier);
% green_fourier_shifted = fftshift(green_fourier);
% blue_fourier_shifted = fftshift(blue_fourier);

% red_fourier_shifted_c = log(1+abs(red_fourier_shifted));
% green_fourier_shifted_c = log(1+abs(green_fourier_shifted));
% blue_fourier_shifted_c = log(1+abs(blue_fourier_shifted));

% % figure(3);
% % subplot(2,2,1); imshow(red_fourier_shifted_c, []); title('Red Channel');
% % subplot(2,2,2); imshow(green_fourier_shifted_c, []); title('Green Channel');
% % subplot(2,2,3); imshow(blue_fourier_shifted_c, []); title('Blue Channel');

% min_lim = min(red_fourier_shifted_c(:));
% max_lim = max(red_fourier_shifted_c(:));
% fourier_shifted_s = (255/(max_lim-min_lim)).*(red_fourier_shifted_c-min_lim);
% imwrite(uint8(fourier_shifted_s), 'red_channel_fourier.jpg');

% min_lim = min(green_fourier_shifted_c(:));
% max_lim = max(green_fourier_shifted_c(:));
% fourier_shifted_s = (255/(max_lim-min_lim)).*(green_fourier_shifted_c-min_lim);
% imwrite(uint8(fourier_shifted_s), 'green_channel_fourier.jpg');

% min_lim = min(blue_fourier_shifted_c(:));
% max_lim = max(blue_fourier_shifted_c(:));
% fourier_shifted_s = (255/(max_lim-min_lim)).*(blue_fourier_shifted_c-min_lim);
% imwrite(uint8(fourier_shifted_s), 'blue_channel_fourier.jpg');


% %% FILTERING
% filter = imread('filter.png');
% filter = imresize(filter, [rows, cols]);
% % figure(4); imshow(filter); title('Filter');

% red_fourier_filtered = red_fourier_shifted.*filter;
% red_fourier_filtered_c = log(1+abs(red_fourier_filtered));

% green_fourier_filtered = green_fourier_shifted.*filter;
% green_fourier_filtered_c = log(1+abs(green_fourier_filtered));

% blue_fourier_filtered = blue_fourier_shifted.*filter;
% blue_fourier_filtered_c = log(1+abs(blue_fourier_filtered));


% figure(5);
% subplot(2,2,1); imshow(red_fourier_shifted_c, []); title('Red Channel');
% subplot(2,2,2); imshow(green_fourier_filtered_c, []); title('Green Channel');
% subplot(2,2,3); imshow(blue_fourier_filtered_c, []); title('Blue Channel');


