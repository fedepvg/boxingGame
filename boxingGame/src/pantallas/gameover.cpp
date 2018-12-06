#include "gameover.h"

#include "TGUI/TGUI.hpp"
#include "gameplay.h"
#include "juego/juego.h"

namespace juego
{
	static Texture fontex;
	static Text* resultado;

	Gameover::Gameover()
	{
		for (int i = 0; i < cantBotonesMenu; i++)
		{
			botonGO[i] = NULL;
		}

		for (int i = 0; i < cantBotonesMenu; i++)
		{
			botonGO[i] = tgui::Button::create();
		}
	}


	Gameover::~Gameover()
	{
	}

	void Gameover::inicializar()
	{
		fontex.loadFromFile("res/assets/fondo_gameover.png");

		fondo.setTexture(fontex);
		fondo.setPosition(0, 0);

		resultado = new Text();
		String* texto[cantBotonesMenu];
		texto[0] = new String("Volver a Jugar");
		texto[1] = new String("Volver al Menu");
		tgui::Layout2d* size = new tgui::Layout2d(sf::Vector2f{ 120,60 });

		int distanciaBotones = 60;
		
		resultado->setFont(*Juego::getGui()->getFont());

		
		if (Gameplay::getGanador())
		{
			resultado->setString("Ganaste!");
		}
		else
		{
			resultado->setString("Perdiste");
		}
		resultado->setFillColor(sf::Color::Yellow);
		resultado->setCharacterSize(80);
		resultado->setPosition(static_cast<float>(Juego::getAnchoPantalla() / 2 - resultado->getString().getSize() / 2 * resultado->getCharacterSize()/2), static_cast<float>(Juego::getAltoPantalla() / 5));

		for (int i = 0; i < cantBotonesMenu; i++)
		{
			if (botonGO[i] != NULL)
			{
				botonGO[i]->setText(*texto[i]);
				botonGO[i]->setRenderer(Juego::getTheme().getRenderer("Button"));
				//tgui::ButtonRenderer(theme.getRenderer("Button")).setBackgroundColor(sf::Color::Red);

				botonGO[i]->setTextSize(40);
				if (texto[i]->getSize() > 5)
				{
					botonGO[i]->setSize(texto[i]->getSize() * 120 / 5, size->y);

					//logica de tamaño de botones basada en la cantidad de letras
					//5 letras - 120 ancho - regla de 3
				}
				else
				{
					botonGO[i]->setSize(*size);
				}
			}
		}
		for (int i = 0; i < cantBotonesMenu; i++)
		{
			if (botonGO[i] != NULL)
			{
				if (i > 0)
				{
					botonGO[i]->setPosition(Juego::getAnchoPantalla() / 2 - botonGO[i]->getSize().x / 2,
						botonGO[i - 1]->getPosition().y + botonGO[i]->getSize().y + distanciaBotones);
				}
				else
				{
					int y = 0;
					for (int i = 0; i < cantBotonesMenu; i++)
					{
						y += static_cast<int> (botonGO[i]->getSize().y);  //suma el tamaño de los botones y los espacios intermedios 
						if (i < cantBotonesMenu - 1)	  //para centrar la posicion de los botones
						{
							y += distanciaBotones;
						}
					}

					botonGO[i]->setPosition(Juego::getAnchoPantalla() / 2 - botonGO[i]->getSize().x / 2, Juego::getAltoPantalla() / 2 - y / 2);
				}
			}
		}

		botonGO[jugarGO]->connect("pressed", [&]() {Juego::setEstadoActual(gameplay, true); });
		botonGO[menuGO]->connect("pressed", [&]() {Juego::setEstadoActual(menu, false); });

		for (int i = 0; i < cantBotonesMenu; i++)
		{
			if (botonGO[i] != NULL)
			{
				Juego::getGui()->add(botonGO[i]);
				botonGO[i]->setVisible(true);
			}
		}
	}

	void Gameover::chequearInput()
	{

	}

	void Gameover::actualizar()
	{
		if (Gameplay::getGanador())
		{
			resultado->setString("Ganaste!");
		}
		else
		{
			resultado->setString("Perdiste");
		}
	}

	

	void Gameover::dibujar()
	{
		Juego::getWindow()->draw(fondo);
		Juego::getWindow()->draw(*resultado);
	}

	void Gameover::desinicializar()
	{
		
	}

	void Gameover::esconderGui()
	{
		for (int i = 0; i < cantBotonesMenu; i++)
		{
			if (botonGO[i] != NULL)
			{
				botonGO[i]->setVisible(false);
			}
		}
	}

	void Gameover::mostrarGui()
	{
		for (int i = 0; i < cantBotonesMenu; i++)
		{
			if (botonGO[i] != NULL)
			{
				botonGO[i]->setVisible(true);
			}
		}
	}
}