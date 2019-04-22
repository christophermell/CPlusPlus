#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

void PrintMonth(const int month, const int startday, const bool leap); //Prototype

const string MONTHS[13] = { "","January", "February", "March", "April", "May","June", "July",
"August","Septenber","October", "November","December" }; //String you told us to copy

int main(void)
{
	// ******************************************************************
	// * Print just a bunch of Random months - Assignment #3 *
	// ******************************************************************
	PrintMonth(1, 0, false); // Print January 1st, on a Sunday
	PrintMonth(2, 1, true); // Print February 1st leap year, on Monday
	PrintMonth(1, 2, false); // Print January 1st, on a Tuesday
	PrintMonth(2, 3, false); // Print February 1st not leap, on Wednesday
	PrintMonth(1, 4, false); // Print January 1st, on a Thursday
	PrintMonth(2, 5, false); // Print February 1st, on a Friday
	PrintMonth(1, 6, false); // Print January 1st, on a Saturday
	PrintMonth(6, 1, false); // Print June 1st, on Monday
	PrintMonth(12, 4, false); // Print December 1st, on a Thursday
	return 0;
}
void PrintMonth(const int month, const int startday, const bool leap)
{
	//aray to give the number of days in each month
	int days_in_month[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	//array to give the number of letters in name of each month for alignment purposes
	int chars_in_month[13] = { 0,7,8,5,5,3,4,4,6,9,7,8,8 };
	//Print out the month
	cout << setw(14 + (chars_in_month[month]/2)) << MONTHS[month] << endl;
	//Print out the days of the week
	cout << " Sun Mon Tue Wed Thu Fri Sat" << endl;
	//Take leap years into account
	if (leap == true)
		days_in_month[2] = 29;
	else
		days_in_month[2] = 28;
	//set start date of month under correct day of the week
	for (int start = 0; start < startday; start++)
	{
		cout << "    ";
	}
	//Print out all the dates in the month
	for (int date = 1; date <= days_in_month[month]; date++)
	{
		cout << setw(3) << date << " ";
		//break after every saturday
		if ((date + startday) % 7 == 0)
			cout << endl;
	}
	cout << endl; //Put the month name on the next line
}