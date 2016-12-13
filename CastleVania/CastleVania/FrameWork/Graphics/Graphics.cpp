#include "Graphics.h"
#include "../GlobalVariable/Define.h"
#include <stdio.h>
CGraphics::CGraphics(int backBufferWidth, int backBufferHeight, bool isFullScreen)
{
	e_pDirectObject = NULL;
	e_pD3DDevice = NULL;
	e_pBackBuffer = NULL;
	m_backBufferFormat = BACKBUFFER_FORMAT_D3DFMT_X8R8G8B8;
	m_backBufferWidth = backBufferWidth;
	m_backBufferHeight = backBufferHeight;
	m_isFullScreen = isFullScreen;
	e_spriteHandler = NULL;
}

bool CGraphics::Init()
{
	e_pDirectObject = Direct3DCreate9(D3D_SDK_VERSION);
	if (!e_pDirectObject)
		return false;
	D3DPRESENT_PARAMETERS d3dpp;

	ZeroMemory(&d3dpp, sizeof(d3dpp));

	d3dpp.Windowed = m_isFullScreen ? FALSE : TRUE;

	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;

	d3dpp.BackBufferFormat = m_backBufferFormat;
	d3dpp.BackBufferCount = 1;
	d3dpp.BackBufferHeight = m_backBufferHeight;
	d3dpp.BackBufferWidth = m_backBufferWidth;
	HRESULT result;

	result = e_pDirectObject->CreateDevice(
		D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		e_hWnd,
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&d3dpp,
		&e_pD3DDevice);

	if (result != D3D_OK)
	{
		return false;
	}

	result = e_pD3DDevice->GetBackBuffer(0, 0, D3DBACKBUFFER_TYPE_MONO, &e_pBackBuffer);
	if (result != D3D_OK)
	{
		return false;
	}

	result = D3DXCreateSprite(e_pD3DDevice, &e_spriteHandler);
	LPD3DXSPRITE a = e_spriteHandler;

	if (result != D3D_OK)
	{
		return false;
	}
	return true;
	
}


void CGraphics::Draw()
{
	if (e_pD3DDevice->BeginScene())
	{
		//e_pD3DDevice->ColorFill(e_pBackBuffer, NULL, D3DCOLOR_XRGB(0, 0, 0));
		e_pD3DDevice->EndScene();
	}
	e_pD3DDevice->Present(NULL, NULL, NULL, NULL);
		
}

CGraphics::~CGraphics()
{
	if (e_pD3DDevice)
	{
		e_pD3DDevice->Release();
	}

	if (e_pDirectObject)
	{
		e_pDirectObject->Release();
	}

	if (e_pBackBuffer)
	{
		e_pBackBuffer->Release();
	}

}