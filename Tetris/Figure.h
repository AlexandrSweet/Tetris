#pragma once
#include <vector>
#include "Canvas.h"

using namespace std;

struct Point
{
	Point(int _x=0, int _y=0) : x(_x), y(_y) {}
	int x, y;
};
class Figure
{
public:
	Figure(Point position);
	void Update(double dt);
	void Draw(Canvas& canvas);
	void MoveR();
	void MoveL();

private:
	Point m_Position;
	double m_TimeFromLastUpdate = 0;
	vector<Point> m_Body;

};

