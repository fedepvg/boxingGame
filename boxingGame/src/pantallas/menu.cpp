#include "menu.h"

#include "juego/juego.h"

#include "TGUI/TGUI.hpp"

namespace juego
{
	static Texture fondTex;
	static Texture tex;
	static String* texto[cantBotones];
	static tgui::Layout2d* size = new tgui::Layout2d(Vector2f{ 120,60 }); //tamaño estandar
	static int distanciaBotones = 60;

	Menu::Menu()
	{
		for (int i = 0; i < cantBotones; i++)
		{
			button[i] = NULL;
		}
	}


	Menu::~Menu()
	{
		for (int i = 0; i < cantBotones; i++)
		{
			if (texto[i] != NULL)
			{
				delete texto[i];
				texto[i] = NULL;
			}
		}
	}

	void Menu::inicializar()
	{
		

		for (int i = 0; i < cantBotones; i++)
		{
			button[i]=tgui::Button::create();
		}

		if (!tex.loadFromFile("res/assets/logo.png"))
		{

		}

		if (!fondTex.loadFromFile("res/assets/fondo_menu.png"))
		{

		}

		logo.setTexture(tex);
		logo.setScale(1.3f, 1.3f);
		logo.setPosition(static_cast<float>(Juego::getAnchoPantalla() / 2 - logo.getTexture()->getSize().x/2*logo.getScale().x), static_cast<float>( Juego::getAltoPantalla() / 5));

		fondo.setTexture(fondTex);
		fondo.setPosition(0, 0);
		
		texto[0] = new String("Jugar");
		texto[1] = new String("Opciones");
		texto[2] = new String("Creditos");
		texto[3] = new String("Salir");

		for (int i = 0; i < cantBotones; i++)
		{
			if (button[i] != NULL)
			{
				button[i]->setText(*texto[i]);

				button[i]->setRenderer(Juego::getTheme().getRenderer("Button"));

				button[i]->setTextSize(40); //tamaño estandar
				if (texto[i]->getSize() > 5)
				{
					button[i]->setSize(texto[i]->getSize() * 120 / 5, size->y);

					//logica de tamaño de botones basada en la cantidad de letras
					//5 letras - 120 ancho - regla de 3
				}
				else
				{
					button[i]->setSize(*size);
				}
			}
		}

		for (int i = 0; i < cantBotones; i++)
		{
			if (button[i] != NULL)
			{
				if (i > 0)
				{
					button[i]->setPosition(button[i - 1]->getPosition().x + button[i - 1]->getSize().x + distanciaBotones, button[i - 1]->getPosition().y);
				}
				else
				{
					int x = 0;
					for (int i = 0; i < cantBotones; i++)
					{
						x += static_cast<int> (button[i]->getSize().x);  //suma el tamaño de los botones y los espacios intermedios 
						if (i < cantBotones - 1)	  //para centrar la posicion de los botones
						{
							x += distanciaBotones;
						}
					}
					
					button[i]->setPosition(Juego::getAnchoPantalla()/2-x/2, Juego::getAltoPantalla() / 3*2 - size->y / 2);
				}
			}
		}

		for (int i = 0; i < cantBotones; i++)
		{
			if (button[i] != NULL)
			{
				Juego::getGui()->add(button[i]);
			}
		}

		button[0]->connect("pressed", [&]() { Juego::setEstadoActual(gameplay,false); });
		button[1]->connect("pressed", [&]() { Juego::setEstadoActual(opciones,false); });
		button[2]->connect("pressed", [&]() {Juego::setEstadoActual(creditos, false); });
		button[3]->connect("pressed", [&]() {Juego::setInGame(false); });
	}

	void Menu::chequearInput()
	{
		
	}

	void Menu::actualizar()
	{
		
	}

	void Menu::dibujar()
	{
		Juego::getWindow()->draw(fondo);
		Juego::getWindow()->draw(logo);
		Juego::dibujarVersion();
	}

	void Menu::desinicializar()
	{

	}

	void Menu::esconderGui()
	{
		for (int i = 0; i < cantBotones; i++)
		{
			if (button[i] != NULL)
			{
				button[i]->setVisible(false);
			}
		}
	}

	void Menu::mostrarGui()
	{
		for (int i = 0; i < cantBotones; i++)
		{
			if (button[i] != NULL)
			{
				button[i]->setVisible(true);
			}
		}
	}

	

	
}