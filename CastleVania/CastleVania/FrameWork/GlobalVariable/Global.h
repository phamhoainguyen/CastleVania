#ifndef			__GLOBAL_H__
#define			__GLOBAL_H__
#include <d3d9.h>
#include <d3dx9.h>
#include <dinput.h>

extern HWND e_hWnd;							// Window for Graphics
extern IDirect3D9* e_pDirectObject;			// Direct Object
extern IDirect3DDevice9* e_pD3DDevice;		// device
extern HWND e_hWnd;							// Dung de luu tru cua so sau khi tao thanh cong
extern HINSTANCE e_hInstance;				// Handle can de tao 1 cua so
extern LPD3DXSPRITE e_spriteHandler;		// Sprite Handler
extern IDirect3DSurface9* e_pBackBuffer;	// backbuffer
extern int e_tickPerFrame;
extern int e_screenWidth;
extern int e_screenHeight;


#endif			//__GLOBAL_H__