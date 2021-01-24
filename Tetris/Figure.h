#pragma once
#include <vector>
#include "Canvas.h"


struct Point
{
	Point(int _x=0, int _y=0) : x(_x), y(_y) {}
	int x;
	int y;
};
class Figure
{
public:
	Figure(Point position);
	void Update(double dt);
	void Draw(Canvas& canvas);
	void MoveR();
	void MoveL();
	void Rotate();
	const std::vector<Point>& GetBody() const;
	Point GetPosition() const;
	void SetPosition(Point position);
	void Boost();
	void Backup();
	void Restore();

private:
	Point m_Position;
	Point m_PositionBackup;
	double m_TimeFromLastUpdate = 0;
	double m_TimeForUpdate = 500;
	std::vector<std::vector<Point>> m_Body;
	size_t m_CurrentRotate = 0;
	size_t m_CurrentRotateBackup = 0;
};

