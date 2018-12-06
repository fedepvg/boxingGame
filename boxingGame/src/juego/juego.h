#ifndef JUEGO_H
#define JUEGO_H

#include "pantallas/pantalla.h"

#include "SFML/Graphics.hpp"
#include "TGUI/Gui.hpp"

using namespace sf;

namespace juego
{
	enum Estados
	{
		menu,
		gameplay,
		creditos,
		gameover,
		opciones,
		pausa
	};

	const int cantPantallas = 6;

	class Juego
	{
	private:
		static bool _inGame;
		static bool haySonido;
		static Pantalla* pantalla[cantPantallas];
		static unsigned int _anchoPantalla;
		static unsigned int _altoPantalla;
		static RenderWindow* window;
		static Estados estadoActual;
		static Estados estadoAnterior;
		static Clock _dClock;
		static Time _dt;
		static tgui::Gui* gui;
		static tgui::Theme theme;
		static sf::Font _fuente;
		static sf::Text version;
		static View view;
	public:
		Juego();
		~Juego();
		void inicializar();
		void desinicializar();
		static RenderWindow* getWindow();
		static void setInGame(bool inGame);
		static bool getInGame();
		void ejecutar(Juego* juego);
		static float getFrameTime();
		void resetClock();
		static int getAnchoPantalla();
		static int getAltoPantalla();
		static void setAnchoPantalla(unsigned int ancho);
		static void setAltoPantalla(unsigned int alto);
		static Estados getEstadoActual();
		static void setEstadoActual(Estados e, bool reinicio);
		static tgui::Gui* getGui();
		static tgui::Theme getTheme();
		static sf::Font getFuente();
		static void dibujarVersion();
		static bool getHaySonido();
		static void setHaySonido(bool b);
	};
}

#endif

