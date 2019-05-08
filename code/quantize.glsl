R""(

uniform shaderFxDataBlock{
  int nivelesR;
  int nivelesG;
  int nivelesB;
  //[...] otras variables
};

vec4 shaderFx(sampler2D tex, vec2 texCoord){
  vec4 texColor=texture(tex, texCoord); //Obtiene el color del pixel deseado
  vec3 niveles=vec3(nivelesR, nivelesG, nivelesB) - vec3(1.0); //Crea un vector de niveles

  vec3 cuantizado=round(texColor.rgb * niveles) / niveles;

  //Devuelve el vector de color con el resultado
  return vec4(cuantizado, texColor.a);
}

)""
