#include <iostream>
#include <iomanip>
#include "box.h"
using namespace std;

Box::Box(const int s, const char bord, const char fill)
{
	GetSize();
	SetBorder(bord);
	SetFill(fill);
	Summary();
}
void Box::Grow()
{
	if (Size < 39) Size++;
}
void Box::Shrink()
{
	if (Size > 1) Size--;
}

int Box::GetSize()
{
	return Size;
}

int Box::Perimeter()
{
	return 4 * Size;
}

int Box::Area()
{
	return Size*Size;
}

void Box::SetBorder(const char bord)
{
	if (int('!') <= int(bord) && int(bord) <= int('~')) BordChar = bord;
	else BordChar = DEFAULTBORDER;
}

void Box::SetFill(const char fill)
{
	if ('!' <= fill && fill <= '~') FillChar = fill;
	else FillChar = DEFAULTFILL;
}

void Box::Draw()
{
	cout << "Insert box drawing here." << endl;
	//size 1 and 2 have no fill, so don't even use them
	//3 and above have top and bottom rows of borders for (i=0;i<s;i++)
	//rest of rows has bord on edges and fill = size-2
}

void Box::Summary()
{
	cout << "Box size: " << GetSize() << endl;
	cout << "Perimeter: " << Perimeter() << endl;
	cout << "Area: " << Area() << endl;
	Draw();
}