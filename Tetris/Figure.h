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
	const std::vector<Point>& GetBody() const;
	Point GetPosition() const;
	void Boost();
	void Backup();
	void Restore();

private:
	Point m_Position;
	Point m_PositionBackup;
	double m_TimeFromLastUpdate = 0;
	double m_TimeForUpdate = 500;
	std::vector<Point> m_Body;
};

