#ifndef GAMETIME_H
#define GAMETIME_H

#include <Windows.h>

class CTimer
{

public:

	CTimer();
	bool Initialize();
	LONGLONG GetElapsedTime();
	LONGLONG GetTotalGameTime();
	void Reset();
private:
	
	LONGLONG start;
	LONGLONG elapsedTime;
	LONGLONG totalGameTime;
	LONGLONG now;
};
#endif /* GAME_H */