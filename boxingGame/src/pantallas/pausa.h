#ifndef PAUSA_H
#define PAUSA_H

#include "pantalla.h"

#include "TGUI/TGUI.hpp"

using namespace tgui;

namespace juego
{
	const int cantBotonesPausa = 3;

	enum BotonesPausa
	{
		despausaB,
		menuB,
		reiniciarB
	};

	class Pausa :public Pantalla
	{
		Button::Ptr botonP[cantBotonesPausa];
	public:
		Pausa();
		~Pausa();
		void inicializar();
		void chequearInput();
		void actualizar();
		void dibujar();
		void desinicializar();
		void esconderGui();
		void mostrarGui();
	};
}
#endif