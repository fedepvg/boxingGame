#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "pantallas/pantalla.h"
#include "objetos/personaje.h"
#include "juego/juego.h"

#include "TGUI/TGUI.hpp"


namespace juego
{
	class Gameplay : public Pantalla
	{
		Personaje* jugador;
		View view;
		tgui::Button::Ptr botonPausa;
		static bool ganador;
	public:
		Gameplay();
		~Gameplay();
		void inicializar();
		void reiniciar();
		void chequearInput();
		void actualizar();
		void dibujar();
		void desinicializar();
		void crearEnemigo();
		void esconderGui();
		void mostrarGui();
		static bool getGanador();
		static void setGanador(bool g);
	};
}
#endif