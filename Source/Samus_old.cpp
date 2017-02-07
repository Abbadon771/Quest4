#include <iostream>
#include <fstream>

//Game Architecture Headers
#include "constants.h"
#include "Samus.h"

Samus::Samus()
{
	this->spriteHeights = spriteHeights;
	//Initialize at bottom left of screen
	posX = 0.0f;
	posY = (float)(SCREEN_HEIGHT - S_SPRITE_HEIGHT);

	//Standing, facing to the right
	state = STILL_RIGHT;
	animationID = 0;

	//Load Animation Data
	loadAnimation("./Assets/Config/animation.txt");
}

Samus::Samus(int* spriteHeights)
{
	this->spriteHeights = spriteHeights;
	//Initialize at bottom left of screen
	posX = 0.0f;
	posY = (float)(SCREEN_HEIGHT - S_SPRITE_HEIGHT);

	//Standing, facing to the right
	state = STILL_RIGHT;
	animationID = 0;

	//Load Animation Data
	loadAnimation("./Assets/Config/animation.txt");
	//Compute Initial Sprite
	updateSprite();
}

Samus::~Samus(){
	
	//Clean-up ragged 2D array
	for(int i=0;i<numStates;i++){
		delete [] animationMap[i];
	}
	delete [] animationMap;
	
	//Clean-up 1D array
	delete [] animationSize;

}

void Samus::loadAnimation(string gameFile){

	//Declare and open filestream
	fstream fin;
	fin.open(gameFile.c_str(),ios::in);

	//Number of columns to store
	fin >> numStates;

	//Allocate memory
	animationSize = new int[numStates];
	animationMap = new int*[numStates];

	//Load the ragged array
	for(int i=0;i<numStates;i++){

		fin >> animationSize[i];
		animationMap[i] = new int[animationSize[i]];

		for(int j=0;j<animationSize[i];j++){
			fin >> animationMap[i][j];
		}

	}

	//Clean-up
	fin.close();

}


int Samus::getState() const{
	return(state);
}

int Samus::getSpriteID() const{
	return(spriteID);
}

//Set Methods
void Samus::setPosX(float posX){
	this->posX = posX;
}

void Samus::setPosY(float posY){
	this->posY = posY;
}

void Samus::setState(int state){
	this->state = state;
}

void Samus::setSpriteID(int spriteID){
	this->spriteID = spriteID;
}

void Samus::setSpriteHeights(int* spriteHeights)
{
	this->spriteHeights = spriteHeights;
}

//Plotting Methods
int Samus::getPosX() const{
	return((int)posX);
}

int Samus::getPosY() const{
	return((int)posY);
}

void Samus::update(S_TRANSITION command){

	switch(command){
		//Execute the appropriate state transition
	case UP: 
		moveUp(); 
		break;
	case DOWN: 
		moveDown();
		break;
	case LEFT: moveLeft(); break;
	case RIGHT: moveRight(); break;
	case NA: noAction(); break;
	}

	//Samus Boundary Checking (left boundary)
	if(getPosX() <= 0){
		setPosX(0);
	}

	//Boundary Checking (top and bottom boundaries)
	if(getPosY() >= SCREEN_HEIGHT-spriteHeights[spriteID]){
		setPosY((float)(SCREEN_HEIGHT-spriteHeights[spriteID]));
	}
	if(getPosY() <= 0){
		setPosY(0.0f);
	}

}

void Samus::moveUp()
{
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


void Samus::moveRight(){

	//Conduct the appropriate state transition and/or animation
	switch(state){
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
		state=STILL_RIGHT;
		animationID = 0;
	}
	updateSprite();
}


void Samus::moveLeft(){

	//Conduct the appropriate state transition and/or animation
	switch(state){
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
		state=STILL_LEFT;
		animationID = 0;
	}
	updateSprite();
		
}

void Samus::noAction(){

	if (state != STILL_LEFT || state != STILL_RIGHT)
	{
		//Conduct the appropriate state transition
		switch (state) 
		{
		case RUN_RIGHT:
		case UP_RIGHT:
			state = STILL_RIGHT;
			break;
		case RUN_LEFT:
		case UP_LEFT:
			state = STILL_LEFT;
			break;	

		}
		//Reset animation and update the sprite
		animationID=0;
		updateSprite();		
	}

}

void Samus::updateSprite(){

	animationID++;

	//Wrap animation sequence
	if(animationID>=animationSize[state]){
		animationID = 0;
	}

	//Map sprite ID
	spriteID = animationMap[state][animationID];
	posY = SCREEN_HEIGHT - spriteHeights[spriteID];
}