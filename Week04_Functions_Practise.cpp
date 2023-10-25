#include <iostream>

using std::cout;
using std::endl;
using std:: string;

void printMessage(string message);
int addition(int num1, int num2);
float Max(float n1, float n2, float n3);
bool isEven(int number);
bool isOdd(int number);

int main()
{
	printMessage("Testing addition function: ");
	cout << addition(1,2) << endl;

	printMessage("Testing maximum value function: ");
	float MAX = Max(20.5f, 50.5f, 30.5f);
	cout << MAX << endl;

	printMessage("Testing even function: ");
	int number = 10;
	bool IsEven = isEven(number);
	bool IsOdd = isOdd(number);

	if (IsEven)
	{
		cout << number << " is even" << endl;

	}
	if (isOdd)
	{
		cout << number << " is odd" << endl;
	}

}

void printMessage(string message)
{
	cout << message << endl;
}

int addition(int num1, int num2)
{
	return (num1 + num2);
}

float Max(float n1, float n2, float n3)
{
	float max = n1;
	if (n2 > max)
	{
		max = n2;
	}
	if (n3 > max)
	{
		max = n3;
	}
	return max;
}

bool isEven(int number)
{
	if (number % 2 == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool isOdd(int number)
{
	return !isEven(number);
}