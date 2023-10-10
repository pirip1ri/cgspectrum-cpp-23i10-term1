#include <iostream>

using namespace std;

int main()
{
    //Prompt user for three numbers and retrieve those three numbers
    cout << "We are going to calculate the sum and average of three numbers!" << endl;
    cout << "Please input your first number: ";
    float firstNumber;
    cin >> firstNumber;
    cout << "Now, input your second number: ";
    float secondNumber;
    cin >> secondNumber;
    cout << "Finally, input your third number: ";
    float thirdNumber;
    cin >> thirdNumber;
    //Calculate the sum of the numbers
    float sum = firstNumber + secondNumber + thirdNumber;
    //Calculate the average (or mean) value of the three numbers
    float meanValue = sum / 3;
    //Output the results
    cout << "The sum of " << firstNumber << ", " << secondNumber << " and " << thirdNumber << " is " << sum << ", and the average value is " << meanValue << "." << endl;
}


