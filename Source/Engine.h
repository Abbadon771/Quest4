#ifndef ENGINE_H
#define ENGINE_H
#include "Object.h"
class Engine {
public:
	Engine(int*);
	void changeGameState(S_TRANSITION command);
	Object* getObject(int index);
	int getNumObjects();
	bool getGameOver();

private:
	Object** objects;
	int numObjects;
	bool gameOver;
};

#endif