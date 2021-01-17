#include "Tetris.h"

Tetris::Tetris() : m_Figure(Point(5,1))
{
	m_GameField.Resize(14, 26);
	m_Canvas.Resize(26, 14);
}

void Tetris::OnKeyPressed(int btnCode)
{
	switch (btnCode)
	{
	case 75:
		m_Figure.MoveL();
		break;
	case 77:
		m_Figure.MoveR();
		break;	
	case 80:
		m_Figure.Boost();
		return;
	}
	if (m_GameField.HasCollision(m_Figure))
	{
		m_Figure.Restore();
	}
}

void Tetris::Update(double dt)
{
	m_Figure.Backup();
	m_Figure.Update(dt);
	if (m_GameField.HasCollision(m_Figure))
	{
		m_Figure.Restore();
		m_GameField.Merge(m_Figure);
		m_Figure = Point(5, 1);
	}
	m_Canvas.Clear();
	m_GameField.Draw(m_Canvas);
	m_Figure.Draw(m_Canvas);
	m_Canvas.Render();
}

bool Tetris::End()
{
	return false;
}
