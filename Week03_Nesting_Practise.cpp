#include <iostream>

using namespace std;

int main()
{
	float firstNumber;
	cout << "Please enter a positive number: ";
	cin >> firstNumber;

	if (firstNumber > 0)
	{
		float secondNumber;
		cout << "Please enter a non-zero number: ";
		cin >> secondNumber;

		if (secondNumber != 0)
		{
			float answer = (firstNumber / secondNumber);
			cout << firstNumber << " / " << secondNumber << " = " << answer;
		}
		else if (secondNumber == 0)
		{
			cout << "Invalid input. Cannot compute. Goodbye!" << endl;
		}
		else
		{
			cout << "Invalid input. Goodbye!" << endl;
		}
	}
	else
	{
		cout << "Invalid Input. Goodbye!";
	}
}