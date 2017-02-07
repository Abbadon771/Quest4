#ifndef SAMUS_H
#define SAMUS_H
#include <string>
#include "constants.h"
#include "Object.h"

using namespace std;

class Samus : public Object 
{
public:
	Samus(int*, int, int);
	~Samus();

	void update(S_TRANSITION);

private:
	float velY;
	int state;

	int animationID;
	int numStates;
	int* animationSize;
	int** animationMap;
	int* spriteHeights;

	void loadAnimation(string);
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
	void noAction();
	void updateSprite();

};


#endif