#/bin/bash

FLAGS="-std=c++17 -Wall -lzuazo -lavutil -lavformat -lavcodec -lswscale -lglfw $(/usr/lib/x86_64-linux-gnu/ImageMagick-6.9.10/bin-q16/Magick++-config --cppflags --cxxflags --ldflags --libs)"

echo "Compilando el código de la presentación"
g++ code/Presentacion.cpp code/Cuantizar.cpp -o Presentacion $FLAGS 

echo "Hecho."
