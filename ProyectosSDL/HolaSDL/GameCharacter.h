#pragma once
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

