//#include "Action.h"
//
//CAction::CAction()
//{
//	m_sprite = NULL;
//	m_velocity = D3DXVECTOR3(0, 0, 0);
//}
//
//CAction::CAction(CSprite *sprite, D3DXVECTOR3 velocity)
//{
//	m_sprite = m_sprite;
//	m_velocity = velocity;
//}
//
//
//CAction::~CAction()
//{
//	if (m_sprite)
//		delete m_sprite;
//}
//
//void CAction::Go(float ellapseTime)
//{
//	float x = m_sprite->GetPosition().x + m_velocity.x * ellapseTime;
//	float y = m_sprite->GetPosition().x + m_velocity.y * ellapseTime;
//	D3DXVECTOR3 position = D3DXVECTOR3(x, y, 0);
//
//	m_sprite->SetPosition(position);
//}