#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <cmath>

//Block Constants
const int BLOCK_SPRITE_WIDTH = 28;
const int BLOCK_SPRITE_HEIGHT = BLOCK_SPRITE_WIDTH;

//GUI Constants
const int SCREEN_WIDTH = BLOCK_SPRITE_WIDTH * 30;
const int SCREEN_HEIGHT = int(floor((float(2) / 3)*SCREEN_WIDTH));
const int SCREEN_BPP = 32;
const int FRAMES_PER_SECOND = 12;
const int FRAME_DELAY = 1000 / FRAMES_PER_SECOND;

//Physics Constants
const float DELTA_T = 0.1f;
const float GRAVITY = 10.0f;

//Object Constants
enum OBJECT_ID { OBJECT, SAMUS, BLOCK, RIOS };

//Samus Constants
const int S_SPRITE_HEIGHT = 32;
const int S_SPRITE_HEIGHT_TALL = 38;
const int S_SPRITE_HEIGHT_BALL = 13;
const int S_SPRITE_SMALLEST_WIDTH = 16;
const int S_NUM_SPRITES = 58;

//Animation Constants
enum S_STATE { STILL_RIGHT, STILL_LEFT, RUN_RIGHT, RUN_LEFT, BALL, UP_RIGHT, UP_LEFT };
enum S_TRANSITION { UP, DOWN, LEFT, RIGHT, ATTACK, NA };
const int S_RUN_SPEED = 12;
const int RIOS_SPEED = 10;


//Rios Constants
const int RIOS_SPRITE_HEIGHT = 19;
const int RIOS_SPRITE_WIDTH = 24;


#endif