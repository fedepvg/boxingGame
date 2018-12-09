#ifndef ANIMACION_H
#define ANIMACION_H

#include "pugixml.hpp"
#include "SFML/Graphics.hpp"

#include <iostream>

using namespace pugi;
using namespace sf;

namespace juego
{
	enum tipoAnimacion{idle,gIzq,gDer,caida,levantada};

	const int cantAnimaciones = 5;

	class Animacion
	{
	private:
		int cantFrames;
		int frameActual;
		xml_node_iterator interadorFrame;
		int iteradorAnimacion; 
		xml_document doc;
		xml_parse_result result;
		tipoAnimacion tipoAnim;
		Texture sprSheet;
	public:
		Animacion(std::string rutaImg, std::string rutaXml, tipoAnimacion tipo);
		~Animacion();
	};
}

#endif