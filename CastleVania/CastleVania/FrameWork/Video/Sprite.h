#ifndef			__SPRITE_H__
#define			__SPRITE_H__
#include "Texture.h"

class CSprite
{
protected:
	CTexture* m_texture;
	RECT* m_srcRect;
	D3DXVECTOR3 m_center;
	int m_framePerRow;
	int m_totalFrame;
	int m_framePerCol;
	int m_frameWidth;
	int m_frameHeight;
	D3DXVECTOR3 m_position;
	int m_angle;

public:
	CSprite();
	CSprite(CTexture* texture);

	virtual void SetFrameWidth(int frameWidth);
	virtual int GetFrameWidth();

	virtual void SetFrameHeight(int frameHeight);
	virtual int GetFrameHeight();

	virtual void SetFramePerRow(int framePerRow);
	virtual int GetFramePerRow();

	virtual void SetFramePerCol(int framePerCol);
	virtual int GetFramePerCol();

	virtual void SetTotalFrame(int totalFrame);
	virtual int GetTotalFrame();

	virtual void SetSrcRect(RECT* srcRect);
	virtual RECT GetBodySprite();

	virtual void SetCenter(int type);
	D3DXVECTOR3 GetCenter();

	virtual void SetPosition(int x, int y);
	D3DXVECTOR3 GetPosition();

	virtual void Draw(int x, int y);

	virtual void Draw();
	virtual void Rotate();

	virtual void DrawFlipY();

	void SetAngle(int angle);

	virtual ~CSprite();

};

#endif			// __SPRITE_H__
//
//#ifndef			__SPRITE_H__
//#define			__SPRITE_H__
//#include "Texture.h"
//
//class CSprite
//{
//protected:
//	CTexture* m_texture;
//	RECT* m_srcRect;
//	D3DXVECTOR3 m_position;
//	int m_currentFrame;
//	int m_totalFrame;
//	int m_angle;
//	float m_timeLocal;
//
//public:
//	CSprite();
//	CSprite(CTexture* texture, RECT* srcRect, int totalFrame);
//
//	//sang frame tiếp theo
//	virtual void Next();
//
//	//trở về frame đầu tiên
//	virtual void Reset();
//
//	void Update(float gameTime);
//
//	//chọn 1 frame nào đó
//	virtual void SelectIndex(int index);
//
//	//update animation
//	//virtual void Update(int ellapseTime);
//
//	// Render current sprite at location (X,Y) at the target surface
//	virtual void Draw();
//
//	//Render with scale (-1, 1)
//	virtual void DrawFlipX();
//
//	//render with scale (1, -1)
//	virtual void DrawFlipY();
//
//	//Render Rect of texture at (x,y)
//	virtual void DrawRect(int X, int Y, RECT SrcRect);
//
//	virtual RECT GetBodySprite();
//
//	virtual void DrawIndex(int index);
//	virtual void SetPosition(D3DXVECTOR3 position);
//	virtual D3DXVECTOR3 GetPosition();
//	virtual int GetIndex();
//	virtual ~CSprite();
//
//
//
//};
//
//
//#endif			// __SPRITE_H__