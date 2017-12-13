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
				 numColMap,
				 cellSize;
public:
	GameMap();
	~GameMap();

	void GameMap::loadFromFile();
	void GameMap::saveToFile();
	void GameMap::update();
};

