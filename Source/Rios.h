#ifndef RIOS_H
#define RIOS_H

#include "Object.h"

class Rios : public Object {

public:
	Rios(int, int);
	void update(S_TRANSITION);

private:
	bool rise;
	int moveCount;
	int moveCountMax;
};

#endif	
