#include <iostream>

using namespace std;

int main()
{
	cout << "----- Leap Year Calculator -----" << endl;
	cout << "Please enter a year: ";

	int year;
	cin >> year;

	if (year % 4 == 0)
	{
		if (year % 100 == 0)
		{
			if (year % 400 == 0)
			{
				cout << year << " is a leap year." << endl;
			}
			else
			{
				cout << year << " is not a leap year." << endl;
			}
		}
		else
		{
			cout << year << " is a leap year." << endl;
		}
	}
	else if (year % 4 == 1 || year % 4 == 2 || year % 4 == 3)
	{
		cout << year << " is not a leap year." << endl;
	}

	else
	{
		cout << year << "Invalid input." << endl;
	}
}
