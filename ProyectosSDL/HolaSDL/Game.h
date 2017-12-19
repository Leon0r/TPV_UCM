#pragma once
#include "GameMap.h"
class Pacman; // Evita llamadas circulares

class Game
{
private:
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;

	const int winWidth = 600;
	const int winHeigth = 600;
	int winX,
		winY;


	GameMap* map;
	Pacman* pacman;

	int foodLeft;

	// Eventos
	SDL_Event* event = nullptr;
	bool exit = false;

	void Game::Right(int& posX);
	void Game::Left(int& posX);
	void Game::Down(int& posY);
	void Game::Up(int& posY);

public:
	Game();
	~Game();
	void Game::loadGame();
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

