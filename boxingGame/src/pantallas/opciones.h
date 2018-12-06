#ifndef OPCIONES_H
#define OPCIONES_H

#include "pantalla.h"

#include "TGUI/TGUI.hpp"

using namespace tgui;

namespace juego
{
	class Opciones :public Pantalla
	{
		Button::Ptr atras;
		Button::Ptr sonidoONoff;
		sf::Sprite fondo;
	public:
		Opciones();
		~Opciones();
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