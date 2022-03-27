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

bool Year::operator!=(const Year& other) const {
	return number_ != other.number_;
}

bool Year::operator==(const Year& other) const {
	return number_ == other.number_;
}


int operator+(int nbOfDays, const Year& year) {
	return nbOfDays + year.nbOfDays_;
}

int operator+=(int nbOfDays, const Year& year) {
	return nbOfDays + year.nbOfDays_;
}

int operator-(int nbOfDays, const Year& year) {
	return nbOfDays - year.nbOfDays_;
}

int operator-=(int nbOfDays, const Year& year) {
	return nbOfDays - year.nbOfDays_;
}


int Year::getSmallestYearNb(const Year& other) const {
	if (*this == other)
		throw invalid_argument("Both years are the same.");

	return number_ < other.number_ ? number_ : other.number_;
}

int Year::getDaysBetween(const Year& other) const {
	int nbOfDaysBetween = 0;

	if (*this != other) {
		int smallestYear = this->getSmallestYearNb(other.number_);

		for (int i = 1; i < abs(number_ - other.number_); ++i) {
			nbOfDaysBetween = nbOfDaysBetween + Year(smallestYear + i);
		}
	}

	return nbOfDaysBetween;
}

int Year::operator-(const Year& other) const {
	int nbOfDaysBetween = this->getDaysBetween(other);

	return number_ < other.number_ ? -1 * nbOfDaysBetween : nbOfDaysBetween;
}

Year& Year::operator+(int nbOfDays) const {
	nbOfDays = nbOfDays - *this;

	if (nbOfDays < 0) {
		Year newYear = *this;
		return newYear;
	}

	else {
		int i = 0;
		while (nbOfDays > Year(number_ + ++i).nbOfDays_) {
			nbOfDays = nbOfDays - Year(number_ + i);
		}

		Year newYear = Year(number_ + i);
		return newYear;
	}
}