#include "Cuantizar.h"

const std::string Cuantizar::s_shaderSrc(
    #include "quantize.glsl"
);

Cuantizar::Cuantizar() : 
ShaderEffect(s_shaderSrc)
{
    setNivelesRojo(2);
    setNivelesVerde(2);
    setNivelesAzul(2);
}

Cuantizar::Cuantizar(const Zuazo::Utils::VideoMode& vidMode) : 
ShaderEffect(vidMode, s_shaderSrc)
{
    setNivelesRojo(2);
    setNivelesVerde(2);
    setNivelesAzul(2);
}

void Cuantizar::setNivelesRojo(int niveles){
    ShaderEffect::setParam("nivelesR", niveles);
}

int Cuantizar::getNivelesRojo() const{
    const int* niveles=ShaderEffect::getParam<int>("nivelesR");
    return niveles ? *niveles : 0;
}  

void Cuantizar::setNivelesVerde(int niveles){
    ShaderEffect::setParam("nivelesG", niveles);
}

int Cuantizar::getNivelesVerde() const{
    const int* niveles=ShaderEffect::getParam<int>("nivelesG");
    return niveles ? *niveles : 0;
}  

void Cuantizar::setNivelesAzul(int niveles){
    ShaderEffect::setParam("nivelesB", niveles);
}

int Cuantizar::getNivelesAzul() const{
    const int* niveles=ShaderEffect::getParam<int>("nivelesB");
    return niveles ? *niveles : 0;
}  
