#ifndef CREDITOS_H
#define CREDITOS_H

#include "pantalla.h"

#include "SFML/Graphics.hpp"
#include "TGUI/TGUI.hpp"

using namespace tgui;

namespace juego
{
	class Creditos :public Pantalla
	{
		sf::Texture fondo;
		Button::Ptr atras;
	public:
		Creditos();
		~Creditos();
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