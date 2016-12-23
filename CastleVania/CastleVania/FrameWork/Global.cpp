#include "Global.h"


HWND e_hWnd;						// Window for Graphics
IDirect3D9* e_pDirectObject;		// Direct Object
IDirect3DDevice9* e_pD3DDevice;		// Device
HINSTANCE e_hInstance;				// Handle can de tao 1 cua so	
LPD3DXSPRITE e_spriteHandler;		// Sprite Handler
IDirect3DSurface9* e_pBackBuffer;	// backbuffer
 int e_tickPerFrame = 30;
 int e_screenWidth = 800;
 int e_screenHeight = 600;
