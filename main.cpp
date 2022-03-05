#include <iostream>
#include "calendar.h"

using namespace std;


int main() {
	Year year = 2021;
	Year yearComing = 2025;
	cout << "2025 - 2021 = " << yearComing - year << endl;

	Year result = yearComing + 366;
	cout << "2025 + 366 = " << result << endl;
	result = year + 300;
	cout << "2021 + 300 = " << result << endl;

	Month month = Month(Months::DECEMBER, 2002);
	Month otherMonth = Month(Months::FEBUARY, 2004);
	cout << "Dec. 2002 - Feb. 2003 = " << month - otherMonth << endl;
	cout << "Feb. 2003 - Dec. 2002 = " << otherMonth - month << endl;

	Month march = Month(Months::MARCH, 2007);
	Month newMonth = march + 300;
	cout << "Mar. 2007 + 300 = " << newMonth << endl;

	Date today;
	cout << today;
	today.americanDateAbreviation();
	today.dateAbreviation();

	Date oldDate = Date(27, Months::DECEMBER, year);
	cout << today - oldDate << "   " << oldDate - today;

	return 0;
}