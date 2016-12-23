#include "Timer.h"

CTimer::CTimer()
{
	start = 0;
	elapsedTime = 0;
	totalGameTime = 0;
	now = 0;
}

bool CTimer::Initialize()
{
	//LARGE_INTEGER i;

	//if (!QueryPerformanceFrequency(&i))
	//	return false;

	//frequencySeconds = (float)(i.QuadPart);

	//QueryPerformanceCounter(&i);
	//start = i.QuadPart;
	start = GetTickCount();
	totalGameTime = 0;

	return true;
}

LONGLONG CTimer::GetElapsedTime()
{
	//LARGE_INTEGER i;

	//QueryPerformanceCounter(&i);
	//elapsedTime = (float)(i.QuadPart - start) / frequencySeconds;
	//totalGameTime += elapsedTime;
	now = GetTickCount();
	elapsedTime = now - start;
	totalGameTime += elapsedTime;

	return elapsedTime;
	
}

LONGLONG CTimer::GetTotalGameTime()
{
	return totalGameTime;
}

void CTimer::Reset()
{
	//LARGE_INTEGER i;
	//QueryPerformanceCounter(&i);
	//start = i.QuadPart;

	start = now;
}