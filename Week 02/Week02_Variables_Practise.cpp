#include <iostream>
// why does #include <string> need to be incorporated?
#include <string>

using namespace std;

int main()
{
   // First create a list of data types by stating first the variable type and then the variable name:
	int age; // creating a variable that is a 'whole number'
	float weight; // creating a variable that is numeric, but is able to use decimals
	double distance; // similar to above, but can use larger values
	bool isAlive; // True or False statement
	char initial; // Singal character
	string name; // String of letters to create words (from namespace std)

	unsigned short int betterAge; // Unsigned -> only positive, short -> smaller range of numbers (0-65,535)
	long double hugeDistance; // long -> longer range of numbers (???), double -> implies any number


	//Then, we define 'Values' to these variables:
	age = 23;
	weight = 65;
	distance = 1215.08;
	isAlive = true;
	initial = 'M';
	name = "Matt";

	//Once everything has been defined, create an output that allows you to see if the code works!
	cout << "My name is " << name << " and I am " << age << " years old." << endl;
	cout << "Am I alive: " << isAlive << endl;

}

