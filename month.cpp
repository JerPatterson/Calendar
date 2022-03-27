#include <iostream>
#include <map>
#include "calendar.h"

using namespace std;


static const map<string, unsigned> MONTHS_IN_NUM =
{ {"January"s, 1}, {"Febuary"s, 2}, {"March"s, 3}, {"April"s, 4}, {"May"s, 5},
	{"June"s, 6}, {"July"s, 7}, {"August"s, 8}, {"September"s, 9}, {"October"s, 10},
	{"November"s, 11}, {"December"s, 12} };

static const map<unsigned, string> MONTHS_IN_STRING =
{ {1, "January"s}, {2, "Febuary"s}, {3, "March"s}, {4, "April"s}, {5, "May"s},
	{6, "June"s}, {7, "July"s}, {8, "August"s}, {9, "September"s}, {10, "October"s},
	{11, "November"s}, {12, "December"s} };


Month::Month(const Months& month, int year) :
	name_(month),
	year_(Year(year))
{
	setNbOfDays();
}

Month::Month(int monthNumber, int year) :
	name_(Months(monthNumber)),
	year_(year)
{
	setNbOfDays();
}

Month::Month(const Months& month, const Year& year) :
	name_(month),
	year_(year)
{
	setNbOfDays();
}

Month::Month(const string& name, int year) :
	name_(static_cast<Months>(MONTHS_IN_NUM.at(name))),
	year_(Year(year))
{
	setNbOfDays();
}


void Month::setNbOfDays() {
	if (name_ == Months::FEBUARY) {
		if (year_.getLeapStatus()) nbOfDays_ = 29;
		else nbOfDays_ = 28;
	}

	else {
		map<int, int> nbOfDays;
		nbOfDays[1] = nbOfDays[3] = nbOfDays[5] = nbOfDays[7] = nbOfDays[8] = nbOfDays[10] = nbOfDays[12] = 31;
		nbOfDays[4] = nbOfDays[6] = nbOfDays[9] = nbOfDays[11] = 30;

		nbOfDays_ = nbOfDays[static_cast<int>(name_)];
	}
}

int Month::getNumber() const {
	return static_cast<int>(name_);
}

ostream& operator<<(ostream& o, const Month& month) {
	return o << MONTHS_IN_STRING.at(static_cast<int>(month.name_));
}

bool Month::operator<(const Month& month) const {
	if (year_ < month.year_) return true;
	else if (year_ > month.year_) return false;
	else if (static_cast<int>(name_) < static_cast<int>(month.name_)) return true;
	else return false;
}

bool Month::operator>(const Month& month) const {
	if (year_ > month.year_) return true;
	else if (year_ < month.year_) return false;
	else if (static_cast<int>(name_) > static_cast<int>(month.name_)) return true;
	else return false;
}

int operator+(int nbOfDays, const Month& month) {
	return nbOfDays + month.nbOfDays_;
}

int Month::numberOfDaysYearBetween(const Month& other) const {
	return abs(year_ - other.year_);
}

bool Month::isInTheSameYear(const Month& other) const {
	return year_.getNumber() == other.year_.getNumber();
}

int Month::operator-(const Month& other) const {
	int nbOfDaysBetween = this->numberOfDaysYearBetween(other);

	// Sort the two month for the right calculation.
	const Month *firstMonth, *secondMonth;
	if (*this < other)
		firstMonth = this, secondMonth = &other;
	else if (*this > other)
		firstMonth = &other, secondMonth = this;
	else return nbOfDaysBetween; // Mean the two are equal

	// If months are in the same year (cases):
	if (isInTheSameYear(other)) {
		for (int i = firstMonth->getNumber() + 1; i < firstMonth->getNumber() + secondMonth->getNumber(); ++i)
			nbOfDaysBetween = nbOfDaysBetween + Month(Months(i), year_.getNumber());
	}

	// If months are in different years :
	else {
		for (int i = firstMonth->getNumber() + 1; i <= NUMBER_OF_MONTHS_IN_A_YEAR; ++i)
			nbOfDaysBetween = nbOfDaysBetween + Month(Months(i), firstMonth->year_.getNumber());
		for (int i = 1; i < secondMonth->getNumber(); ++i)
			nbOfDaysBetween = nbOfDaysBetween + Month(Months(i), secondMonth->year_.getNumber());

		nbOfDaysBetween = secondMonth->year_ - firstMonth->year_;
	}

	if (*this < other) return -1 * nbOfDaysBetween;
	else if (*this > other) return nbOfDaysBetween;
}

int operator-(int nbOfDays, const Month& month) {
	return nbOfDays - month.nbOfDays_;
}

Month& Month::operator+(int nbOfDays) const {
	// Substract number of days in the current month
	nbOfDays = nbOfDays - this->nbOfDays_;

	if (nbOfDays < 0) {
		Month newMonth = *this;
		return newMonth;
	}

	else {
		// Substract number of days left in the current year
		nbOfDays = nbOfDays - Month(Months(NUMBER_OF_MONTHS_IN_A_YEAR), this->getYear());

		// Find the new month and year
		int i = static_cast<int>(name_);
		Year newYear = this->getYear();
		Month newMonth = Month(Months(this->getNumber()), newYear);
		while (nbOfDays > newMonth.nbOfDays_) {
			if (i == NUMBER_OF_MONTHS_IN_A_YEAR) {
				newYear = Year(newYear.getNumber() + 1);
				i = 0;
			}

			newMonth = Month(Months(++i), newYear);
			nbOfDays = nbOfDays - newMonth;
		}

		return newMonth;
	}
}