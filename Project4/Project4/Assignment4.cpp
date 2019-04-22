#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

void PrintMonth(ofstream &DataFile, const int month, const int startday, const bool leap);                          //Prototypes
bool leap(const int year);
int dayofweek(const int day, const int month, const int year);
void PrintYear(ofstream &DataFile, const int year);

const string MONTHS[13] = { "","January", "February", "March", "April", "May","June", "July",
"August","Septenber","October", "November","December" };                                        //String you told us to copy

//array to give the number of days in each month
int days_in_month[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

int main(void)
{
	int year = 1582;
	cout << "Enter a 4 digit year between 1582 and 9999: ";                              //take in the year
	cin >> year;
	while (year > 9999 || year < 1582)
	{
		cout << "Invalid year. Enter a 4 digit year between 1582 and 9999: ";
		cin >> year;
	}
	bool leap(const int year);
	cout << "Leap year is: " << leap(year) << endl;
	ofstream DataFile("cal.dat");                                                        //Open file
	DataFile << year << endl;                                                            //Copy year to file
	PrintYear(DataFile, year);
	DataFile.close();                                                                    //Close file
	cout << "The calendar of the year " << year << " was saved to a file." << endl;
	cout << "Program Done." << endl;
	return 0;
}

bool leap(const int year)                                                                //returns true if year is a leap year
{                                                                                        //false otherwise
	if (year % 400 == 0)
		return true;
	else if (year % 100 == 0)
		return false;
	else if (year % 4 == 0)
		return true;
	else
		return false;
}

int dayofweek(const int day, const int month, const int year)                            //returns day of week for date passed in as parameter
{
	int a, y, m, d;
	a = (14 - month) / 12;
	y = year - a;
	m = month + 12 * a - 2;
	d = (day + y + y / 4 - y / 100 + y / 400 + (31 * m / 12)) % 7;
	return d;
}

void PrintYear(ofstream &DataFile, const int year)                                      //calls PrintMonth, leap, and dayofweek.
{
	for (int month = 1; month < 13; month++)
	{
		int day = 1;

		PrintMonth(DataFile, month, dayofweek(day, month, year), leap(year));
	}
}

void PrintMonth(ofstream &DataFile, const int month, const int startday, const bool leap)
{
	//array to give the number of days in each month
	int days_in_month[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	//array to give the number of letters in name of each month for alignment purposes
	int chars_in_month[13] = { 0,7,8,5,5,3,4,4,6,9,7,8,8 };

	//Print out the month
	DataFile << setw(14 + (chars_in_month[month] / 2)) << MONTHS[month] << endl;
	//Print out the days of the week
	DataFile << " Sun Mon Tue Wed Thu Fri Sat" << endl;

	//Take leap years into account
	if (leap == true)
		days_in_month[2] = 29;
	else
		days_in_month[2] = 28;

	//set start date of month under correct day of the week
	for (int start = 0; start < startday; start++)
	{
		DataFile << "    ";
	}

	//Print out all the dates in the month
	for (int date = 1; date <= days_in_month[month]; date++)
	{
		DataFile << setw(3) << date << " ";

		//break after every saturday
		if ((date + startday) % 7 == 0)
			DataFile << endl;
	}
	DataFile << endl; //Put the month name on the next line
	cout << "Month " << MONTHS[month] << " successfully saved in file." << endl;
}