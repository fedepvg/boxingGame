#ifndef MENU_H
#define MENU_H

#include "pantalla.h"
#include "juego/juego.h"

#include "TGUI/TGUI.hpp"
#include "SFML/Graphics.hpp"

using namespace sf;

namespace juego
{
	const int cantBotones = 4;

	class Menu:public Pantalla
	{
		tgui::Button::Ptr button[cantBotones];
		tgui::EditBox::Ptr editBox[cantBotones];		
		sf::Sprite logo;
		sf::Sprite fondo;
	public:
		Menu();
		~Menu();
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