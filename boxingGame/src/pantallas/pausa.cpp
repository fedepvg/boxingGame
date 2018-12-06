#include "pausa.h"

#include "juego/juego.h"

#include "SFML/Graphics.hpp"
#include "TGUI/TGUI.hpp"

namespace juego
{
	sf::String texto[cantBotonesPausa];
	RectangleShape fondo;

	Pausa::Pausa()
	{
		for (int i = 0; i < cantBotonesPausa; i++)
		{
			botonP[i] = NULL;
		}
	}


	Pausa::~Pausa()
	{
	}
	
	void Pausa::inicializar()
	{

		fondo.setPosition({ 0,0 });
		fondo.setSize({ static_cast<float>(Juego::getAnchoPantalla()),static_cast<float>(Juego::getAltoPantalla()) });
		fondo.setFillColor(sf::Color(0, 0, 0, 170));
		fondo.setPosition({ Juego::getWindow()->getView().getCenter().x - fondo.getSize().x/2,
			Juego::getWindow()->getView().getCenter().y - fondo.getSize().y/2 });

		for (int i = 0; i < cantBotonesPausa; i++)
		{
			botonP[i] = tgui::Button::create();
		}


		String* texto[cantBotonesPausa];
		texto[0] = new String("Continuar");
		texto[1] = new String("Menu");
		texto[2] = new String("Reiniciar");
		tgui::Layout2d* size = new tgui::Layout2d(sf::Vector2f{ 120,60 });

		int distanciaBotones = 60;

		for (int i = 0; i < cantBotonesPausa; i++)
		{
			if (botonP[i] != NULL)
			{
				botonP[i]->setText(*texto[i]);
				botonP[i]->setRenderer(Juego::getTheme().getRenderer("Button"));
				//tgui::ButtonRenderer(theme.getRenderer("Button")).setBackgroundColor(sf::Color::Red);

				botonP[i]->setTextSize(40);
				if (texto[i]->getSize() > 5)
				{
					botonP[i]->setSize(texto[i]->getSize() * 120 / 5, size->y);

					//logica de tamaño de botones basada en la cantidad de letras
					//5 letras - 120 ancho - regla de 3
				}
				else
				{
					botonP[i]->setSize(*size);
				}
			}
		}
		for (int i = 0; i < cantBotonesPausa; i++)
		{
			if (botonP[i] != NULL)
			{
				if (i > 0)
				{
					botonP[i]->setPosition(Juego::getAnchoPantalla() / 2 - botonP[i]->getSize().x / 2,
						botonP[i - 1]->getPosition().y + botonP[i]->getSize().y + distanciaBotones);
				}
				else
				{
					int y = 0;
					for (int i = 0; i < cantBotonesPausa; i++)
					{
						y += static_cast<int>(botonP[i]->getSize().y);  //suma el tamaño de los botones y los espacios intermedios 
						if (i < cantBotonesPausa - 1)	  //para centrar la posicion de los botones
						{
							y += distanciaBotones;
						}
					}

					botonP[i]->setPosition(Juego::getAnchoPantalla() / 2 - botonP[i]->getSize().x / 2, Juego::getAltoPantalla() / 2 -y/2);
				}
			}

			botonP[despausaB]->connect("pressed", [&]() {Juego::setEstadoActual(gameplay, false); });
			botonP[menuB]->connect("pressed", [&]() {Juego::setEstadoActual(menu,false); });
			botonP[reiniciarB]->connect("pressed", [&]() {Juego::setEstadoActual(gameplay, true); });
			
		}

		for (int i = 0; i < cantBotonesPausa; i++)
		{
			if (botonP[i] != NULL)
			{
				Juego::getGui()->add(botonP[i]);
			}
		}
	}

	void Pausa::chequearInput()
	{

	}

	void Pausa::actualizar()
	{
		
	}

	void Pausa::dibujar()
	{
		Juego::getWindow()->draw(fondo);
	}

	void Pausa::desinicializar()
	{
		
	}

	void Pausa::esconderGui()
	{
		for (int i = 0; i < cantBotonesPausa; i++)
		{
			if (botonP[i] != NULL)
			{
				botonP[i]->setVisible(false);
			}
		}
	}

	void Pausa::mostrarGui()
	{
		for (int i = 0; i < cantBotonesPausa; i++)
		{
			if (botonP[i] != NULL)
			{
				botonP[i]->setVisible(true);
			}
		}
	}
}