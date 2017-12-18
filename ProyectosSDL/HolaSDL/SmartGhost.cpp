#include "SmartGhost.h"


SmartGhost::SmartGhost()
{
}


SmartGhost::~SmartGhost()
{
}

void SmartGhost::update() {

}
void SmartGhost::loadFromFile(ifstream& level) {
	GameCharacter::loadFromFile(level);

}
void SmartGhost::saveToFile(ofstream& level) {
	GameCharacter::saveToFile(level);

}