#pragma once

#include <Windows.h>
#include <chrono>

#include "Canvas.h"

using namespace std;

class Game
{
	using Clock = chrono::system_clock;
	using Time = chrono::time_point<Clock>;

public:
	Game();

	virtual void OnKeyPressed(int btnCode) = 0;
	virtual void Update(double dt) = 0;
	virtual bool End() = 0;

	void Run();			
private:
	HANDLE m_ConsoleIn;
};
