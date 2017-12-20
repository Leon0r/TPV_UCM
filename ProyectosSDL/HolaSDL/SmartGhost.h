#pragma once
#include "Ghost.h"

class SmartGhost :
	public Ghost
{
private:
	int edad;

public:
	SmartGhost();
	SmartGhost(Game* game);

	virtual ~SmartGhost();

	virtual void SmartGhost::update();
	virtual void SmartGhost::loadFromFile(ifstream& level);
	virtual void SmartGhost::saveToFile(ofstream& level);
};

