#include "checkML.h"
#include "Game.h"
//const int NUM_TEXTURES = 2;

int main(int argc, char* argv[]){
	
	Game* game;
	game = new Game();

	game->run();

	return 0;
}