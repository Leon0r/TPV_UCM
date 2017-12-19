#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "Textures.h"
// Para los archivos de entrada/salida
#include <fstream> 
using namespace std;

class GameObject
{
protected:
	
	int cellSize; // Tamaño de las celdas de juego (en verdad estando el rectDest no hace falta pero bue)
	SDL_Rect rectDest; // rect de destino al ser pintado (width y heigth se inician a cellSize para que sean cuadradas)

	Textures* texture; // Puntero a la textura que tiene que pintar
	
public:
	GameObject();
	~GameObject();

	void GameObject::loadGameObject(int cellSize, Textures* texture); // Asigna el tamaño de celda y el puntero a textura
	void GameObject::render();
	void GameObject::update();
	void GameObject::loadFromFile();
	void GameObject::saveToFile();
};

