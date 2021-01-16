#include "Game.h"

#include <iostream>
#include <conio.h>
#include "FPS.h"

using namespace std;


Game::Game()
{
	m_ConsoleIn = GetStdHandle(STD_INPUT_HANDLE);
}

void Game::Run()
{
	Time last = Clock::now();
	while (!End())
	{
		FPS fps;

		if (_kbhit())
		{
			OnKeyPressed(_getch());
			if(!FlushConsoleInputBuffer(m_ConsoleIn))
				cout << "FlushConsoleInputBuffer failed with error " << GetLastError() << endl;
		}

		Update(static_cast<double>(chrono::duration_cast<chrono::milliseconds>(Clock::now() - last).count()));
		last = Clock::now();

		Sleep(1);
	}
}