#include "Ghost.h"

Ghost::Ghost():GameCharacter()
{
	// Inicializa el random para las direcciones
	srand(time(nullptr)); // Sin el #include <time.h> no funciona
}

Ghost::Ghost(Game* game):GameCharacter(game){
	type = 0;
}

Ghost::~Ghost()
{
}

void Ghost::update() {
	chooseDir();
	GameCharacter::update();
}

// Elige la sig direccin con un random
void Ghost::chooseDir() {

	// Busca las posibles dirs del fantasma
	possibleDirs();
	// Quita, si puede, la direccion de la que viene
	eraseBackDir();

	if (numDirs > 0) {
		// Genera la posicion de la nueva direccion con el modulo del random que sale
		int nextDir = (rand() % numDirs);
		dir.x = directions[nextDir].x;
		dir.y = directions[nextDir].y;
	}
}

// Busca las posibles dirs del fantasma
void Ghost::possibleDirs() {
	numDirs = 4; // Empieza asumiendo que puede ir en cualquiera de las 4 direcciones
	int i = 0;
	while (i < numDirs) {

		if (!sigPosToroideEsLibre(directions[i])) // Si la direccion que prueba no es válida (hay muro)
		{
			/*
			Tiene todas las direcciones en el vector
			Las va probando y, si no son válidas, intercambia la posicion con la última del vector
			porque aun no se ha probado seguro.
			NumDirs apunta al siguiente al ultimo, por lo que al hacer direcciones[numDirs - 1] entras el el último que no se ha probado
			Se resta (numDirs--) para dejar "descartadas" las dirs que no son válidas, en vez de inicializar el vector cada vez
			Y cuando acabe el bucle, las direcciones posibles deberian estar entre 0 y numDirs-1
			*/
			swap(directions[i].x, directions[numDirs - 1].x);
			swap(directions[i].y, directions[numDirs - 1].y);
			numDirs--;
		}
		else
			i++;
	}

	
}
// Quita, si puede, la direccion de la que viene
void Ghost::eraseBackDir() {
	// Elimina la direccion de la que viene si tiene mas direcciones posibles
	if (numDirs > 1) {
		int i = 0; // reutiliza la variable contador del bucle anterior porque a esta altura no se necesita más

			   // Busca la direccion contraria a la que viene y la descarta de igual forma que en el bucle anterior
		while ((i<numDirs) && (directions[i].x != -dir.x || directions[i].y != -dir.y))
			i++;
		if (i < numDirs) {
			// Cambia la direccion de la que viene por la última válida
			swap(directions[i].x, directions[numDirs - 1].x);
			swap(directions[i].y, directions[numDirs - 1].y);
			numDirs--;
		}
	}
}

void Ghost::die() {

}