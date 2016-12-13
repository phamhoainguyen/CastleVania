#include "Window.h"
#include "../GlobalVariable/Define.h"
CWindow::CWindow(HINSTANCE hInstance, int mode, bool isFullScreen, LPWSTR windowName)
{
	e_hWnd = NULL;
	e_hInstance = hInstance;
	m_mode = mode;
	m_isFullScreen = isFullScreen;
	m_windowName = windowName;
	SetDimention(m_mode);
}

bool CWindow::Init()
{
	WNDCLASSEX wc;
	wc.cbSize = sizeof(WNDCLASSEX);

	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.hInstance = e_hInstance;

	wc.lpfnWndProc = (WNDPROC)WinProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hIcon = NULL;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = m_windowName;
	wc.hIconSm = NULL;

	RegisterClassEx(&wc);

	DWORD style;
	if (m_isFullScreen)
		style = WS_EX_TOPMOST | WS_VISIBLE | WS_POPUP;
	else
		style = WS_OVERLAPPEDWINDOW;
	e_hWnd =
		CreateWindow(
		m_windowName,
		m_windowName,
		style,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		m_screenWidth,
		m_screenHeight,
		NULL,
		NULL,
		e_hInstance,
		NULL);


	if (!m_isFullScreen)             // if window
	{
		// Adjust window size so client area is GAME_WIDTH x GAME_HEIGHT
		RECT clientRect;
		GetClientRect(e_hWnd, &clientRect);   // get size of client area of window
		MoveWindow(e_hWnd,
			0,                                           // Left
			0,                                           // Top
			m_screenWidth + (m_screenWidth - clientRect.right),    // Right
			m_screenHeight + (m_screenHeight - clientRect.bottom), // Bottom
			TRUE);                                       // Repaint the window
	}
	if (!e_hWnd)
	{
		DWORD ErrCode = GetLastError();
		return false;
	}

	ShowWindow(e_hWnd, SW_SHOWNORMAL);
	UpdateWindow(e_hWnd);
	return true;
}


void CWindow::SetDimention(int mode)
{
	switch (mode)
	{
	case GAME_SCREEN_RESOLUTION_640_480_24:
		m_screenWidth = 640;
		m_screenHeight = 480;
		m_depth = 24;
		break;

	case GAME_SCREEN_RESOLUTION_800_600_24:
		m_screenWidth = 800;
		m_screenHeight = 600;
		m_depth = 24;
		break;

	case GAME_SCREEN_RESOLUTION_1024_768_24:
		m_screenWidth = 1024;
		m_screenHeight = 768;
		m_depth = 24;
		break;

	default:
		break;
	}
}

CWindow::~CWindow()
{
	//delete m_windowName;
}

LRESULT CALLBACK CWindow::WinProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

bool CWindow::GetIsFullScreen()
{
	return m_isFullScreen;
}

int CWindow::GetScreenHeight()
{
	return m_screenHeight;
}

int CWindow::GetScreenWidth()
{
	return m_screenWidth;
}

LPWSTR CWindow::GetWindowName()
{
	return m_windowName;
}