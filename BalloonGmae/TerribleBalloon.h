#pragma once
#include "Balloon.h"

class TerribleBalloon:
	public Balloon
{
public: 

	TerribleBalloon(sizeofScreenBuffer myScreenBufferSize,location myLoc, int iHowLongBeforeChangeDir, SPEED spd, DIRECTION dir=UP,BALLOON_STATE type=IS_BEE);
	//TerribleBalloon(void);

    virtual bool draw(std::vector<std::string> &myScreenVector);	
	virtual ~TerribleBalloon(void);

	// the time the fly can fly
	int iHowLongBeforeChangeDir;

};