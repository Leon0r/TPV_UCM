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
	if (age < DEATH_AGE) {
		searchDir();
		age++;
	}
	else
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
	
	if (numDirs > 0) { // Solo busca dir si tiene m�s de una posibilidad
		// Solo quita hacia atras si esta en cruces
		// Principalmente es para que no parpadee en la celda donde empieza
		if (numDirs > 2)
			eraseBackDir();// Evita que vaya hacia atras

		int dirAux, i;

		int dist = 3000;
		int aux;
		for (i = 0; i < numDirs; i++) {
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
		possibleDirs();
		i = 0;
		// Para cada direccion posible busca si hay algun fantasma
		while (i < numDirs && !isGhost(posAct.x + directions[i].x, posAct.y + directions[i].y, it)) {
			i++;
		}
		// Si hay algun fantasma, es adulto y da probabilidad, nace otro en una de las dirs libres
		if (i < numDirs && age >= ADULT_AGE && age <= DEATH_AGE ) {//&& (rand() % 10 == 1)
			cout << "nace";
			giveBirth();
		}

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
		// Para que vaya al contrario que el padre
		ghost->dir.x = -dir.x;
		ghost->dir.y = -dir.y;
		//la posicion libre
		ghost->posAct.x = 1;
		ghost->posAct.y = 1;
		ghost->game = game;
		ghost->posIni.x = ghost->posAct.x;
		ghost->posAct.y = ghost->posAct.y;
		ghost->targetPos = targetPos;
		ghost->cellSize = 15;
		ghost->rectDest.h = ghost->cellSize;
		ghost->rectDest.w = ghost->cellSize;
		ghost->texture = texture;
		game->newSmartGhost(ghost);
//}
}