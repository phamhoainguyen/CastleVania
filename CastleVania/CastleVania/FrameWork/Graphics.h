#ifndef		__GRAPHICS_H__
#define		__GRAPHICS_H__
#include <d3d9.h>
#include <d3dx9.h>
#include "Global.h"
class CGraphics
{
protected:

	int m_backBufferWidth;
	int m_backBufferHeight;
	bool m_isFullScreen;

	D3DFORMAT m_backBufferFormat;
	
public:
	CGraphics(int backBufferWidth, int backBufferHeight, bool isFullScreen);
	bool Init();
	~CGraphics();
	void Draw();
};

#endif		//__GRAPHICS_H__