#include <iostream>
using namespace std;
const int ARRAYSIZE = 100;
void HammingSort(int a[], const int s);
void Swap(int x, const int y);

int main(void)
{
	int array[ARRAYSIZE] = {0};
	int SIZE = 0;
	for (int i = 1; i <= 100; i++) //Enter in numbers and keep track of the size of the array
	{
		cout << "Enter number "<<i<<" into the array: ";
		cin >> array[i];
		SIZE++;
		if (array[i] < 0) //break if negative number is entered
		{
			SIZE--;
			break;
		}
	}
	cout << "The size of the array is: " << SIZE << endl;
	
	//HammingSort
	HammingSort(&array[SIZE], SIZE);
	
	//average
	int sum = 0;
	float average;
	for (int i = 0; i <= SIZE-1; i++)
	{
		sum = sum + array[i];
		average = sum/SIZE;
	}
	
	cout << "The sum is: " << sum << endl;
	cout << "The average is: " << average << endl;
	return 0;
}

void HammingSort(int a[], const int y)
{
	int temp;
	bool swapped = true;
	while (swapped)
	{
		swapped = false;
		for (int i = 0; i < y - 1; i++)                   //loop
		{
			if (a[i] > a[i + 1])                          //if a[i]>a[i+1]
			{                                             //begin
				int temp = a[i];                          //swap them
				a[i] = a[i + 1];
				a[i + 1] = temp;
				swapped = true;
				for (int k = y; k < 0; k--)               //loop
				{
					if (a[k - 1] > a[k])                  //if a[k-1]>a[k]
					{                                     //begin
						int temp1 = a[k - 1];             //swap them
						a[k - 1] = a[k];
						a[k] = temp1;
						swapped = true;
					}
				}
			}
		}
	}
	for (int i =100-y; i <= 100; i++)
		cout << a[i] << ", ";
	cout << endl;
}