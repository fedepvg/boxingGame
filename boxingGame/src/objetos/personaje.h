#ifndef PERSONAJE_H
#define PERSONAJE_H

#include "SFML\Graphics.hpp"

using namespace sf;

namespace juego
{
	class Personaje
	{
	protected:
		sf::Sprite sprite;
		sf::Vector2f pos;
	private:
		int cantVidas;
	public:
		Personaje(float x, float y,sf::Vector2f v);
		~Personaje();
		virtual void inicializar()=0;
		void setVidas(int vid);
		int getVidas();
		sf::Vector2f getPos();
		void setPos(float x, float y);
		void setX(float x);
		void setY(float y);
		virtual void actualizar();
		virtual void dibujar();
	};
}
#endif
