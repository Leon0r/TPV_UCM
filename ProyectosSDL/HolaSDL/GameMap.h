#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "GameObject.h"
class Game;
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
	GameMap(Game* game);
	virtual ~GameMap();

 

	// Devuelve el tipo de la celda													
	int getCellType(int row, int col) {return(static_cast<int>(map[row][col]));};
	// Devuelve el numero de filas que hay en el mapa
	int getNumRow() { return numRowMap; }; 
	// Devuelve el numero de columnas que hay en el mapa
	int getNumCols() { return numColMap; }; 

	// Rellena una celda con el tipo type
	void fillCell(int row, int col, int type);

	/// SON NECESARIOS LOS DOS ¿¿
	// Lee lo necesario del archivo level para cargar el mapa
	void loadMap(ifstream& level, int cellSize, Textures* texture); 
	// Lee lo necesario del archivo level para cargar el mapa
	virtual void loadFromFile(ifstream& level);
	// Escribe los datos del mapa en el archivo level
	virtual void saveToFile(ofstream& level); 
	// Pinta el mapa en pantalla
	virtual void render(); 

	virtual void update();
};

