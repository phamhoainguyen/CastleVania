#ifndef			__COLLISION_H__
#define			__COLLISION_H__
#include "../DynamicObject/Object.h"

typedef struct  Box
{
	float posX, posY;
	float width, height;
	float velocityX, velocityY;
}Box;

Box GetBound(CObject object);
float SweptAABB(CObject object1, CObject object2, float& normalx, float& normaly);
#endif			//__COLLISION_H__