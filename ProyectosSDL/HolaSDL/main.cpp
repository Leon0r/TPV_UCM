
#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
#include <fstream>
using namespace std;

#include"GameMap.h"
const int NUM_TEXTURES = 2;

int main(int argc, char* argv[]){
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;

	// TAMAÑO Y POSICION VENTANA
	const int winWidth = 600;
	const int winHeigth = 600;
	int winX, winY;
	winX = winY = SDL_WINDOWPOS_CENTERED;

	SDL_Init(SDL_INIT_EVERYTHING);

	window = SDL_CreateWindow("Pacman", winX, winY, winWidth, winHeigth, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	Textures* textures[NUM_TEXTURES]; // Array con todas las texturas del juego

	struct infoText {
		const char* filename;
		int numFils;
		int numColumns;
	};
	infoText infoT[NUM_TEXTURES]{ { "..\\sprites\\pacmanCellsFull.png", 4, 1 },{ "..\\sprites\\pacmanSheet.png", 4, 14 } };
	textures[0] = new Textures;
	textures[0]->loadTextureFromImage(renderer, infoT[0].filename, infoT[0].numFils, infoT[0].numColumns);
	GameMap map;
	ifstream level("..\\levels\\level01.pac");
	map.loadMap(level, 20, textures[0]);
	map.render();
	level.close();
	SDL_RenderPresent(renderer);
	system("pause");
	return 0;
}