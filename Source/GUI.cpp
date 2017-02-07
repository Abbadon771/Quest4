#include <iostream>
#include <fstream>
#include <string>

#include "GUI.h"
#include "Texture.h"
#include "constants.h"

using namespace std;

GUI::GUI(){

	//Initialize the window
	window = NULL;

    //Initialize the renderer
	renderer = NULL;

	//Images surfaces used in GUI
	metroidSheetTexture = NULL;
    blockSheetTexture = NULL;
	lavaSheetTexture = NULL;
	riosSheetTexture = NULL;

	//Text structures used in GUI
	normalFont = NULL;

	//Start-up the GUI!
	initGUI();

	//Load in all the images and clip (if necessary)
	loadMedia();

	//Exit criteria
	quit=false;

}

GUI::~GUI(){
	cleanUp();
}

int GUI::observeEvent(){
	return(SDL_PollEvent( &event ));
}

S_TRANSITION GUI::getCommand()
{
	//Base command is "NA" for "Not Applicable"
	command = NA;

	//If a key is pressed
	if (event.type == SDL_KEYDOWN) {
		{
			//Animate
			switch (event.key.keysym.sym) 
			{

			case SDLK_UP: command = UP; break;
			case SDLK_DOWN:	command = DOWN; break;
			case SDLK_LEFT: command = LEFT; break;
			case SDLK_RIGHT: command = RIGHT; break;

			}
		}

	}
	
	return(command);
}

bool GUI::quitGame(){
	return(event.type == SDL_QUIT );
}

void GUI::initGUI(){

	//Initialize all SDL subsystems
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0){

		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
		exit(1);
	}
	//Initialize PNG loading
	int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags))
	{
		printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
		exit(1);
	}

	//Initialize SDL_ttf
	if (TTF_Init() == -1)
	{
		printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
		exit(1);
	}

	//Construct and check window construction
	window = SDL_CreateWindow("Metroid Clone",
					SDL_WINDOWPOS_UNDEFINED,
					SDL_WINDOWPOS_UNDEFINED,
                    SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	if(window==NULL){

			printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
			exit(1);
	}

	//Construct and check renderer construction
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if(renderer == NULL){

		printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
		exit(1);

	}

}

void GUI::loadMedia(){

	//Open Samus Sprite Sheet Forward
	metroidSheetTexture = new Texture();
	metroidSheetTexture->load(renderer,"./Assets/Images/samus.png");

	//Parse Samus Sprite Sheet Forward
	
		
	int i = 0;
	//becoming visible 
	//0
	metroidClips[i].x = 0;
	metroidClips[i].y = 7;
	metroidClips[i].w = 16;
	metroidClips[i].h = 32;
	i++;
	//1
	metroidClips[i].x = 18;
	metroidClips[i].y = 7;
	metroidClips[i].w = 16;
	metroidClips[i].h = 32;
	i++;
	//2
	metroidClips[i].x = 36;
	metroidClips[i].y = 7;
	metroidClips[i].w = 16;
	metroidClips[i].h = 32;
	i++;
	//3
	metroidClips[i].x = 54;
	metroidClips[i].y = 7;
	metroidClips[i].w = 16;
	metroidClips[i].h = 32;
	i++;

	//stand Right
	//4
	metroidClips[i].x = 72;
	metroidClips[i].y = 7;
	metroidClips[i].w = 20;
	metroidClips[i].h = 32;
	i++;

	//stand Right Up
	//5
	metroidClips[i].x = 94;
	metroidClips[i].y = 1;
	metroidClips[i].w = 14;
	metroidClips[i].h = 38;
	i++;

	//Run Right
	//6
	metroidClips[i].x = 110;
	metroidClips[i].y = 7;
	metroidClips[i].w = 15;
	metroidClips[i].h = 32;
	i++;
	//7
	metroidClips[i].x = 127;
	metroidClips[i].y = 7;
	metroidClips[i].w = 17;
	metroidClips[i].h = 32;
	i++;
	//8
	metroidClips[i].x = 146;
	metroidClips[i].y = 7;
	metroidClips[i].w = 20;
	metroidClips[i].h = 32;
	i++;

	//Jump Right - small
	//9
	metroidClips[i].x = 168;
	metroidClips[i].y = 14;
	metroidClips[i].w = 18;
	metroidClips[i].h = 25;
	i++;
	
	//Jump Right - roll
	//10
	metroidClips[i].x = 188;
	metroidClips[i].y = 16;
	metroidClips[i].w = 14;
	metroidClips[i].h = 23;
	i++;
	//11
	metroidClips[i].x = 204;
	metroidClips[i].y = 24;
	metroidClips[i].w = 19;
	metroidClips[i].h = 15;
	i++;
	//12
	metroidClips[i].x = 225;
	metroidClips[i].y = 16;
	metroidClips[i].w = 14;
	metroidClips[i].h = 23;
	i++;
	//13
	metroidClips[i].x = 241;
	metroidClips[i].y = 24;
	metroidClips[i].w = 19;
	metroidClips[i].h = 15;
	i++;

	//Ball Right
	//14
	metroidClips[i].x = 262;
	metroidClips[i].y = 26;
	metroidClips[i].w = 12;
	metroidClips[i].h = 13;
	i++;
	//15
	metroidClips[i].x = 276;
	metroidClips[i].y = 26;
	metroidClips[i].w = 12;
	metroidClips[i].h = 13;
	i++;
	//16
	metroidClips[i].x = 290;
	metroidClips[i].y = 26;
	metroidClips[i].w = 12;
	metroidClips[i].h = 13;
	i++;
	//17
	metroidClips[i].x = 304;
	metroidClips[i].y = 26;
	metroidClips[i].w = 12;
	metroidClips[i].h = 13;
	i++;

	//Run Shoot Right
	//18
	metroidClips[i].x = 318;
	metroidClips[i].y = 7;
	metroidClips[i].w = 18;
	metroidClips[i].h = 32;
	i++;
	//19
	metroidClips[i].x = 340;
	metroidClips[i].y = 7;
	metroidClips[i].w = 20;
	metroidClips[i].h = 32;
	i++;
	//20
	metroidClips[i].x = 362;
	metroidClips[i].y = 7;
	metroidClips[i].w = 22;
	metroidClips[i].h = 32;
	i++;
	//21
	metroidClips[i].x = 386;
	metroidClips[i].y = 7;
	metroidClips[i].w = 25;
	metroidClips[i].h = 32;
	i++;

	//Crouch Shoot Right
	//22
	metroidClips[i].x = 413;
	metroidClips[i].y = 14;
	metroidClips[i].w = 23;
	metroidClips[i].h = 25;
	i++;

	//Run Shoot Up Right
	//23
	metroidClips[i].x = 438;
	metroidClips[i].y = 3;
	metroidClips[i].w = 14;
	metroidClips[i].h = 36;
	i++;
	//24
	metroidClips[i].x = 454;
	metroidClips[i].y = 1;
	metroidClips[i].w = 12;
	metroidClips[i].h = 38;
	i++;
	//25
	metroidClips[i].x = 471;
	metroidClips[i].y = 1;
	metroidClips[i].w = 17;
	metroidClips[i].h = 38;
	i++;
	//26
	metroidClips[i].x = 490;
	metroidClips[i].y = 1;
	metroidClips[i].w = 19;
	metroidClips[i].h = 38;
	i++;

	//Jump Shoot UP Right
	//27
	metroidClips[i].x = 511;
	metroidClips[i].y = 7;
	metroidClips[i].w = 18;
	metroidClips[i].h = 32;
	i++;
	//28
	metroidClips[i].x = 531;
	metroidClips[i].y = 9;
	metroidClips[i].w = 18;
	metroidClips[i].h = 30;
	i++;

	//**************LEFT********************************************
	//becoming visible (LEFT)
	//29
	metroidClips[i].x = 1084;
	metroidClips[i].y = 7;
	metroidClips[i].w = 16;
	metroidClips[i].h = 32;
	i++;
	//30
	metroidClips[i].x = 1066;
	metroidClips[i].y = 7;
	metroidClips[i].w = 16;
	metroidClips[i].h = 32;
	i++;
	//31
	metroidClips[i].x = 1048;
	metroidClips[i].y = 7;
	metroidClips[i].w = 16;
	metroidClips[i].h = 32;
	i++;
	//32
	metroidClips[i].x = 1030;
	metroidClips[i].y = 7;
	metroidClips[i].w = 16;
	metroidClips[i].h = 32;
	i++;

	//stand Left
	//33
	metroidClips[i].x = 1008;
	metroidClips[i].y = 7;
	metroidClips[i].w = 20;
	metroidClips[i].h = 32;
	i++;

	//stand Left Up
	//34
	metroidClips[i].x = 992;
	metroidClips[i].y = 1;
	metroidClips[i].w = 14;
	metroidClips[i].h = 38;
	i++;

	//Run Left
	//35
	metroidClips[i].x = 975;
	metroidClips[i].y = 7;
	metroidClips[i].w = 15;
	metroidClips[i].h = 32;
	i++;
	//36
	metroidClips[i].x = 956;
	metroidClips[i].y = 7;
	metroidClips[i].w = 17;
	metroidClips[i].h = 32;
	i++;
	//37
	metroidClips[i].x = 934;
	metroidClips[i].y = 7;
	metroidClips[i].w = 20;
	metroidClips[i].h = 32;
	i++;

	//Crouch LEft
	//38
	metroidClips[i].x = 914;
	metroidClips[i].y = 14;
	metroidClips[i].w = 18;
	metroidClips[i].h = 25;
	i++;

	//Jump Left
	//39
	metroidClips[i].x = 898;
	metroidClips[i].y = 16;
	metroidClips[i].w = 14;
	metroidClips[i].h = 23;
	i++;
	//40
	metroidClips[i].x = 877;
	metroidClips[i].y = 24;
	metroidClips[i].w = 19;
	metroidClips[i].h = 15;
	i++;
	//41
	metroidClips[i].x = 861;
	metroidClips[i].y = 16;
	metroidClips[i].w = 14;
	metroidClips[i].h = 23;
	i++;
	//42
	metroidClips[i].x = 840;
	metroidClips[i].y = 24;
	metroidClips[i].w = 19;
	metroidClips[i].h = 15;
	i++;

	//Ball Left
	//43
	metroidClips[i].x = 826;
	metroidClips[i].y = 26;
	metroidClips[i].w = 12;
	metroidClips[i].h = 13;
	i++;
	//44
	metroidClips[i].x = 812;
	metroidClips[i].y = 26;
	metroidClips[i].w = 12;
	metroidClips[i].h = 13;
	i++;
	//45
	metroidClips[i].x = 798;
	metroidClips[i].y = 26;
	metroidClips[i].w = 12;
	metroidClips[i].h = 13;
	i++;
	//46
	metroidClips[i].x = 784;
	metroidClips[i].y = 26;
	metroidClips[i].w = 12;
	metroidClips[i].h = 13;
	i++;

	//Run Shoot Left
	//47
	metroidClips[i].x = 764;
	metroidClips[i].y = 7;
	metroidClips[i].w = 18;
	metroidClips[i].h = 32;
	i++;
	//48
	metroidClips[i].x = 740;
	metroidClips[i].y = 7;
	metroidClips[i].w = 20;
	metroidClips[i].h = 32;
	i++;
	//49
	metroidClips[i].x = 716;
	metroidClips[i].y = 7;
	metroidClips[i].w = 22;
	metroidClips[i].h = 32;
	i++;
	//50
	metroidClips[i].x = 689;
	metroidClips[i].y = 7;
	metroidClips[i].w = 25;
	metroidClips[i].h = 32;
	i++;

	//Crouch Shoot Left
	//51
	metroidClips[i].x = 664;
	metroidClips[i].y = 14;
	metroidClips[i].w = 23;
	metroidClips[i].h = 25;
	i++;

	//Run Shoot Up Left
	//52
	metroidClips[i].x = 648;
	metroidClips[i].y = 3;
	metroidClips[i].w = 14;
	metroidClips[i].h = 36;
	i++;
	//53
	metroidClips[i].x = 634;
	metroidClips[i].y = 1;
	metroidClips[i].w = 12;
	metroidClips[i].h = 38;
	i++;
	//54
	metroidClips[i].x = 612;
	metroidClips[i].y = 1;
	metroidClips[i].w = 17;
	metroidClips[i].h = 38;
	i++;
	//55
	metroidClips[i].x = 591;
	metroidClips[i].y = 1;
	metroidClips[i].w = 19;
	metroidClips[i].h = 38;
	i++;

	//Jump Shoot UP Left
	//56
	metroidClips[i].x = 571;
	metroidClips[i].y = 7;
	metroidClips[i].w = 18;
	metroidClips[i].h = 32;
	i++;
	//57
	metroidClips[i].x = 551;
	metroidClips[i].y = 9;
	metroidClips[i].w = 18;
	metroidClips[i].h = 30;
	i++;




	//Open Block Sprite Sheet
	blockSheetTexture = new Texture();
	blockSheetTexture->load(renderer,"./Assets/Images/block.png");

	//Open Top Block Sprite Sheet
	lavaSheetTexture = new Texture();
	lavaSheetTexture->load(renderer,"./Assets/Images/lava.png");

	//Open Rios Sprite Sheet
	riosSheetTexture = new Texture();
	riosSheetTexture->load(renderer, "./Assets/Images/rios.png");
	rios2SheetTexture = new Texture();
	rios2SheetTexture->load(renderer, "./Assets/Images/rios2.png");
	riosSwitch = true;



	//Open the font
	normalFont = TTF_OpenFont("./Assets/Fonts/impact.ttf", 48);
	if (normalFont == NULL) {
		printf("Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError());
	}
	
}

void GUI::cleanUp(){

	//Free the window
	SDL_DestroyWindow(window);
    window = NULL;

    //Free the renderer
   	SDL_DestroyRenderer(renderer);
    renderer = NULL;

    //Free loaded images
	metroidSheetTexture->free();
    blockSheetTexture->free();
	lavaSheetTexture->free();
	riosSheetTexture->free();
	
	//Free font structures
	TTF_CloseFont(normalFont);

    //Quit SDL Subsystems
   	IMG_Quit();
	TTF_Quit();
    SDL_Quit();

}

void GUI::displayGameState(Engine & engine)
{

	//Clear screen
	SDL_SetRenderDrawColor(renderer,0,0,0,255);  
	SDL_RenderClear(renderer);
	string text = "";
	//Render Objects
	for (int i = 0; i<engine.getNumObjects(); i++) {
		Object* object = engine.getObject(i);
		switch (object->getObjectID())
		{
		case BLOCK:
			blockSheetTexture->render(renderer, object->plotX(), object->plotY(), NULL);
			break;
		case RIOS:
			if (riosSwitch)
			{
				riosSheetTexture->render(renderer, object->plotX(), object->plotY(), NULL);
			}
			else
			{
				rios2SheetTexture->render(renderer, object->plotX(), object->plotY(), NULL);
			}
			riosSwitch = !riosSwitch;
			break;
		case SAMUS:
			text = "(" + to_string(engine.getObject(19) ->getPosY()) + ") - ";
			metroidSheetTexture->render(renderer, object->getPosX(), object->getPosY(), &metroidClips[object->getSpriteID()]);
			break;
		}		
	}

	//-------------------------------------------------------------
	//Display the User's Command in top right corner
	//-------------------------------------------------------------
	
	int textX = 0;
	int textY = 0;

	if (!engine.getGameOver())
	{
		switch (command) {
		case UP: text += "Up"; break;
		case ATTACK: text += "Attack"; break;
		case DOWN: text += "Down"; break;
		case RIGHT: text += "Right"; break;
		case LEFT: text += "Left"; break;
		case NA: text += "NA"; break;
		}

		textX = 480;
		textY = 10;
	}
	else
	{
		//Set the text to end of game condition
		text = "Game Over";

		//Center the texxt
		textX = 200;
		textY = 140;
	}
	
	//Render Command to Text
	SDL_Color textColor = { 255, 255, 153 };
	SDL_Texture* textSheetTexture = SDL_CreateTextureFromSurface(renderer, TTF_RenderText_Solid(normalFont, text.c_str(), textColor));

	//Set rendering space and render to screen
	int width = 0, height = 0;
	SDL_QueryTexture(textSheetTexture, NULL, NULL, &width, &height);
	SDL_Rect renderQuad = { textX, textY, width, height };

	//Render to screen
	SDL_RenderCopy(renderer, textSheetTexture, NULL, &renderQuad);
	//-------------------------------------------------------------
	//-------------------------------------------------------------

	//Update the visible screen
	SDL_RenderPresent(renderer);
	
}