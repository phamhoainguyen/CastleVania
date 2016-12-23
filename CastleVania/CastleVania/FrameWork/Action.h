#ifndef __ACTION_H__
#define __ACTION_H__
#include "Object.h"
class CAction
{

public:
	CAction();
	void Go(CObject* object);
	void Jump(CObject* object);
	~CAction();
};


#endif //__ACTION_H__