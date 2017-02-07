#ifndef OBJECT_H
#define OBJECT_H

class Object {
public:
	Object(int, int);
	int plotX();
	int plotY();
	virtual void update(S_TRANSITION) = 0;
	int getSpriteID();
	int getObjectID();
	int getPosY();
	int getPosX();
	void setPosX(float);
	void setPosY(float);

protected:
	float posX;
	float posY;
	OBJECT_ID objectID;
	int spriteID;

};

#endif
