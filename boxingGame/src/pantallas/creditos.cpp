#include "creditos.h"

#include "juego/juego.h"

namespace juego
{
	static sf::Sprite spr;

	Creditos::Creditos()
	{
		fondo.loadFromFile("res/assets/creditos.png");
	}


	Creditos::~Creditos()
	{
	}

	void Creditos::inicializar()
	{
		spr.setTexture(fondo);
		spr.setPosition(0, 0);
		
		atras = Button::create();
		atras->setText("Atras");
		atras->setRenderer(Juego::getTheme().getRenderer("Button"));
		atras->setTextSize(10);
		atras->setSize(60, 30);
		atras->setPosition(atras->getSize().x / 2, atras->getSize().y / 2);
		atras->connect("pressed", [&]() {Juego::setEstadoActual(menu, false); });
		Juego::getGui()->add(atras);
	}

	void Creditos::chequearInput()
	{

	}

	void Creditos::actualizar()
	{

	}

	void Creditos::dibujar()
	{
		Juego::getWindow()->draw(spr);
		Juego::dibujarVersion();
	}

	void Creditos::desinicializar()
	{
	}

	void Creditos::esconderGui()
	{
		atras->setVisible(false);
	}

	void Creditos::mostrarGui()
	{
		atras->setVisible(true);
	}
}