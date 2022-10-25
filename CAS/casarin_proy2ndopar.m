%% 
clear; close all; clc;


%% LOAD IMAGE
img = imread('beluga.jpg');
[rows, cols, channels] = size(img);

%% SPLIT RGB CHANNELS
R = img(:,:,1);
G = img(:,:,2);
B = img(:,:,3);


%% SHOW ONLY ONE CHANNEL
% figure(1);
% subplot(1,3,1); imshow(R); title('Red Channel');
% subplot(1,3,2); imshow(G); title('Green Channel');
% subplot(1,3,3); imshow(B); title('Blue Channel');

red_image = cat(3, R, zeros(size(R)), zeros(size(R)));
green_image = cat(3, zeros(size(G)), G, zeros(size(G)));
blue_image = cat(3, zeros(size(B)), zeros(size(B)), B);


%% SHOW FULL COLORS IN SUBPLOT
% figure(2);
% subplot(2,2,1); imshow(img); title('Original Image');
% subplot(2,2,2); imshow(red_image); title('Red Channel');
% subplot(2,2,3); imshow(green_image); title('Green Channel');
% subplot(2,2,4); imshow(blue_image); title('Blue Channel');


%% SAVE IMAGES
% imwrite(red_image, 'red_channel.jpg');
% imwrite(green_image, 'green_channel.jpg');
% imwrite(blue_image, 'blue_channel.jpg');


%% OBTAIN FOURIER TRANSFORM
red_fourier = fft2(R);
green_fourier = fft2(G);
blue_fourier = fft2(B);

red_fourier_c = log(1+abs(red_fourier));
green_fourier_c = log(1+abs(green_fourier));
blue_fourier_c = log(1+abs(blue_fourier));


%% SHOW FOURIER TRANSFORM 
% figure(2);
% subplot(2,2,1); imshow(red_fourier_c, []); title('Red Channel');
% subplot(2,2,2); imshow(green_fourier_c, []); title('Green Channel');
% subplot(2,2,3); imshow(blue_fourier_c, []); title('Blue Channel');


%% SHIFTED VERSION
red_fourier_shifted = fftshift(red_fourier);
green_fourier_shifted = fftshift(green_fourier);
blue_fourier_shifted = fftshift(blue_fourier);

red_fourier_shifted_c = log(1+abs(red_fourier_shifted));
green_fourier_shifted_c = log(1+abs(green_fourier_shifted));
blue_fourier_shifted_c = log(1+abs(blue_fourier_shifted));


%% SHOW SHIFTED FOURIER TRANSFORM
% figure(3);
% subplot(2,2,1); imshow(red_fourier_shifted_c, []); title('Red Channel');
% subplot(2,2,2); imshow(green_fourier_shifted_c, []); title('Green Channel');
% subplot(2,2,3); imshow(blue_fourier_shifted_c, []); title('Blue Channel');


%% SAVE SHIFTED IMAGES
min_lim = min(red_fourier_shifted_c(:));
max_lim = max(red_fourier_shifted_c(:));
fourier_shifted_s = (255/(max_lim-min_lim)).*(red_fourier_shifted_c-min_lim);
imwrite(uint8(fourier_shifted_s), 'red_channel_fourier.jpg');

min_lim = min(green_fourier_shifted_c(:));
max_lim = max(green_fourier_shifted_c(:));
fourier_shifted_s = (255/(max_lim-min_lim)).*(green_fourier_shifted_c-min_lim);
imwrite(uint8(fourier_shifted_s), 'green_channel_fourier.jpg');

min_lim = min(blue_fourier_shifted_c(:));
max_lim = max(blue_fourier_shifted_c(:));
fourier_shifted_s = (255/(max_lim-min_lim)).*(blue_fourier_shifted_c-min_lim);
imwrite(uint8(fourier_shifted_s), 'blue_channel_fourier.jpg');


%% FILTERING
img2 = imread('red_channel_fourier.jpg');
img2 = imresize(img2, [rows, cols])>128;
% figure(4); imshow(img2); title('Red Channel');
red_fourier_filtered = red_fourier_shifted.*img2;
red_fourier_filtered_c = log(1+abs(red_fourier_filtered));
% figure(5); imshow(red_fourier_filtered_c, []); title('Red Channel');

img3 = imread('green_channel_fourier.jpg');
img3 = imresize(img3, [rows, cols])>128;
% figure(6); imshow(img3); title('Green Channel');
green_fourier_filtered = green_fourier_shifted.*img3;
green_fourier_filtered_c = log(1+abs(green_fourier_filtered));
% figure(7); imshow(green_fourier_filtered_c, []); title('Green Channel');

img4 = imread('blue_channel_fourier.jpg');
img4 = imresize(img4, [rows, cols])>128;
% figure(8); imshow(img4); title('Blue Channel');
blue_fourier_filtered = blue_fourier_shifted.*img4;
blue_fourier_filtered_c = log(1+abs(blue_fourier_filtered));
% figure(9); imshow(blue_fourier_filtered_c, []); title('Blue Channel');


%% RECONSTRUCT IMAGE
red_fourier_filtered_shifted = ifftshift(red_fourier_filtered);
red_fourier_filtered_shifted_c = log(1+abs(red_fourier_filtered_shifted));
% figure(10); imshow(red_fourier_filtered_shifted_c, []); title('Red Channel');

green_fourier_filtered_shifted = ifftshift(green_fourier_filtered);
green_fourier_filtered_shifted_c = log(1+abs(green_fourier_filtered_shifted));
% figure(11); imshow(green_fourier_filtered_shifted_c, []); title('Green Channel');

blue_fourier_filtered_shifted = ifftshift(blue_fourier_filtered);
blue_fourier_filtered_shifted_c = log(1+abs(blue_fourier_filtered_shifted));
% figure(12); imshow(blue_fourier_filtered_shifted_c, []); title('Blue Channel');


%% SHOW INVERSE SHIFTED FILTERED SPECTRUM
% figure(5);
% subplot(2,2,1); imshow(red_fourier_filtered_shifted_c, []); title('Red Channel');
% subplot(2,2,2); imshow(green_fourier_filtered_shifted_c, []); title('Green Channel');
% subplot(2,2,3); imshow(blue_fourier_filtered_shifted, []); title('Blue Channel');


%% RECREATE IMAGE USING 3 CHANNELS
final_image = zeros(rows, cols, 3);
final_image(:,:,1) = ifft2(red_fourier_filtered_shifted);
final_image(:,:,2) = ifft2(green_fourier_filtered_shifted);
final_image(:,:,3) = ifft2(blue_fourier_filtered_shifted);

%% SHOW FINAL IMAGE
% figure(6); imshow(uint8(real(final_image))); title('Final Image');
% figure(7); imshow(uint8(real(img))); title('Original Image');

%% SAVE FINAL IMAGE
imwrite(uint8(real(final_image)), 'final_image.jpg');

%% SHOW ORIGINAL AND FINAL IMAGE
figure(7);
subplot(1,2,1); imshow(img); title('Original Image');
subplot(1,2,2); imshow(uint8(real(final_image))); title('Final Image');

