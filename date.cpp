#include <iostream>
#include <map>
#include <string>
#include "calendar.h"

using namespace std;

static const map<int, string> DAYS_OF_WEEK_IN_STRING =
{ {1, "Monday"s}, {2, "Tuesday"s}, {3, "Wednesday"s}, {4, "Thursday"s},
	{5, "Friday"s}, {6, "Saturday"s}, {7, "Sunday"s} };


Date::Date(int number, Months month, Year year) :
	number_(number),
	year_(year),
	month_(Month(month, year)),
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

bool Date::operator<(const Date& date) const {
	if (year_ < date.year_) return true;
	else if (year_ > date.year_) return false;
	else if (month_ < date.month_) return true;
	else if (month_ > date.month_) return false;
	else if (number_ < date.number_) return true;
	else return false;
}
bool Date::operator>(const Date& date) const {
	if (month_ > date.month_) return true;
	else if (month_ < date.month_) return false;
	else if (number_ > date.number_) return true;
	else return false;
}

int operator+(int nbOfDays, const Date& date) {
	return nbOfDays + date.number_;
}

int operator-(const Month& month, const Date& date) {
	return -1 * (date.number_ - month); // Use of already define operator- : int - Month
}

int Date::operator-(const Date& other) const {
	// Sort the two date for the right calculation.
	const Date *firstDate, *secondDate;
	if (*this < other)
		firstDate = this, secondDate = &other;
	else if (*this > other)
		firstDate = &other, secondDate = this;
	else return 0; // Mean the two are equal

	int nbOfDaysBetween = abs(firstDate->month_ - secondDate->month_) + *secondDate + (firstDate->month_ - *firstDate);

	if (*this < other) return -1 * nbOfDaysBetween;
	else if (*this > other) return nbOfDaysBetween;
}

int operator-(int nbOfDays, const Date& date) {
	return nbOfDays - date.number_;
}

Date& Date::operator+(int) const {
	Date date = Date();
	return date;
}