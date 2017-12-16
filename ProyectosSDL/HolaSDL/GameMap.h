#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "GameObject.h"

class GameMap :
	public GameObject
{
private:
	// Filas y columnas del mapa
	unsigned int numRowMap,
				 numColMap;
	
	// Tipos de celda del mapa de juego
	enum MapCell {Empty, Wall, Food, Vitamin};
	MapCell** map;

public:
	GameMap();
	~GameMap();

	void GameMap::fillCell(int row, int col, int type); // Rellena una celda con el tipo type

	// Devuelve el tipo de la celda													
	int GameMap::getCellType(int row, int col) {return(static_cast<int>(map[row][col]));};

	int GameMap::getNumRow() { return numRowMap; }; // Devuelve el numero de filas que hay en el mapa
	int GameMap::getNumCols() { return numColMap; }; // Devuelve el numero de columnas que hay en el mapa

	void GameMap::loadMap(ifstream& level, int cellSize, Textures* texture); // Lee lo necesario del archivo level para cargar el mapa
	void GameMap::loadFromFile(ifstream& level); // Lee lo necesario del archivo level para cargar el mapa
	void GameMap::saveToFile(ofstream& level); // Escribe los datos del mapa en el archivo level
	void GameMap::update();
	void GameMap::render(); // Pinta el mapa en pantalla
};

