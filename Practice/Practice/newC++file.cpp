#include <iostream>
#include <ctime>
#include<cstdlib>
using namespace std;

int main(void)
{
	int seed = time(0);
	for (int counter = 0; counter < 100; counter++)
		cout << rand()%56+1 << endl;
	return 0;
}

//random number from 1 to 56 
//rand()%56+1