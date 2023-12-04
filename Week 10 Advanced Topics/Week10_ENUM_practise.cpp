#include <iostream>

using namespace std;

enum class Day
{
	MONDAY = 1, START_OF_WEEK = MONDAY,
	TUESDAY,
	WEDNESDAY,
	THURSDAY,
	FRIDAY,
	SATURDAY,
	SUNDAY, END_OF_WEEK = SUNDAY
};

Day& operator++(Day& d)
{
	return d = (d == Day::END_OF_WEEK) ? Day::MONDAY : static_cast<Day>(static_cast<int>(d) + 1);
}

ostream& operator<<(ostream& left, const Day& right)
{
	switch (right)
	{
	case Day::MONDAY:
		left << "Monday";
		break;
	case Day::TUESDAY:
		left << "Tuesday";
		break;
	case Day::WEDNESDAY:
		left << "Wednesday";
		break;
	case Day::THURSDAY:
		left << "Thursday";
		break;
	case Day::FRIDAY:
		left << "Friday";
		break;
	case Day::SATURDAY:
		left << "Saturday";
		break;
	case Day::SUNDAY:
		left << "Sunday";
		break;
	default:
		left << "INVALID";
	}
	return left;
}

int main()
{
	Day today = Day::SUNDAY;

	++today;

	if (today > Day::FRIDAY)
	{
		cout << "It's the weekend! :)" << endl;
	}

	if (today < Day::SATURDAY)
	{
		cout << "It's a weekday... :(" << endl;
	}

	++today;
	cout << today << endl;

	return 0;
}