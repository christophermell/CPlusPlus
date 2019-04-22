#include <iostream>
#include <string> 
#include "box.h" 

using namespace std;
const int MAXLINESIZE = 256;
void PrintMessage();
int GetBoxSize();
void DisplayMenu();
char GetChar(const string mychar);
// *********************************************************************
// *                                                                   *
// * Function: main()                                                  *
// * Description: Tests the box class.  Asks the user for the          *
// *   characteristics of a box and draws it.  Then displays a menu    *
// *   so you can go through the different box member functions.       *
// *                                                                   *
// *                                                                   *
// * Author: Dr. David A. Gaitros                                      *
// * Date:  January 21st, 2016                                         *
// *                                                                   *
// * Copyright (C) 2016 Dr. David A. Gaitros, Florida State University *
// * All rights reserved. Not for distrubtion or use unless by written *
// * permission of the author.                                         *
// *********************************************************************  
int main(void)
{
	char menuoption = ' ';
	Box * myboxptr;
	int boxs = 0;
	char boxf = ' ';
	char boxb = ' ';
	PrintMessage();
	boxs = GetBoxSize();
	boxf = GetChar("Fill");
	boxb = GetChar("Border");
	myboxptr = new Box(boxs, boxb, boxf);
	myboxptr->Draw();
	while (menuoption != 'e' && menuoption != 'E')

	{
		DisplayMenu();
		cin >> menuoption;
		cin.clear();
		switch (menuoption)
		{
		case 'D': case 'd':  myboxptr->Draw();
			break;
		case 'E':; case 'e':  cout << "Bye: " << endl;
			break;
		case 'R': case 'r':
			myboxptr->Summary();
			break;
		case 'S': case 's': myboxptr->Shrink();
			cout << "Attempted to Shrink the box" << endl;
			break;
		case 'G': case 'g': myboxptr->Grow();
			cout << "Attempted to Brow the box" << endl;
			break;
		case 'B': case 'b':
			cout << "Enter in a new border character: ";
			cin >> boxb;
			cin.clear();
			myboxptr->SetBorder(boxb);
			cout << "Attempted to set the border character" << endl;
			break;
		case 'F': case 'f':
			cout << "Enter in a new fill character: ";
			cin >> boxf;
			cin.clear();
			myboxptr->SetFill(boxf);
			cout << "Attempted to set the fill character" << endl;
			break;
		case 'Z': case 'z':
			cout << "The size of the box is: :" << myboxptr->GetSize() << endl;
			break;
		case 'A': case 'a':
			cout << "The area is: " << myboxptr->Area() << endl;
			break;
		case 'P': case 'p':
			cout << " The Perimeter is: " << myboxptr->Perimeter() << endl;
			break;
		default:  cout << "Invalid Option, re-enter:";
		}

	}
	return 0;
}

// *********************************************************************
// *                                                                   *
// * Function: PrintMessage                                            *
// * Description:  Print the intial message to the user.               *
// *                                                                   *
// * Author: Dr. David A. Gaitros                                      *
// * Date:  January 21st, 2016                                         *
// *                                                                   *
// * Copyright (C) 2016 Dr. David A. Gaitros, Florida State University *
// * All rights reserved. Not for distrubtion or use unless by written *
// * permission of the author.                                         *
// *********************************************************************  
void PrintMessage()
{
	for (int index = 0; index<48; index++)
		cout << endl;
	cout << "***********************************************" << endl;
	cout << "***  Welcome to the Box Building Program    ***" << endl;
	cout << "***  This program will test your Box Class  ***" << endl;
	cout << "***  You will be asked to enter in a box    ***" << endl;
	cout << "***    size, border character and fill      ***" << endl;
	cout << "***    character.  Your class should        ***" << endl;
	cout << "***    handle box size out of range and     ***" << endl;
	cout << "***    but this program will check to see   ***" << endl;
	cout << "***    if an integer has been entered.      ***" << endl;
	cout << "*** Afterwards we will draw the initial     ***" << endl;
	cout << "***   box and present a menu where you      ***" << endl;
	cout << "***   test the other features of your class.***" << endl;
	cout << "***********************************************" << endl;
	return;
}
// *********************************************************************
// *                                                                   *
// * Function: GetBoxSize                                              *
// * Description: Asks the user to input a new box size and returns    *
// *   the number to the calling routine.  If the user inputs numbers  *
// *   followed by characters, the characters will be stripped off     *
// *   and return the number.                                          *
// *                                                                   *
// * Author: Dr. David A. Gaitros                                      *
// * Date:  January 21st, 2016                                         *
// *                                                                   *
// * Copyright (C) 2016 Dr. David A. Gaitros, Florida State University *
// * All rights reserved. Not for distrubtion or use unless by written *
// * permission of the author.                                         *
// *********************************************************************  
int GetBoxSize()
{
	static int boxsize = 0;
	char line[MAXLINESIZE];
	cout << endl << endl << "Enter in the Box size (1-39): ";
	cin.getline(line, MAXLINESIZE);
	boxsize = atoi(line);
	cin.clear();
	return boxsize;
}

// *********************************************************************
// *                                                                   *
// * Function: GetChar                                                 *
// * Description: Interesting routine. Duel purpose. Returns a         *
// *   character to the calling routine.  The string that is passed    *
// *   in will tell the user what type of character to enter.  Usually *
// *   a Border or Fill Character.                                     *
// *                                                                   *
// * Author: Dr. David A. Gaitros                                      *
// * Date:  January 21st, 2016                                         *
// *                                                                   *
// * Copyright (C) 2016 Dr. David A. Gaitros, Florida State University *
// * All rights reserved. Not for distrubtion or use unless by written *
// * permission of the author.                                         *
// *********************************************************************  
char GetChar(const string whatchar)
{
	static char mychar;

	cout << endl << "Enter a " << whatchar << " Character: ";
	cin >> mychar;
	cin.clear();
	return mychar;
}
// *********************************************************************
// *                                                                   *
// * Function: DiaplayMenu                                             *
// * Description: Diplay the menu option                               *
// *                                                                   *
// * Author: Dr. David A. Gaitros                                      *
// * Date:  January 21st, 2016                                         *
// *                                                                   *
// * Copyright (C) 2016 Dr. David A. Gaitros, Florida State University *
// * All rights reserved. Not for distrubtion or use unless by written *
// * permission of the author.                                         *
// *********************************************************************  
void DisplayMenu()
{
	cout << " B O X  M E N U " << endl;
	cout << "_______________ " << endl;
	cout << " S -> Shrink Box by 1" << endl;
	cout << " G -> Grow Box by 1 " << endl;
	cout << " R -> Report Statistics for the box" << endl;
	cout << " B -> Set new Border character for the box" << endl;
	cout << " F -> Set new Fill character for the box" << endl;
	cout << " Z -> Show the Size of the Box " << endl;
	cout << " D -> Draw the box" << endl;
	cout << " P -> Show Perimeter of the box" << endl;
	cout << " A -> Show Area of the box " << endl;
	cout << " E -> Exit " << endl;
	cout << " _____________ " << endl;
	cout << "Option: ";
}
