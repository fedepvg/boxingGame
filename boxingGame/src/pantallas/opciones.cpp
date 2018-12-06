#include "opciones.h"

#include "juego/juego.h"

namespace juego
{
	static sf::Texture fontex;
	Opciones::Opciones()
	{
		
	}


	Opciones::~Opciones()
	{
	}


	void Opciones::inicializar()
	{
		fontex.loadFromFile("res/assets/fondo_gameover.png");

		fondo.setTexture(fontex);
		fondo.setPosition(0, 0);

		atras = Button::create();
		atras->setText("Atras");
		atras->setRenderer(Juego::getTheme().getRenderer("Button"));
		atras->setTextSize(40);
		atras->setSize(120, 60);
		atras->setPosition(atras->getSize().x / 2, atras->getSize().y / 2);
		atras->connect("pressed", [&]() {Juego::setEstadoActual(menu, false); });
		Juego::getGui()->add(atras);

		sonidoONoff = Button::create();
		
		
		sonidoONoff->setText("Sonido: ON");
		

		sonidoONoff->setRenderer(Juego::getTheme().getRenderer("Button"));
		sonidoONoff->setTextSize(40);
		sonidoONoff->setSize(sonidoONoff->getText().getSize()*120/5, sonidoONoff->getText().getSize() * 60 / 5); //tamaño estandar
		sonidoONoff->setPosition(Juego::getAnchoPantalla()/2-sonidoONoff->getSize().x/2,
								Juego::getAltoPantalla()/2-sonidoONoff->getSize().y/2);
		sonidoONoff->connect("pressed", [&]() {Juego::setHaySonido(!Juego::getHaySonido()); });
		Juego::getGui()->add(sonidoONoff);
	}

	void Opciones::chequearInput() 
	{

	}

	void Opciones::actualizar()
	{
		if (Juego::getHaySonido())
		{
			sonidoONoff->setText("Sonido: ON");
		}
		else
		{
			sonidoONoff->setText("Sonido: OFF");
		}
	}

	void Opciones::dibujar()
	{
		Juego::getWindow()->draw(fondo);
	}

	void Opciones::desinicializar()
	{
	}

	void Opciones::esconderGui()
	{
		atras->setVisible(false);
		sonidoONoff->setVisible(false);
	}

	void Opciones::mostrarGui()
	{
		atras->setVisible(true);
		sonidoONoff->setVisible(true);
	}
}