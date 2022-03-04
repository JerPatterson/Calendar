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


class Year {
public:
	Year() = default;
	Year(int);

	friend class Month;

	friend std::ostream& operator<<(std::ostream&, const Year&);

private:
	int number_ = 2022;
	bool isLeap_ = false;
	int nbOfDays_ = 365;

	void setNbOfDays();
	void setLeapYearStatus();
};


class Month {
public:
	Month() = default;
	Month(const Months&, int);
	Month(const std::string&, int);

private:
	Months name_ = Months::UNDEFINED;
	Year year_;
	int nbOfDays_ = 0;

	void setNbOfDays();
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
	Year year_;
	Months month_ = Months::MARCH;
	DaysOfWeek dayOfWeek_ = DaysOfWeek::FRIDAY;
};