#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

const int MAXSIZE = 80;
const int MAXLINE = 80;

struct Roster {
	string LName;
	string FName;
	char Cheesecake;
};

void GetFilename(ifstream &, char *);
int CountRecords(ifstream &);
void ReadInData(ifstream &, const int, char *, struct Roster *);
void Sort(const int, struct Roster *);
int IsPie(const int, struct Roster *);
int IsCake(const int, struct Roster *);
void PrintReport(const int, struct Roster *);

int main(void)
{
	int count = 0;
	ifstream inputfile;
	char filename[MAXSIZE];
	GetFilename(inputfile, filename);                      //Get filename & validate
	count = CountRecords(inputfile);                       //Count # of records
	Roster * MyRoster;
	MyRoster = new Roster[count];
	ReadInData(inputfile, count, filename, MyRoster);      //Read data into array
	Sort(count, MyRoster);                                 //sort data
	IsPie(count, MyRoster);                                //how many pie
	IsCake(count, MyRoster);                               //how many cake
	PrintReport(count, MyRoster);                          //print report
	inputfile.close();
	cout << "End of program!" << endl;
	return 0;
}

/*****************************************************
*  prompts user to enter filename in standard input  *
*             verifies and opens the file            *
*****************************************************/
void GetFilename(ifstream & ipf, char * fn)
{
	cout << "Enter a valid input filename: ";
	cin >> fn;
	cout << "Filename entered." << endl;
	ipf.open(fn);
	while (!ipf.is_open())
	{
		cout << "Invalid filename. Enter a valid input filename: ";
		cin >> fn;
		ipf.open(fn);
	}
}

/**********************************
*          count records          *
* stolen from thursday's lecture  *
**********************************/
int CountRecords(ifstream & ipf)
{
	char line[MAXLINE];
	int count = 0;
	ipf.getline(line, MAXLINE);
	while (!ipf.eof())
	{
		count++;
		ipf.getline(line,MAXLINE);
	}
	cout << "There are " << count << " Records" << endl;
	ipf.close();
	return count;
}

/****************************
*reads data into MyRoster*
*****************************/
void ReadInData(ifstream & ipf, const int c, char * fn, struct Roster * mr)
{
	ipf.open(fn);
	for (int i = 0; i < c; i++)
	{
		ipf >> mr[i].LName;
		ipf >> mr[i].FName;
		ipf >> mr[i].Cheesecake;
	}
	ipf.close();
}

/****************************
*sorts data in MyRoster*
*****************************/
void Sort(const int c, struct Roster * mr)
{
	bool swapped = true;
	while (swapped)
	{
		swapped = false;
		for (int i = 0; i < c - 1; i++)
		{
			if (mr[i].LName > mr[i + 1].LName)
			{
				Roster temp = mr[i];
				mr[i] = mr[i + 1];
				mr[i + 1] = temp;
				swapped = true;
			}
		}
	}
}

/********************************
*counts how many people said pie*
*********************************/
int IsPie(const int c, struct Roster * mr)
{
	int pie = 0;
	for (int i = 0; i < c - 1; i++)
		if (mr[i].Cheesecake == 'P') pie++;
	return pie;
}

/*********************************
*counts how many people said cake*
**********************************/
int IsCake(const int c, struct Roster * mr)
{
	int cake = 0;
	for (int i = 0; i < c - 1; i++)
		if (mr[i].Cheesecake == 'C') cake++;
	return cake;
}

void PrintReport(const int c, struct Roster * mr)
{
	cout << setw(34) << "THE CHEESECAKE REPORT" << endl;
	cout << setw(14) << "Last Name" << setw(14) <<
		"First Name" << setw(14) << "Cake or Pie" << endl;
	cout << setw(14) << "---------" << setw(14) <<
		"----------" << setw(14) << "-----------" << endl;
	for (int i = 0; i < c; i++)
		cout << setw(13) << mr[i].LName << setw(14) <<
			mr[i].FName << setw(10) << mr[i].Cheesecake << endl;
	cout << endl;
	cout << "Number of records is: " << c << endl;
	cout << "Number who said Pie: " << IsPie(c, mr) << endl;
	cout << "Number who said Cake: " << IsCake(c, mr) << endl;
}