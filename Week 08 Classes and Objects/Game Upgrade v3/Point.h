#pragma once

struct Point // struct is a type of class that is set to public as default
{
	int x; // member variable
	int y;


	Point()
		:x(0)
		,y(0)
	{

	}
	Point(int x, int y)
	{
		this->x = x; // 'this ->' function specifies the member variable position.
		this->y = y;
	}
};