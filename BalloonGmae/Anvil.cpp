#include "Anvil.h"


Anvil::Anvil(sizeofScreenBuffer myScreenBufferSize,location myLoc,int iHowLongBeforeFall, SPEED spd, DIRECTION dir,BALLOON_STATE type ):Moveable(myScreenBufferSize,myLoc,spd, dir,pointsIfMoveableWins,pointsIfCosmoWins)
{
	pointsIfMoveableWins=5;
	pointsIfCosmoWins=5;
}


Anvil::~Anvil(void)
{
}

//returns true if its time to delete this balloon
bool Anvil::draw(std::vector<std::string> &myScreenVector){			//pure virtual, abstract base class, MUST BE DEFINED BY DERIVED CLASSES	
	bool bDeleteMe = false;
	switch(col){
	case COSMO_POPPED:

		if (myLoc.y<DEFAULT_HEIGHT) myScreenVector[myLoc.y  ].replace(myLoc.x,BALLOON_WIDTH,			"    |  ");
		if (myLoc.y+1<DEFAULT_HEIGHT) myScreenVector[myLoc.y+1  ].replace(myLoc.x,BALLOON_WIDTH,		"  \\   /");
		if (myLoc.y+2<DEFAULT_HEIGHT) myScreenVector[myLoc.y+2  ].replace(myLoc.x,BALLOON_WIDTH,		" - pop-");
		if (myLoc.y+3<DEFAULT_HEIGHT) myScreenVector[myLoc.y+3  ].replace(myLoc.x,BALLOON_WIDTH,		"  /   \\");
		if (myLoc.y+4<DEFAULT_HEIGHT) myScreenVector[myLoc.y+4  ].replace(myLoc.x,BALLOON_WIDTH,		"    |  ");
		bDeleteMe = true;
		break;

	case BALLOON_CLOBBERED_COSMO:
		if (myLoc.y<DEFAULT_HEIGHT) myScreenVector[myLoc.y  ].replace(myLoc.x,BALLOON_WIDTH+2,		"  *   *  ");
		if (myLoc.y+1<DEFAULT_HEIGHT) myScreenVector[myLoc.y+1  ].replace(myLoc.x,BALLOON_WIDTH+2,	" * * * * ");
		if (myLoc.y+2<DEFAULT_HEIGHT) myScreenVector[myLoc.y+2  ].replace(myLoc.x,BALLOON_WIDTH+2,	" *BOOM * ");
		if (myLoc.y+3<DEFAULT_HEIGHT) myScreenVector[myLoc.y+3  ].replace(myLoc.x,BALLOON_WIDTH+2,	" * * * * ");
		if (myLoc.y+4<DEFAULT_HEIGHT) myScreenVector[myLoc.y+4  ].replace(myLoc.x,BALLOON_WIDTH+2,	"  *   *  ");
		bDeleteMe = true;
		break;
		

	default:	
		
		if (myLoc.y<DEFAULT_HEIGHT) 	myScreenVector[myLoc.y  ].replace(myLoc.x,BALLOON_WIDTH+3,	"    ___   ");
		if (myLoc.y+1<DEFAULT_HEIGHT) myScreenVector[myLoc.y+1  ].replace(myLoc.x,BALLOON_WIDTH+3,	"   /__/\\  ");
		if (myLoc.y+2<DEFAULT_HEIGHT) myScreenVector[myLoc.y+2  ].replace(myLoc.x,BALLOON_WIDTH+3,	"  /   \\ \\ ");
		if (myLoc.y+3<DEFAULT_HEIGHT) myScreenVector[myLoc.y+3  ].replace(myLoc.x,BALLOON_WIDTH+3,	" /     \\ \\");
		if (myLoc.y+4<DEFAULT_HEIGHT) myScreenVector[myLoc.y+4  ].replace(myLoc.x,BALLOON_WIDTH+3,	"/_______\\/");
		if (myLoc.y+1<DEFAULT_HEIGHT) myLoc.y++;
		else bDeleteMe=true;
		break;
	}

	return bDeleteMe;
}