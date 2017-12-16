#include "GameCharacter.h"



GameCharacter::GameCharacter()
{
}


GameCharacter::~GameCharacter()
{
}

void GameCharacter::loadCharacter(ifstream& level, int esqTextX, int cellSize, Textures * texture)
{
	loadGameObject(cellSize, texture);
	loadFromFile(level);
	frame.x = esqTextX;
	frame.y = 0;
}

void GameCharacter::update() {

}

void GameCharacter::render() {
	GameObject::render();

}

// Lee lo necesario del archivo para cargar el GameCharacter
void GameCharacter::loadFromFile(ifstream& level) {
	// Inicializa las posiciones inicial y actual a la pos de entrada
	level >> posAct.x;
	level >> posAct.y;
	level >> posIni.x;
	level >> posIni.y;
	// Inicializa la direccion de movimiento
	level >> dir.x;
	level >> dir.y;
}

// Escribe posAct, posIni, dir del GameCharacter
void GameCharacter::saveToFile(ofstream& level) {
	level << posAct.x << " " << posAct.y << " "
		<< posIni.x << " " << posIni.y << " "
		<< dir.x << " " << dir.y;
}