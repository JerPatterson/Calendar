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