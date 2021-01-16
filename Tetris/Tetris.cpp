#include "Tetris.h"

Tetris::Tetris()
{
	m_GameField.Resize(14, 26);
	m_Canvas.Resize(26, 14);
}

void Tetris::OnKeyPressed(int btnCode)
{
}

void Tetris::Update(double dt)
{
	m_Canvas.Clear();
	m_GameField.Draw(m_Canvas);
	m_Canvas.Render();
}

bool Tetris::End()
{
	return false;
}
