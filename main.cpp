#include <iostream>
#include "calendar.h"

using namespace std;


int main() {
	Date today;

	cout << today;
	today.americanDateAbreviation();
	today.dateAbreviation();

	return 0;
}