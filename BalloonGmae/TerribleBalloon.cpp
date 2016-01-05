#include "TerribleBalloon.h"
#include <time.h>

TerribleBalloon::TerribleBalloon(sizeofScreenBuffer myScreenBufferSize,location myLoc, int iHowLongBeforeChangeDir, SPEED spd, DIRECTION dir,BALLOON_STATE type):Balloon(myScreenBufferSize,myLoc,iHowLongBeforeFall,spd,dir)
{
	pointsIfMoveableWins=0;
	pointsIfCosmoWins=0;
	dir=(DIRECTION)((rand()%4)+1);
	this->iHowLongBeforeChangeDir=iHowLongBeforeChangeDir;
}


TerribleBalloon::~TerribleBalloon(void)
{

}

bool TerribleBalloon::draw(std::vector<std::string> &myScreenVector){			//pure virtual, abstract base class, MUST BE DEFINED BY DERIVED CLASSES	
	bool bDeleteMe = false;
	int Rside,Bside;
	
	if (DEFAULT_HEIGHT-1<myLoc.y+2) return true; else Bside=myLoc.y+2;
	switch(dir){
	case UP:

		if (DEFAULT_WIDTH>=myLoc.x+3) Rside=3; else return true;
		if (myLoc.y<DEFAULT_HEIGHT) myScreenVector[myLoc.y  ].replace(myLoc.x,Rside,		" ||");
		if (myLoc.y+1<DEFAULT_HEIGHT) myScreenVector[myLoc.y+1  ].replace(myLoc.x,Rside,	"(o3");
		if (myLoc.y+2<DEFAULT_HEIGHT) myScreenVector[myLoc.y+2  ].replace(myLoc.x,Rside,	"(o3");
		if (myLoc.y+3<DEFAULT_HEIGHT) myScreenVector[myLoc.y+3  ].replace(myLoc.x,Rside,	"  3");
		if (myLoc.y>=1) myLoc.y--;
		else return true;
		break;

	case DOWN:

		if (DEFAULT_WIDTH>=myLoc.x+3) Rside=3; else return true;
		if (myLoc.y<DEFAULT_HEIGHT) myScreenVector[myLoc.y  ].replace(myLoc.x,Rside,		" 3 ");
		if (myLoc.y+1<DEFAULT_HEIGHT) myScreenVector[myLoc.y+1  ].replace(myLoc.x,Rside,	"3o)");
		if (myLoc.y+2<DEFAULT_HEIGHT) myScreenVector[myLoc.y+2  ].replace(myLoc.x,Rside,	"3o)");
		if (myLoc.y+3<DEFAULT_HEIGHT) myScreenVector[myLoc.y+3  ].replace(myLoc.x,Rside,	"|| ");
		if (myLoc.y+1<DEFAULT_HEIGHT) myLoc.y++;
		else return true;
		break;

	case LEFT:

		if (DEFAULT_WIDTH>=myLoc.x+4) Rside=4; else return true;
		if (myLoc.x>=0 && myLoc.y<Bside) myScreenVector[myLoc.y  ].replace(myLoc.x,Rside,		"()()");
		if (myLoc.x+1>=0 && myLoc.y+1<Bside) myScreenVector[myLoc.y+1  ].replace(myLoc.x,Rside,	"OOO-");
		if (myLoc.x+2>=0 && myLoc.y+2<Bside) myScreenVector[myLoc.y+2  ].replace(myLoc.x,Rside,	"()()");
		if (myLoc.x>=1) myLoc.x--;
		else return true;
		break;

	case RIGHT:

		if (DEFAULT_WIDTH-1>=myLoc.x+4) Rside=4; else return true;
		if (myLoc.x<DEFAULT_WIDTH && myLoc.y<Bside) myScreenVector[myLoc.y  ].replace(myLoc.x,Rside,		"()()");
		if (myLoc.x+1<DEFAULT_WIDTH && myLoc.y+1<Bside) myScreenVector[myLoc.y+1  ].replace(myLoc.x,Rside,	"-OOO");
		if (myLoc.x+2<DEFAULT_WIDTH && myLoc.y+2<Bside) myScreenVector[myLoc.y+2  ].replace(myLoc.x,Rside,	"()()");
		if (myLoc.x+1<DEFAULT_WIDTH) myLoc.x++;
		else return true;
		break;
	}
	
	//int randnum=rand()%100;
	//if (randnum>70)  dir= (DIRECTION)((rand()%4)+1);
	DIRECTION nextDir;
	if (iHowLongBeforeChangeDir ==0) {
		nextDir = (DIRECTION)(rand()%4 +1);
		iHowLongBeforeChangeDir = rand() %4+1;
		setDirection(nextDir);
	} else {
		iHowLongBeforeChangeDir --;
	}
	

	return bDeleteMe;
}