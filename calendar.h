#pragma once
#include <map>
#include <string>


static const int NUMBER_OF_DAYS_IN_A_WEEK = 7;
static const int NUMBER_OF_DAYS_IN_A_YEAR = 365;


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

	friend std::ostream& operator<<(std::ostream& o, const Date& date);
	void dateAbreviation() const;
	void americanDateAbreviation() const;

private:
	int number_ = 4;
	Months month_ = Months::MARCH;
	int year_ = 2022;
	DaysOfWeek dayOfWeek_ = DaysOfWeek::FRIDAY;
};