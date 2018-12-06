#include "gameplay.h"

#include "objetos/jugador.h"
#include "juego/juego.h"
#include "objetos/enemigo.h"

namespace juego
{
	const int tam_tiles = 32;

	bool Gameplay::ganador = false;

	Gameplay::Gameplay()
	{
		jugador = new Jugador(90, 2000, { 150.f,250.f });
		crearEnemigo();
		
		view.setSize(static_cast<float>(Juego::getAnchoPantalla() / 2.5f), static_cast<float>(Juego::getAnchoPantalla() / 2.5f));
		view.setCenter(jugador->getPos());
		jugador->inicializar();

		botonPausa = tgui::Button::create();
		botonPausa->setSize(40, 40);
		botonPausa->setText("| |");
		botonPausa->setPosition(Juego::getAnchoPantalla() - botonPausa->getSize().x*1.5f, botonPausa->getSize().y / 2);
		botonPausa->setRenderer(Juego::getTheme().getRenderer("Button"));
		botonPausa->connect("pressed", [&]() {Juego::setEstadoActual(pausa, false); });
		Juego::getGui()->add(botonPausa);
		setGanador(false);
	}

	Gameplay::~Gameplay()
	{
		delete jugador;
	}

	void Gameplay::inicializar()
	{
		reiniciar();
	}

	void Gameplay::reiniciar()
	{
		jugador->inicializar();

	}

	void Gameplay::chequearInput()
	{
		
	}

	void Gameplay::actualizar()
	{
		
	}

	void Gameplay::dibujar()
	{
		Juego::getWindow()->setView(view);
		jugador->dibujar();
	}

	void Gameplay::desinicializar()
	{
		delete jugador;
	}	

	void Gameplay::crearEnemigo()
	{
		
	}

	void Gameplay::esconderGui()
	{
		botonPausa->setVisible(false);
		view.setCenter({ static_cast<float>(Juego::getAnchoPantalla() / 2),static_cast<float>(Juego::getAltoPantalla() / 2) });
	}

	void Gameplay::mostrarGui()
	{
		botonPausa->setVisible(true);
	}

	bool Gameplay::getGanador()
	{
		return ganador;
	}

	void Gameplay::setGanador(bool g)
	{
		ganador = g;
	}
}