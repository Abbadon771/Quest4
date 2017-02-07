#include "constants.h"
#include "Object.h"

Object::Object(int pX, int pY)
{
	posX = pX;
	posY = pY;
	objectID = OBJECT;
	spriteID = -1;
}
//converts float to int
int Object::plotX() 
{
	return (int)posX;
}

int Object::plotY()
{
	return (int)posY;
}
//get functions
int Object::getSpriteID() 
{
	return spriteID;
}
int Object::getPosX()
{
	return posX;
}
int Object::getPosY()
{
	return posY;
}
int Object::getObjectID()
{
	return objectID;
}
//set functions
void Object::setPosX(float pooX)
{
	posX = pooX;
}

void Object::setPosY(float pooY)
{
	posY = pooY;
}