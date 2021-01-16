#pragma once
#include <chrono>

using namespace std;

class FPS
{
	using Clock = chrono::system_clock;
	using Time = chrono::time_point<Clock>;

public:
	FPS();
	~FPS();

private:
	int ElapsedSeconds();

	static int m_FPS;
	static int m_FPSCount;
	static Time m_Last;
};
