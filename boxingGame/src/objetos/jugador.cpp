#include "jugador.h"

#include "SFML\Graphics.hpp"
#include "SFML/Audio.hpp"
#include "juego/juego.h"

using namespace sf;

namespace juego
{
	static Texture tex;
	static IntRect src;
	bool caminandoDer;
	bool caminandoIzq;
	static float tiempoAnimacion;
	static float timer;
	static sf::SoundBuffer bufferDash;
	static sf::SoundBuffer bufferSalto;
	static sf::Sound dash;
	static sf::Sound salto;

	Jugador::Jugador(float x, float y, Vector2f v) :Personaje(x, y, v)
	{
		tex.loadFromFile("res/assets/char.png");
		bufferDash.loadFromFile("res/assets/dash.wav");
		bufferSalto.loadFromFile("res/assets/jump.wav");

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
		dash.setBuffer(bufferDash);
		salto.setBuffer(bufferSalto);
		salto.setVolume(25);
		sprite.setOrigin(static_cast<float> (sprite.getTextureRect().width / 2), static_cast<float> ( sprite.getTextureRect().height / 2));

		setPos(50, 1800);

		caminandoDer = false;
		caminandoIzq = false;
		tiempoAnimacion = 0;
		timer = 0.0f;
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
		Juego::getWindow()->draw(sprite);
	}

	Jugador Jugador::getJug()
	{
		return *this;
	}
}