#pragma once

#include "Diapositiva.h"
#include "Pdf.h"

#include <zuazo/Includes.h>

extern const std::string pdfDir;
extern const std::string webcamDir;
extern const std::string urdinDir;
extern const std::string bbbDir;

extern zz::Video::DummyVideoPad salidaVideo;
extern zz::Utils::VideoMode defaultVideoMode;
extern std::unique_ptr<Pdf> diapositivasPdf;

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











    //Diapositiva38
    DIAP_BEGIN(Diapositiva38)
        DIAP_PRIV_OBJ_BEGIN
            std::unique_ptr<zz::Processors::Compositor> m_comp;
            std::unique_ptr<zz::Video::VideoSourceBase> m_src1;
            std::unique_ptr<zz::Video::VideoSourceBase> m_src2;
            std::unique_ptr<zz::Video::VideoSourceBase> m_src3;
            std::unique_ptr<zz::Processors::ChromaKey>  m_chroma;
        DIAP_PRIV_OBJ_END
        DIAP_ONIN_BEGIN
            m_comp=std::make_unique<zz::Processors::Compositor>(defaultVideoMode);
            m_src1=zz::videoSourceFromFile(bbbDir);
            m_src2=zz::videoSourceFromFile(urdinDir);
            m_src3=zz::videoSourceFromFile(webcamDir);
            m_chroma=std::make_unique<zz::Processors::ChromaKey>(defaultVideoMode);

            //Establece los tamaños
            zz::Graphics::Rectangle bkgdRect{
                .size=zz::Utils::Vec2f(defaultVideoMode.res.width, defaultVideoMode.res.height)
            };

            zz::Graphics::Rectangle vidPlaneRect{
                .size=zz::Utils::Vec2f(defaultVideoMode.res.width, defaultVideoMode.res.height) / 4.0f
            };

            zz::Utils::Vec3f positions(vidPlaneRect.size, 1.0);

            //Crea y configura las capas
            auto bkgd=std::make_shared<zz::Processors::Compositor::VideoLayer>(bkgdRect);
            bkgd->videoIn << diapositivasPdf->videoOut;
            bkgd->setAnchorage(zz::Utils::Vec3f(bkgdRect.size / 2.0f, 0.0));

            auto vidPlane1=std::make_shared<zz::Processors::Compositor::VideoLayer>(vidPlaneRect);
            vidPlane1->videoIn << m_src1->videoOut;
            vidPlane1->setScalingMode(zz::Utils::ScalingMode::Boxed);
            vidPlane1->setPosition(positions * zz::Utils::Vec3f(-1.0, -1.0, 1.0));
            vidPlane1->setAnchorage(zz::Utils::Vec3f(vidPlaneRect.size / 2.0f, 0.0));

            auto vidPlane2=std::make_shared<zz::Processors::Compositor::VideoLayer>(vidPlaneRect);
            vidPlane2->videoIn << m_src2->videoOut;
            vidPlane2->setScalingMode(zz::Utils::ScalingMode::Boxed);
            vidPlane2->setPosition(positions * zz::Utils::Vec3f(0.0, -1.0, 1.0));
            vidPlane2->setAnchorage(zz::Utils::Vec3f(vidPlaneRect.size / 2.0f, 0.0));

            auto vidPlane3=std::make_shared<zz::Processors::Compositor::VideoLayer>(vidPlaneRect);
            m_chroma->videoIn << m_src3->videoOut;
            vidPlane3->videoIn << m_chroma->videoOut;
            vidPlane3->setScalingMode(zz::Utils::ScalingMode::Boxed);
            vidPlane3->setPosition(positions * zz::Utils::Vec3f(1.0, -1.0, 1.0));
            vidPlane3->setAnchorage(zz::Utils::Vec3f(vidPlaneRect.size / 2.0f, 0.0));

            //Mete las capas en el compositor
            std::vector<std::shared_ptr<zz::Processors::Compositor::LayerBase>> capas;
            capas.push_back(bkgd);
            capas.push_back(vidPlane1);
            capas.push_back(vidPlane2);
            capas.push_back(vidPlane3);
            m_comp->setLayers(capas);

            salidaVideo<<m_comp->videoOut;
            diapositivasPdf->ir_a(38);
        DIAP_ONIN_END
        DIAP_ONOUT_BEGIN
            m_src1.reset();
            m_src2.reset();
            m_src3.reset();
            m_comp.reset();
            m_chroma.reset();
            salidaVideo<<nullptr;
        DIAP_ONOUT_END
    DIAP_END(Diapositiva38)




















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
            std::unique_ptr<zz::Processors::Compositor> m_comp;
            std::unique_ptr<zz::Video::VideoSourceBase> m_src;
        DIAP_PRIV_OBJ_END
        DIAP_ONIN_BEGIN
            m_src=zz::videoSourceFromFile(bbbDir);
            m_comp=std::make_unique<zz::Processors::Compositor>(defaultVideoMode);

            //Establece los tamaños
            zz::Graphics::Rectangle bkgdRect{
                .size=zz::Utils::Vec2f(defaultVideoMode.res.width, defaultVideoMode.res.height)
            };

            zz::Graphics::Rectangle vidPlaneRect{
                .size=zz::Utils::Vec2f(defaultVideoMode.res.width, defaultVideoMode.res.height) / 2.0f
            };

            //Crea y configura las capas
            auto bkgd=std::make_shared<zz::Processors::Compositor::VideoLayer>(bkgdRect);
            bkgd->videoIn << diapositivasPdf->videoOut;
            bkgd->setAnchorage(zz::Utils::Vec3f(bkgdRect.size / 2.0f, 0.0));
            auto vidPlane=std::make_shared<zz::Processors::Compositor::VideoLayer>(vidPlaneRect);
            vidPlane->videoIn << m_src->videoOut;
            vidPlane->setScalingMode(zz::Utils::ScalingMode::Boxed);
            vidPlane->setPosition(zz::Utils::Vec3f(0, -static_cast<float>(defaultVideoMode.res.height) / 4.0f, 1.0));
            vidPlane->setAnchorage(zz::Utils::Vec3f(vidPlaneRect.size / 2.0f, 0.0));

            //Mete las capas en el compositor
            std::vector<std::shared_ptr<zz::Processors::Compositor::LayerBase>> capas;
            capas.push_back(bkgd);
            capas.push_back(vidPlane);
            m_comp->setLayers(capas);

            salidaVideo<<m_comp->videoOut;
            diapositivasPdf->ir_a(27);
        DIAP_ONIN_END
        DIAP_ONOUT_BEGIN
            m_src.reset();
            m_comp.reset();
            salidaVideo<<nullptr;
        DIAP_ONOUT_END
    DIAP_END(Diapositiva27)

    //Diapositiva28
    DIAP_BEGIN(Diapositiva28)
        DIAP_PRIV_OBJ_BEGIN
            std::unique_ptr<zz::Processors::Compositor> m_comp;
            std::unique_ptr<zz::Video::VideoSourceBase> m_src;
        DIAP_PRIV_OBJ_END
        DIAP_ONIN_BEGIN
            m_src=zz::videoSourceFromFile(urdinDir);
            m_comp=std::make_unique<zz::Processors::Compositor>(defaultVideoMode);

            //Establece los tamaños
            zz::Graphics::Rectangle bkgdRect{
                .size=zz::Utils::Vec2f(defaultVideoMode.res.width, defaultVideoMode.res.height)
            };

            zz::Graphics::Rectangle vidPlaneRect{
                .size=zz::Utils::Vec2f(defaultVideoMode.res.width, defaultVideoMode.res.height) / 3.0f
            };

            //Crea y configura las capas
            auto bkgd=std::make_shared<zz::Processors::Compositor::VideoLayer>(bkgdRect);
            bkgd->videoIn << diapositivasPdf->videoOut;
            bkgd->setAnchorage(zz::Utils::Vec3f(bkgdRect.size / 2.0f, 0.0));
            auto vidPlane=std::make_shared<zz::Processors::Compositor::VideoLayer>(vidPlaneRect);
            vidPlane->videoIn << m_src->videoOut;
            vidPlane->setScalingMode(zz::Utils::ScalingMode::Boxed);
            vidPlane->setPosition(zz::Utils::Vec3f(0, -static_cast<float>(defaultVideoMode.res.height) / 6.0f, 1.0));
            vidPlane->setAnchorage(zz::Utils::Vec3f(vidPlaneRect.size / 2.0f, 0.0));

            //Mete las capas en el compositor
            std::vector<std::shared_ptr<zz::Processors::Compositor::LayerBase>> capas;
            capas.push_back(bkgd);
            capas.push_back(vidPlane);
            m_comp->setLayers(capas);

            salidaVideo<<m_comp->videoOut;
            diapositivasPdf->ir_a(28);
        DIAP_ONIN_END
        DIAP_ONOUT_BEGIN
            m_src.reset();
            m_comp.reset();
            salidaVideo<<nullptr;
        DIAP_ONOUT_END
    DIAP_END(Diapositiva28)

    //Diapositiva29
    DIAP_BEGIN(Diapositiva29)
        DIAP_PRIV_OBJ_BEGIN
            std::unique_ptr<zz::Processors::Compositor> m_comp;
            std::unique_ptr<zz::Video::VideoSourceBase> m_src;
        DIAP_PRIV_OBJ_END
        DIAP_ONIN_BEGIN
            m_src=zz::videoSourceFromFile(webcamDir);
            m_comp=std::make_unique<zz::Processors::Compositor>(defaultVideoMode);

            //Establece los tamaños
            zz::Graphics::Rectangle bkgdRect{
                .size=zz::Utils::Vec2f(defaultVideoMode.res.width, defaultVideoMode.res.height)
            };

            zz::Graphics::Rectangle vidPlaneRect{
                .size=zz::Utils::Vec2f(defaultVideoMode.res.width, defaultVideoMode.res.height) / 2.0f
            };

            //Crea y configura las capas
            auto bkgd=std::make_shared<zz::Processors::Compositor::VideoLayer>(bkgdRect);
            bkgd->videoIn << diapositivasPdf->videoOut;
            bkgd->setAnchorage(zz::Utils::Vec3f(bkgdRect.size / 2.0f, 0.0));
            auto vidPlane=std::make_shared<zz::Processors::Compositor::VideoLayer>(vidPlaneRect);
            vidPlane->videoIn << m_src->videoOut;
            vidPlane->setScalingMode(zz::Utils::ScalingMode::Boxed);
            vidPlane->setPosition(zz::Utils::Vec3f(0, -static_cast<float>(defaultVideoMode.res.height) / 4.0f, 1.0));
            vidPlane->setAnchorage(zz::Utils::Vec3f(vidPlaneRect.size / 2.0f, 0.0));

            //Mete las capas en el compositor
            std::vector<std::shared_ptr<zz::Processors::Compositor::LayerBase>> capas;
            capas.push_back(bkgd);
            capas.push_back(vidPlane);
            m_comp->setLayers(capas);

            salidaVideo<<m_comp->videoOut;
            diapositivasPdf->ir_a(29);
        DIAP_ONIN_END
        DIAP_ONOUT_BEGIN
            m_src.reset();
            m_comp.reset();
            salidaVideo<<nullptr;
        DIAP_ONOUT_END
    DIAP_END(Diapositiva29)

PRESENTACION_END(zzcusl13)