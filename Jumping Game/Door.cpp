#include <iostream>
#include <windows.h>
#include "Door.h"

Door::Door(int x, int y, ActorColour color, ActorColour closedColor)
    : PlacableActor(x, y, color)
    , m_isOpen(false)
    , m_closedColour(closedColor)
{

}

void Door::Draw()
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    if (m_isOpen)
    {
        SetConsoleTextAttribute(console, (int)(m_colour)); // Changed m_colour
    }
    else
    {
        SetConsoleTextAttribute(console, (int)(m_closedColour)); // Changed m_closedColour
    }
    std::cout << "|";
    SetConsoleTextAttribute(console, (int)(ActorColour::RegularColour));
}