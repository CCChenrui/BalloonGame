#include "Person.h"


Person::Person(sizeofScreenBuffer myScreenBufferSize,location myLoc, SPEED spd, DIRECTION dir ):Moveable(myScreenBufferSize,myLoc, spd, dir),bLegChangePosition(false)
{

}


Person::~Person(void)
{
}

//always return false since person never deleted
bool Person::draw(std::vector<std::string> &myScreenVector){			//pure virtual, abstract base class, MUST BE DEFINED BY DERIVED CLASSES	

	bLegChangePosition = !bLegChangePosition;
	switch(dir){
	case LEFT:
		if (myLoc.x>=0) {
	
			myScreenVector[myLoc.y  ].replace(myLoc.x,PERSON_WIDTH,	    "   \\\\\\\\|//// ");
			myScreenVector[myLoc.y+1  ].replace(myLoc.x,PERSON_WIDTH,		"    |~ ////  ");
			myScreenVector[myLoc.y+2  ].replace(myLoc.x,PERSON_WIDTH,		"    |O  //   ");
			myScreenVector[myLoc.y+3  ].replace(myLoc.x,PERSON_WIDTH,		"   <    |    ");
			myScreenVector[myLoc.y+4  ].replace(myLoc.x,PERSON_WIDTH,		"    |_/ |    ");
			myScreenVector[myLoc.y+5  ].replace(myLoc.x,PERSON_WIDTH,		"--o |__/    ");
			myScreenVector[myLoc.y+6  ].replace(myLoc.x,PERSON_WIDTH,		"   \\__|      ");
			myScreenVector[myLoc.y+7  ].replace(myLoc.x,PERSON_WIDTH,		"      |      ");
		if (bLegChangePosition) {		
			myScreenVector[myLoc.y+8  ].replace(myLoc.x,PERSON_WIDTH,		"     /|      ");
			myScreenVector[myLoc.y+9  ].replace(myLoc.x,PERSON_WIDTH,		"   \\/_|      ");
		}
		else {
			myScreenVector[myLoc.y+8  ].replace(myLoc.x,PERSON_WIDTH,		"      |      ");
			myScreenVector[myLoc.y+9  ].replace(myLoc.x,PERSON_WIDTH,		"    \\||      ");
		}
		if (myLoc.x>=3) myLoc.x--;
		break;
		};
//	

	case RIGHT:
		if (myLoc.x<=DEFAULT_WIDTH) {
			myScreenVector[myLoc.y  ].replace(myLoc.x,PERSON_WIDTH,		" \\\\\\\\|////   ");
			myScreenVector[myLoc.y+1  ].replace(myLoc.x,PERSON_WIDTH,		"  \\\\\\\\ ~|    ");
			myScreenVector[myLoc.y+2  ].replace(myLoc.x,PERSON_WIDTH,		"   \\\\  O|    ");
			myScreenVector[myLoc.y+3  ].replace(myLoc.x,PERSON_WIDTH,		"    |    >   ");
			myScreenVector[myLoc.y+4  ].replace(myLoc.x,PERSON_WIDTH,		"    | \\_|    ");
			myScreenVector[myLoc.y+5  ].replace(myLoc.x,PERSON_WIDTH,		"     \\__| o--");
			myScreenVector[myLoc.y+6  ].replace(myLoc.x,PERSON_WIDTH,		"      |__/   ");
			myScreenVector[myLoc.y+7  ].replace(myLoc.x,PERSON_WIDTH,		"      |      ");
		if (bLegChangePosition) {
			myScreenVector[myLoc.y+8  ].replace(myLoc.x,PERSON_WIDTH,		"      |\\     ");
			myScreenVector[myLoc.y+9  ].replace(myLoc.x,PERSON_WIDTH,		"      |_\\/    ");
		}
		else {
			myScreenVector[myLoc.y+8  ].replace(myLoc.x,PERSON_WIDTH,		"      |     ");
			myScreenVector[myLoc.y+9  ].replace(myLoc.x,PERSON_WIDTH,		"      ||/    ");
		}
		if (myLoc.x<=DEFAULT_WIDTH-15) myLoc.x++;
		break;
		};
//
	case UP:
		 {
			myScreenVector[myLoc.y  ].replace(myLoc.x,PERSON_WIDTH,		" \\\\\\\\\\|///// ");
			myScreenVector[myLoc.y+1  ].replace(myLoc.x,PERSON_WIDTH,		"  \\\\|\\ /|//  ");
			myScreenVector[myLoc.y+2  ].replace(myLoc.x,PERSON_WIDTH,		"   \\|O O|/   ");
			myScreenVector[myLoc.y+3  ].replace(myLoc.x,PERSON_WIDTH,		"    | ^ |    ");
			myScreenVector[myLoc.y+4  ].replace(myLoc.x,PERSON_WIDTH,		" \\  | - |  / ");
			myScreenVector[myLoc.y+5  ].replace(myLoc.x,PERSON_WIDTH,		"  o |___| o  ");
			myScreenVector[myLoc.y+6  ].replace(myLoc.x,PERSON_WIDTH,		"   \\__|__/   ");
			myScreenVector[myLoc.y+7  ].replace(myLoc.x,PERSON_WIDTH,		"      |     ");
			myScreenVector[myLoc.y+8  ].replace(myLoc.x,PERSON_WIDTH,		"      |     ");
			myScreenVector[myLoc.y+9  ].replace(myLoc.x,PERSON_WIDTH,		"     _|_     ");
			break;
		};

	case  NO_DIR:
		 {
			myScreenVector[myLoc.y  ].replace(myLoc.x,PERSON_WIDTH,		" \\\\\\\\\\|///// ");
			myScreenVector[myLoc.y+1  ].replace(myLoc.x,PERSON_WIDTH,		"  \\\\|~ ~|//  ");
			myScreenVector[myLoc.y+2  ].replace(myLoc.x,PERSON_WIDTH,		"   \\|O O|/   ");
			myScreenVector[myLoc.y+3  ].replace(myLoc.x,PERSON_WIDTH,		"    | ^ |    ");
			myScreenVector[myLoc.y+4  ].replace(myLoc.x,PERSON_WIDTH,		"    | v |    ");
			myScreenVector[myLoc.y+5  ].replace(myLoc.x,PERSON_WIDTH,		"    |___|    ");
			myScreenVector[myLoc.y+6  ].replace(myLoc.x,PERSON_WIDTH,		"    __|__    ");
			myScreenVector[myLoc.y+7  ].replace(myLoc.x,PERSON_WIDTH,		"    \\ | /    ");
			myScreenVector[myLoc.y+8  ].replace(myLoc.x,PERSON_WIDTH,		"     0|0     ");
			myScreenVector[myLoc.y+9  ].replace(myLoc.x,PERSON_WIDTH,		"     _|_     ");
			break;
		};
	}

	return false;
}
