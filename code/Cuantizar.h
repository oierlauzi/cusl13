#pragma once

#include "zuazo/Includes.h"

class Cuantizar : public Zuazo::Processors::ShaderEffect{
public:
    Cuantizar();
    Cuantizar(const Zuazo::Utils::VideoMode& vidMode);
    Cuantizar(const Cuantizar& other)=delete;
    Cuantizar(Cuantizar&& other)=default;
    virtual ~Cuantizar()=default;

    void  setNivelesRojo(int niveles);
    int   getNivelesRojo() const;    

    void  setNivelesVerde(int niveles);
    int   getNivelesVerde() const;   

    void  setNivelesAzul(int niveles);
    int   getNivelesAzul() const;
private:
    static const std::string s_shaderSrc;
};