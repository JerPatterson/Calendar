#pragma once

enum class DaysOfWeek {
	UNDEFINED, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY
};

enum class Months {
	UNDEFINED, JANUARY, FEBUARY, MARCH, APRIL, MAY, JUNE, JULY, AUGUST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER
};


class Date {
public:
	Date() = default;

private:
	int number_ = 4;
	Months month_ = Months::MARCH;
	int year_ = 2022;
	DaysOfWeek dayOfWeek_ = DaysOfWeek::FRIDAY;
};