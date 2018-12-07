#include "personaje.h"

#include "juego/juego.h"

namespace juego
{
	Personaje::Personaje(float x, float y)
	{
		pos.x = x;
		pos.y = y;
		cantVidas = 1;
	}

	Personaje::~Personaje()
	{
		
	}

	void Personaje::inicializar()
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

	void Personaje::chequearInput()
	{
		if (!estaGolpeado || !estaCaido || golpe == sinGolpe || esquive == sinEsquive)
		{
			if (Keyboard::isKeyPressed(static_cast<Keyboard::Key>(tipoGolpe::golpeIzq)))
			{
				setGolpe(golpeIzq);
			}

			if (Keyboard::isKeyPressed(static_cast<Keyboard::Key>(tipoGolpe::golpeDer)))
			{
				setGolpe(golpeDer);
			}

			if (Keyboard::isKeyPressed(static_cast<Keyboard::Key>(tipoEsquive::esquiveIzq)))
			{
				setEsquive(esquiveIzq);
			}

			if (Keyboard::isKeyPressed(static_cast<Keyboard::Key>(tipoEsquive::esquiveDer)))
			{
				setEsquive(esquiveIzq);
			}
		}
	}

	void Personaje::actualizar()
	{
		
	}

	void Personaje::dibujar()
	{
		
	}

	void Personaje::setGolpe(tipoGolpe tGolpe)
	{
		golpe = tGolpe;
	}

	void Personaje::setEsquive(tipoEsquive tEsquive)
	{
		esquive = tEsquive;
	}

	tipoGolpe Personaje::getGolpe()
	{
		return golpe;
	}

	tipoEsquive Personaje::getEsquive()
	{
		return esquive;
	}

	void Personaje::setTipoPers(tipoPersonaje tipo)
	{
		tipoPers = tipo;
	}

	tipoPersonaje Personaje::getTipoPers()
	{
		return tipoPers;
	}

	void actualizarIA()
	{

	}
}