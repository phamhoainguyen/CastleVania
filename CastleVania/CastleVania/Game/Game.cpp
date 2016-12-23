#include "Game.h"
#include "../FrameWork/Input.h"
#include "../FrameWork/Define.h"

CGame::CGame()
{
	m_graphics = NULL;
	m_window = NULL;
	m_tileMap = NULL;
	m_simon = NULL;
	m_timer = NULL;
	m_deltaTime = 0.0f;
	m_morningStar = NULL;
}

CGame::~CGame()
{
}

bool CGame::Init(HINSTANCE hInstance)
{

	m_timer = new CTimer();
	m_timer->Initialize();

	m_window = new CWindow(hInstance, GAME_SCREEN_RESOLUTION_800_600_24, NO_FULL_SCREEN, WINDOW_NAME);
	m_window->Init();
	m_graphics = new CGraphics(m_window->GetScreenWidth(), m_window->GetScreenHeight(), m_window->GetIsFullScreen());
	m_graphics->Init();

	
	if (CInput::GetInstance()->InitInput(e_hInstance) == 0)
		return false;
	if (CInput::GetInstance()->InitKeyboard(e_hWnd) == 0)
		return false;


	/***************Simon**********************/
	m_simon = new CSimon();

	if (!(m_simon->Init(L"Resources/simon.png")))
		return false;

	m_simon->SetPosition(CCamera::GetInstance()->Transform(200, 100).x + 1, CCamera::GetInstance()->Transform(200, 100).y);


	m_tileMap = new CTileMap(L"Resources/ground/tilemapTS.png", "Resources/ground/tilemapBG.txt", 576);

	if (m_tileMap->LoadMap())
		return false;



	return true;
}

void CGame::Run()
{
	MSG msg;
	int done = 0;



	while (!done)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT) done = 1;

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		e_spriteHandler->Begin(D3DXSPRITE_ALPHABLEND);

		this->Update();

		e_spriteHandler->End();
		
		m_graphics->Draw();
	}
}


void CGame::Update()
{
	INPUT->ProcessKeyboard();
	INPUT->Update();

	e_pD3DDevice->ColorFill(e_pBackBuffer, NULL, D3DCOLOR_XRGB(0, 0, 0)); // refresh backbuffer before draw

	if ((m_deltaTime = m_timer->GetElapsedTime()) >= ((m_deltaTime*FRAME_PER_SECOND) / 1000))
	{
		m_deltaTime = m_deltaTime / 1000;
		m_simon->Update(m_deltaTime);
		m_tileMap->Render(CCamera::GetInstance());
		m_simon->Move();
		m_timer->Reset();
	}
	
}


void CGame::End()
{
	delete m_graphics;
	delete m_window;
}