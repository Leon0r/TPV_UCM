#pragma once
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
	par posAux = { 0, 0 };

	par* targetPos = nullptr; // Posicion hacia la que se mueve

	par frame; // Coordenadas en la textura del frame (esquina sup izquierda) concreto a renderizar
	// Como todos los personajes tienen las animaciones colocadas igual, 
	// solo hace falta saber donde empieza cada una

	int type; // guarda el tipo de personaje (0 = fant tonto, 1 = fant evol, 2 = pacman)  

	GameCharacter();
	GameCharacter(Game* game);

public:
	virtual ~GameCharacter();

	// Devuelve la posicion actual del personaje
	virtual void getPosAct(int& posX, int& posY) { posX = posAct.x; posY = posAct.y; };
	virtual par* getPosAct() { return &posAct; };
	// Recibe la posicion hacia la que se tiene que mover
	void setTarget(par* posPacman) { targetPos = posPacman; };

	// devuelve el tipo del personaje
	virtual int getType() { return type; }; // devuelve el tipo del personaje

	void loadCharacter(ifstream& level, int esqTextX, int cellSize, Textures* texture, Game* game);
	virtual void update();
	virtual void render();
	// Lee lo necesario del archivo para cargar el GameCharacter
	virtual void loadFromFile(ifstream& level);
	// Escribe posAct, posIni, dir del GameCharacter
	virtual void saveToFile(ofstream& level);
	// Devuelve true si la sig posicion en direccion dir es libre y la devuelve en nextPos la sig posicion calculada
	bool sigPosToroideEsLibre(par dirAct, par& nextPos);
	// Solo mira que en dir se pueda mover (para el random de fantasmas)
	bool sigPosToroideEsLibre(par dirAct);
	// Reinicio de pos personaje al morir
	virtual void die();
 };

