#include <iostream>
#include <windows.h>
#include "Key.h"

void Key::Draw()
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console,(int) m_colour);

	std::cout << "+" << std::endl;
	SetConsoleTextAttribute(console, (int) ActorColour::RegularColour);
}