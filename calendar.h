#pragma once
#include <map>


static const int NUMBER_OF_DAYS_IN_A_WEEK = 7;
static const int NUMBER_OF_DAYS_IN_A_YEAR = 365;

static const map<int, string> DAY_OF_WEEK_IN_STRING =
{ {1, "Monday"s}, {2, "Tuesday"s}, {3, "Wednesday"s}, {4, "Thursday"s},
	{5, "Friday"s}, {6, "Saturday"s}, {7, "Sunday"s} };

static const map<int, string> MONTHS_IN_STRING =
{ {1, "January"s}, {2, "Febuary"s}, {3, "March"s}, {4, "April"s}, {5, "May"s},
	{6, "June"s}, {7, "July"s}, {8, "August"s}, {9, "September"s}, {10, "October"s},
	{11, "November"s}, {12, "December"} };


enum class DaysOfWeek {
	UNDEFINED, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY
};

enum class Months {
	UNDEFINED, JANUARY, FEBUARY, MARCH, APRIL, MAY, JUNE, JULY, AUGUST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER
};


class Date {
public:
	Date() = default;
	Date(int, Months, int);

private:
	int number_ = 4;
	Months month_ = Months::MARCH;
	int year_ = 2022;
	DaysOfWeek dayOfWeek_ = DaysOfWeek::FRIDAY;
};