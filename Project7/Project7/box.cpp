#include <iostream>
#include <iomanip>
#include "box.h"
using namespace std;

Box::Box(const int s, const char bord, const char fill)
{
	Size = s;        //Acts like a SetSize function
	GetSize();
	SetBorder(bord);
	SetFill(fill);
	Summary();
}
/********************************************************************
*     Increases the size of the box by 1 every time it's called     *
*********************************************************************/ 
void Box::Grow()
{
	if (Size < 39) Size++;
}
/********************************************************************
*     Decreases the size of the box by 1 every time it's called     *
*********************************************************************/
void Box::Shrink()
{
	if (Size > 1) Size--;
}
/********************************************************************
*    Sets the Size variable to the const int parameter passed in    *
*********************************************************************/
int Box::GetSize()
{
		if (Size < 1)
			Size = DEFAULTMIN;
		if (Size > 39)
			Size = DEFAULTMAX;
	return Size;
}
/********************************************************************
*                 Returns the perimeter of the box                  *
*********************************************************************/
int Box::Perimeter()
{
	return 4*Size;
}
/********************************************************************
*                    Returns the area of the box                    *
*********************************************************************/
int Box::Area()
{
	return Size*Size;
}
/********************************************************************
*           Sets the border character to BordChar unless            *
*             the character passed in is out of bounds              *
*********************************************************************/
void Box::SetBorder(const char bord)
{
	if (int('!') <= int(bord) && int(bord) <= int('~')) BordChar = bord;
	else BordChar = DEFAULTBORDER;
}
/********************************************************************
*            Sets the fill character to BordChar unless             *
*             the character passed in is out of bounds              *
*********************************************************************/
void Box::SetFill(const char fill)
{
	if ('!' <= fill && fill <= '~') FillChar = fill;
	else FillChar = DEFAULTFILL;
}
/*********************************************************************
*                           Draws the box                            *
*********************************************************************/
void Box::Draw()
{
	if (Size == 1)                        //special case 1
		cout << FillChar << endl << endl;
	else if (Size == 2)                   //special case 2
	{
		cout << setw(3) << BordChar << setw(3) << BordChar << endl;
		cout << setw(3) << BordChar << setw(3) << BordChar << endl << endl;
	}
	else
	{
		for (int i = 0; i < Size; i++)    //top row
			cout << setw(3) << BordChar;
		cout << endl;
		for (int i = 0; i < Size - 2; i++)//Middle
		{
			cout << setw(3) << BordChar;
			for (int i = 0; i < Size - 2; i++)
			{
				cout << setw(3) << FillChar;
			}
			cout << setw(3) << BordChar << endl;
		}
		for (int i = 0; i < Size; i++)    //bottom row
			cout << setw(3) << BordChar;
		cout << endl << endl;
	}
}
/********************************************************************
*              Prints out information about the box                 *
*        Calls GetSize(), Perimeter(), Area(), and Draw()           *
*********************************************************************/
void Box::Summary()
{
	cout << "Box size: " << GetSize() << endl;
	cout << "Perimeter: " << Perimeter() << endl;
	cout << "Area: " << Area() << endl;
	Draw();
}