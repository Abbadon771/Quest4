#include "constants.h"
#include "Rios.h"	


Rios::Rios(int poX, int poY) : Object(poX,poY)
{
	rise = true;
	moveCount = 0;
	moveCountMax = (SCREEN_HEIGHT - poY - RIOS_SPRITE_HEIGHT) / RIOS_SPEED;
	objectID = RIOS;
}
void Rios::update(S_TRANSITION)
{
	//movement of rios up and down.  If rios is at its highest point, rise is true and it comes back down
	if (rise == true)
	{
		posY = posY + RIOS_SPEED;
	}
	else
	{
		posY = posY - RIOS_SPEED;
	}
	moveCount++;
	//If rios is at its lowest point, rise is false and it goes up
	if (moveCount >= moveCountMax)
	{
		moveCount = 0;
		rise = !rise;
	}
}