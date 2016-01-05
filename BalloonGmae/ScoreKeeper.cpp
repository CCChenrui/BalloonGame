#include "ScoreKeeper.h"

const char COSMO_SCORE_PREFIX[]		= "COSMO =";
const int  LEN_COSMO_SCORE_PREFIX	= 7;
const char BALLOON_SCORE_PREFIX[]	= "BALLOONS ="; 
const int  LEN_BALLOON_SCORE_PREFIX	= 10;
const int  SPACES_FOR_SCORE			= 6;

ScoreKeeper::ScoreKeeper(void)
{
	resetScores();
}

ScoreKeeper::~ScoreKeeper(void)
{
}

bool ScoreKeeper::getDisplayString(std::string &scoreString){
	//TODO calculate the score that goes in the display string here
	std::string s = std::to_string(scoreCosmo);
	scoreString.replace(0,LEN_COSMO_SCORE_PREFIX,"COSMO ="); scoreString.replace(1+LEN_COSMO_SCORE_PREFIX,SPACES_FOR_SCORE,s); 
	s = std::to_string(scoreBalloon);
	scoreString.replace(62,LEN_BALLOON_SCORE_PREFIX,"BALLOONS ="); scoreString.replace(63+LEN_BALLOON_SCORE_PREFIX,SPACES_FOR_SCORE,s);
	return true;
}
