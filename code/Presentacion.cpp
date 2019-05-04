
/* COMO COMPILAR:
 * g++ Presentacion.cpp -o ../Presentacion -std=c++17 -lzuazo -lavutil -lavformat -lavcodec -lswscale -lglfw -lMagick++-6.Q16 -lMagickWand-6.Q16 -lMagickCore-6.Q16
 */ 

/*
 * Includes
 */
#include "Diapositivas.h"
#include "Pdf.h"

#include <zuazo/Includes.h>

#include <list>
#include <iostream>

using namespace Zuazo; //Nos ahorrara muchos zz::

/*
 * Directorios utiles
 */
const std::string pdfDir("tex/presentacion.pdf");
const std::string webcamDir("/dev/video0");
const std::string urdinDir("images/urdin.jpg");
const std::string bbbDir("videos/big_buck_bunny.mp4");

/*
 * Variables globales
 */
Video::DummyVideoPad salidaVideo;
Utils::VideoMode defaultVideoMode;
std::unique_ptr<Pdf> diapositivasPdf;

/*
 * Diapositivas
 */


int main(int argc, char* argv[]){
    //Inicializa zuazo
    zz::init();

    //Establecemos un modo de video para las ventanas
    Utils::VideoMode windowVideoMode{
        .res            =Utils::Resolution(1280, 960),
        .frameRate      =Utils::Rational(30.0),
    };

    zz::begin();
        //Crea dos ventanas para mostrar la salida
        Consumers::Window win1(windowVideoMode, "Ventana1");
        Consumers::Window win2(windowVideoMode, "Ventana2");
        //Modo de escalado
        win1.setScalingMode(Utils::ScalingMode::Boxed);
        win2.setScalingMode(Utils::ScalingMode::Boxed);
        //Filtro de escalado
        win1.setScalingFilter(Utils::ScalingFilter::Nearest);
        win2.setScalingFilter(Utils::ScalingFilter::Nearest);
        //Establecer salida de video
        win1.videoIn << salidaVideo;
        win2.videoIn << salidaVideo;

        //Obtine las pantallas disponibles en el sistema
        auto pantallas=Consumers::Window::Screen::getScreens();
    zz::end();
    
    //Muestralas:
    u_int32_t idx=0;
    for(auto ite=pantallas.begin(); ite != pantallas.end(); ++ite){
        auto& pantalla=*(*ite);
        std::cout 
            << idx++ <<": "                                                         //Indice
            << pantalla.getName()                                                   //Nombre
            << " (" << pantalla.getRes().width << "x" << pantalla.getRes().height   //Resolucion
            << "@" << static_cast<double>(pantalla.getRate()) << "Hz)"                  //Tasa de refresco
            << std::endl; 
    }

    std::cout << "Indice de la pantalla para Ventana1:";
    int scr=-1;
    //std::cin >> scr; std::cin.get(); ///////////////////////////////////////  DESCOMENTAR!!!!

    zz::begin();
        if(scr >= 0 && scr < (int)pantallas.size()){
            //Indice valido
            auto ite=pantallas.begin();
            std::advance(ite, scr);
            win1.setFullScreen(*ite);
        }

        win1.setFramerate(Utils::Rational(30.0)); //30Hz si o si, sino mi portatil sufre
        const auto& resolution=win1.getResolution();

        defaultVideoMode=Utils::VideoMode{
            .pixFmt         =Utils::PixelFormats::PIX_FMT_RGB32,
            .res            =resolution,
            .codec          =Utils::Codecs::CODEC_NONE, //No nos importa
            .frameRate      =Utils::Rational(30.0),
            .progressive    =true //No nos importa
        };

        //Carga el PDF
        std::cout << "Cargando el PDF..." << std::endl;
        double ppi=resolution.height * 25.4 / 96; //Altura por defecto en beamer = 96mm; 1in = 25.4mm
        diapositivasPdf=std::unique_ptr<Pdf>(new Pdf(pdfDir, round(ppi)));
        std::cout << "Listo! PPI:" << ppi << std::endl;

        //Carga las diapositivas
        std::cout << "Cargando las diapositivas..." << std::endl;
        auto diapositivas=GET_PRESENTACION(zzcusl13);
        auto ite=diapositivas.begin();
        (*ite)->onIn();
        std::cout << "Listo!" << std::endl;
    zz::end();

    char c;
    do{
        c=getchar();
        Context ctx;

        switch (c){
        case ('+'):
            if(ite != --diapositivas.end()){
                (*ite)->onOut();
                ++ite;
                (*ite)->onIn();
            }
            break;
        case ('-'):
            if(ite != diapositivas.begin()){
                (*ite)->onOut();
                --ite;
                (*ite)->onIn();
            }
            break;
        
        default:
            break;
        }
    }while(c != 'q');

    std::cout << "Saliendo..." << std::endl;

    //Cierra todo
    zz::begin();
        diapositivas.clear();
        diapositivasPdf.reset();
        win1.close();
        win2.close();
    zz::end();

    zz::terminate();

    std::cout << "Agur!" << std::endl;

    return 0;
}