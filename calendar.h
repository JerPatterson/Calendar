#pragma once
#include <map>
#include <string>


static const int NUMBER_OF_DAYS_IN_A_WEEK = 7;
static const int NUMBER_OF_MONTHS_IN_A_YEAR = 12;
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
	friend int operator-(int, const Year&);

	bool operator<(const Year&) const;
	bool operator>(const Year&) const;
	int operator-(const Year&) const;
	Year& operator+(int) const;

	bool getLeapStatus() const { return isLeap_; };
	int getNbOfDays() const { return nbOfDays_; };
	int getNumber() const { return number_; };

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
	Month(const Months&, const Year&);
	Month(const std::string&, int);

	int getNumber() const;
	int getNbOfDays() const { return nbOfDays_; };
	const Year& getYear() const { return year_; }; // TEMPORARY FIX

	friend std::ostream& operator<<(std::ostream&, const Month&);
	friend int operator+(int, const Month&);
	friend int operator-(int, const Month&);

	bool operator<(const Month&) const;
	bool operator>(const Month&) const;
	int operator-(const Month&) const;
	Month& operator+(int) const;

private:
	Months name_ = Months::UNDEFINED;
	Year year_;
	int nbOfDays_ = 0;

	void setNbOfDays();
};


class Date {
public:
	Date() = default;
	Date(int, Months, Year);
	Date(int, Month);

	void dateAbreviation() const;
	void americanDateAbreviation() const;

	friend std::ostream& operator<<(std::ostream&, const Date&);
	friend int operator+(int, const Date&);
	friend int operator-(int, const Date&);
	friend int operator-(const Month&, const Date&);

	bool operator<(const Date&) const;
	bool operator>(const Date&) const;
	int operator-(const Date&) const;
	Date& operator+(int) const;

private:
	int number_ = 4;
	Year year_ = 2022;
	Month month_ = Month(Months::MARCH, 2022);
	DaysOfWeek dayOfWeek_ = DaysOfWeek::FRIDAY;

	void setDayOfWeek();
};
