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
