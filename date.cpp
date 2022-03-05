#include <iostream>
#include <map>
#include <string>
#include "calendar.h"

using namespace std;

static const map<int, string> DAYS_OF_WEEK_IN_STRING =
{ {1, "Monday"s}, {2, "Tuesday"s}, {3, "Wednesday"s}, {4, "Thursday"s},
	{5, "Friday"s}, {6, "Saturday"s}, {7, "Sunday"s} };


Date::Date(int number, Month month, Year year) :
	number_(number),
	year_(year),
	month_(month),
	dayOfWeek_(DaysOfWeek::UNDEFINED) // For now... later call getDayOfWeek (TODO)
{
}


ostream& operator<<(ostream& o, const Date& date) {
	o << DAYS_OF_WEEK_IN_STRING.at(static_cast<int>(date.dayOfWeek_)) << ", ";
	o << date.month_ << ' ';
	o << date.number_ << ", " << date.year_ << endl;

	return o;
}

void Date::dateAbreviation() const {
	if (number_ < 10) cout << 0;
	cout << number_ << '/';
	
	if (month_.getNumber() < 10) cout << 0;
	cout << month_.getNumber() << '/';
	
	cout << year_ << endl;
}

void Date::americanDateAbreviation() const {
	if (month_.getNumber() < 10) cout << 0;
	cout << month_.getNumber() << '/';

	if (number_ < 10) cout << 0;
	cout << number_ << '/';

	cout << year_ << endl;
}