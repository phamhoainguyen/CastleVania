#ifndef		__ANIMATION_H__
#define		__ANIMATION_H__
#include "Sprite.h"

class CAnimation
{
private:

	int m_frameStart;
	int m_frameEnd;
	int m_currentFrame;
	float m_velocity;
	RECT m_srcRect;
	int m_timeLocal;
	int m_direction;

public:

	CAnimation();
	CAnimation(int frameStar, int frameEnd);
	void TransformFrame();

	void SetFrameStart(int frameStart);
	int GetFrameStart();

	void SetFrameEnd(int frameEnd);
	int GetFrameEnd();

	void SetCurrentFrame(int currentFrame);
	int GetCurrentFrame();

	void SetVelocity(int velocity);
	int GetVelocity();

	void SetSrcRect(CSprite *sprite);
	RECT GetSrcRect();

	void SetDirection(int direction);
	int GetDirection();

	void Draw(CSprite *sprite);
	bool RunAnimation(CSprite *sprite);
	void ResetAnimation();
	void RunAnimationForever(CSprite *sprite);
	~CAnimation();
};

#endif		//__ANIMATION_H__


//#ifndef		__ANIMATION_H__
//#define		__ANIMATION_H__
//#include "Sprite.h"
//
//class CAnimation
//{
//private:
//	CSprite *m_sprite;
//public:
//	CAnimation();
//	CAnimation(CSprite* sprite);
//	void RunAnimation(int ellapseTime);
//	~CAnimation();
//};
//
//#endif		//__ANIMATION_H__