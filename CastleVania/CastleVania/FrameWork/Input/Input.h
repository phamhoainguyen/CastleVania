
#ifndef __INPUT_H__
#define __INPUT_H__

#include "../GlobalVariable/Global.h"
#include "../Pattern/Singleton.h"
#include <dinput.h>

#define KEYBOARD_BUFFER_SIZE 256
class CInput : public Singleton<CInput>
{
	friend class Singleton<CInput>;
protected:
	CInput(void);
	LPDIRECTINPUT8 m_dinput;
	LPDIRECTINPUTDEVICE8 m_keyboard;

	int Keyboard_Buffer_Size;
	BYTE  m_keyStates[256];
	DIDEVICEOBJECTDATA m_keyEvents[KEYBOARD_BUFFER_SIZE];
	int m_keyUP;
	int m_keyDown;

public:
	~CInput(void);
	int InitInput(HINSTANCE hInstance);
	int InitKeyboard(HWND hWnd);

	// Lấy trạng thái bàn phím
	void ProcessKeyboard();

	//// Xử lí keydown = buffer
	//int KeyDown(int KeyCode);
	//Update KeyState tu KeyEvents
	void Update();

	//Lay trang thai phim voi "key"
	//BYTE GetKeyState(int key) { return m_keyStates[key]; }

	// Xử lí keydown
	int IsKeyDown(int KeyCode);

	int GetKeyDown();
	int GetKeyUp();

};
#endif // !__INPUT_H__

