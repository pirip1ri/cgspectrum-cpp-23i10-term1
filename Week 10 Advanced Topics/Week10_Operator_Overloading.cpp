#include <iostream>

using namespace std;

class Point
{
public:
	int x;
	int y;

	Point(int x = 0, int y = 0)
		:x(x)
		,y(y)
	{

	}

	//"Operator" Keyword specifies what to use when a specific operator is called
	//Addition
	Point operator+(const Point& other) const
	{
		return Point(x + other.x, y + other.y);
	}

	//Subtraction
	Point operator-(const Point& other) const
	{
		return Point(x + other.x, y + other.y);
	}

	//Negation
	Point operator-() const
	{
		return Point(-x, -y);
	}

	//Multiplication
	Point operator*(int z) const
	{
		return Point(z * x, z * y);
	}
};