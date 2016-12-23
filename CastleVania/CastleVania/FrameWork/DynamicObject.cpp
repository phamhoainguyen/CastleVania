#include "Camera.h"
#include "Timer.h"
#include "Define.h"
#include "DynamicObject.h"
CDynamicObject::CDynamicObject() : CObject()
{
	m_animation = NULL;
	m_numberAnimation = 0;
	m_currentAnimation = 0;
	m_action = NULL;
}
bool CDynamicObject::Init(LPWSTR filePath)
{
	CObject::Init(filePath);

	m_action = new CAction();
	m_animation = new CAnimation[m_numberAnimation];
	return true;
}




CAnimation CDynamicObject::GetAnimation(int animationIndex)
{
	return m_animation[animationIndex];
}


void CDynamicObject::Go()
{
	//CObject::UpdatePosition();
	m_action->Go(this);
	if (m_direction == DIRECTION_RIGHT)
	{
		this->m_animation[m_currentAnimation].SetDirection(DIRECTION_RIGHT);
	}

	else if (m_direction == DIRECTION_LEFT)
	{
		this->m_animation[m_currentAnimation].SetDirection(DIRECTION_LEFT);
	}
	m_animation[m_currentAnimation].RunAnimationForever(this);
}



void CDynamicObject::Jump()
{
	//m_velocity.y += m_acceleration * m_deltaTime;
	//m_position.y -= m_velocity.y * m_deltaTime;

	//if (m_velocity.y < 0)
	//{
	//	m_velocity.y += m_acceleration * m_deltaTime * 2;
	//	m_position.y -= m_velocity.y * m_deltaTime;
	//}
	m_action->Jump(this);
	if (m_position.y >= CCamera::GetInstance()->Transform(200, 100).y)
	{
		m_position.y = CCamera::GetInstance()->Transform(200, 100).y;
		m_acceleration = 0;
		m_velocity.y = 0;
	}

	m_animation[m_currentAnimation].SetDirection(this->m_direction);
	m_animation[m_currentAnimation].RunAnimationForever(this);
}


CDynamicObject::~CDynamicObject(){
	if (m_animation)
		delete m_animation;
	if (m_action)
		delete m_action;
}