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
	level >> edad;
}
void SmartGhost::saveToFile(ofstream& level) {
	level << edad;
}