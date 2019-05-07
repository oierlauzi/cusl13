#pragma once

#include "Diapositiva.h"
#include "Pdf.h"
#include "Cuantizar.h"

#include <zuazo/Includes.h>



extern zz::Utils::Vec2f                            resolucion;
extern zz::Utils::VideoMode                        defaultVideoMode;

extern zz::Video::DummyVideoPad                    salidaVideo;
extern std::unique_ptr<Pdf>                        diapositivasPdf;

extern std::unique_ptr<zz::Sources::FFmpeg>        player;
extern std::unique_ptr<zz::Sources::ImageMagick>   image;
extern std::unique_ptr<zz::Sources::V4L2>          webcam;

extern std::unique_ptr<zz::Processors::ChromaKey>  chroma;
extern std::unique_ptr<zz::Processors::Compositor> comp;

#define DEFAULT_DIAPOSITIVA(x, n)                   \
    DIAP_BEGIN(x)                                   \
        DIAP_ONIN_BEGIN                             \
            salidaVideo<<diapositivasPdf->videoOut; \
            diapositivasPdf->ir_a(n);               \
        DIAP_ONIN_END                               \
        DIAP_ONOUT_BEGIN                            \
            salidaVideo<<nullptr;                   \
        DIAP_ONOUT_END                              \
    DIAP_END(x)                                     


/*
 * ¿Quien necesita LaTex cuando tiene el preprocesador de C?
 */

PRESENTACION_BEGIN(zzcusl13)

    //Diapositiva1
    DEFAULT_DIAPOSITIVA(Diapositiva1, 1)

    //Diapositiva2
    DEFAULT_DIAPOSITIVA(Diapositiva2, 2)

    //Diapositiva3
    DEFAULT_DIAPOSITIVA(Diapositiva3, 3)

    //Diapositiva4
    DEFAULT_DIAPOSITIVA(Diapositiva4, 4)

    //Diapositiva5
    DEFAULT_DIAPOSITIVA(Diapositiva5, 5)

    //Diapositiva6
    DEFAULT_DIAPOSITIVA(Diapositiva6, 6)

    //Diapositiva7
    DEFAULT_DIAPOSITIVA(Diapositiva7, 7)

    //Diapositiva8
    DEFAULT_DIAPOSITIVA(Diapositiva8, 8)

    //Diapositiva9
    DEFAULT_DIAPOSITIVA(Diapositiva9, 9)

    //Diapositiva10
    DEFAULT_DIAPOSITIVA(Diapositiva10, 10)

    //Diapositiva11
    DEFAULT_DIAPOSITIVA(Diapositiva11, 11)

    //Diapositiva12
    DEFAULT_DIAPOSITIVA(Diapositiva12, 12)

    //Diapositiva13
    DEFAULT_DIAPOSITIVA(Diapositiva13, 13)

    //Diapositiva14
    DEFAULT_DIAPOSITIVA(Diapositiva14, 14)

    //Diapositiva15
    DEFAULT_DIAPOSITIVA(Diapositiva15, 15)

    //Diapositiva16
    DEFAULT_DIAPOSITIVA(Diapositiva16, 16)

    //Diapositiva17
    DEFAULT_DIAPOSITIVA(Diapositiva17, 17)

    //Diapositiva18
    DEFAULT_DIAPOSITIVA(Diapositiva18, 18)

    //Diapositiva19
    DEFAULT_DIAPOSITIVA(Diapositiva19, 19)

    //Diapositiva20
    DEFAULT_DIAPOSITIVA(Diapositiva20, 20)

    //Diapositiva21
    DEFAULT_DIAPOSITIVA(Diapositiva21, 21)

    //Diapositiva22
    DEFAULT_DIAPOSITIVA(Diapositiva22, 22)

    //Diapositiva23
    DEFAULT_DIAPOSITIVA(Diapositiva23, 23)

    //Diapositiva24
    DEFAULT_DIAPOSITIVA(Diapositiva24, 24)

    //Diapositiva25
    DEFAULT_DIAPOSITIVA(Diapositiva25, 25)

    //Diapositiva26
    DEFAULT_DIAPOSITIVA(Diapositiva26, 26)

    //Diapositiva27
    DIAP_BEGIN(Diapositiva27)
        DIAP_PRIV_OBJ_BEGIN
        DIAP_PRIV_OBJ_END
        DIAP_ONIN_BEGIN
            //Establece los tamaños
            zz::Graphics::Rectangle bkgdRect{
                .size=resolucion
            };

            zz::Graphics::Rectangle vidPlaneRect{
                .size=resolucion / 3.0f
            };

            //Crea y configura las capas
            auto bkgd=std::make_shared<zz::Processors::Compositor::VideoLayer>(bkgdRect);
            bkgd->videoIn << diapositivasPdf->videoOut;
            bkgd->setAnchorage(zz::Utils::Vec3f(bkgdRect.size / 2.0f, 0.0));
            bkgd->setScalingMode(zz::Utils::ScalingMode::Boxed);

            auto vidPlane=std::make_shared<zz::Processors::Compositor::VideoLayer>(vidPlaneRect);
            vidPlane->videoIn << player->videoOut;
            vidPlane->setScalingMode(zz::Utils::ScalingMode::Boxed);
            vidPlane->setPosition(zz::Utils::Vec3f(0, -resolucion.y / 4.0f, 1.0));
            vidPlane->setAnchorage(zz::Utils::Vec3f(vidPlaneRect.size / 2.0f, 0.0));

            //Mete las capas en el compositor
            std::vector<std::shared_ptr<zz::Processors::Compositor::LayerBase>> capas;
            capas.push_back(bkgd);
            capas.push_back(vidPlane);
            comp->setLayers(capas);

            salidaVideo<<comp->videoOut;
            diapositivasPdf->ir_a(27);
            player->setState(zz::NonLinearUpdate::States::Playing);
        DIAP_ONIN_END
        DIAP_ONOUT_BEGIN
            salidaVideo<<nullptr;
            player->setState(zz::NonLinearUpdate::States::Paused);
        DIAP_ONOUT_END
    DIAP_END(Diapositiva27)

    //Diapositiva28
    DIAP_BEGIN(Diapositiva28)
        DIAP_PRIV_OBJ_BEGIN
        DIAP_PRIV_OBJ_END
        DIAP_ONIN_BEGIN
            //Establece los tamaños
            zz::Graphics::Rectangle bkgdRect{
                .size=resolucion
            };

            zz::Graphics::Rectangle vidPlaneRect{
                .size=resolucion / 3.0f
            };

            //Crea y configura las capas
            auto bkgd=std::make_shared<zz::Processors::Compositor::VideoLayer>(bkgdRect);
            bkgd->videoIn << diapositivasPdf->videoOut;
            bkgd->setAnchorage(zz::Utils::Vec3f(bkgdRect.size / 2.0f, 0.0));
            bkgd->setScalingMode(zz::Utils::ScalingMode::Boxed);

            auto vidPlane=std::make_shared<zz::Processors::Compositor::VideoLayer>(vidPlaneRect);
            vidPlane->videoIn << image->videoOut;
            vidPlane->setScalingMode(zz::Utils::ScalingMode::Boxed);
            vidPlane->setPosition(zz::Utils::Vec3f(0, -resolucion.y / 4.0f, 1.0));
            vidPlane->setAnchorage(zz::Utils::Vec3f(vidPlaneRect.size / 2.0f, 0.0));

            //Mete las capas en el compositor
            std::vector<std::shared_ptr<zz::Processors::Compositor::LayerBase>> capas;
            capas.push_back(bkgd);
            capas.push_back(vidPlane);
            comp->setLayers(capas);

            salidaVideo<<comp->videoOut;
            diapositivasPdf->ir_a(28);
        DIAP_ONIN_END
        DIAP_ONOUT_BEGIN
            salidaVideo<<nullptr;
        DIAP_ONOUT_END
    DIAP_END(Diapositiva28)


    //Diapositiva29
    DIAP_BEGIN(Diapositiva29)
        DIAP_PRIV_OBJ_BEGIN
        DIAP_PRIV_OBJ_END
        DIAP_ONIN_BEGIN
            //Establece los tamaños
            zz::Graphics::Rectangle bkgdRect{
                .size=resolucion
            };

            zz::Graphics::Rectangle vidPlaneRect{
                .size=resolucion / 3.0f
            };

            //Crea y configura las capas
            auto bkgd=std::make_shared<zz::Processors::Compositor::VideoLayer>(bkgdRect);
            bkgd->videoIn << diapositivasPdf->videoOut;
            bkgd->setAnchorage(zz::Utils::Vec3f(bkgdRect.size / 2.0f, 0.0));
            bkgd->setScalingMode(zz::Utils::ScalingMode::Boxed);

            auto vidPlane=std::make_shared<zz::Processors::Compositor::VideoLayer>(vidPlaneRect);
            vidPlane->videoIn << webcam->videoOut;
            vidPlane->setScalingMode(zz::Utils::ScalingMode::Boxed);
            vidPlane->setPosition(zz::Utils::Vec3f(0, -resolucion.y / 4.0f, 1.0));
            vidPlane->setAnchorage(zz::Utils::Vec3f(vidPlaneRect.size / 2.0f, 0.0));

            //Mete las capas en el compositor
            std::vector<std::shared_ptr<zz::Processors::Compositor::LayerBase>> capas;
            capas.push_back(bkgd);
            capas.push_back(vidPlane);
            comp->setLayers(capas);

            salidaVideo<<comp->videoOut;
            diapositivasPdf->ir_a(29);
        DIAP_ONIN_END
        DIAP_ONOUT_BEGIN
            salidaVideo<<nullptr;
        DIAP_ONOUT_END
    DIAP_END(Diapositiva29)

    //Diapositiva30
    DEFAULT_DIAPOSITIVA(Diapositiva30, 30)

    //Diapositiva31
    DIAP_BEGIN(Diapositiva31)
        DIAP_PRIV_OBJ_BEGIN
            std::unique_ptr<zz::Processors::HueSaturationLuminosity> m_fx;
        DIAP_PRIV_OBJ_END
        DIAP_ONIN_BEGIN
            //Crea y configura el efecto
            m_fx=std::make_unique<zz::Processors::HueSaturationLuminosity>(defaultVideoMode);
            m_fx->setHue(120);
            m_fx->setSaturation(1.5);
            m_fx->videoIn << webcam->videoOut;

            //Establece los tamaños
            zz::Graphics::Rectangle bkgdRect{
                .size=resolucion
            };

            zz::Graphics::Rectangle vidPlaneRect{
                .size=resolucion / 3.0f
            };
            //Crea y configura las capas
            auto bkgd=std::make_shared<zz::Processors::Compositor::VideoLayer>(bkgdRect);
            bkgd->videoIn << diapositivasPdf->videoOut;
            bkgd->setAnchorage(zz::Utils::Vec3f(bkgdRect.size / 2.0f, 0.0));
            bkgd->setScalingMode(zz::Utils::ScalingMode::Boxed);

            auto vidPlane=std::make_shared<zz::Processors::Compositor::VideoLayer>(vidPlaneRect);
            vidPlane->videoIn << m_fx->videoOut;
            vidPlane->setScalingMode(zz::Utils::ScalingMode::Boxed);
            vidPlane->setPosition(zz::Utils::Vec3f(0, -resolucion.y / 4.0f, 1.0));
            vidPlane->setAnchorage(zz::Utils::Vec3f(vidPlaneRect.size / 2.0f, 0.0));

            //Mete las capas en el compositor
            std::vector<std::shared_ptr<zz::Processors::Compositor::LayerBase>> capas;
            capas.push_back(bkgd);
            capas.push_back(vidPlane);
            comp->setLayers(capas);

            salidaVideo<<comp->videoOut;
            diapositivasPdf->ir_a(31);
        DIAP_ONIN_END
        DIAP_ONOUT_BEGIN
            m_fx.reset();
            salidaVideo<<nullptr;
        DIAP_ONOUT_END
    DIAP_END(Diapositiva31)

    //Diapositiva32
    DIAP_BEGIN(Diapositiva32)
        DIAP_PRIV_OBJ_BEGIN
            std::unique_ptr<zz::Processors::BrightnessContrast> m_fx;
        DIAP_PRIV_OBJ_END
        DIAP_ONIN_BEGIN
            //Crea y configura el efecto
            m_fx=std::make_unique<zz::Processors::BrightnessContrast>(defaultVideoMode);
            m_fx->setBrightness(0.8);
            m_fx->setContrast(0.8);
            m_fx->videoIn << image->videoOut;

            //Establece los tamaños
            zz::Graphics::Rectangle bkgdRect{
                .size=resolucion
            };

            zz::Graphics::Rectangle vidPlaneRect{
                .size=resolucion / 3.0f
            };
            //Crea y configura las capas
            auto bkgd=std::make_shared<zz::Processors::Compositor::VideoLayer>(bkgdRect);
            bkgd->videoIn << diapositivasPdf->videoOut;
            bkgd->setAnchorage(zz::Utils::Vec3f(bkgdRect.size / 2.0f, 0.0));
            bkgd->setScalingMode(zz::Utils::ScalingMode::Boxed);

            auto vidPlane=std::make_shared<zz::Processors::Compositor::VideoLayer>(vidPlaneRect);
            vidPlane->videoIn << m_fx->videoOut;
            vidPlane->setScalingMode(zz::Utils::ScalingMode::Boxed);
            vidPlane->setPosition(zz::Utils::Vec3f(0, -resolucion.y / 4.0f, 1.0));
            vidPlane->setAnchorage(zz::Utils::Vec3f(vidPlaneRect.size / 2.0f, 0.0));

            //Mete las capas en el compositor
            std::vector<std::shared_ptr<zz::Processors::Compositor::LayerBase>> capas;
            capas.push_back(bkgd);
            capas.push_back(vidPlane);
            comp->setLayers(capas);

            salidaVideo<<comp->videoOut;
            diapositivasPdf->ir_a(32);
        DIAP_ONIN_END
        DIAP_ONOUT_BEGIN
            m_fx.reset();
            salidaVideo<<nullptr;
        DIAP_ONOUT_END
    DIAP_END(Diapositiva32)

    //Diapositiva33
    DIAP_BEGIN(Diapositiva33)
        DIAP_PRIV_OBJ_BEGIN
            std::unique_ptr<zz::Processors::Grayscale> m_fx;
        DIAP_PRIV_OBJ_END
        DIAP_ONIN_BEGIN
            //Crea y configura el efecto
            m_fx=std::make_unique<zz::Processors::Grayscale>(defaultVideoMode);
            m_fx->videoIn << player->videoOut;

            //Establece los tamaños
            zz::Graphics::Rectangle bkgdRect{
                .size=resolucion
            };

            zz::Graphics::Rectangle vidPlaneRect{
                .size=resolucion / 3.0f
            };
            //Crea y configura las capas
            auto bkgd=std::make_shared<zz::Processors::Compositor::VideoLayer>(bkgdRect);
            bkgd->videoIn << diapositivasPdf->videoOut;
            bkgd->setAnchorage(zz::Utils::Vec3f(bkgdRect.size / 2.0f, 0.0));
            bkgd->setScalingMode(zz::Utils::ScalingMode::Boxed);

            auto vidPlane=std::make_shared<zz::Processors::Compositor::VideoLayer>(vidPlaneRect);
            vidPlane->videoIn << m_fx->videoOut;
            vidPlane->setScalingMode(zz::Utils::ScalingMode::Boxed);
            vidPlane->setPosition(zz::Utils::Vec3f(0, -resolucion.y / 4.0f, 1.0));
            vidPlane->setAnchorage(zz::Utils::Vec3f(vidPlaneRect.size / 2.0f, 0.0));

            //Mete las capas en el compositor
            std::vector<std::shared_ptr<zz::Processors::Compositor::LayerBase>> capas;
            capas.push_back(bkgd);
            capas.push_back(vidPlane);
            comp->setLayers(capas);

            salidaVideo<<comp->videoOut;
            diapositivasPdf->ir_a(33);
            player->setState(zz::NonLinearUpdate::States::Playing);
        DIAP_ONIN_END
        DIAP_ONOUT_BEGIN
            m_fx.reset();
            salidaVideo<<nullptr;
            player->setState(zz::NonLinearUpdate::States::Paused);
        DIAP_ONOUT_END
    DIAP_END(Diapositiva33)

    //Diapositiva34
    DIAP_BEGIN(Diapositiva34)
        DIAP_PRIV_OBJ_BEGIN
        DIAP_PRIV_OBJ_END
        DIAP_ONIN_BEGIN
            //Establece los tamaños
            zz::Graphics::Rectangle bkgdRect{
                .size=resolucion
            };

            zz::Graphics::Rectangle vidPlaneRect{
                .size=resolucion / 3.0f
            };
            //Crea y configura las capas
            auto bkgd=std::make_shared<zz::Processors::Compositor::VideoLayer>(bkgdRect);
            bkgd->videoIn << diapositivasPdf->videoOut;
            bkgd->setAnchorage(zz::Utils::Vec3f(bkgdRect.size / 2.0f, 0.0));
            bkgd->setScalingMode(zz::Utils::ScalingMode::Boxed);

            auto vidPlane=std::make_shared<zz::Processors::Compositor::VideoLayer>(vidPlaneRect);
            vidPlane->videoIn << chroma->videoOut;
            vidPlane->setScalingMode(zz::Utils::ScalingMode::Boxed);
            vidPlane->setPosition(zz::Utils::Vec3f(0, -resolucion.y / 4.0f, 1.0));
            vidPlane->setAnchorage(zz::Utils::Vec3f(vidPlaneRect.size / 2.0f, 0.0));

            //Mete las capas en el compositor
            std::vector<std::shared_ptr<zz::Processors::Compositor::LayerBase>> capas;
            capas.push_back(bkgd);
            capas.push_back(vidPlane);
            comp->setLayers(capas);

            salidaVideo<<comp->videoOut;
            diapositivasPdf->ir_a(34);
        DIAP_ONIN_END
        DIAP_ONOUT_BEGIN
            salidaVideo<<nullptr;
        DIAP_ONOUT_END
    DIAP_END(Diapositiva34)

    //Diapositiva35
    DIAP_BEGIN(Diapositiva35)
        DIAP_PRIV_OBJ_BEGIN
            std::unique_ptr<zz::Processors::Alpha2Luma> m_fx;
        DIAP_PRIV_OBJ_END
        DIAP_ONIN_BEGIN
            //Crea y configura el efecto
            m_fx=std::make_unique<zz::Processors::Alpha2Luma>(defaultVideoMode);
            m_fx->videoIn << chroma->videoOut;

            //Establece los tamaños
            zz::Graphics::Rectangle bkgdRect{
                .size=resolucion
            };

            zz::Graphics::Rectangle vidPlaneRect{
                .size=resolucion / 3.0f
            };
            //Crea y configura las capas
            auto bkgd=std::make_shared<zz::Processors::Compositor::VideoLayer>(bkgdRect);
            bkgd->videoIn << diapositivasPdf->videoOut;
            bkgd->setAnchorage(zz::Utils::Vec3f(bkgdRect.size / 2.0f, 0.0));
            bkgd->setScalingMode(zz::Utils::ScalingMode::Boxed);

            auto vidPlane=std::make_shared<zz::Processors::Compositor::VideoLayer>(vidPlaneRect);
            vidPlane->videoIn << m_fx->videoOut;
            vidPlane->setScalingMode(zz::Utils::ScalingMode::Boxed);
            vidPlane->setPosition(zz::Utils::Vec3f(0, -resolucion.y / 4.0f, 1.0));
            vidPlane->setAnchorage(zz::Utils::Vec3f(vidPlaneRect.size / 2.0f, 0.0));

            //Mete las capas en el compositor
            std::vector<std::shared_ptr<zz::Processors::Compositor::LayerBase>> capas;
            capas.push_back(bkgd);
            capas.push_back(vidPlane);
            comp->setLayers(capas);

            salidaVideo<<comp->videoOut;
            diapositivasPdf->ir_a(35);
        DIAP_ONIN_END
        DIAP_ONOUT_BEGIN
            m_fx.reset();
            salidaVideo<<nullptr;
        DIAP_ONOUT_END
    DIAP_END(Diapositiva35)

    //Diapositiva36
    DIAP_BEGIN(Diapositiva36)
        DIAP_PRIV_OBJ_BEGIN
            std::unique_ptr<zz::Processors::Invert> m_fx;
        DIAP_PRIV_OBJ_END
        DIAP_ONIN_BEGIN
            //Crea y configura el efecto
            m_fx=std::make_unique<zz::Processors::Invert>(defaultVideoMode);
            m_fx->videoIn << player->videoOut;

            //Establece los tamaños
            zz::Graphics::Rectangle bkgdRect{
                .size=resolucion
            };

            zz::Graphics::Rectangle vidPlaneRect{
                .size=resolucion / 3.0f
            };
            //Crea y configura las capas
            auto bkgd=std::make_shared<zz::Processors::Compositor::VideoLayer>(bkgdRect);
            bkgd->videoIn << diapositivasPdf->videoOut;
            bkgd->setAnchorage(zz::Utils::Vec3f(bkgdRect.size / 2.0f, 0.0));
            bkgd->setScalingMode(zz::Utils::ScalingMode::Boxed);

            auto vidPlane=std::make_shared<zz::Processors::Compositor::VideoLayer>(vidPlaneRect);
            vidPlane->videoIn << m_fx->videoOut;
            vidPlane->setScalingMode(zz::Utils::ScalingMode::Boxed);
            vidPlane->setPosition(zz::Utils::Vec3f(0, -resolucion.y / 4.0f, 1.0));
            vidPlane->setAnchorage(zz::Utils::Vec3f(vidPlaneRect.size / 2.0f, 0.0));

            //Mete las capas en el compositor
            std::vector<std::shared_ptr<zz::Processors::Compositor::LayerBase>> capas;
            capas.push_back(bkgd);
            capas.push_back(vidPlane);
            comp->setLayers(capas);

            salidaVideo<<comp->videoOut;
            diapositivasPdf->ir_a(36);
            player->setState(zz::NonLinearUpdate::States::Playing);
        DIAP_ONIN_END
        DIAP_ONOUT_BEGIN
            m_fx.reset();
            salidaVideo<<nullptr;
            player->setState(zz::NonLinearUpdate::States::Paused);
        DIAP_ONOUT_END
    DIAP_END(Diapositiva36)

    //Diapositiva37
    DEFAULT_DIAPOSITIVA(Diapositiva37, 37)

    //Diapositiva38
    DIAP_BEGIN(Diapositiva38)
        DIAP_PRIV_OBJ_BEGIN
        DIAP_PRIV_OBJ_END
        DIAP_ONIN_BEGIN
            //Establece los tamaños
            zz::Graphics::Rectangle bkgdRect{
                .size=resolucion
            };

            zz::Graphics::Rectangle vidPlaneRect{
                .size=resolucion / 4.0f
            };

            zz::Utils::Vec3f positions(vidPlaneRect.size, 1.0);

            //Crea y configura las capas
            auto bkgd=std::make_shared<zz::Processors::Compositor::VideoLayer>(bkgdRect);
            bkgd->videoIn << diapositivasPdf->videoOut;
            bkgd->setAnchorage(zz::Utils::Vec3f(bkgdRect.size / 2.0f, 0.0));
            bkgd->setScalingMode(zz::Utils::ScalingMode::Boxed);

            auto vidPlane1=std::make_shared<zz::Processors::Compositor::VideoLayer>(vidPlaneRect);
            vidPlane1->videoIn << player->videoOut;
            vidPlane1->setScalingMode(zz::Utils::ScalingMode::Boxed);
            vidPlane1->setPosition(positions * zz::Utils::Vec3f(-1.0, -1.0, 1.0));
            vidPlane1->setAnchorage(zz::Utils::Vec3f(vidPlaneRect.size / 2.0f, 0.0));

            auto vidPlane2=std::make_shared<zz::Processors::Compositor::VideoLayer>(vidPlaneRect);
            vidPlane2->videoIn << image->videoOut;
            vidPlane2->setScalingMode(zz::Utils::ScalingMode::Boxed);
            vidPlane2->setPosition(positions * zz::Utils::Vec3f(0.0, -1.0, 1.0));
            vidPlane2->setAnchorage(zz::Utils::Vec3f(vidPlaneRect.size / 2.0f, 0.0));

            auto vidPlane3=std::make_shared<zz::Processors::Compositor::VideoLayer>(vidPlaneRect);
            vidPlane3->videoIn << chroma->videoOut;
            vidPlane3->setScalingMode(zz::Utils::ScalingMode::Boxed);
            vidPlane3->setPosition(positions * zz::Utils::Vec3f(1.0, -1.0, 1.0));
            vidPlane3->setAnchorage(zz::Utils::Vec3f(vidPlaneRect.size / 2.0f, 0.0));

            //Mete las capas en el compositor
            std::vector<std::shared_ptr<zz::Processors::Compositor::LayerBase>> capas;
            capas.push_back(bkgd);
            capas.push_back(vidPlane1);
            capas.push_back(vidPlane2);
            capas.push_back(vidPlane3);
            comp->setLayers(capas);

            salidaVideo << comp->videoOut;
            diapositivasPdf->ir_a(38);
            player->setState(zz::NonLinearUpdate::States::Playing);
        DIAP_ONIN_END
        DIAP_ONOUT_BEGIN
            salidaVideo<<nullptr;
            player->setState(zz::NonLinearUpdate::States::Paused);
        DIAP_ONOUT_END
    DIAP_END(Diapositiva38)

    //Diapositiva39
    DIAP_BEGIN(Diapositiva39)
        DIAP_PRIV_OBJ_BEGIN
        DIAP_PRIV_OBJ_END
        DIAP_ONIN_BEGIN
            //Establece los tamaños
            zz::Graphics::Rectangle bkgdRect{
                .size=resolucion
            };

            zz::Graphics::Rectangle vidPlaneRect{
                .size=resolucion / 4.0f
            };

            zz::Utils::Vec3f positions(vidPlaneRect.size, 1.0);

            //Crea y configura las capas
            auto bkgd=std::make_shared<zz::Processors::Compositor::VideoLayer>(bkgdRect);
            bkgd->videoIn << diapositivasPdf->videoOut;
            bkgd->setAnchorage(zz::Utils::Vec3f(bkgdRect.size / 2.0f, 0.0));
            bkgd->setScalingMode(zz::Utils::ScalingMode::Boxed);

            auto vidPlane1=std::make_shared<zz::Processors::Compositor::VideoLayer>(vidPlaneRect);
            vidPlane1->videoIn << player->videoOut;
            vidPlane1->setScalingMode(zz::Utils::ScalingMode::Boxed);
            vidPlane1->setPosition(positions * zz::Utils::Vec3f(-0.5, -1.0, 1.0));
            vidPlane1->setAnchorage(zz::Utils::Vec3f(vidPlaneRect.size / 2.0f, 0.0));

            auto vidPlane2=std::make_shared<zz::Processors::Compositor::VideoLayer>(vidPlaneRect);
            vidPlane2->videoIn << image->videoOut;
            vidPlane2->setScalingMode(zz::Utils::ScalingMode::Boxed);
            vidPlane2->setPosition(positions * zz::Utils::Vec3f(0.0, -1.0, 2.0));
            vidPlane2->setAnchorage(zz::Utils::Vec3f(vidPlaneRect.size / 2.0f, 0.0));

            auto vidPlane3=std::make_shared<zz::Processors::Compositor::VideoLayer>(vidPlaneRect);
            vidPlane3->videoIn << chroma->videoOut;
            vidPlane3->setScalingMode(zz::Utils::ScalingMode::Boxed);
            vidPlane3->setPosition(positions * zz::Utils::Vec3f(0.5, -1.0, 3.0));
            vidPlane3->setAnchorage(zz::Utils::Vec3f(vidPlaneRect.size / 2.0f, 0.0));

            //Mete las capas en el compositor
            std::vector<std::shared_ptr<zz::Processors::Compositor::LayerBase>> capas;
            capas.push_back(bkgd);
            capas.push_back(vidPlane1);
            capas.push_back(vidPlane2);
            capas.push_back(vidPlane3);
            comp->setLayers(capas);

            salidaVideo << comp->videoOut;
            diapositivasPdf->ir_a(39);
            player->setState(zz::NonLinearUpdate::States::Playing);
        DIAP_ONIN_END
        DIAP_ONOUT_BEGIN
            salidaVideo<<nullptr;
            player->setState(zz::NonLinearUpdate::States::Paused);
        DIAP_ONOUT_END
    DIAP_END(Diapositiva39)

    //Diapositiva40
    DIAP_BEGIN(Diapositiva40)
        DIAP_PRIV_OBJ_BEGIN
        DIAP_PRIV_OBJ_END
        DIAP_ONIN_BEGIN
            //Establece los tamaños
            zz::Graphics::Rectangle bkgdRect{
                .size=resolucion
            };

            zz::Graphics::Rectangle vidPlaneRect{
                .size=resolucion / 4.0f
            };

            zz::Utils::Vec3f positions(vidPlaneRect.size, 1.0);

            //Crea y configura las capas
            auto bkgd=std::make_shared<zz::Processors::Compositor::VideoLayer>(bkgdRect);
            bkgd->videoIn << diapositivasPdf->videoOut;
            bkgd->setAnchorage(zz::Utils::Vec3f(bkgdRect.size / 2.0f, 0.0));
            bkgd->setScalingMode(zz::Utils::ScalingMode::Boxed);

            auto vidPlane1=std::make_shared<zz::Processors::Compositor::VideoLayer>(vidPlaneRect);
            vidPlane1->videoIn << player->videoOut;
            vidPlane1->setScalingMode(zz::Utils::ScalingMode::Boxed);
            vidPlane1->setPosition(positions * zz::Utils::Vec3f(-0.5, -1.0, 1.0));
            vidPlane1->setAnchorage(zz::Utils::Vec3f(vidPlaneRect.size / 2.0f, 0.0));

            auto vidPlane2=std::make_shared<zz::Processors::Compositor::VideoLayer>(vidPlaneRect);
            vidPlane2->videoIn << image->videoOut;
            vidPlane2->setScalingMode(zz::Utils::ScalingMode::Boxed);
            vidPlane2->setPosition(positions * zz::Utils::Vec3f(0.0, -1.0, 2.0));
            vidPlane2->setAnchorage(zz::Utils::Vec3f(vidPlaneRect.size / 2.0f, 0.0));

            auto vidPlane3=std::make_shared<zz::Processors::Compositor::VideoLayer>(vidPlaneRect);
            vidPlane3->videoIn << chroma->videoOut;
            vidPlane3->setScalingMode(zz::Utils::ScalingMode::Boxed);
            vidPlane3->setPosition(positions * zz::Utils::Vec3f(0.5, -1.0, 3.0));
            vidPlane3->setAnchorage(zz::Utils::Vec3f(vidPlaneRect.size / 2.0f, 0.0));

            //Mete las capas en el compositor
            std::vector<std::shared_ptr<zz::Processors::Compositor::LayerBase>> capas;
            capas.push_back(bkgd);
            capas.push_back(vidPlane1);
            capas.push_back(vidPlane2);
            capas.push_back(vidPlane3);
            comp->setLayers(capas);

            salidaVideo << comp->videoOut;
            diapositivasPdf->ir_a(40);
            player->setState(zz::NonLinearUpdate::States::Playing);
        DIAP_ONIN_END
        DIAP_ONOUT_BEGIN
            salidaVideo<<nullptr;
            player->setState(zz::NonLinearUpdate::States::Paused);
        DIAP_ONOUT_END
    DIAP_END(Diapositiva40)

    //Diapositiva41
    DIAP_BEGIN(Diapositiva41)
        DIAP_PRIV_OBJ_BEGIN
            std::unique_ptr<zz::Processors::Compositor> m_comp;
            std::unique_ptr<zz::Video::VideoSourceBase> m_src1;
            std::unique_ptr<zz::Video::VideoSourceBase> m_src2;
            std::unique_ptr<zz::Video::VideoSourceBase> m_src3;
            std::unique_ptr<zz::Processors::ChromaKey>  m_chroma;
        DIAP_PRIV_OBJ_END
        DIAP_ONIN_BEGIN
            //Establece los tamaños
            zz::Graphics::Rectangle bkgdRect{
                .size=resolucion
            };

            zz::Graphics::Rectangle vidPlaneRect{
                .size=resolucion / 4.0f
            };

            zz::Utils::Vec3f positions(vidPlaneRect.size, vidPlaneRect.size.x);

            //Crea y configura las capas
            auto bkgd=std::make_shared<zz::Processors::Compositor::VideoLayer>(bkgdRect);
            bkgd->setScalingFilter(zz::Utils::ScalingFilter::Bilinear);
            bkgd->setScalingMode(zz::Utils::ScalingMode::Boxed);
            bkgd->videoIn << diapositivasPdf->videoOut;
            bkgd->setAnchorage(zz::Utils::Vec3f(bkgdRect.size / 2.0f, 0.0));

            auto vidPlane1=std::make_shared<zz::Processors::Compositor::VideoLayer>(vidPlaneRect);
            vidPlane1->videoIn << player->videoOut;
            vidPlane1->setScalingMode(zz::Utils::ScalingMode::Boxed);
            vidPlane1->setScalingFilter(zz::Utils::ScalingFilter::Bilinear);
            vidPlane1->setPosition(positions * zz::Utils::Vec3f(-0.4, -1.0, 0.9));
            vidPlane1->setAnchorage(zz::Utils::Vec3f(vidPlaneRect.size / 2.0f, 0.0));

            auto vidPlane2=std::make_shared<zz::Processors::Compositor::VideoLayer>(vidPlaneRect);
            vidPlane2->videoIn << image->videoOut;
            vidPlane2->setScalingMode(zz::Utils::ScalingMode::Boxed);
            vidPlane2->setScalingFilter(zz::Utils::ScalingFilter::Bilinear);
            vidPlane2->setPosition(positions * zz::Utils::Vec3f(0.0, -1.0, 1.8));
            vidPlane2->setAnchorage(zz::Utils::Vec3f(vidPlaneRect.size / 2.0f, 0.0));

            auto vidPlane3=std::make_shared<zz::Processors::Compositor::VideoLayer>(vidPlaneRect);
            vidPlane3->videoIn << chroma->videoOut;
            vidPlane3->setScalingMode(zz::Utils::ScalingMode::Boxed);
            vidPlane3->setScalingFilter(zz::Utils::ScalingFilter::Bilinear);
            vidPlane3->setPosition(positions * zz::Utils::Vec3f(0.4, -1.0, 2.7));
            vidPlane3->setAnchorage(zz::Utils::Vec3f(vidPlaneRect.size / 2.0f, 0.0));

            //Mete las capas en el compositor
            std::vector<std::shared_ptr<zz::Processors::Compositor::LayerBase>> capas;
            capas.push_back(bkgd);
            capas.push_back(vidPlane1);
            capas.push_back(vidPlane2);
            capas.push_back(vidPlane3);
            comp->setLayers(capas);

            //Coloca la cámara
            zz::Utils::Vec3f camPos=comp->getCameraPosition() + zz::Utils::Vec3f(bkgdRect.size / 1.3f, bkgdRect.size.x) / 2.2f;
            zz::Utils::Vec3f target(0.0f, -vidPlaneRect.size.y * 0.5, vidPlaneRect.size.x);
            comp->setCameraPosition(camPos);
            comp->setCameraTarget(target);

            salidaVideo<<comp->videoOut;
            diapositivasPdf->ir_a(40);
            player->setState(zz::NonLinearUpdate::States::Playing);
        DIAP_ONIN_END
        DIAP_ONOUT_BEGIN
            salidaVideo<<nullptr;
            comp->setDefaultCamera();
            player->setState(zz::NonLinearUpdate::States::Paused);
        DIAP_ONOUT_END
    DIAP_END(Diapositiva41)

    //Diapositiva42
    DEFAULT_DIAPOSITIVA(Diapositiva42, 41)

    //Diapositiva43
    DEFAULT_DIAPOSITIVA(Diapositiva43, 42)

    //Diapositiva44
    DEFAULT_DIAPOSITIVA(Diapositiva44, 43)

    //Diapositiva45
    DIAP_BEGIN(Diapositiva45)
        DIAP_PRIV_OBJ_BEGIN
            std::unique_ptr<zz::Sources::ImageMagick> winImg;
        DIAP_PRIV_OBJ_END
        DIAP_ONIN_BEGIN
            //Abre la imagen
            winImg=std::make_unique<zz::Sources::ImageMagick>("images/hola_mundo_win.png");
            zz::Utils::Vec2f winRes(winImg->getResolution().width / 2.0f, winImg->getResolution().height / 2.0f);
            zz::Utils::Vec2f fillRes(640, 360);

            //Establece los tamaños
            zz::Graphics::Rectangle bkgdRect{
                .size=resolucion
            };

            zz::Graphics::Rectangle winRect{
                .size=winRes
            };

            zz::Graphics::Rectangle fillRect{
                .size=fillRes
            };

            //Crea y configura las capas
            auto bkgd=std::make_shared<zz::Processors::Compositor::VideoLayer>(bkgdRect);
            bkgd->videoIn << diapositivasPdf->videoOut;
            bkgd->setAnchorage(zz::Utils::Vec3f(bkgdRect.size / 2.0f, 0.0));
            bkgd->setScalingMode(zz::Utils::ScalingMode::Boxed);

            auto window=std::make_shared<zz::Processors::Compositor::VideoLayer>(winRect);
            window->videoIn << winImg->videoOut;
            window->setPosition(zz::Utils::Vec3f(-winRect.size / 2.0f, 1.0));

            auto fill=std::make_shared<zz::Processors::Compositor::VideoLayer>(fillRect);
            fill->videoIn << webcam->videoOut;
            fill->setPosition(zz::Utils::Vec3f(window->getPosition()) + zz::Utils::Vec3f(32.5f , 42.0f, 0.0f));

            //Mete las capas en el compositor
            std::vector<std::shared_ptr<zz::Processors::Compositor::LayerBase>> capas;
            capas.push_back(bkgd);
            capas.push_back(window);
            capas.push_back(fill);
            comp->setLayers(capas);

            salidaVideo << comp->videoOut;
            diapositivasPdf->ir_a(43);
        DIAP_ONIN_END
        DIAP_ONOUT_BEGIN
            salidaVideo<<nullptr;
            winImg.reset();
        DIAP_ONOUT_END
    DIAP_END(Diapositiva45)


    //Diapositiva46
    DEFAULT_DIAPOSITIVA(Diapositiva46, 44)

    //Diapositiva47
    DEFAULT_DIAPOSITIVA(Diapositiva47, 45)

    //Diapositiva48
    DEFAULT_DIAPOSITIVA(Diapositiva48, 46)

    //Diapositiva49
    DEFAULT_DIAPOSITIVA(Diapositiva49, 47)

    //Diapositiva50
    DEFAULT_DIAPOSITIVA(Diapositiva50, 48)

    //Diapositiva51
    DEFAULT_DIAPOSITIVA(Diapositiva51, 49)

    //Diapositiva52
    DIAP_BEGIN(Diapositiva52)
        DIAP_PRIV_OBJ_BEGIN
            std::unique_ptr<zz::Sources::ImageMagick> winImg;
            std::unique_ptr<Cuantizar>  cuant;
        DIAP_PRIV_OBJ_END
        DIAP_ONIN_BEGIN
            //Abre la imagen
            winImg=std::make_unique<zz::Sources::ImageMagick>("images/cuantizar_win.png");
            cuant=std::make_unique<Cuantizar>(defaultVideoMode);
            zz::Utils::Vec2f winRes(winImg->getResolution().width / 2.0f, winImg->getResolution().height / 2.0f);
            zz::Utils::Vec2f fillRes(640, 360);

            //Establece los tamaños
            zz::Graphics::Rectangle bkgdRect{
                .size=resolucion
            };

            zz::Graphics::Rectangle winRect{
                .size=winRes
            };

            zz::Graphics::Rectangle fillRect{
                .size=fillRes
            };

            //Crea y configura las capas
            auto bkgd=std::make_shared<zz::Processors::Compositor::VideoLayer>(bkgdRect);
            bkgd->videoIn << diapositivasPdf->videoOut;
            bkgd->setAnchorage(zz::Utils::Vec3f(bkgdRect.size / 2.0f, 0.0));
            bkgd->setScalingMode(zz::Utils::ScalingMode::Boxed);

            auto window=std::make_shared<zz::Processors::Compositor::VideoLayer>(winRect);
            window->videoIn << winImg->videoOut;
            window->setPosition(zz::Utils::Vec3f(-winRect.size / 2.0f, 1.0));

            auto fill=std::make_shared<zz::Processors::Compositor::VideoLayer>(fillRect);
            cuant->videoIn << webcam->videoOut;
            fill->videoIn << cuant->videoOut;
            fill->setPosition(zz::Utils::Vec3f(window->getPosition())  + zz::Utils::Vec3f(32.5f , 42.0f, 0.0f));
            
            //Mete las capas en el compositor
            std::vector<std::shared_ptr<zz::Processors::Compositor::LayerBase>> capas;
            capas.push_back(bkgd);
            capas.push_back(window);
            capas.push_back(fill);
            comp->setLayers(capas);

            salidaVideo << comp->videoOut;
            diapositivasPdf->ir_a(49);
        DIAP_ONIN_END
        DIAP_ONOUT_BEGIN
            salidaVideo<<nullptr;
            winImg.reset();
            cuant.reset();
        DIAP_ONOUT_END
    DIAP_END(Diapositiva52)

    //Diapositiva53
    DEFAULT_DIAPOSITIVA(Diapositiva53, 50)

    //Diapositiva54
    DEFAULT_DIAPOSITIVA(Diapositiva54, 51)

    //Diapositiva55
    DEFAULT_DIAPOSITIVA(Diapositiva55, 52)

    //Diapositiva56
    DEFAULT_DIAPOSITIVA(Diapositiva56, 53)

    //Diapositiva57
    DEFAULT_DIAPOSITIVA(Diapositiva57, 54)

    //Diapositiva58
    DEFAULT_DIAPOSITIVA(Diapositiva58, 55)

    //Diapositiva59
    //TODO MEME

    //Diapositiva60
    DEFAULT_DIAPOSITIVA(Diapositiva60, 56)

    //Diapositiva61
    DEFAULT_DIAPOSITIVA(Diapositiva61, 57)

    //Diapositiva62
    DEFAULT_DIAPOSITIVA(Diapositiva62, 58)

    //Diapositiva63
    DEFAULT_DIAPOSITIVA(Diapositiva63, 59)

PRESENTACION_END(zzcusl13)