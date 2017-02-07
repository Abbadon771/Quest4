#ifndef BLOCK_H
#define BLOCK_H
#include "Object.h"

class Block : public Object {
public:
	Block(int, int);
	void update(S_TRANSITION);
};

#endif	
