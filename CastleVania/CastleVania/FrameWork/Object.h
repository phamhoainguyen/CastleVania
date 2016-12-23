#ifndef			__OBJECT_H__
#define			__OBJECT_H__

#include "Sprite.h"
#include "Input.h"
#include "Texture.h"
#include "Animation.h"
#include "Timer.h"
#include "Collision.h"

class CObject : public CSprite
{
protected:
	float m_deltaTime;
	int m_direction;
	D3DXVECTOR2 m_velocity;
	float m_acceleration;	// gia toc

public:

	CObject();
	virtual bool Init(LPWSTR filePath);
	virtual void SetVelocity(D3DXVECTOR2 velocity);
	virtual D3DXVECTOR2 GetVelocity();
	virtual void SetAcceleration(float acceleration);
	virtual float GetAcceleration();
	virtual void UpdatePosition();
	virtual void Update(float dt);
	virtual float GetDeltaTime();
	virtual void Go() = 0;
	virtual void Jump() = 0;
	int GetDirection();
	void SetDirection(int direction);
	virtual ~CObject();
};


#endif			//__OBJECT_H__