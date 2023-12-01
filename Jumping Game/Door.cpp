#include <iostream>
#include <windows.h>
#include "Door.h"

Door::Door(int x, int y, int colour, int ClosedColour)
	:PlacableActor(x, y, colour)
	, m_isOpen(false)
	, m_closedColour(ClosedColour)
{

}

void Door::Draw()
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	if (m_isOpen)
	{
		SetConsoleTextAttribute(console, m_colour);
	}
	else
	{
		SetConsoleTextAttribute(console, m_closedColour);
	}
	std::cout << "|";
	SetConsoleTextAttribute(console, kRegularColour);
}