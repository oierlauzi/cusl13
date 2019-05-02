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

inline void Cuantizar::setNivelesRojo(int niveles){
    ShaderEffect::setParam("nivelesR", niveles);
}

inline int Cuantizar::getNivelesRojo() const{
    const int* niveles=ShaderEffect::getParam<int>("nivelesR");
    return niveles ? *niveles : 0;
}  

inline void Cuantizar::setNivelesVerde(int niveles){
    ShaderEffect::setParam("nivelesG", niveles);
}

inline int Cuantizar::getNivelesVerde() const{
    const int* niveles=ShaderEffect::getParam<int>("nivelesG");
    return niveles ? *niveles : 0;
}  

inline void Cuantizar::setNivelesAzul(int niveles){
    ShaderEffect::setParam("nivelesB", niveles);
}

inline int Cuantizar::getNivelesAzul() const{
    const int* niveles=ShaderEffect::getParam<int>("nivelesB");
    return niveles ? *niveles : 0;
}  
