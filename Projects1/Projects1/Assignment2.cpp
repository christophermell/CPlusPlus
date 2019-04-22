#include <iostream>
#include <iomanip>
#include <bitset>
using namespace std;

void PrintOutTwoNumbers(const int x, const int y);
int main(void)
{
	PrintOutTwoNumbers(10, 25);
	return 0;
}

void PrintOuttTwoNumbers(const int x, const int y)
{
	cout << "The first number is " << x << endl;
	cout << "The second number is " << y << endl;
	return;
}