#include <iostream>
#include "calendar.h"

using namespace std;


int main() {
	Year year = 2021;
	cout << year << endl;

	Date today;
	cout << today;
	today.americanDateAbreviation();
	today.dateAbreviation();

	return 0;
}