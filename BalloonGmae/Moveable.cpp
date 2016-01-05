#include "Moveable.h"


Moveable::Moveable(sizeofScreenBuffer myScreenBufferSize,location myLoc, SPEED spd, DIRECTION dir, int pointsIfMoveableWins, int pointsIfCosmoWins,BALLOON_STATE type ):myScreenBufferSize(myScreenBufferSize),myLoc(myLoc),spd(spd),pointsIfMoveableWins(pointsIfMoveableWins),pointsIfCosmoWins(pointsIfCosmoWins),type(type)
{
}

void Moveable::setDirection(DIRECTION dir){
	this->dir = dir;
}
void Moveable::setSpeed(SPEED spd){
	this->spd = spd;
}


bool Moveable::draw(std::vector<std::string> &myScreenVector){
	//this -> myScreenVector;
	return true;
}


Moveable::~Moveable(void){

}


void Moveable::setCollidedState(COLLISION col)
{

	if(col!=NO)
		setCollidable(false);
	this->col = col;
}


