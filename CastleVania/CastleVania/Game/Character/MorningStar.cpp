#include "MorningStar.h"
#include "../../FrameWork/GlobalVariable/Define.h"

CMorningStar::CMorningStar() : CSprite()
{
	m_morningStarSrcRectArray = NULL;
}

bool CMorningStar::Init(LPWSTR filePath)
{
	//////////////////////////Create and Load Texture/////////////////
	m_texture = new CTexture(filePath);
	if (!m_texture->Load(D3DCOLOR_XRGB(255, 0, 255)))
		return false;
	/****************************************************************/

	m_frameHeight = 68;
	m_frameWidth = 160;
	m_framePerRow = 3;
	m_framePerCol = 3;

	/***********************************/
	m_morningStarSrcRectArray = new RECT[9];
	for (int i = 0; i < 9; i++)
	{
		m_morningStarSrcRectArray[i].top = (i / m_framePerRow) * m_frameHeight;
		m_morningStarSrcRectArray[i].left = (i % m_framePerRow) * m_frameWidth;
		m_morningStarSrcRectArray[i].right = m_morningStarSrcRectArray[i].left + m_frameWidth;
		m_morningStarSrcRectArray[i].bottom = m_morningStarSrcRectArray[i].top + m_frameHeight;
	}

	if (m_morningStarSrcRectArray == NULL || m_frameHeight == 0 || m_frameWidth == 0)
		return false;


	return true;
}

//void CMorningStar::SetSrcRect(int type)
//{
//	//RECT srcRect = { (type / m_framePerRow) * m_frameWidth, (type % m_framePerRow) * m_frameHeight, m_frameWidth, m_frameHeight };
//	//m_srcRect = &srcRect;
//	m_srcRect->top = (type / m_framePerRow) * m_frameWidth;
//	m_srcRect->left = (type % m_framePerRow) * m_frameHeight;
//	m_srcRect->right = m_srcRect->left + m_frameWidth;
//	m_srcRect->bottom = m_srcRect->top + m_frameHeight;
//
//	//CSprite::SetSrcRect(&srcRect);
//}

void CMorningStar::SetMorningStarType(int type)
{
	m_type = type;
}

//void CMorningStar::SetPosition(D3DXVECTOR3 characterPosition)
//{ 
//	if (m_characterFrameNumber == 1)
//		m_position.x = characterPosition.x - 145;
//
//	if (m_characterFrameNumber == 2)
//		m_position.x = characterPosition.x - 130;
//
//	if (m_characterFrameNumber == 3)
//		m_position.x = characterPosition.x - 98;
//
//	m_position.y = characterPosition.y;
//	m_position.z = characterPosition.z;
//}

void CMorningStar::Draw(int level, int numberFrame, D3DXVECTOR3 position, int direction)
{
	m_position.y = position.y;
	m_position.z = position.z;
	if (direction == 1)
	{
		if (numberFrame == 5 || numberFrame == 15 || numberFrame == 18 || numberFrame == 21)
		{
			m_srcRect = &m_morningStarSrcRectArray[(level * 3) + 0];
			m_position.x = position.x - 145 + 60; //OK
			CSprite::Draw();
		}

		if (numberFrame == 6 || numberFrame == 16 || numberFrame == 19 || numberFrame == 22)
		{
			m_srcRect = &m_morningStarSrcRectArray[(level * 3) + 1];
			m_position.x = position.x - 130 + 55; //OK
			CSprite::Draw();

		}

		if (numberFrame == 7 || numberFrame == 17 || numberFrame == 20 || numberFrame == 23)
		{
			m_srcRect = &m_morningStarSrcRectArray[(level * 3) + 2];
			m_position.x = position.x - 98 + 20; //OK
			m_position.y = position.y;
			CSprite::Draw();
		}
	}

	if (direction == 2)
	{
		if (numberFrame == 5 || numberFrame == 15 || numberFrame == 18 || numberFrame == 21)
		{
			m_srcRect = &m_morningStarSrcRectArray[(level * 3) + 0];
			m_position.x = position.x - 145 + 130; //OK
			CSprite::DrawFlipY();
		}

		if (numberFrame == 6 || numberFrame == 16 || numberFrame == 19 || numberFrame == 22)
		{
			m_srcRect = &m_morningStarSrcRectArray[(level * 3) + 1];
			m_position.x = position.x - 130 + 115; //OK
			CSprite::DrawFlipY();

		}

		if (numberFrame == 7 || numberFrame == 17 || numberFrame == 20 || numberFrame == 23)
		{
			m_srcRect = &m_morningStarSrcRectArray[(level * 3) + 2];
			m_position.x = position.x - 98 + 80; //OK
			m_position.y = position.y + 3;
			CSprite::DrawFlipY();
		}
	}

}


CMorningStar::~CMorningStar()
{

}