#pragma once
#include "checkML.h"
#include "SDL.h"
#include "SDL_image.h"
#include "Textures.h"
// Para los archivos de entrada/salida
#include <fstream> 
using namespace std;
class Game;

class GameObject
{
protected:
	Game* game;
	int cellSize; // Tamaño de las celdas de juego (en verdad estando el rectDest no hace falta pero bue)
	SDL_Rect rectDest; // rect de destino al ser pintado (width y heigth se inician a cellSize para que sean cuadradas)

	Textures* texture; // Puntero a la textura que tiene que pintar

	GameObject();
	GameObject(Game* game);

public:

	virtual ~GameObject();
	void loadGameObject(int cellSize, Textures* texture); // Asigna el tamaño de celda y el puntero a textura
	virtual void render() = 0;
	virtual void update() = 0;
	virtual void loadFromFile(ifstream& level) = 0;
	virtual void saveToFile(ofstream& level) = 0;
};

