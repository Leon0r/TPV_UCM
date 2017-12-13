#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "GameObject.h"

class GameCharacter :
	public GameObject
{
public:
	GameCharacter();
	~GameCharacter();

	void GameCharacter::render();
	void GameCharacter::loadFromFile();
	void GameCharacter::saveToFile();

};

