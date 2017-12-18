#pragma once
#include "GameMap.h"

class Game
{
private:
	GameMap* map;
	void Game::Right(int& posX);
	void Game::Left(int& posX);
	void Game::Down(int& posY);
	void Game::Up(int& posY);
	void Game::nextPosToroide(int& posX, int& posY, const int dirX, const int dirY);

public:
	Game();
	~Game();
	bool Game::nextCell(int posX, int posY, const int dirX, const int dirY);
};

