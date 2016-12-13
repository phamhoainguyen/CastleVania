#ifndef			__GHOST_H__
#define			__GHOST_H__
#include "../../FrameWork/DynamicObject/Object.h"

class CGhost : public CObject
{
private:
	bool m_life;

public:

	CGhost();
	void SetLife(bool life);
	bool GetLife();
	void IsDead();
	~CGhost();
};


#endif			//__GHOST_H__