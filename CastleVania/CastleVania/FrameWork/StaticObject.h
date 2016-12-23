#ifndef			__STATIC_OBJECT_H__
#define			__STATIC_OBJECT_H__

#include "Object.h"
#include "Action.h"

class CStaticObject : public CObject
{
protected:
	CAction* m_action;
public:
	void Go();
	void Jump();

};

#endif			//__STATIC_OBJECT_H__