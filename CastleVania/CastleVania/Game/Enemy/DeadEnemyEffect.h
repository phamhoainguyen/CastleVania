#ifndef		__DEAD_ENEMY_EFFECT_H__
#define		__DEAD_ENEMY_EFFECT_H__
#include "../../FrameWork/DynamicObject/Object.h"
#include "../../FrameWork/Video/Sprite.h"

class DeadEffect : public CObject
{
private:
	CSprite* m_star;
public:
	bool Init();
	DeadEffect();
	void PlayEffect();
	~DeadEffect();
};

#endif		//__DEAD_ENEMY_EFFECT_H__