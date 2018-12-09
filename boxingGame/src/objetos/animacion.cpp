#include "animacion.h"

namespace juego
{
	Animacion::Animacion(std::string rutaImg, std::string rutaXml, tipoAnimacion tipo)
	{
		tipoAnim = tipo;
		result = doc.load_file(rutaXml.c_str());
		sprSheet.loadFromFile(rutaImg.c_str());
	}

	Animacion::~Animacion()
	{

	}
}