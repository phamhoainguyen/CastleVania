#ifndef		__WINDOW_H__
#define		__WINDOW_H__
#include <Windows.h>
#include "../GlobalVariable/Global.h"

class CWindow
{
private:
	/***********************Cac thanh phan can thiet de ve cua so Window*************************/
	int m_screenWidth;				// Chieu rong cua so										//
	int m_screenHeight;				// Chieu dai cua so											//
	int m_mode;						// che do cua so (800x600, 600x480, ...)					//
	bool m_isFullScreen;			// Thiet lap cua so co full man hinh hay khong				//
	int m_depth;					// Do sau cua cua so										//
	LPWSTR m_windowName;			// Ten class cua cua so										//
	//////////////////////////////////////////////////////////////////////////////////////////////

	/*****************************Con tro ham de xu ly su kien message***************************/
	static LRESULT CALLBACK WinProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);		//
	//////////////////////////////////////////////////////////////////////////////////////////////

	/************tuy vao mode ma chung ta dung ham nay set width and height cho cua so***********/
	void SetDimention(int mode);																//
	//////////////////////////////////////////////////////////////////////////////////////////////

public:
	CWindow(HINSTANCE hInstance, int mode, bool isFullScreen, LPWSTR windowName);
	~CWindow();
	bool Init();						// Khoi tao cua so
	int GetScreenWidth();
	int GetScreenHeight();
	bool GetIsFullScreen();
	LPWSTR GetWindowName();
};

#endif		//__WINDOW_H__