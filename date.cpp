#include <iostream>
#include <map>
#include <string>
#include "calendar.h"

using namespace std;

static const map<int, string> DAYS_OF_WEEK_IN_STRING =
{ {1, "Monday"s}, {2, "Tuesday"s}, {3, "Wednesday"s}, {4, "Thursday"s},
	{5, "Friday"s}, {6, "Saturday"s}, {7, "Sunday"s} };

static const map<unsigned, string> MONTHS_IN_STRING =
{ {1, "January"s}, {2, "Febuary"s}, {3, "March"s}, {4, "April"s}, {5, "May"s},
	{6, "June"s}, {7, "July"s}, {8, "August"s}, {9, "September"s}, {10, "October"s},
	{11, "November"s}, {12, "December"s} };


Date::Date(int number, Months month, int year) :
	number_(number),
	month_(month),
	year_(year),
	dayOfWeek_(DaysOfWeek::UNDEFINED) // For now... later call getDayOfWeek (TODO)
{
}


ostream& operator<<(ostream& o, const Date& date) {
	o << DAYS_OF_WEEK_IN_STRING.at(static_cast<int>(date.dayOfWeek_)) << ", ";
	o << MONTHS_IN_STRING.at(static_cast<int>(date.month_)) << ' ';
	o << date.number_ << ", " << date.year_ << endl;

	return o;
}

void Date::americanDateAbreviation() const {
	cout << static_cast<int>(month_) << '/' << number_ << '/' << year_ << endl;
}