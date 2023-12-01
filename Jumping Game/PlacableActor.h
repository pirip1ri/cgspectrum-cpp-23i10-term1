#pragma once
#include "Point.h"

constexpr int kGreenColour = 10;
constexpr int kGreenColourSolid = 34;
constexpr int kRedColour = 12;
constexpr int kRedColourSolid = 68;
constexpr int kBlueColour = 9;
constexpr int kBlueColourSolid = 153;
constexpr int kRegularColour = 7;

class PlacableActor
{
public:
	PlacableActor(int x, int y, int colour = kRegularColour);
	virtual ~PlacableActor();

	int GetXPosition();
	int GetYPosition();
	int* GetXPositionPointer();
	int* GetYPositionPointer();
	void SetPosition(int x, int y);

	int GetColour()
	{
		return m_colour;
	}
	void Remove()
	{
		m_IsActive = false;
	}
	bool IsActive()
	{
		return m_IsActive;
	}
	void Place(int x, int y);

	virtual void Draw() = 0; // pure virtual
	virtual void Update() // Some players will not need to update themselves, so an empty function would do to create an instance#include "Pla
	{

	}

protected:
	Point* m_pPosition;
	bool m_IsActive;
	int m_colour;
};
