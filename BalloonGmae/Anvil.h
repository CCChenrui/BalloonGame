#pragma once
#include "moveable.h"

class Anvil :
	public Moveable
{
public:
	Anvil(sizeofScreenBuffer myScreenBufferSize,location myLoc, int iHowLongBeforeFall, SPEED spd=NO_SPD, DIRECTION dir=DOWN,BALLOON_STATE type=IS_BEE);
	virtual ~Anvil(void);

	//returns true if its time to delete
	virtual bool draw(std::vector<std::string> &myScreenVector);	

private:
	//waits around a while before it falls 
	int iHowLongBeforeFall;
};
