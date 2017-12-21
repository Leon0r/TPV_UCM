#include "GameMap.h"
#include "Game.h"

GameMap::GameMap():GameObject(){
}

GameMap::GameMap(Game* game):GameObject(game) {
}

GameMap::~GameMap()
{
	for (int i = 0; i < numRowMap; i++)
		delete map[i];

	delete map;
}

// Lee lo necesario del archivo level para cargar el mapa
void GameMap::loadMap(ifstream& level, int cellSize, Textures* texture) {

	loadGameObject(cellSize, texture);
	loadFromFile(level); // Lee los datos del archivo y los pasa a MapCell
}

// Rellena una celda con el tipo type
void GameMap::fillCell(int row, int col, int type) {

	// El casting para convertir de int a MapCell 
	// (0 = empty, 1 = wall, 2 = food, 3 = vitamin)
	map[row][col] = static_cast<MapCell>(type); 
}

// Lee lo necesario del archivo level para cargar el mapa
void GameMap::loadFromFile(ifstream& level)
{
	int type;

	level >> numRowMap;
	level >> numColMap;

	// Inicializa el mapa a MapCell
	map = new MapCell*[numRowMap];

	for (int i = 0; i < numRowMap; i++)
		map[i] = new MapCell[numColMap];

	// Asigna el tipo que le corresponde a cada celda 
	for (int i = 0; i < numRowMap; i++) {
		for (int j = 0; j < numColMap; j++) {
			level >> type;
			fillCell(i, j, type);
			if (type >= 2)
				game->addFood();
		}
	}
}

// Escribe los datos del mapa en el archivo level (solo los datos del mapa)
void GameMap::saveToFile(ofstream& level)
{
	level << numRowMap << " ";
	level << numColMap << endl;
	for (int i = 0; i < numRowMap; i++) {
		for (int j = 0; j < numColMap; j++) {

			level << getCellType(i, j) << " "; 
		}
		level << endl;
	}
	level << endl;
}

// Pinta el mapa en pantalla (renderCopy de las celdas)
void GameMap::render() {

	int aux;

	for (int i = 0; i < numRowMap; i++) {
		for (int j = 0; j < numColMap; j++) {
			rectDest.y = cellSize * i + 100;
			rectDest.x = cellSize * j;
			aux = static_cast<int>(map[i][j]); // Estan colocadas en el png para que sea el mismo orden (0=empty, etc)
			texture->renderFrame(rectDest, aux, 0);
		}
	}
}

void GameMap::update()
{

}
