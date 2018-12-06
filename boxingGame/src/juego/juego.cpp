#include "juego.h"

#include "pantallas/gameplay.h"
#include "pantallas/menu.h"
#include "pantallas/opciones.h"
#include "pantallas/pausa.h"
#include "pantallas/gameover.h"
#include "pantallas/creditos.h"

#include "SFML/Graphics.hpp"

namespace juego
{
	bool Juego::_inGame = true;

	bool Juego::haySonido = true;

	tgui::Gui* Juego::gui = new tgui::Gui();

	tgui::Theme Juego::theme;

	sf::Font Juego::_fuente;

	sf::Text Juego::version;

	Pantalla* Juego::pantalla[cantPantallas];

	Time Juego::_dt;
	Clock Juego::_dClock;

	unsigned int Juego::_anchoPantalla = 1200;
	unsigned int Juego::_altoPantalla = 800;

	RenderWindow *Juego::window = new RenderWindow(VideoMode(_anchoPantalla, _altoPantalla), "Plataformero");
	View Juego::view;

	Estados Juego::estadoActual = menu;
	Estados Juego::estadoAnterior = gameplay;

	Juego::Juego()
	{
		for (int i = 0; i < cantPantallas; i++)
		{
			pantalla[i] = NULL;
		}

		gui->setTarget(*window);
		theme.load("res/assets/themes/BabyBlue.txt");
		if (!_fuente.loadFromFile("res/assets/fuentes/ANTQUAB.ttf"))
		{
			//error
		}
		gui->setFont(_fuente);

		pantalla[gameplay] = new Gameplay();
		pantalla[menu] = new Menu();
		pantalla[opciones] = new Opciones();
		pantalla[pausa] = new Pausa();
		pantalla[gameover] = new Gameover();
		pantalla[creditos] = new Creditos();
		
		

		version.setString("v1.0");
		version.setCharacterSize(40);
		version.setFillColor(sf::Color::White);
		version.setFont(*Juego::getGui()->getFont());
		version.setPosition(static_cast<float> ((Juego::getAnchoPantalla() - version.getString().getSize() * 120 / 5)) - 20, 20.0f);

		view.setCenter(static_cast<float>(_anchoPantalla / 2), static_cast<float>(_altoPantalla / 2));
		view.setSize(static_cast<float>(_anchoPantalla), static_cast<float>(_altoPantalla));
	}

	Juego::~Juego()
	{
		for (int i = 0; i < cantPantallas; i++)
		{
			if (pantalla[i] != NULL)
				delete pantalla[i];
		}
		delete window;
	}

	void Juego::inicializar()
	{
		for (int i = 0; i < cantPantallas; i++)
		{
			if (pantalla[i] != NULL)
			{
				pantalla[i]->inicializar();
			}
		}
	}

	void Juego::desinicializar()
	{
		for (int i = 0; i < cantPantallas; i++)
		{
			if (pantalla[i] != NULL)
			{
				pantalla[i]->desinicializar();
			}
		}
		delete gui;
	}

	RenderWindow* Juego::getWindow()
	{
		return window;
	}

	void Juego::setInGame(bool inGame)
	{
		_inGame = inGame;
	}

	bool Juego::getInGame()
	{
		return _inGame;
	}

	void Juego::ejecutar(Juego* juego)
	{
		inicializar();
		while (getInGame())
		{
			sf::Event event;
			while (window->pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window->close();

				gui->handleEvent(event);
			}
			
			window->clear();

			
			if (pantalla[estadoActual]!=NULL)
			{
				pantalla[estadoActual]->chequearInput();
				pantalla[estadoActual]->actualizar();
				if (estadoActual == pausa)
				{
					pantalla[gameplay]->dibujar();
				}
				pantalla[estadoActual]->dibujar();
				pantalla[estadoActual]->mostrarGui();
				for (int i = 0; i < cantPantallas; i++)
				{
					if (i != estadoActual)
					{
						pantalla[i]->esconderGui();
					}
				}
			}
			
			gui->draw();

			window->display();

			resetClock();
		}
		desinicializar();
	}

	float Juego::getFrameTime() 
	{
		return _dt.asSeconds();
	}

	void Juego::resetClock()
	{
		_dt=_dClock.restart();
	}

	int Juego::getAnchoPantalla()
	{
		return _anchoPantalla;
	}
	int Juego::getAltoPantalla()
	{
		return _altoPantalla;
	}

	void Juego::setAnchoPantalla(unsigned int ancho)
	{
		_anchoPantalla=ancho;
		window->setSize({ _anchoPantalla, _altoPantalla });
	}
	void Juego::setAltoPantalla(unsigned int alto)
	{
		_altoPantalla=alto;
		window->setSize({ _anchoPantalla, _altoPantalla });
	}

	Estados Juego::getEstadoActual()
	{
		return estadoActual;
	}

	void Juego::setEstadoActual(Estados e, bool reinicio)
	{
		estadoAnterior = estadoActual;
		estadoActual = e;

		if ((estadoActual==gameplay && estadoAnterior==menu)||
			(estadoActual==gameplay && estadoAnterior==gameover) ||
			(estadoAnterior==pausa && estadoActual==gameplay && reinicio))
		{
			pantalla[gameplay]->inicializar();
		}

		if ((estadoAnterior == gameplay && estadoActual != pausa) || (estadoAnterior==pausa && estadoActual!=gameplay))
		{
			window->setView(view);
		}
	}

	tgui::Gui* Juego::getGui()
	{
		return gui;
	}

	tgui::Theme Juego::getTheme()
	{
		return theme;
	}

	sf::Font Juego::getFuente()
	{
		return _fuente;
	}

	void Juego::dibujarVersion()
	{
		window->draw(version);
	}

	bool Juego::getHaySonido()
	{
		return haySonido;
	}

	void Juego::setHaySonido(bool b)
	{
		haySonido = b;
	}
}