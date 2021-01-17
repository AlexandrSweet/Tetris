#include "Figure.h"

Figure::Figure(Point position)
{
	m_Position = position;
	m_Body = { Point(0, 0), Point(1, 0), Point(2, 0),Point(3, 0) };
}

void Figure::Update(double dt)
{
	m_TimeFromLastUpdate += dt;
	if (m_TimeFromLastUpdate <= m_TimeForUpdate) return;
	m_TimeFromLastUpdate = 0;
	++m_Position.y;
}

void Figure::Draw(Canvas& canvas)
{
	for (const Point& point : m_Body)
	{
		canvas.SetChar(point.x + m_Position.x, point.y + m_Position.y, 0x25D8);
	}
}

void Figure::MoveR()
{
	m_Position.x++;
}

void Figure::MoveL()
{
	m_Position.x--;
}

const std::vector<Point>& Figure::GetBody() const
{
	return m_Body;
}

Point Figure::GetPosition() const
{
	return m_Position;
}

void Figure::Boost()
{
	m_TimeForUpdate = 50;
}



void Figure::Backup()
{
	m_PositionBackup = m_Position;
}

void Figure::Restore()
{
	m_Position = m_PositionBackup;
}
