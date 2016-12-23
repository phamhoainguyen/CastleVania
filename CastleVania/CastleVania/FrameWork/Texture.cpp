#include "Texture.h"

CTexture::CTexture(LPWSTR filePath)
{
	m_filePath = filePath;
	m_image = NULL;
}

bool CTexture::Load(D3DCOLOR transparent)
{
	D3DXIMAGE_INFO fileInfo;
	HRESULT result;

	result = D3DXGetImageInfoFromFile(m_filePath, &fileInfo);
	if (result != D3D_OK)
	{
		return false;
	}

	RECT size = { 0, 0, fileInfo.Width, fileInfo.Height };
	this->m_size = size;
	// Tao 1 device cua doi tuong spriteHandler
	LPDIRECT3DDEVICE9 d3ddv; 

	e_spriteHandler->GetDevice(&d3ddv);


	result = D3DXCreateTextureFromFileEx(
		d3ddv,		//su dung device moi duoc tao ra
		m_filePath,
		fileInfo.Width,
		fileInfo.Height,
		1,
		D3DUSAGE_DYNAMIC,
		D3DFMT_UNKNOWN,
		D3DPOOL_DEFAULT,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		transparent,
		&fileInfo,
		NULL,
		&m_image);
	if (result!= D3D_OK)
	{
		return false;
	}


	
	return true;
		
}

void CTexture::Draw(int x, int y)
{
	D3DXVECTOR3 position((float)x, (float)y, 0);
	e_spriteHandler->Draw(m_image, NULL, NULL, &position, D3DCOLOR_XRGB(255, 255, 255));
}

CTexture::~CTexture()
{
	if (m_image)
		m_image->Release();
}

LPDIRECT3DTEXTURE9 CTexture::GetImage()
{
	return m_image;
}