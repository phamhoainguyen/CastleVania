#include "Object.h"
#include "../Video/Camera.h"
#include "../Time/Timer.h"
#include "../GlobalVariable/Define.h"
CObject::CObject() : CSprite()
{
	m_animation = NULL;
	m_velocity = { 0, 0 };
	m_acceleration = 0.0f;
	m_direction = 0;
	m_numberAnimation = 0;
	m_currentAnimation = 0;
}
bool CObject::Init(LPWSTR filePath)
{
	m_texture = new CTexture(filePath);
	if (!m_texture->Load(D3DCOLOR_XRGB(255, 0, 255)))
		return false;

	m_animation = new CAnimation[m_numberAnimation];
	return true;
}

void CObject::SetVelocity(D3DXVECTOR2 velocity)
{
	m_velocity = velocity;
}


void CObject::SetAcceleration(float acceleration)
{
	m_acceleration = acceleration;
}

void CObject::UpdatePosition()
{
	m_position.x += m_velocity.x * m_deltaTime;
	m_position.z = 0;
}

CAnimation CObject::GetAnimation(int animationIndex)
{
	return m_animation[animationIndex];
}

void CObject::Go()
{
	this->UpdatePosition();

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

void CObject::Update(float dt)
{
	m_deltaTime = dt;
}

void CObject::Jump()
{
	m_velocity.y += m_acceleration * m_deltaTime;
	m_position.y -= m_velocity.y * m_deltaTime;

	if (m_velocity.y < 0)
	{
		m_velocity.y += m_acceleration * m_deltaTime * 2;
		m_position.y -= m_velocity.y * m_deltaTime;
	}

	if (m_position.y >= CCamera::GetInstance()->Transform(200, 100).y)
	{
		m_position.y = CCamera::GetInstance()->Transform(200, 100).y;
		m_acceleration = 0;
		m_velocity.y = 0;
	}
	m_animation[m_currentAnimation].SetDirection(this->m_direction);
	m_animation[m_currentAnimation].RunAnimationForever(this);
}


int CObject::GetDirection()
{
	return m_direction;
}

void CObject::SetDirection(int direction)
{
	m_direction = direction;
}


D3DXVECTOR2 CObject::GetVelocity()
{
	return m_velocity;
}

CObject::~CObject(){
	if (m_animation)
		delete m_animation;
}