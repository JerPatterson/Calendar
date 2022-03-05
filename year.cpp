#include <iostream>
#include "calendar.h"

using namespace std;


Year::Year(int number) :
	number_(number)
{
	setLeapYearStatus();
	setNbOfDays();
}

void Year::setLeapYearStatus() {
	// A year is leap if it's divisable by 400
	if (number_ % 400 == 0)
		isLeap_ = true;

	// A year is leap if it's not divisable by 100 but divisable by 4
	else if (number_ % 100 != 0 && number_ % 4 == 0)
		isLeap_ = true;

	else
		isLeap_ = false;
}

void Year::setNbOfDays() {
	if (isLeap_) nbOfDays_ = 366;
	else nbOfDays_ = 365;
}

ostream& operator<<(ostream& o, const Year& year) {
	return o << year.number_;
}

bool Year::operator<(const Year& other) const {
	return number_ < other.number_;
}

bool Year::operator>(const Year& other) const {
	return number_ > other.number_;
}

int operator+(int nbOfDays, const Year& year) {
	return nbOfDays + year.nbOfDays_;
}

int Year::operator-(const Year& other) const {
	int smallestYear = min<int>(number_, other.number_);

	int nbOfDaysBetween = 0;
	for (int i = 1; i < abs(number_ - other.number_); ++i) {
		nbOfDaysBetween = nbOfDaysBetween + Year(smallestYear + i);
	}

	if (number_ < other.number_) return -1 * nbOfDaysBetween;
	else  return nbOfDaysBetween;
}

int operator-(int nbOfDays, const Year& year) {
	return nbOfDays - year.nbOfDays_;
}

Year& Year::operator+(int nbOfDays) const {
	int i = 0;
	while (nbOfDays > 0) {
		nbOfDays = nbOfDays - Year(number_ + ++i).getNbOfDays();
	}

	Year year = Year(number_ + i);
	return year;
}