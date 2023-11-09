// Week02_Centimeters_Converter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int main()
{
    // Prompt distance in cm
    cout << "Please enter the distance measured in cm: ";
    //Retrieve cm
    float centimeters;
    cin >> centimeters;
    //Calculate feet
    float totalFeet = centimeters / 30.48f;
    int justFeet = (int)totalFeet;
    // Calculate inches
    int inches = (int)((totalFeet - justFeet) * 12);
    //Display info to user
    cout << centimeters << "cm is equivalent to " << justFeet << "ft. and " << inches << "in." << endl;
}

