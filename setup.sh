#/bin/bash

#Descargar archivos necesarios
echo "Descargando archivos necesarios..."
mkdir videos
wget https://download.blender.org/peach/bigbuckbunny_movies/big_buck_bunny_480p_h264.mov
mv big_buck_bunny_480p_h264.mov videos/big_buck_bunny.mov

#Compila la presentación de LaTex
echo "Compilando el la presentación en LaTex..."
cd tex
pdflatex presentacion.tex
pdflatex presentacion.tex #Hace 2 veces para mostrar correctamente la numeracion
cd ..

#Compila todo el código necesario
echo "Compilando el código de la presentación..."
FLAGS="-std=c++17 -Wall -lzuazo -lavutil -lavformat -lavcodec -lswscale -lglfw $(/usr/lib/x86_64-linux-gnu/ImageMagick-6.9.10/bin-q16/Magick++-config --cppflags --cxxflags --ldflags --libs)"
g++ code/Presentacion.cpp code/Cuantizar.cpp -o Presentacion $FLAGS 
g++ code/HolaMundo.cpp -o HolaMundo $FLAGS 
g++ code/Cuantizar.cpp code/CuantizarApp.cpp -o Cuantizar $FLAGS 

echo "¡Hecho!"
