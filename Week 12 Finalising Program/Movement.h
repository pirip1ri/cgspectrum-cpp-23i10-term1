#pragma once

class Movement
{
public:
	void MovingUp(int& newPlayerX, int& newPlayerY, bool& m_FloorBelow, bool& m_Jumping, bool& m_floating);
	void MovingLeft(int& newPlayerX, int& newPlayerY, bool& m_FloorBelow, bool& m_Jumping, bool& m_floating);
	void MovingRight(int& newPlayerX, int& newPlayerY, bool& m_FloorBelow, bool& m_Jumping, bool& m_floating);
};