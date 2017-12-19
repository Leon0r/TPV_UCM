#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "GameObject.h"

class Game; // Evita llamadas circulares

// struct "par" para manejar direcciones y posiciones como pares (x, y) de enteros
struct par {
	int x;
	int y;
};

class GameCharacter :
	public GameObject
{
protected:
	par posIni; // Pos inicial del character para reiniciarla al morir
	par posAct; // Pos actual del character
	par dir; // Direccion actual del character

	par frame; // Coordenadas en la textura del frame (esquina sup izquierda) concreto a renderizar
	// Como todos los personajes tienen las animaciones colocadas igual, 
	// solo hace falta saber d�nde empieza cada una

	Game* game;

public:
	GameCharacter();
	~GameCharacter();

	void GameCharacter::loadCharacter(ifstream& level, int esqTextX, int cellSize, Textures* texture, Game* game);
	void GameCharacter::update();

	void GameCharacter::render();
	void GameCharacter::loadFromFile(ifstream& level); // Lee lo necesario del archivo para cargar el GameCharacter
	void GameCharacter::saveToFile(ofstream& level); // Escribe posAct, posIni, dir del GameCharacter
	bool GameCharacter::sigPosToroideEsLibre(par dirAct); // Solo mira que en dir se pueda mover (para el random de fantasmas)
	bool GameCharacter::sigPosToroideEsLibre(par dirAct, par& nextPos); // Devuelve la sig posicion en la direccion dir
};

