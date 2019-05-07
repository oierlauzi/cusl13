# Zuazo - CUSL XIII, Córdoba 9/10 de Mayo de 2019

## Descripcion

Estas son las diapositivas y el código utilizado en la presentación del proyecto Zuazo en la Fase Final del 
Concurso Universitario de Software Libre (CUSL) XIII

## Requisitos

- Ver requisitos de la librería Zuazo (en mi GitHub: https://github.com/oierlauzi/zuazo)

- Tener instalado Zuazo

- Tener una cámara web conectada al ordenador

Mi ordenador, con procesador i5-4300U y tarjeta gráfica integrada, ejecutando la presentación, la CPU se encuentra a un uso aproximado del
%50. La mayoría de esta carga proviene de la decodificación de la película.

## Cómo descargar:

-Insatalar Zuazo:

Ver el README.md de Zuazo (página anteriormente indicada)

-Instala el compilador de LaTex

``sudo apt-get install texlive latex-beamer``

-Descarga el repositorio:

``git clone https://github.com/oierlauzi/zuazo-cusl13.git``

-Compila la presentación:

``cd zuazo-cusl13``

``sh setup.sh``

**Nota:** Para la presentación se utilizo cómo cámara web el dispositivo ``/dev/video2`` que esta _hardcoded_ en el código. Probablemente 
necesite cambiarlo en el fichero ``code/Presentacion.cpp`` para adecuarlo a su ordenador

## Cómo ver las diapositivas en PDF

Las diapositivas de la presentación se han realizado en LaTex. Adeḿas, se le han añadido elementos de video mediante Zuazo.
Para ver exclusivamente las diapositivas (sin video) en formato PDF vaya al directorio ``tex`` del repositorio local (una vez compilado)
y abra ``presentacion.pdf``. Alternativamente, si no quiere compilar el código completo, vaya a este mismo directorio y ejecute 
``pdflatex presentacion.tex``

## Cómo probar los ejemplos mostrados

En la presentación se muestran 2 ejemplos. Si ha utilizado ``setup.sh`` para compilar, en la raiz del repositorio, ya debería de haber los 
dos binarios listos para ejecutar. En caso contrario, utilice los comandos propuestos en la cabecera de cada programa, situadas en los archivos 
``code/HolaMundo.cpp`` y ``code/CuantizarApp.cpp``

## Cómo ver la presentación completa

Una vez compilado, solo hace falta ejecutar el binario ``Presentacion`` ubicada en la raiz del repositorio local


