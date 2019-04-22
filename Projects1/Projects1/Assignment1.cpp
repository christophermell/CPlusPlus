#include <iostream>
using namespace std;
int main(void)
{
	float first, second, third, sum, average;

	cout << "This program calculates statistical information from three data points." << endl;
	//Enter the first number
	cout << "Enter the first number.";
	cin >> first;
	//enter the second number
	cout << "Enter the second number.";
	cin >> second;
	//enter the third number
	cout << "Enter the third number.";
	cin >> third;
	//display the largest number
	if ((first >= second) & (first >= third))
	{
		cout << "The largest number is " << first << endl;
	}
	else
	{
		if ((second >= first)&(second >= third))
		{
			cout << "The largest number is " << second << endl;
		}
		else
			cout << "The largest number is " << third << endl;
	}
	//display the smallest number
	if ((first<=second)&(first<=third))
	{
		cout << "The smallest number is " << first << endl;
	}
	else
	{
		if ((second <= first)&(second <= third))
		{
			cout << "The smallest number is " << second << endl;
		}
		else
			cout << "The smallest number is " << third << endl;
	}
	//Calculate the sum
	sum = first + second + third;
	cout << "The sum of the data points is " << sum << endl;
	//Calculate the average
	average = sum / 3;
	cout << "the average of the data points is " << average << endl;
	return 0;
}