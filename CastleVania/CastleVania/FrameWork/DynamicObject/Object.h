#ifndef			__OBJECT_H__
#define			__OBJECT_H__

#include "../Video/Sprite.h"
#include "../Input/Input.h"
#include "../Video/Texture.h"
#include "../Video/Animation.h"
#include "../Time/Timer.h"
class CObject : public CSprite
{
protected:
	float m_deltaTime;
	int m_direction;
	CAnimation* m_animation;
	int m_numberAnimation;
	int m_currentAnimation;
	D3DXVECTOR2 m_velocity;
	float m_acceleration;	// gia toc

	float m_positionYBeforeJump;  // vi tri toa do y truoc khi simon nhay
public:

	CObject();
	virtual bool Init(LPWSTR filePath);
	virtual void SetVelocity(D3DXVECTOR2 velocity);
	virtual D3DXVECTOR2 GetVelocity();
	virtual void SetAcceleration(float acceleration);
	virtual void UpdatePosition();
	virtual CAnimation GetAnimation(int animationIndex);
	virtual void Go();
	virtual void Update(float dt);
	virtual void Jump();
	int GetDirection();
	void SetDirection(int direction);
	virtual ~CObject();
};


#endif			//__OBJECT_H__