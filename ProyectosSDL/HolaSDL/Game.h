#pragma once
#include "GameMap.h"

class Game
{
private:
	GameMap* map;
	int foodLeft;

	void Game::Right(int& posX);
	void Game::Left(int& posX);
	void Game::Down(int& posY);
	void Game::Up(int& posY);
	

public:
	Game();
	~Game();
	bool Game::nextCell(int posX, int posY, const int dirX, const int dirY);
	// Consulta si la casilla es comestible: comida o energ�a, en el segundo caso devuelve true
	bool Game::cellEatable(const int x, const int y);
	void Game::nextPosToroide(int& posX, int& posY, const int dirX, const int dirY);
};

