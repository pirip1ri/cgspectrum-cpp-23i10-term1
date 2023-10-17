#include <iostream>

using namespace std;

int main()
{
	float score;
	float total;
	cout << "Please enter the total amount of marks you achieved on the paper: ";
	cin >> score;
	cout << "Please enter the total amount of marks the paper could have: ";
	cin >> total;

	float grade = (score / total);

	cout << "You're grade is: ";
	if (grade >= 0.9)
	{
		cout << "A+" << endl;
	}
	else if (grade >= 0.8)
	{
		cout << "A" << endl;
	}
	else if (grade >= 0.7)
	{
		cout << "B" << endl;
	}
	else if (grade >= 0.6)
	{
		cout << "C" << endl;
	}
	else if (grade >= 0.5)
	{
		cout << "D" << endl;
	}
	else
	{
		cout << "F" << endl;
	}
}