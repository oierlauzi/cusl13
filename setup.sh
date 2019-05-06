#/bin/bash

mkdir videos

#Descargar archivos necesarios
echo "Descargando archivos necesarios..."
wget https://download.blender.org/peach/bigbuckbunny_movies/big_buck_bunny_1080p_h264.mov videos/big_buck_bunny.mov

#Compila la presentación de LaTex
echo "Compilando el la presentación en LaTex..."
cd tex
pdflatex presentacion.tex
cd ..

#Compila la aplicación de la presentación
echo "Compilando el código de la presentación..."
FLAGS="-std=c++17 -Wall -lzuazo -lavutil -lavformat -lavcodec -lswscale -lglfw $(/usr/lib/x86_64-linux-gnu/ImageMagick-6.9.10/bin-q16/Magick++-config --cppflags --cxxflags --ldflags --libs)"
g++ code/Presentacion.cpp -o Presentacion $FLAGS 

echo "¡Hecho!"