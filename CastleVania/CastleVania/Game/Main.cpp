#include"Game.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{

	CGame game = CGame();
	game.Init(hInstance);
	game.Run();
	game.End();

	return 0;
}