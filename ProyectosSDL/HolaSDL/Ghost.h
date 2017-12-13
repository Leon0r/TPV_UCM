#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "GameCharacter.h"

class Ghost :
	public GameCharacter
{
public:
	Ghost();
	~Ghost();

	void Ghost::update();
};

