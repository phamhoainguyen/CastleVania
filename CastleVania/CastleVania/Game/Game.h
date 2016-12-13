#ifndef			__GAME_H__
#define			__GAME_H__
#include "../FrameWork/Graphics/Graphics.h"
#include "../FrameWork/Graphics/Window.h"
#include "Character/Simon.h"
#include "../FrameWork/Time/Timer.h"
#include "../FrameWork/Video/Camera.h"
#include "Map/TileMap.h"
#include "../FrameWork/Video/Animation.h"
#include "Character/MorningStar.h"

class CGame
{
private:
	CSimon* m_simon;
	CMorningStar* m_morningStar;
	CWindow *m_window;
	CGraphics *m_graphics;
	CTileMap *m_tileMap;
	CTimer * m_timer;

public:

	CGame();
	~CGame();
	bool Init(HINSTANCE hInstance);
	void Run();
	void End();

};

#endif			//__GAME_H__