#ifndef			__TEXTURE_H__
#define			__TEXTURE_H__
#include <d3d9.h>
#include <d3dx9.h>
#include "../GlobalVariable/Global.h"

class CTexture
{
private:

	LPWSTR m_filePath;
	LPDIRECT3DTEXTURE9 m_image;
	RECT m_size;
	
public:
	CTexture(LPWSTR filePath);
	~CTexture();
	bool Load(D3DCOLOR transparent);
	LPWSTR GetFilePath();
	void Draw(int x, int y);
	LPDIRECT3DTEXTURE9 GetImage();
	
};

#endif			//__TEXTURE_H__