#pragma once
#include <vector>
#include <time.h>
#include "GameCharacter.h"

class Ghost :
	public GameCharacter
{
private:
	int numDirs = 4; // Numero posible de dirs
	// inicializa el vector de direcciones a las 4 posibles (arriba, abajo, izquierda, derecha)
	vector<par> directions{ { 0,-1 },{ 0,1 },{ -1,0 },{ 1,0 } }; 
	void Ghost::chooseDir(); // Elige la sig direccin con un random
	void Ghost::possibleDirs(); // Busca las posibles dirs del fantasma

public:
	Ghost();
	Ghost(Game* game);

	virtual ~Ghost();

	virtual void update();
};

