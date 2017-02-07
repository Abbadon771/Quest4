//System Headers
#include <fstream>
#include <string>
#include <iostream>

//Game Headers
#include "constants.h"
#include "Engine.h"
#include "Object.h"
#include "Samus.h"
#include "Block.h"
#include "Rios.h"

Engine::Engine(int* spriteHeights)
{
	
	gameOver = false;
	int objectID = 0;
	numObjects = 0;
	int posX = 0;
	int posY = 0;
	OBJECT_ID curObject;
	fstream rin;
	//opens of the file containt all the objects for the assignment
	rin.open("./Assets/Config/level.txt", ios::in);
	//pull in first item to numObjects
	rin >> numObjects;
	objects = new Object*[numObjects];
	for (int i = 0; i < numObjects; i++)
	{//pull in ID, x, and y positions
		rin >> objectID >> posX >> posY;
		switch (objectID)
		{
		case SAMUS:
			objects[i] = new Samus(spriteHeights, posX, posY);
			break;
		case BLOCK:
			objects[i] = new Block(posX, posY);
			break;
		case RIOS:
			objects[i] = new Rios(posX, posY);
		default:
			break;
		}
	}
}
void Engine::changeGameState(S_TRANSITION command) 
{
	
	Object* samus= nullptr;
	Object* rios = nullptr;
	int changePos = 0;
	//applies the update command to all the objects in the array
	for (int i = 0; i < numObjects; i++)
	{
		objects[i]->update(command);
		if (objects[i]->getObjectID() == SAMUS)
		{
			samus = (Samus*)objects[i];
		}
		
	}
	//creates the sidescrolling apsect of the program.  As Samus goes past half the screen, then block and rios move to the left
	if (samus->getPosX() > SCREEN_WIDTH / 2)
	{
		samus->setPosX(samus->getPosX() - S_RUN_SPEED);
		for (int j = 0; j < numObjects; j++)
		{
			if (objects[j]->getObjectID() != SAMUS)
			{
				
				objects[j]->setPosX(objects[j]->getPosX() - S_RUN_SPEED);
			}
		}
	}

	for (int i = 0; i < numObjects; i++)
	{
		//new object to hold object rios
		Object* object = getObject(i);
		//calculates at what positions rios and samus should be at to get a game over
		if (object->getObjectID() == RIOS)
		{
			int samusTop = samus->plotY();
			int samusBottom = samus->plotY() + S_SPRITE_HEIGHT;
			int samusLeft = samus->plotX();
			int samusRight = samus->plotX() + S_SPRITE_SMALLEST_WIDTH;

			int riosTop = object->plotY();
			int riosBottom = object->plotY() + RIOS_SPRITE_HEIGHT;
			int riosLeft = object->plotX();
			int riosRight = object->plotX() + RIOS_SPRITE_WIDTH;
			//collision detection
			if (((riosLeft < samusRight && riosRight > samusRight) || (riosLeft > samusLeft && riosRight < samusLeft))
				&& samusTop < riosBottom)
			{
				gameOver = true;
			}
		}
	}
	
}

Object* Engine::getObject(int index) 
{
	return(objects[index]);
}

int Engine::getNumObjects()
{
	return numObjects;
}

bool Engine::getGameOver()
{
	return gameOver;
}