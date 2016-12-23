#ifndef			__GAME_H__
#define			__GAME_H__
#include "../FrameWork/Graphics.h"
#include "../FrameWork/Window.h"
#include "Simon.h"
#include "../FrameWork/Timer.h"
#include "../FrameWork/Camera.h"
#include "TileMap.h"
#include "../FrameWork/Animation.h"
#include "MorningStar.h"
#include "../FrameWork/Collision.h"

class CGame
{
private:
	CSimon* m_simon;
	CMorningStar* m_morningStar;
	CWindow *m_window;
	CGraphics *m_graphics;
	CTileMap *m_tileMap;
	CTimer * m_timer;
	float m_deltaTime;

public:

	CGame();
	~CGame();
	
	bool Init(HINSTANCE hInstance);
	void Run();
	void Update();
	void End();

};

#endif			//__GAME_H__