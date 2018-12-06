#ifndef JUGADOR_H
#define JUGADOR_H

#include "personaje.h"

#include "SFML\Graphics.hpp"

using namespace sf;

namespace juego
{
	class Jugador : public Personaje
	{
	public:
		Jugador(float x, float y, sf::Vector2f v);
		~Jugador();
		void inicializar();
		void actualizar();
		void dibujar();
		Jugador getJug();
	};
}

#endif