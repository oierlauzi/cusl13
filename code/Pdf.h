#pragma once

#include <zuazo/Includes.h>
#include <Magick++.h> 

class Pdf : public zz::Video::TVideoSourceBase<zz::Video::DummyVideoPad>
{
public:
    Pdf(const std::string& file, int ppi){
        m_nHoja=1;
        m_videoSourcePad << m_imzz.videoOut;

        Magick::ReadOptions opt;
        Magick::Geometry geom(ppi, ppi);
        opt.density(geom);

        //Carga las imagenes
        readImages(&m_hojas, file, opt);
        cargar();
    }
    Pdf(const Pdf& otro)=default;
    Pdf(Pdf&& otro)=default;
    ~Pdf()=default;

    void ir_a(int hoja){
        m_nHoja=hoja;
        cargar();
    }

    void siguiente(){
        m_nHoja++;
        cargar();
    }  

    void anterior(){
        m_nHoja--;
        cargar();
    }

    zz::Utils::Resolution getResolution() const{
        return m_imzz.getResolution();
    }                  
private:
    int                         m_nHoja;
    std::vector<Magick::Image>  m_hojas; 
    zz::Sources::ImageMagick    m_imzz;

    void cargar(){
        if(m_nHoja > 0 && m_nHoja <= (int)m_hojas.size()){
            m_imzz.replace(std::make_shared<Magick::Image>(m_hojas[m_nHoja - 1]));
        }else{
            m_imzz.replace(std::make_shared<Magick::Image>());
        }
    }
};
