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

	friend std::ostream& operator<<(std::ostream&, const Year&);
	friend int operator+(int, const Year&);

	int operator-(const Year&) const;

	bool getLeapStatus() const { return isLeap_; };
	int getNbOfDays() const { return nbOfDays_; };

private:
	int number_ = 2022;
	bool isLeap_ = false;
	int nbOfDays_ = 365;

	void setNbOfDays();
	void setLeapYearStatus();
};

class Date {
public:
	Date() = default;
	Date(int, Months, Year);

	friend std::ostream& operator<<(std::ostream&, const Date&);
	void dateAbreviation() const;
	void americanDateAbreviation() const;

private:
	int number_ = 4;
	Year year_ = 2022;
	Months month_ = Months::MARCH;
	DaysOfWeek dayOfWeek_ = DaysOfWeek::FRIDAY;
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
