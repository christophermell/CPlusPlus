#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

bool leap(const int year);

const string MONTHS[13] = { "","January", "February", "March", "April", "May","June", "July",
"August","Septenber","October", "November","December" }; //String you told us to copy

//aray to give the number of days in each month
int days_in_month[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

int main(void)
{
	int year = 1582;
	cout << "Enter a 4 digit year between 1582 and 9999: ";
	cin >> year;
	while (year > 9999 || year < 1582)
	{
		cout << "Invalid year. Enter a 4 digit year between 1582 and 9999: ";
		cin >> year;
	}
	bool leap(year);
	ofstream outputFile;
	outputFile.open("cal.dat.");
	outputFile << year << endl;
	return 0;
}

bool leap(const int year) //returns true if year is a leap year, false otherwise
{
	if (year % 400 == 0)
		return true;
	else if (year % 100 == 0)
		return false;
	else if (year % 4 == 0)
		return true;
	else
		return false;
}

