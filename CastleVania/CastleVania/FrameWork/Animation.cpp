#include "Animation.h"
#include "Define.h"
CAnimation::CAnimation()
{
	m_currentFrame = 0;
	m_frameEnd = 0;
	m_frameStart = 0;
	m_srcRect = { 0 };
	m_velocity = 0.0f;
	m_timeLocal = 0;
	m_direction = DIRECTION_RIGHT;

}

CAnimation::CAnimation(int frameStart, int frameEnd)
{
	m_currentFrame = frameStart - 1;
	m_frameEnd = frameEnd;
	m_frameStart = frameStart;
	m_srcRect = { 0 };
	m_velocity = 0.0f;
	m_timeLocal = 0;
	m_direction = DIRECTION_RIGHT;
}

void CAnimation::SetFrameStart(int frameStart)
{
	m_frameStart = frameStart;
}
int CAnimation::GetFrameStart()
{
	return m_frameStart;
}

void CAnimation::SetFrameEnd(int frameEnd)
{
	m_frameEnd = frameEnd;
}

int CAnimation::GetFrameEnd()
{
	return m_frameEnd;
}

void CAnimation::SetCurrentFrame(int currentFrame)
{
	m_currentFrame = currentFrame;
}


int CAnimation::GetCurrentFrame()
{
	return m_currentFrame;
}

void CAnimation::SetVelocity(int velocity)
{
	m_velocity = velocity;
}

int CAnimation::GetVelocity()
{
	return m_velocity;
}

void CAnimation::SetSrcRect(CSprite *sprite)
{

	m_srcRect.top = m_currentFrame / sprite->GetFramePerRow() * sprite->GetFrameHeight();
	m_srcRect.left = m_currentFrame % sprite->GetFramePerRow() * sprite->GetFrameWidth();
	m_srcRect.right = m_srcRect.left + sprite->GetFrameWidth();
	m_srcRect.bottom = m_srcRect.top + sprite->GetFrameHeight();

	sprite->SetSrcRect(&m_srcRect);

}

RECT CAnimation::GetSrcRect()
{
	return m_srcRect;
}


void CAnimation::TransformFrame()
{

}



bool CAnimation::RunAnimation(CSprite *sprite)
{
	int now = GetTickCount();

	if ((now - m_timeLocal > 1000 / m_velocity))
	{
		m_timeLocal = now;
		m_currentFrame++;
	}


	this->Draw(sprite);

	if (m_currentFrame > m_frameEnd)
		return true;
	return false;
}

void CAnimation::ResetAnimation()
{
	m_currentFrame = m_frameStart - 1;
}

void CAnimation::RunAnimationForever(CSprite *sprite)
{

	int now = GetTickCount();
	if (now - m_timeLocal > 1000 / m_velocity)
	{
		m_timeLocal = now;
		m_currentFrame++;
		if (m_currentFrame > m_frameEnd)
		{
			m_currentFrame = m_frameStart;
		}
	}
	this->Draw(sprite);
}

void CAnimation::SetDirection(int direction)
{
	m_direction = direction;
}
int CAnimation::GetDirection()
{
	return  m_direction;
}


void CAnimation::Draw(CSprite *sprite)
{
	this->SetSrcRect(sprite);

	if (m_direction == DIRECTION_LEFT)
	{
		sprite->Draw();
	}

	else if (m_direction == DIRECTION_RIGHT)
	{
		sprite->DrawFlipY();
	}
}

CAnimation::~CAnimation()
{

}