#include "Ghost.h"



Ghost::Ghost()
{
	// Inicializa el random para las direcciones
	srand(time(nullptr)); // Sin el #include <time.h> no funciona
}


Ghost::~Ghost()
{
}

void Ghost::update() {
	GameCharacter::update();
}