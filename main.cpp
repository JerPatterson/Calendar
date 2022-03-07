#include <iostream>
#include <functional>
#include "calendar.h"

using namespace std;


// Curryfication | To make a date :
auto makeDate(int number) {
	return [=](int month) {
		return [=](int year) {
			Date tempDate = Date(number, month, year);
			return tempDate;
		};
	};
}

// Curryfication | To make a month :
auto makeMonth(int month) {
	return [=](int year) {
		Month tempDate = Month(month, year);
		return tempDate;
	};
}


int main() {
	int number;
	Year year, otherYear;
	Month month, otherMonth;
	Date today, date, otherDate;

	year = 2021; otherYear = 2025;
	cout << otherYear << " - " << year << " = " << otherYear - year << endl;
	cout << otherYear << " - " << year << " = " << otherYear - year << endl;
	cout << "-----------------------------------------------------------" << endl;

	number = 366; year = otherYear + number;
	cout << otherYear << " + " << number << " = " << year << endl;
	number = 300; year = year + 300;
	cout << year << " + " << number << " = " << year << endl;
	cout << "-----------------------------------------------------------" << endl;

	month = makeMonth(12)(2002);
	otherMonth = makeMonth(2)(2003);
	cout << month << " - " << otherMonth << " = " << month - otherMonth << endl;
	cout << otherMonth << " - " << month << " = " << otherMonth - month << endl;
	cout << "-----------------------------------------------------------" << endl;

	month = makeMonth(3)(2007);
	otherMonth = month + number;
	cout << month << " + " << number << " = " << otherMonth << endl;
	number = 4;  otherMonth = month + number;
	cout << month << " + " << number << " = " << otherMonth << endl;
	number = 365;  otherMonth = month + number;
	cout << month << " + " << number << " = " << otherMonth << endl;
	cout << "-----------------------------------------------------------" << endl;

	cout << today << endl;
	today.americanDateAbreviation();
	today.dateAbreviation();
	cout << "-----------------------------------------------------------" << endl;

	otherDate = makeDate(27)(12)(2021);
	cout << today << " - " << otherDate << " = " << today - otherDate << endl;
	cout << otherDate << " - " << today << " = " << otherDate - today << endl;
	cout << "-----------------------------------------------------------" << endl;

	number = 35; date = otherDate + number;
	cout << otherDate << " + " << number << " = " << date << endl;
	number = 365; otherDate = date + number;
	cout << date << " + " << number << " = " << otherDate << endl;

	return 0;
}