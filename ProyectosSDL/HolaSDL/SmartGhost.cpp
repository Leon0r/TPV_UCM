#include "SmartGhost.h"
#include "Game.h"

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
	age++;
	if (age > DEATH_AGE)
		dieOld();
	GameCharacter::update();
}

// Lee los datos de archivo
void SmartGhost::loadFromFile(ifstream& level) {
	GameCharacter::loadFromFile(level);
	level >> age;
}

// Guarda en archivo
void SmartGhost::saveToFile(ofstream& level) {
	GameCharacter::saveToFile(level);
	level << " " << age;
}

// Muerte "natural" de fantasma
void SmartGhost::dieOld() {

	dead = true;
	// dir a 0 para asegurar que se para
	dir.x = 0;
	dir.y = 0;
}

void SmartGhost::die() {
	GameCharacter::die();
}

// De las dirs posibles, busca la que mas le acerque a Pacman
void SmartGhost::searchDir() {
	list <GameCharacter*>::iterator it;
	possibleDirs();

	if (numDirs > 1) { // Solo busca dir si tiene m�s de una posibilidad
		int dirAux, i;

		int dist = 3000;
		int aux;
		for (i = 0; i < directions.size(); i++) {
			{
				// Calcula la coordenada que le deja mas "cerca" del pacman
				aux = abs((posAct.x + directions[i].x) - targetPos->x) +
					abs((posAct.y + directions[i].y) - targetPos->y);

				// Guarda la pos de la dir mas cercana
				if (aux < dist) {
					dist = aux;
					dirAux = i;
				}
			}
		}
		dir.x = directions[dirAux].x;
		dir.y = directions[dirAux].y;

		/// METODO A PARTE: 
		///CAMBIAR A UN WHILE QUE VACIE LAS DIRECCIONES OTRA VEZ Y COMPRUEBE DONDE HAY LIBRE
		/// UNA CASILLA Y AHÍ GIVEABIRTH
		/*for (int i = 0; i < directions.size(); i++) {
			cout << endl << directions.size() << " "  << i << endl;
			if (isGhost(posAct.x + directions[i].x, posAct.y + directions[i].y, it))
				giveBirth();
		}*/
	}
}

void SmartGhost::giveBirth() {
//	if (rand() % 10000 == 1){
		SmartGhost* ghost = new SmartGhost();
		ghost->age = 0;
		ghost->dir = dir;
		ghost->posAct = posAct;
		ghost->game = game;
		ghost->posIni = posAct;
		ghost->targetPos = targetPos;
		ghost->texture = texture;
		game->newSmartGhost(ghost);
//}
}