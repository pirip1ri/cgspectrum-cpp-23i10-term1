#include <iostream>

using namespace std;

void populateArray(float theArray[], int size);
float getAverage(float theArray[], int size);
void displayArray(float theArray[], int size);
float largestValue(float theArray[], int size);
float smallestValue(float theArray[], int size);

int main()
{
	constexpr int kSize = 5;
	float myGrades[kSize];
	cout << "Please enter 5 grades" << endl;
	populateArray(myGrades, kSize);
	float average = getAverage(myGrades, kSize);
	cout << "The average of your grades ";
	displayArray(myGrades, kSize);
	cout << " is " << average << endl;

}

void populateArray(float theArray[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cin >> theArray[i];
	}
}

float getAverage(float theArray[], int size)
{
	float sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += theArray[i];
	}

	float average = sum / size;
	return average;
}

void displayArray(float theArray[], int size)
{
	for (int i = 0; i < (size-1); i++)
	{
		cout << theArray[i] << " ";
	}
	cout << "and " << theArray[(size - 1)];
}

float largestValue(float theArray[], int size)
{
	float largestValue = theArray[0];

	for (int i = 1; i < size; i++)
	{
		if (largestValue < theArray[i])
		{
			largestValue = theArray[i];
		}
	}
	return largestValue;
}

float smallestValue(float theArray[], int size)
{
	float smallestValue = theArray[0];

	for (int i = 1; i < size; i++)
	{
		if (smallestValue > theArray[i])
		{
			smallestValue = theArray[i];
		}
	}
	return smallestValue;
}
