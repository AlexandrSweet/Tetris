#pragma once
#include "Canvas.h"

class GameField
{
public:
	void Resize(int width, int height);
	void Draw(Canvas& canvas);
private:
	int m_Width, m_Height;

};

