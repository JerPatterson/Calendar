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

	friend std::ostream& operator<<(std::ostream&, const Date&);
	void dateAbreviation() const;
	void americanDateAbreviation() const;

private:
	int number_ = 4;
	Months month_ = Months::MARCH;
	int year_ = 2022;
	DaysOfWeek dayOfWeek_ = DaysOfWeek::FRIDAY;
};


class Month {
public:
	Month() = default;
	Month(const Months&, int);
	Month(const string&, int);

private:
	Months name_ = Months::UNDEFINED;
	int year_;
	int nbOfDays_ = 0;

	void setNbOfDays();
};


class Year {
public:
	Year() = default;
	Year(int);

private:
	int number_ = -999999999;
	bool isLeap_ = false;
	int nbOfDays_ = 0;

	void setNbOfDays();
	void setLeapYearStatus();
};