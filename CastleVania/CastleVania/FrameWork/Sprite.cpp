#include "Sprite.h"
#include "Global.h"

CSprite::CSprite()
{
	m_texture = NULL;

	m_angle = 0;

	m_center.x = 0;
	m_center.y = 0;
	m_center.z = 0;

	m_position.x = 0;
	m_position.y = 0;
	m_position.z = 0;
	
	m_framePerRow = 0;
	m_totalFrame = 0;
	m_framePerCol = 0;
	
	m_frameHeight = 0;
	m_frameWidth = 0;

	m_srcRect = NULL;
}


CSprite::CSprite(CTexture* texture)
{
	m_texture = texture;

	m_srcRect = NULL;

	m_angle = 0;

	m_center.x = 0;
	m_center.y = 0;
	m_center.z = 0;

	m_framePerRow = 0;
	m_totalFrame = 0;
	m_framePerCol = 0;

	m_position.x = 0;
	m_position.y = 0;
	m_position.z = 0;

	m_frameHeight = 0;
	m_frameWidth = 0;
}


void CSprite::SetFrameWidth(int frameWidth)
{
	m_frameWidth = frameWidth;
}
int CSprite::GetFrameWidth()
{
	return m_frameWidth;
}

void CSprite::SetFrameHeight(int frameHeight)
{
	m_frameHeight = frameHeight;
}
int CSprite::GetFrameHeight()
{
	return m_frameHeight;
}

void CSprite::SetFramePerRow(int framePerRow)
{
	m_framePerRow = framePerRow;
}
int CSprite::GetFramePerRow()
{
	return m_framePerRow;
}

void CSprite::SetFramePerCol(int framePerCol)
{
	m_framePerCol = framePerCol;
}
int CSprite::GetFramePerCol()
{
	return m_framePerCol;
}


void CSprite::SetTotalFrame(int totalFrame)
{
	m_totalFrame = totalFrame;
}

int CSprite::GetTotalFrame()
{
	return m_totalFrame;
}


void CSprite::SetSrcRect(RECT* srcRect)
{
	m_srcRect = srcRect;
}


RECT CSprite::GetBodySprite()
{
	RECT body;
	body.top = (LONG)m_position.x;
	body.left = (LONG)m_position.y;
	body.right = (LONG)(m_position.x + m_srcRect->right - m_srcRect->left);
	body.bottom = (LONG)(m_position.y + m_srcRect->bottom - m_srcRect->top);
	return body;
}


void CSprite::SetCenter(int type)
{
	if (type == 1)
	{
		m_center.x = m_position.x + (m_srcRect->right - m_srcRect->left) / 2;
		m_center.y = m_position.y + (m_srcRect->top - m_srcRect->bottom) / 2;
		m_center.z = 0;
	}
}

D3DXVECTOR3 CSprite::GetCenter()
{
	return m_center;
}

void CSprite::SetPosition(int x, int y)
{
	m_position.x = x;
	m_position.y = y;
}

D3DXVECTOR3 CSprite::GetPosition()
{
	return m_position;
}


void CSprite::Draw()
{

	e_spriteHandler->Draw(
		m_texture->GetImage(),
		m_srcRect,
		NULL,
		&m_position,
		D3DCOLOR_XRGB(255, 255, 255)
		//0xFFFFFFFF //color
		);
}


void CSprite::Draw(int x, int y)
{

	CSprite::SetPosition(x, y);
	e_spriteHandler->Draw(
		m_texture->GetImage(),
		m_srcRect,
		NULL,
		&m_position,
		D3DCOLOR_XRGB(255, 255, 255)
		//0xFFFFFFFF //color
		);
}

void CSprite::Rotate()
{

}


void CSprite::DrawFlipY()
{
	CSprite::SetCenter(1);
	D3DXMATRIX oldMt;
	e_spriteHandler->GetTransform(&oldMt);

	D3DXMATRIX newMt;
	D3DXVECTOR2 center = D3DXVECTOR2(m_center.x, m_center.y);
	D3DXVECTOR2 rotate = D3DXVECTOR2(-1, 1);

	D3DXMatrixTransformation2D(&newMt, &center, 0.0f, &rotate, NULL, 0.0f, NULL);
	D3DXMATRIX finalMt = newMt * oldMt;
	e_spriteHandler->SetTransform(&finalMt);

	//m_position.x += m_frameWidth;
	this->Draw();

	e_spriteHandler->SetTransform(&oldMt);
}

void CSprite::SetAngle(int angle)
{
	m_angle = angle;
}


CSprite::~CSprite()
{
	if (m_texture != NULL)
		delete m_texture;
	if (m_srcRect != NULL)
		delete m_texture;
}

