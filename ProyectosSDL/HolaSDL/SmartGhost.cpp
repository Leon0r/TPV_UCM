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
	Ghost::loadFromFile(level);
	level >> edad;
}
void SmartGhost::saveToFile(ofstream& level) {
	Ghost::saveToFile(level);
	level << edad;
}