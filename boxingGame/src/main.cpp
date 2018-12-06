#include "juego/juego.h"

using namespace juego;

int main()
{
	Juego* j = new Juego();

	j->ejecutar(j);

	delete j;

	return 0;
}
