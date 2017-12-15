#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "GameObject.h"

// struct "par" para manejar direcciones y posiciones como pares (x, y) de enteros
struct par {
	int x;
	int y;
};

class GameCharacter :
	public GameObject
{
private:
	par posIni; // Pos inicial del character para reiniciarla al morir
	par posAct; // Pos actual del character
	par dir; // Direccion actual del character

	par frame; // Coordenadas en la textura del frame concreto a renderizar


public:
	GameCharacter();
	~GameCharacter();

	void GameCharacter::loadCharacter(int x, int y, int cellSize, Textures* texture);
	void GameCharacter::update();

	void GameCharacter::render();
	void GameCharacter::loadFromFile();
	void GameCharacter::saveToFile();

};

