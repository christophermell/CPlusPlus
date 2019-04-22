#include <iostream>
#include <iomanip>
#include <bitset>
using namespace std;

void funct(const int x);                               //Prototype

int main(void)
{
	int dcml = 0, first, secnd;
	while (dcml >= 0 && dcml < 256)
	{
		cout << "Enter in your first decimal number: ";
		cin >> first;
		while (first < 0 || first>255)
		{
			cout << "Error. Enter a positive integer: ";
			cin >> first;
		}
		cout << "Enter in your second decimal number: ";
		cin >> secnd;
		while (secnd < first || secnd>255)
		{
			cout << "Error. Enter a positive integer: ";
			cin >> secnd;
		}
		for (int dcml = first; dcml <= secnd; dcml++)
		{
			funct(dcml);                               //Function call
		}
		char ans = ' ';
		cout << "Run again?(Y/N): ";
		cin >> ans;
		switch (ans)
		{
		case 'Y': case 'y':
			continue;
		case 'N': case 'n':
			break;
		default: cout << "Error." << endl;
		}
		break;
	} ;

	cout << "End program." << endl;
	return 0;
}
void funct(const int x)                               //Header
{
	cout << setw(3);
	cout << x << "    The 8-bit binary value is    " << bitset<8>(x) << endl;
}