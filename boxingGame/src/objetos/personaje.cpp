#include "personaje.h"

#include "juego/juego.h"

namespace juego
{
	Personaje::Personaje(float x, float y, tipoPersonaje tPer)
	{
		pos.x = x;
		pos.y = y;
		cantVidas = 1;
		tPers = tPer;
		for (int i = 0; i < cantAnimaciones; i++)
		{
			anim[i] = NULL;
		}
		
		if (tipoPers == jugador)
		{
			anim[tipoAnimacion::idle] = new Animacion("res\assets\anims\jug\anim_idle_pP.png", "res\assets\anims\jug\anim_idle_pP.xml",tipoAnimacion::idle);
			anim[tipoAnimacion::gIzq] = new Animacion("res\assets\anims\jug\anim_gIzq_pP.png", "res\assets\anims\jug\anim_gIzq_pP.xml", tipoAnimacion::gIzq);
			anim[tipoAnimacion::gDer] = new Animacion("res\assets\anims\jug\anim_gFer_pP.png", "res\assets\anims\jug\anim_gDer_pP.xml", tipoAnimacion::gDer);
			anim[tipoAnimacion::caida] = new Animacion("res\assets\anims\jug\anim_caida_pP.png", "res\assets\anims\jug\anim_caida_pP.xml", tipoAnimacion::caida);
			anim[tipoAnimacion::levantada] = new Animacion("res\assets\anims\jug\anim_levantada_pP.png", "res\assets\anims\jug\anim_levantada_pP.xml", tipoAnimacion::levantada);
		}
		else
		{
			anim[tipoAnimacion::idle] = new Animacion("res\assets\anims\jug\anim_idle_rival.png", "res\assets\anims\jug\anim_idle_rival.xml", tipoAnimacion::idle);
			anim[tipoAnimacion::gIzq] = new Animacion("res\assets\anims\jug\anim_gIzq_rival.png", "res\assets\anims\jug\anim_gIzq_rival.xml", tipoAnimacion::gIzq);
			anim[tipoAnimacion::gDer] = new Animacion("res\assets\anims\jug\anim_gFer_rival.png", "res\assets\anims\jug\anim_gDer_rival.xml", tipoAnimacion::gDer);
			anim[tipoAnimacion::caida] = new Animacion("res\assets\anims\jug\anim_caida_rival.png", "res\assets\anims\jug\anim_caida_rival.xml", tipoAnimacion::caida);
			anim[tipoAnimacion::levantada] = new Animacion("res\assets\anims\jug\anim_levantada_rival.png", "res\assets\anims\jug\anim_levantada_rival.xml", tipoAnimacion::levantada);
		}
		
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