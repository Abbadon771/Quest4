#include "constants.h"
#include "Block.h"	

Block::Block(int x, int y) : Object(x,y)
{
	posX = x;
	posY = y;
	objectID = BLOCK;
}

void Block::update(S_TRANSITION) 
{
	//this is empty
}