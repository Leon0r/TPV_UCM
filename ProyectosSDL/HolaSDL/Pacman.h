#pragma once
#include "GameCharacter.h"
class Pacman :
	public GameCharacter
{
public:
	Pacman();
	~Pacman();

	void Pacman::render();
	void Pacman::loadFromFile();
	void Pacman::saveToFile();
};

