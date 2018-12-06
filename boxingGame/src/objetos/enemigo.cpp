#include "enemigo.h"

#include "juego/juego.h"

#include "SFML\Graphics.hpp"

using namespace sf;

namespace juego
{
	static Texture tex;
	static float tiempoAnimacion;
	static IntRect src;

	Enemigo::Enemigo(float x, float y, Vector2f v) :Personaje(x, y, v)
	{
		if (!tex.loadFromFile("res/assets/bug.png"))
		{
		}
		sprite.setTexture(tex);
		tiempoAnimacion = 0;
		src.left = 0;
		src.top = 0;
		src.width = static_cast<int>(sprite.getLocalBounds().width / 2);
		src.height = static_cast<int>(sprite.getLocalBounds().height);
		sprite.setTextureRect(src);
		sprite.setPosition(pos);
	}


	Enemigo::~Enemigo()
	{
	}

	void Enemigo::inicializar()
	{
		
		sprite.setTextureRect(src);
		sprite.setPosition(pos);
		sprite.setOrigin(sprite.getGlobalBounds().height, (sprite.getGlobalBounds().width / 2));
	}

	void Enemigo::actualizar()
	{
		
	}

	void Enemigo::dibujar()
	{
		Juego::getWindow()->draw(sprite);
	}
}