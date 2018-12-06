#ifndef PANTALLA_H
#define PANTALLA_H

namespace juego
{
	class Juego;

	class Pantalla
	{
	public:
		Pantalla();
		~Pantalla();
		virtual void inicializar() = 0;
		virtual void chequearInput() = 0;
		virtual void actualizar() = 0;
		virtual void dibujar() = 0;
		virtual void desinicializar() = 0;
		virtual void esconderGui() = 0;
		virtual void mostrarGui() = 0;
	};
}
#endif