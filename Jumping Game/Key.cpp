#include <iostream>
#include <windows.h>
#include "Key.h"

void Key::Draw()
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console, m_colour);

	std::cout << "+" << std::endl;
	SetConsoleTextAttribute(console, kRegularColour);
}