#pragma once
#include "GameMap.h"
#include "Textures.h"
class Pacman; // Evita llamadas circulares

const int NUM_TEXTURES = 2;

class Game
{
private:
	GameMap* map;
	Pacman* pacman;

	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	Textures* textures[NUM_TEXTURES]; // Array de las texturas del juego
	
	// Tamaño y posición de la ventana
	const int winWidth = 600;
	const int winHeigth = 600;
	int winX,
		winY;

	// Struct con lo necesario para inicializar las texturas
	struct infoText {
		const char* filename;
		int numFils;
		int numCols;
	};

	// Array con la información de las texturas
	infoText infoT[NUM_TEXTURES]{
		{ "..\\sprites\\pacmanCellsFull.png", 4, 1 },
		{ "..\\sprites\\pacmanSheet.png", 4, 14 }
	};


	int foodLeft;

	int waitTimeFrame = 100; // A menor tiempo de espera entre frames, mayor la velocidad del bucle
	uint32_t startTime, frameTime; // Control del tiempo de repeticion del bucle

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
	// Inicializa todos los atributos
	void Game::loadGame();
	// Dibuja el estado actual del juego
	void Game::render();
	// Bucle principal del juego
	void Game::run();
	// Se encarga de los eventos de teclado
	void Game::handleEvents();
	// Devuelve true si la sig casilla en direccion dir es vacia
	bool Game::nextCell(int posX, int posY, const int dirX, const int dirY);
	// Calcula la sig pos (con toroide)
	void Game::nextPosToroide(int& posX, int& posY, const int dirX, const int dirY);
	// Consulta si la casilla es comestible: comida o energia, en el segundo caso devuelve true
	bool Game::cellEatable(const int x, const int y);
	// Mira si en hay fantasma en la pos (x,y)
	void Game::collisionWithGhost(int x, int y);

};

