#include <iostream>
#include <string>
#include <iomanip>
#include "measurements.h"
using namespace std;

Measurements::Measurements(const int h, const int w)
{
	SetHeight(h);
	SetWeight(w);
}
void Measurements::Grow()
{
	Height++;
	Weight++;
}
void Measurements::Shrink()
{
	if (Height > 1) Height--;
	if (Weight > 1) Weight--;
}
int Measurements::GetHeight()
{
	return Height;
}
int Measurements::GetWeight()
{
	return Weight;
}
void Measurements::SetHeight(const int h)
{
	if (h > 0) Height = h;
	else Height = DEFAULTHEIGHT;
}
void Measurements::SetWeight(const int w)
{
	if (w > 0) Weight = w;
	else Weight = DEFAULTWEIGHT;
}
void Measurements::PrintHeight()
{
	cout << "You are " << Height / 12 << " Ft " << Height % 12 << " in." << endl;
}
void Measurements::PrintWeight()
{
	cout << "You are " << Weight << " pounds." << endl;
}
void Measurements::PrintStats()
{
	PrintHeight();
	PrintWeight();
}