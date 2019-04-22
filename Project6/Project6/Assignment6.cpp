#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
using namespace std;

void getFilenames(ifstream & ipf, char * ifname, ofstream & opf, char * ofname);
int changeCASEandCount(ifstream & ipf, char * ifname, ofstream & opf, char * ofname);
void WordSizeAndCount(ifstream & ipf, char * ifname, ofstream & opf, char * ofname);

int main(void)
{
	ifstream inputfile;
	ofstream outputfile;
	char ifilename[80];
	char ofilename[80];
	getFilenames(inputfile, ifilename, outputfile, ofilename);                       //Read in an input file and an outputfile
	outputfile << "Number of characters: " << changeCASEandCount                     //Change all characters to uppercase
	(inputfile, ifilename, outputfile, ofilename) << endl;                           //Count the number of characters
	WordSizeAndCount(inputfile, ifilename, outputfile, ofilename);                   //Count the number of words, size of largest and smallest words
	inputfile.close();                                                               //Close the files
	outputfile.close();
	return 0;
}

void getFilenames(ifstream & ipf, char * ifname, ofstream & opf, char * ofname)      //Read in an input file and an outputfile
{
	cout << "Enter a valid input filename: ";
	cin >> ifname;
	ipf.open(ifname);
	while (!ipf.is_open())
	{
		cout << "Invalid filename. Enter a valid input filename: ";
		cin >> ifname;
		ipf.open(ifname);
	}
	cout << "Enter a valid output filename: ";
	cin >> ofname;
	opf.open(ofname);
}

int changeCASEandCount(ifstream & ipf, char * ifname, ofstream & opf, char * ofname)  // Got this function code from tuesday's lecture
{                                                                                     //Change all characters to uppercase
	int charcount = 0;
	char c = ' ';
	ipf.get(c);
	while (!ipf.eof())
	{
		opf << (char)toupper(c);
		ipf.get(c);
		charcount++;                                                                  //Count the number of characters
	}
	opf << endl;
	ipf.close();
	return charcount;
}

void WordSizeAndCount(ifstream & ipf, char * ifname, ofstream & opf, char * ofname)   //Count the number of words
{
	int wordcount = 0;
	int largestwordsize = 0;
	int smallestwordsize = 1000;
	string word;
	ipf.open(ifname);
	while (ipf >> word)                                       //Thursday's lecture & Dr. Gaitros's YouTube channel
	{
		if (word.length() > largestwordsize)                  //Size of the largest word
		{
			largestwordsize = word.length();
		}
		if (word.length() < smallestwordsize)                 //Size of the smallest word
		{
			smallestwordsize = word.length();
		}
		wordcount++;
	}
	opf << "Word count: " << wordcount << endl;               //Print them out
	opf << "Largest word size: " << largestwordsize << endl;
	opf << "Smallest word size: " << smallestwordsize << endl;
}