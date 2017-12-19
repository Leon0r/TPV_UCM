#pragma once
#include "GameMap.h"
class Pacman; // Evita llamadas circulares

class Game
{
private:
	GameMap* map;
	Pacman* pacman;

	int foodLeft;

	// Eventos
	SDL_Event event;
	bool exit = false;

	void Game::Right(int& posX);
	void Game::Left(int& posX);
	void Game::Down(int& posY);
	void Game::Up(int& posY);

public:
	Game();
	~Game();
	// Bucle principal del juego
	void Game::run();
	// Se encarga de los eventos de teclado
	void Game::handleEvents();
	bool Game::nextCell(int posX, int posY, const int dirX, const int dirY);
	// Consulta si la casilla es comestible: comida o energ�a, en el segundo caso devuelve true
	bool Game::cellEatable(const int x, const int y);
	void Game::collisionWithGhost(int x, int y);
	void Game::nextPosToroide(int& posX, int& posY, const int dirX, const int dirY);
};

