#include "personaje.h"

#include "juego/juego.h"

namespace juego
{
	Personaje::Personaje(float x, float y,Vector2f v)
	{
		pos.x = x;
		pos.y = y;
		cantVidas = 1;
	}

	Personaje::~Personaje()
	{
		
	}

	void Personaje::setVidas(int vid)
	{
		cantVidas = vid;
	}

	int Personaje::getVidas()
	{
		return cantVidas;
	}

	Vector2f Personaje::getPos()
	{
		return pos;
	}

	void Personaje::setPos(float x, float y)
	{
		pos.x = x;
		pos.y = y;
	}

	void Personaje::setX(float x)
	{
		pos.x = x;
	}

	void Personaje::setY(float y)
	{
		pos.y = y;
	}

	void Personaje::actualizar()
	{
		
	}

	void Personaje::dibujar()
	{
		
	}
}