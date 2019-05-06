/* COMO COMPILAR:
 * g++ CuantizarApp.cpp Cuantizar.cpp -o Cuantizar -std=c++17 -lzuazo -lavutil -lavformat -lavcodec -lswscale -lglfw -lMagick++-6.Q16 `/usr/lib/x86_64-linux-gnu/ImageMagick-6.9.10/bin-q16/Magick++-config --cppflags --cxxflags --ldflags --libs`
 */

#include<zuazo/Includes.h>
#include<cstdio>
#include <iostream>
#include "Cuantizar.h"

int main(){
    zz::init(); //Inizializa Zuazo
    zz::begin(); //Comenzamos a configurar

    //Abre el primer dispositivo V4L2. Devuelve un std::unique_ptr
    auto fuente=zz::videoSourceFromFile("/dev/video0");
    
    //Crea una ventana con los parametros indicados
    zz::Utils::VideoMode modoDeVideo;
    modoDeVideo.res=zz::Utils::Resolution(1280, 720);
    modoDeVideo.frameRate=zz::Utils::Rational(30.0);
    modoDeVideo.pixFmt=zz::Utils::PixelFormats::PIX_FMT_RGB32;

    zz::Consumers::Window ventana(modoDeVideo, "Cuantizar");
    Cuantizar cuant(modoDeVideo);
    
    cuant.videoIn << fuente->videoOut;
    ventana.videoIn  << cuant.videoOut;
    
    zz::end(); //Indicar que hemos terminado de configurar
    std::cout << cuant.getShaderLog(); //Muestra el log de la compilacion del shader
    getchar(); //Esperar
    zz::begin(); //Comenzamos a configurar

    //Eliminar objetos antes de llamar a terminate()
    fuente.reset(); //Destruye "fuente"
    ventana.close();
    cuant.close();
    
    zz::end(); //Indicar que hemos terminado de configurar
    zz::terminate();
}  
