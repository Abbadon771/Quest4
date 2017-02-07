#include <iostream>
#include <fstream>

//Game Architecture Headers
#include "constants.h"
#include "Samus.h"

Samus::Samus(int* spriteHeights, int poX, int poY):Object(poX,poY)
{
	this->spriteHeights = spriteHeights;
	animationID = 0;
	velY = 0.0f;
	state = STILL_RIGHT;
	loadAnimation("./Assets/Config/animation.txt");
	objectID = SAMUS;
	updateSprite();
}

Samus::~Samus() {
	for (int i = 0; i < numStates; i++)
	{
		delete[] animationMap[i];
	}
	delete[] animationMap;
	delete[] animationSize;
}

void Samus::update(S_TRANSITION command)
{
	switch (command)
	{
		//Execute the appropriate state transition
	case UP:
		moveUp();
		break;
	case DOWN:
		moveDown();
		break;
	case LEFT:
		moveLeft();
		break;
	case RIGHT:
		moveRight();
		break;
	case NA:
		noAction();
		break;
	}
	//Samus Boundary Checking (left boundary)
	if (getPosX() <= 0)
	{
		setPosX(0);
	}
		//Boundary Checking (top and bottom boundaries)
		if (getPosY() >= SCREEN_HEIGHT - spriteHeights[spriteID])
		{
			setPosY((float)(SCREEN_HEIGHT - spriteHeights[spriteID]));
		}
	if (getPosY() <= 0)
	{
		setPosY(0.0f);
	}
}

void Samus::loadAnimation(string gameFile)
{
	//takes the text file that contains sprite animations and adds them to the intended arrays
	fstream fin;
	fin.open(gameFile.c_str(), ios::in);
	fin >> numStates;
	animationSize = new int[numStates];
	animationMap = new int*[numStates];
	for (int i = 0; i<numStates; i++) {
		fin >> animationSize[i];
		animationMap[i] = new int[animationSize[i]];
		for (int j = 0; j<animationSize[i]; j++)
		{
			fin >> animationMap[i][j];
		}
	}
	fin.close();
}

void Samus::moveUp()
{
	//Conduct the appropriate state transition and/or animation
	switch (state)
	{
	case STILL_RIGHT:
		state = UP_RIGHT;
		animationID = 0;
		break;
	case STILL_LEFT:
		state = UP_LEFT;
		animationID = 0;
		break;
	case BALL:
		state = STILL_RIGHT;
		animationID = 0;
		break;
	default:
		break;
	}
	updateSprite();
}
void Samus::moveDown()
{
	//Conduct the appropriate state transition and/or animation
	switch (state)
	{
	case STILL_LEFT:
	case STILL_RIGHT:
		state = BALL;
		animationID = 0;
		break;
	}
	updateSprite();
}
void Samus::moveRight()
{
	//Conduct the appropriate state transition and/or animation
	switch (state)
	{
	case STILL_RIGHT:
		state = RUN_RIGHT;
		animationID = 0;
		posX += S_RUN_SPEED;
		break;
	case RUN_RIGHT:
	case BALL:
		posX += S_RUN_SPEED;
		break;
	default:
		state = STILL_RIGHT;
		animationID = 0;
	}
	updateSprite();
}
void Samus::moveLeft()
{
	//Conduct the appropriate state transition and/or animation
	switch (state)
	{
	case STILL_LEFT:
		state = RUN_LEFT;
		animationID = 0;
		posX -= S_RUN_SPEED;
		break;
	case RUN_LEFT:
	case BALL:
		posX -= S_RUN_SPEED;
		break;
	default:
		state = STILL_LEFT;
		animationID = 0;
	}
	updateSprite();
}
void Samus::noAction()
{
	if (state != STILL_LEFT || state != STILL_RIGHT)
	{
		//Conduct the appropriate state transition
		switch (state)
		{
		case RUN_RIGHT:
		case UP_RIGHT:
			state = STILL_RIGHT;
			animationID = 0;
			break;
		case RUN_LEFT:
		case UP_LEFT:
			state = STILL_LEFT;
			animationID = 0;
			break;
		}
		//Reset animation and update the sprite
		//animationID = 0;
		updateSprite();
	}
}

void Samus::updateSprite()
{
	animationID++;
	//Wrap animation sequence
	if (animationID >= animationSize[state])
	{
		animationID = 0;
	}
	//Map sprite ID
	spriteID = animationMap[state][animationID];
	posY = SCREEN_HEIGHT - spriteHeights[spriteID];
}

