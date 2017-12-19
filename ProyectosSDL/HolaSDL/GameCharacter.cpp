#include "GameCharacter.h"
#include "Game.h"

GameCharacter::GameCharacter():GameObject() {

}

GameCharacter::GameCharacter(Game* game):GameObject(game) {

}

GameCharacter::~GameCharacter()
{
}

void GameCharacter::loadCharacter(ifstream& level, int esqTextX, int cellSize, Textures * texture, Game* game)
{
	loadGameObject(cellSize, texture);
	loadFromFile(level);
	frame.x = esqTextX;
	frame.y = 0;
	GameCharacter::game = game;
}

void GameCharacter::update() {

}

void GameCharacter::render() {
	rectDest.x = rectDest.w*posAct.x;
	rectDest.y = rectDest.h*posAct.y;

	texture->renderFrame(rectDest, frame.y, frame.x);
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

// Devuelve true si la sig posicion en direccion dir es libre y la devuelve en nextPos la sig posicion calculada
bool GameCharacter::sigPosToroideEsLibre(par dirAct, par& nextPos) {
	nextPos = posAct;
	game->nextPosToroide(nextPos.x, nextPos.y, dirAct.x, dirAct.y);
	return game->nextCell(posAct.x, posAct.y, dirAct.x, dirAct.y);
}

bool GameCharacter::sigPosToroideEsLibre(par dirAct) { 
	return (game->nextCell(posAct.x, posAct.y, dirAct.x, dirAct.y)); 
}