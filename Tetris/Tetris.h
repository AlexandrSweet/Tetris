#pragma once
#include "Game.h"

class Tetris: public Game
{
public:
	void OnKeyPressed(int btnCode) override;
	void Update(double dt) override;
	bool End() override;
};

