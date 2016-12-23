#ifndef			__DYNAMIC_OBJECT_H__
#define			__DYNAMIC_OBJECT_H__

#include "Input.h"
#include "Animation.h"
#include "Timer.h"
#include "Collision.h"
#include "Object.h"
#include "Action.h"

class CDynamicObject : public CObject
{
protected:
	CAnimation* m_animation;
	int m_numberAnimation;
	int m_currentAnimation;
	CAction* m_action;
public:

	CDynamicObject();
	virtual bool Init(LPWSTR filePath);
	virtual CAnimation GetAnimation(int animationIndex);
	virtual void Go();
	virtual void Jump();
	virtual ~CDynamicObject();
};


#endif			//__DYNAMIC_OBJECT_H__