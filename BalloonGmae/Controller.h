#pragma once
#include <vector> 
#include <memory>
#include "constants.h"
#include "person.h"
#include "balloon.h"
#include "scorekeeper.h"
#include "instructions.h"
#include "Anvil.h"
#include "TerribleBalloon.h"

class Controller
{
public:
	//pass in width and height of console window, plus default speed
	Controller(int width, int height, SPEED speed=SLOW);
	~Controller(void);

	//render the scene
	void draw();
	void createBalloon();


	//change game speed.
	inline void setSpeed(SPEED speed){mSpeed = speed;};

	//current state intro or run
	inline void setControllerState(CONTROLLER_STATE state){mControllerState = state;};

	//TODO you will have to change this function when you replace
	//myBalloons with a polymorphic vector
	//test to see if cosmo has run into an object
	COLLISION hasCollidedWithCosmo(Moveable* pBalloon);

	inline void changeCosmoDirection(DIRECTION dir){cosmo.setDirection(dir);};

	void createAnvil();

	//creat bee 
	void CreatBee(Moveable* pBalloon);

	void changeBalloonState();


private:
	//reset it all
	void initialize();

	//fills screen buffer with blanks
	void clearScreen();

	//draw scores if needed
	void renderScoresToScreenbuffer();
	
	SPEED mSpeed;		//game speed
	//number of game ticks before  created
	int iTimeBetweenBalloonCreation;

	sizeofScreenBuffer myScreenBufferSize;	//width and height of consolewindow

	//holds entire consolewindow screen, 
	//usually 80 chars wide by 24 lines long
	std::vector<std::string> myScreenVector;

	//all of our balloons not polymorphic though
	//std::vector<Balloon> myBalloons;

	
	//cosmo the person
	Person cosmo;

	//for writing instructions
	Instructions myInstructions;

	//max distance between center of squares for a collision to have occured
	//its corner of one object bounding box touching corner of another
	double mCollisionDistance;

	ScoreKeeper scorekeeper;
	CONTROLLER_STATE mControllerState;


	int iTimeBetweenAnvilCreation;
	
	int end;

	// to store the Balloon state berween terrible balloon and normal balloon
	BALLOON_STATE BalloonState ;
	
	// this vector store all the normal balloons and terrible balloons and anvils
	std::vector<std::unique_ptr<Moveable>> myBalloons;
	
};

