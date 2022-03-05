#include <iostream>
#include "calendar.h"

using namespace std;


int main() {
	Year year = 2021;
	Year yearComing = 2025;
	cout << "2025 - 2021 = " << yearComing - year << endl;

	Year newYear = yearComing + 366;
	cout << "2025 + 366 = " << newYear << endl;

	Month month = Month(Months::DECEMBER, 2002);
	Month otherMonth = Month(Months::FEBUARY, 2003);
	cout << "Dec. 2002 - Feb. 2003 = " << month - otherMonth << endl;

	Date today;
	cout << today;
	today.americanDateAbreviation();
	today.dateAbreviation();

	return 0;
}