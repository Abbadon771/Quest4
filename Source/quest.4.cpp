/*
* Author:	Sean Orme
*			UALR
*
* Date:		September 28, 2014
*
* File:		quest.3.cpp
*
* Purpose:	The purpose of this homework is to illustrate the use of objects in
*           abstracting and simplifying game implementation*/

#include <fstream>
#include <cstdlib> 
#include <ctime> 
#include <string>
#include <iostream>

//Game Architecture Types and Headers
#include "GUI.h"
#include "Timer.h"
#include "Engine.h"
#include "constants.h"

//Game Specific Types
#include "Samus.h"
#include "Block.h"

using namespace std;

int main(int argc, char *argv[]){

	//Initialize GUI->Engine communication*/
	S_TRANSITION command = NA;

	//Construct Timer
	Timer fps;

	//Construct GUI
	GUI gui;
	
	int * spriteHeights = new int[S_NUM_SPRITES];
	for (int i = 0; i < S_NUM_SPRITES; i++)
	{
		//this line may seem confusing until we learn about classes. 
		//it suffices to say that we are grabbing the heights of each clip and storing it in this array
		spriteHeights[i] = gui.getSpriteHeight(i);
	}

	//Construct Engine
	Engine engine(spriteHeights);

	//Initialize Termination Criteria
	bool quit = false;


	//While the user hasn't quit
	while (quit == false) {

		//Start the frame timer
		fps.start();

		//GUI waits for mouse events
		while (gui.observeEvent()) {

			//Receive Command From GUI
			command = gui.getCommand();

			//GUI transmits quit event
			if (gui.quitGame()) {

				quit = true;

			}

		}

		//Task 3: Update Game state
		engine.changeGameState(command);

		//Render Game Data
		gui.displayGameState(engine);

		//Adjust Frame Rate
		if (fps.get_ticks() < FRAME_DELAY) {
			SDL_Delay(FRAME_DELAY - fps.get_ticks());
		}

	}

	//Return
	return 0;

}