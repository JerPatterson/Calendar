#include <map>
#include "calendar.h"

using namespace std;


static const map<string, unsigned> MONTHS_IN_NUM =
{ {"January"s, 1}, {"Febuary"s, 2}, {"March"s, 3}, {"April"s, 4}, {"May"s, 5},
	{"June"s, 6}, {"July"s, 7}, {"August"s, 8}, {"September"s, 9}, {"October"s, 10},
	{"November"s, 11}, {"December"s, 12} };


Month::Month(const Months& month, int year) {
	name_ = month;
	year_ = Year(year);
	setNbOfDays();
}

Month::Month(const string& name, int year) {
	name_ = static_cast<Months>(MONTHS_IN_NUM.at(name));
	year_ = Year(year);
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