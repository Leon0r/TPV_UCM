#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include <vector>
#include <time.h>
#include "GameCharacter.h"

class Ghost :
	public GameCharacter
{
private:
	// inicializa el vector de direcciones a las 4 posibles (arriba, abajo, izquierda, derecha)
	vector<par> directions{ { 0,-1 },{ 0,1 },{ -1,0 },{ 1,0 } }; 

public:
	Ghost();
	~Ghost();

	void Ghost::update();
};

