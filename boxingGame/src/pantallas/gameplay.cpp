#include "gameplay.h"

#include "juego/juego.h"
#include "objetos/personaje.h"

namespace juego
{
	const int tam_tiles = 32;

	bool Gameplay::ganador = false;

	Gameplay::Gameplay()
	{
		for (int i = 0; i < tipoPersonaje::max; i++)
		{
			personaje[i] = NULL;
		}

		for (int i = 0; i < tipoPersonaje::max; i++)
		{
			if (personaje[i] != NULL)
			{
				if(i=tipoPersonaje::jugador)
					personaje[i] = new Personaje(90, 2000, tipoPersonaje::jugador);
				else
					personaje[i] = new Personaje(90, 2000, tipoPersonaje::rival);
				personaje[i]->inicializar();
			}
		}
		
		
		view.setSize(static_cast<float>(Juego::getAnchoPantalla() / 2.5f), static_cast<float>(Juego::getAnchoPantalla() / 2.5f));

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
		for (int i = 0; i < tipoPersonaje::max; i++)
		{
			if (personaje[i] != NULL)
			{
				delete personaje[i];
			}
		}
	}

	void Gameplay::inicializar()
	{
		reiniciar();
	}

	void Gameplay::reiniciar()
	{
		for (int i = 0; i < tipoPersonaje::max; i++)
		{
			if (personaje[i] != NULL)
			{
				personaje[i]->inicializar();
			}
		}
	}

	void Gameplay::chequearInput()
	{
		
	}

	void Gameplay::actualizar(Personaje* personaje[tipoPersonaje::max])
	{
		for (int i = 0; i < tipoPersonaje::max; i++)
		{
			if (personaje[i] != NULL)
			{
				
			}
		}
	}

	void Gameplay::dibujar()
	{
		Juego::getWindow()->setView(view);

		for (int i = 0; i < tipoPersonaje::max; i++)
		{
			if (personaje[i] != NULL)
			{
				personaje[i]->dibujar();
			}
		}
	}

	void Gameplay::desinicializar()
	{
		for (int i = 0; i < tipoPersonaje::max; i++)
		{
			if (personaje[i] != NULL)
			{
				delete personaje[i];
			}
		}
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