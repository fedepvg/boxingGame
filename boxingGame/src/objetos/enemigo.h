#ifndef ENEMIGO_H
#define ENEMIGO_H

#include "personaje.h"

#include "SFML/Graphics.hpp"

namespace juego
{
	class Enemigo : public Personaje
	{
	public:
		Enemigo(float x, float y,sf::Vector2f v);
		~Enemigo();
		void inicializar();
		void actualizar();
		void dibujar();
	};
}
#endif