clear all; close all; clc;
%% Proyecto
I = imread('beluga.jpeg');
s = size(I);
%% Haciendo el tamaño par
if mod(s(1), 2) ~= 0 % Si s(1) es impar
    I = imresize(I, [s(1)-1, s(2)]);
end
s = size(I);
if mod(s(2),2) ~= 0 % Si s(2) es impar?
    I = imresize(I, [s(1), s(2)-1]);
end
s = size(I);
figure, imshow(I), title('Imagen original')

R = I(:,:,1);
G = I(:,:,2);
B = I(:,:,3);
figure
subplot(1,3,1)
imshow(R)
subplot(1,3,2)
imshow(G)
subplot(1,3,3)
imshow(B)
%% FFT sin desplazamiento R
FsdR = fft2(double(R));
FRshow = log(abs(FsdR) + 1);
figure, imshow(FRshow, []); title('FFT sin deplazamiento canal R')
%% FFT sin desplazamiento G
FsdG = fft2(double(G));
FGshow = log(abs(FsdG) + 1);
figure, imshow(FGshow, []); title('FFT sin deplazamiento canal G')
%% FFT sin desplazamiento B
FsdB = fft2(double(B));
FBshow = log(abs(FsdB) + 1);
figure, imshow(FBshow, []); title('FFT sin deplazamiento canal B')

%% Desplazando la FFt R
FR = fftshift(FsdR);
FRshow = log(abs(FR)+1);
figure, imshow(FRshow, []); title('FFT desplazada canal R')
minRshow = min(FRshow(:)); maxRshow = max(FRshow(:));
FRwrite = (255/(maxRshow-minRshow)).*(FRshow-minRshow);
%imwrite(uint8(FRwrite), 'C:\Users\Cliente10\Documents\Trabajos\Procesamiento Imágenes\canalR.png'); %% Guarda la imagen para crear el filtro con base a la desplazada
%% imwrite(uint8(FRwrite), 'canalR.png'); % Eduardo: Te recomiendo usar direcciones relativas para que otros puedan correr tu programa
%% Desplazando la FFt G
FG = fftshift(FsdG);
FGshow = log(abs(FG)+1);
figure, imshow(FGshow, []); title('FFT desplazada canal G')
minGshow = min(FGshow(:)); maxGshow = max(FGshow(:));
FGwrite = (255/(maxGshow-minGshow)).*(FGshow-minGshow);
%imwrite(uint8(FGwrite), 'C:\Users\Cliente10\Documents\Trabajos\Procesamiento Imágenes\canalG.png'); %% Guarda la imagen para crear el filtro con base a la desplazada
%% imwrite(uint8(FGwrite), 'canalG.png'); % Eduardo: Te recomiendo usar direcciones relativas
%% Desplazando la FFt B
FB = fftshift(FsdB);
FBshow = log(abs(FB)+1);
figure, imshow(FBshow, []); title('FFT desplazada canal B')
minBshow = min(FBshow(:)); maxBshow = max(FBshow(:));
FBwrite = (255/(maxBshow-minBshow)).*(FBshow-minBshow);
%imwrite(uint8(FBwrite), 'C:\Users\Cliente10\Documents\Trabajos\Procesamiento Imágenes\canalB.png'); %% Guarda la imagen para crear el filtro con base a la desplazada
%% imwrite(uint8(FBwrite), 'canalB.png'); % Eduardo: Te recomiendo usar direcciones relativas
%% Filtrando R
% f = imread('F1.bmp');
% f = imread('mascara.png')
f = imread('filter.png'); % Filtro aplicado
% f = 1-imresize(f, size(R)); %% 1-imresize(f, size(I)); para invertida
f = imresize(f, size(R))>128;  % Eduardo: La imagen se lee en uint8, pero necesitamos que sea booleano (valores 0s y 1s)
figure, imshow(f)
FR_f = FR.*f;
FR_f_show = log(abs(FR_f)+1);
figure, imshow(FR_f_show, []); title('FFT filtrada')
%% Filtrando G
% f = imread('F1.bmp');
% f = imread('mascara.png')
f = imread('filter.png'); % Filtro aplicado
% f = 1-imresize(f, size(R)); %% 1-imresize(f, size(I)); para invertida
f = imresize(f, size(G))>128;  % Eduardo: La imagen se lee en uint8, pero necesitamos que sea booleano (valores 0s y 1s)
FG_f = FG.*f;
FG_f_show = log(abs(FG_f)+1);
figure, imshow(FG_f_show, []); title('FFT filtrada')
%% Filtrando B
% f = imread('F1.bmp');
% f = imread('mascara.png')
f = imread('filter.png'); % Filtro aplicado
% f = 1-imresize(f, size(R)); %% 1-imresize(f, size(I)); para invertida
f = imresize(f, size(B))>128;  % Eduardo: La imagen se lee en uint8, pero necesitamos que sea booleano (valores 0s y 1s)
FB_f = FB.*f;
FB_f_show = log(abs(FB_f)+1);
figure, imshow(FB_f_show, []); title('FFT filtrada')


%% Reconstruyendo R
FR_f = fftshift(FR_f);
IR_f = ifft2(FR_f);
figure, imshow(IR_f, []), title('Imagen filtrada')
%% Reconstruyendo G
FG_f = fftshift(FG_f);
IG_f = ifft2(FG_f);
figure, imshow(IG_f, []), title('Imagen filtrada')
%% Reconstruyendo B
FB_f = fftshift(FB_f);
IB_f = ifft2(FB_f);
figure, imshow(IB_f, []), title('Imagen filtrada')

I_f = zeros(s(1), s(2), 3); % Eduardo: Lo comenté porque todavía no existen las variables IG_f e IB_f
I_f(:,:,1) = IR_f;
I_f(:,:,2) = IG_f;
I_f(:,:,3) = IB_f;

figure,imshow(uint8(real(I_f))), title('Imagen filtrada') % Eduardo: Muestra el resultado
