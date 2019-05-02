/* COMO COMPILAR:
 * g++ HolaMundo.cpp -o HolaMundo -std=c++17 -lzuazo -lavutil -lavformat -lavcodec -lswscale -lglfw -lMagick++-6.Q16 -lMagickWand-6.Q16 -lMagickCore-6.Q16
 */

#include<zuazo/Includes.h>
#include<cstdio>

int main(){
    zz::init(); //Inizializa Zuazo
    zz::begin(); //Comenzamos a configurar

    //Abre el primer dispositivo V4L2. Devuelve un std::unique_ptr
    auto fuente=zz::videoSourceFromFile("/dev/video0");
    
    //Crea una ventana con los parametros indicados
    zz::Utils::VideoMode modoDeVideo;
    modoDeVideo.res=zz::Utils::Resolution(1280, 720);
    modoDeVideo.frameRate=zz::Utils::Rational(30.0);
    zz::Consumers::Window ventana(modoDeVideo, "Hola Mundo");
    
    ventana.videoIn << fuente->videoOut; //Establece la entrada
    
    zz::end(); //Indicar que hemos terminado de configurar
    getchar(); //Esperar
    zz::begin(); //Comenzamos a configurar

    //Eliminar objetos antes de llamar a terminate()
    fuente.reset(); //Destruye "fuente"
    ventana.close();

    zz::end(); //Indicar que hemos terminado de configurar
    zz::terminate();
} 
