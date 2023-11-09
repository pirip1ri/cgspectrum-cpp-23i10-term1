#include <iostream>

using namespace std;

int Power(int base, int exponent);

int main()
{
	cout << "Please input a base value: ";
	int x;
	cin >> x;
	
	cout << Power(x, 0) << endl;
	cout << Power(x, 1) << endl;
	cout << Power(x, 2) << endl;
	cout << Power(x, 3) << endl;
	cout << Power(x, 4) << endl;
}

int Power(int base, int exponent)
{
	if (exponent < 0)
	{
		cout << "Invalid input.";
	}

	else if (exponent == 0)
	{
		return 1;
	}
	else
	{
		return base * Power(base, exponent - 1);
	}
}