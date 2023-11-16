#include <iostream>
#include "Car.h"

int main()
{
	Car myCar(2021, 250, "Blown up TESLA");
	myCar.Display();
	myCar.Drive(50);
	std::cout << "You have driven an additional 50 miles" << std::endl;
	myCar.Display();
}