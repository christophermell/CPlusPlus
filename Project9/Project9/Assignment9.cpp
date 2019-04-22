#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
using namespace std;

//Prototypes
int NumofNum();
int GetRange();
int NumofTickets();
void PrintTicket(const int, const int, const int);
void CheckArray(int a[], const int, const int);
void PrintInfo(const int, const int, const int);
int Odds(const int, const int);

int main(void)
{
	unsigned seed = time(0);
	srand(seed);
	int number = NumofNum();
	int range = GetRange();
	int tickets = NumofTickets();
	PrintInfo(range, tickets, number);
	PrintTicket(range, tickets, number);
	cout << "END!" << endl;
	return 0;
}

/*********************************************************
*            Prompts user to enter the number            *
*            of numbers you wish to pick from            *
**********************************************************/
int NumofNum()
{
	int num;
	cout << "Enter number of lottery numbers needed (3-7): ";
	cin >> num;
	while (num < 3 || num > 7)
	{
		cout << "Invalid number of values. Try again (3-7): ";
		cin >> num;
	}
	return num;
}

/*********************************************************
*            Prompts user to enter the highest           *
*             possible number in the lottery             *
**********************************************************/
int GetRange()
{
	int r;
	cout << "Enter greatest number of possible numbers (45-70): ";
	cin >> r;
	while (r < 45 || r > 70)
	{
		cout << "Invalid greatest number. Try again (45-70): ";
		cin >> r;
	}
	return r;
}

/*********************************************************
**
**********************************************************/
int NumofTickets()
{
	int t;
	cout << "Enter number of tickets (1-100): ";
	cin >> t;
	while (t < 1 || t > 100)
	{
		cout << "Invalid number. Try again (1-100): ";
		cin >> t;
	}
	return t;
}

/*********************************************************
*                 Prints out all tickets                 *
*                     Calls GetRand()                    *
**********************************************************/
void PrintTicket(const int r, const int t, const int n)
{
	int * array;
	array = new int[n];
	cout << "HERE ARE YOUR LOTTERY SELECTIONS" << endl;
	for (int i = 0; i < t; i++)
	{
		for (int j = 0; j < n; j++)
			array[j] = rand() % r + 1;
		CheckArray(array, r, n);
		for (int j = 0; j < n; j++)
			cout << setw(4) << array[j];
		cout << endl;
	}
}

/*********************************************************
*  Checks for any duplicates using modified Bubble Sort  *
*              makes any necessary switches              *
**********************************************************/
void CheckArray(int a[], const int r, const int n)
{
	bool dupl = true;
	while (dupl)
	{
		dupl = false;
		for (int i = 0; i < n - 1; i++)
		{
			for (int k = i + 1; k < n; k++)
			{
				if (a[i] == a[k])
				{
					a[k] = rand() % r + 1;
					dupl = true;
				}
			}
		}
	}
}

/*********************************************************
*    Prints out the inputted info and odds of winning    *
**********************************************************/
void PrintInfo(const int r, const int t, const int n)
{
	cout << "You will select " << n << " numbers." << endl;
	cout << "The numbers will range from 1 to " << r << "." << endl;
	cout << "The odds of winning are 1 in " << Odds(r, n) << endl;
}

/*********************************************************
*             Calculates the odds of winning             *
*                      Calls itself                      *
**********************************************************/
int Odds(const int r, const int n)
{
	float temp = r / n;
	if (n == 1) return temp;
	return temp*Odds(r-1, n-1);
}