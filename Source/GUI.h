#ifndef GUI_H
#define GUI_H

#include <string>

//GUI definitions
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"

//User-defined tools
#include "Texture.h"
#include "constants.h"

//Game specific types
#include "Engine.h"

using namespace std;

class GUI
{

public:
	GUI();
	~GUI();
	int observeEvent();
	S_TRANSITION getCommand();
	bool quitGame();
	void displayGameState(Engine&);
	int getSpriteHeight(int index) { return metroidClips[index].h; }
	void addText(string texToAdd) { addedText = texToAdd; }

private:

	//
	// PRIVATE METHODS
	//
	void initGUI();
	void loadMedia();
	void cleanUp();

	//
	//PRIVATE MEMBERS
	//
	bool quit;

	//Window(s) to display graphics
	SDL_Window* window;

	//Hardware accelerated renderer
	SDL_Renderer* renderer;

	//The texture and clipping that will be used for Samus
	Texture* metroidSheetTexture;
	SDL_Rect metroidClips[S_NUM_SPRITES];
	
	//The texture to be used for the blocks & lava
	Texture* blockSheetTexture;
	Texture* lavaSheetTexture;
	Texture* riosSheetTexture;
	Texture* rios2SheetTexture;

	bool riosSwitch;

	//The texture to be used for the text
	TTF_Font* normalFont;

	//The event structure that will be used
	SDL_Event event;

	//Maintain last player command given
	S_TRANSITION command;
	string addedText;
};

#endif
