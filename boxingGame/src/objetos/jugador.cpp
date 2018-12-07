#include "jugador.h"

#include "SFML\Graphics.hpp"
#include "SFML/Audio.hpp"
#include "juego/juego.h"

using namespace sf;

namespace juego
{
	static Texture tex;
	static IntRect src;
	static float tiempoAnimacion;
	static float timer;

	Jugador::Jugador(float x, float y, Vector2f v) :Personaje(x, y)
	{

		pos = { x,y };

		sprite.setTexture(tex);
		sprite.setPosition(pos);

		src.top = 0;
		src.left = 0;
		src.width = static_cast<int>(sprite.getLocalBounds().width / 6);
		src.height = static_cast<int>(sprite.getLocalBounds().height);

		sprite.setTextureRect(src);

		inicializar();
	}


	Jugador::~Jugador()
	{
		
	}

	void Jugador::inicializar()
	{
		
	}

	void Jugador::actualizar()
	{
		sprite.setPosition(pos);
		Personaje::actualizar();

		tiempoAnimacion += Juego::getFrameTime();
		timer += Juego::getFrameTime();
	}

	void Jugador::dibujar()
	{
		//Juego::getWindow()->draw(sprite);
	}

	Jugador Jugador::getJug()
	{
		return *this;
	}
}