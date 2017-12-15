#include "GameMap.h"

GameMap::GameMap()
{
}

GameMap::~GameMap()
{
}

// Rellena una celda con el tipo type
void GameMap::fillCell(int row, int col, int type) {

	map[row][col] = static_cast<MapCell>(type); // El casting para convertir de int a MapCell
}

// Lee lo necesario del archivo level para cargar el mapa
void GameMap::loadFromFile(ifstream& level)
{
	GameObject::loadFromFile();
	int type;

	level >> numRowMap;
	level >> numColMap;

	for (int i = 0; i < numRowMap; i++) {
		for (int j = 0; j < numColMap; j++) {
			level >> type;
			fillCell(i, j, type);
		}
	}

}

// Escribe los datos del mapa en el archivo level
void GameMap::saveToFile(ofstream& level)
{
	GameObject::saveToFile();
	level << numRowMap;
	level << numColMap;
	for (int i = 0; i < numRowMap; i++) {
		for (int j = 0; j < numColMap; j++) {

			level << getCellType(i, j) << " ";
		}
		level << endl;
	}
}


// Pinta el mapa en pantalla
void GameMap::render() {

	for (int i = 0; i < numRowMap; i++) {
		for (int j = 0; j < numColMap; j++) {
			GameObject::rectDest.y = cellSize * i;
			GameObject::rectDest.x = cellSize * j;

			texture->renderFrame(GameObject::rectDest, static_cast<int>(map[i][j]), 0);
		}
	}
}

void GameMap::update() 
{

}
