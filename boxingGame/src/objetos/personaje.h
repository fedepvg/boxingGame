#ifndef PERSONAJE_H
#define PERSONAJE_H

#include "SFML\Graphics.hpp"
#include "animacion.h"

using namespace sf;

namespace juego
{
	enum tipoGolpe { golpeIzq=Keyboard::J, golpeDer=Keyboard::K, sinGolpe = 0 };
	enum tipoEsquive { esquiveIzq = Keyboard::A, esquiveDer = Keyboard::D, sinEsquive = 0 };
	enum tipoPersonaje{jugador,rival,max};

	class Personaje
	{
	protected:
		sf::Sprite sprite;
		sf::Vector2f pos;
		Animacion* anim[cantAnimaciones];
		tipoPersonaje tPers;
	private:
		int cantVidas;
		bool estaCaido;
		bool seLevanta;
		bool estaGolpeado;
		bool contragolpea;
		bool puedeGolpear;
		bool cooldownActivo;
		float cooldown;
		tipoGolpe golpe;
		tipoEsquive esquive;
		tipoPersonaje tipoPers;
	public:
		Personaje(float x, float y, tipoPersonaje tPer);
		~Personaje();
		virtual void inicializar();
		void setVidas(int vid);
		int getVidas();
		sf::Vector2f getPos();
		void setPos(float x, float y);
		void setX(float x);
		void setY(float y);
		void chequearInput();
		void actualizar();
		void dibujar();
		void setGolpe(tipoGolpe tGolpe);
		void setEsquive(tipoEsquive tEsquive);
		tipoGolpe getGolpe();
		tipoEsquive getEsquive();
		void setTipoPers(tipoPersonaje tipo);
		tipoPersonaje getTipoPers();
		void actualizarIA();
	};
}
#endif
