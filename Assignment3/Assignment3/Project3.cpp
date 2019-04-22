#include <iostream>
using namespace std;
int i = 100; //Global variable
int main(void)
{
	int i = 200;
	{
		int i = 1000;
		cout << ::i << endl;
	}
	return 0;
}