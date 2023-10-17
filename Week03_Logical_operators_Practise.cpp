#include <iostream>

using namespace std;

int main()
{
	cout << "Please enter an integer: ";
	int integer;
	cin >> integer;

	bool isPositive = (integer > 0);
	bool isNegative = (integer < 0);
	bool isZero = !isPositive && !isNegative;
	bool isNonZero = !isZero;

	bool isEven = (integer % 2) == 0;
	bool isOdd = !isEven;

	if (isNonZero)
	{
		if (isPositive && isEven)
			cout << integer << " is a Positive Even Number." << endl;

		else if (isPositive && isOdd)
			cout << integer << " is a Positive Odd Number." << endl;

		else if (isNegative && isOdd)
			cout << integer << " is a Negative Odd Number." << endl;

		else
			cout << integer << " is a Negative Even Number." << endl;
	}

	else
	{
		cout << "The value you put in is zero." << endl;
	}
}
