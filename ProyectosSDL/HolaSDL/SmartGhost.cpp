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
	searchDir();
	GameCharacter::update();
}

// Lee los datos de archivo
void SmartGhost::loadFromFile(ifstream& level) {
	GameCharacter::loadFromFile(level);
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

	possibleDirs();

	if (numDirs > 1) { // Solo busca dir si tiene más de una posibilidad
		int dirAux, i;

		int dist = 3000;
		int auxDistY, aux;
		for (i = 0; i < numDirs; i++) {
			// Calcula la coordenada que le deja mas cerca del pacman
			aux = abs((posAct.x + dir.x) - targetPos->x);
			auxDistY = abs((posAct.y + dir.x) - targetPos->y);
			if (aux < auxDistY)
				aux = auxDistY;
			// Guarda la pos de la dir mas cercana
			if (aux < dist) {
				dist = aux;
				dirAux = i; 
			}
		}
		dir.x = directions[dirAux].x;
		dir.y = directions[dirAux].y;
	}
}

