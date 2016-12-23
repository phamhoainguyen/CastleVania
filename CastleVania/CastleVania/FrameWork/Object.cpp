#include "Object.h"
#include "Camera.h"
#include "Timer.h"
#include "Define.h"
CObject::CObject() : CSprite()
{
	m_velocity = { 0, 0 };
	m_acceleration = 0.0f;
	m_direction = 0;
	m_deltaTime = 0.0f;
}
bool CObject::Init(LPWSTR filePath)
{
	m_texture = new CTexture(filePath);
	if (!m_texture->Load(D3DCOLOR_XRGB(255, 0, 255)))
		return false;
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



void CObject::Update(float dt)
{
	m_deltaTime = dt;
}


int CObject::GetDirection()
{
	return m_direction;
}

void CObject::SetDirection(int direction)
{
	m_direction = direction;
}

float CObject::GetAcceleration()
{
	return m_acceleration;
}


D3DXVECTOR2 CObject::GetVelocity()
{
	return m_velocity;
}

float CObject::GetDeltaTime()
{
	return m_deltaTime;
}

CObject::~CObject(){
	
}