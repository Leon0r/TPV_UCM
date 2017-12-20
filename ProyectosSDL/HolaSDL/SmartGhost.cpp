#include "SmartGhost.h"


SmartGhost::SmartGhost()
{
}
SmartGhost::SmartGhost(Game* game) :Ghost(game){
	type = 1;
}

SmartGhost::~SmartGhost()
{
}

void SmartGhost::update() {

}

// Lee los datos de archivo
void SmartGhost::loadFromFile(ifstream& level) {
	level >> age;
}

// Guarda en archivo
void SmartGhost::saveToFile(ofstream& level) {
	level << age;
}

// Muerte "natural" de fantasma
void SmartGhost::dieOld() {
	if (age > DEATH_AGE) {
		dead = true;
		// dir a 0 para asegurar que se para
		dir.x = 0;
		dir.y = 0;
	}
}
// De las dirs posibles, busca la que mas le acerque a Pacman
void SmartGhost::searchDir() {
	if (numDirs > 1) { // Solo busca dir si tiene más de una posibilidad
		par dirAux;
		for (int i = 0; i < numDirs; i++) {
			if ()
		}
	}
}