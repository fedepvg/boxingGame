#ifndef ANIMACION_H
#define ANIMACION_H

#include "pugixml.hpp"

using namespace pugi;

namespace juego
{
	enum tipoAnimacion{idle,gIzq,gDer,caida,levantada};

	class Animacion
	{
	private:
		int cantFrames;
		int frameActual;
		xml_node_iterator iteradorFrame;
		int iteradorAnimacion;
	public:
		Animacion();
		~Animacion();
	};
}

#endif