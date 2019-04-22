#ifndef MEASUREMENTS_H
#define MEASUREMENTS_H
const int DEFAULTHEIGHT = 69;
const int DEFAULTWEIGHT = 130;

class Measurements
{
public:
	Measurements(const int = DEFAULTHEIGHT, const int = DEFAULTWEIGHT);
	void Grow();
	void Shrink();
	void SetWeight(const int);
	void SetHeight(const int);
	int GetHeight();
	int GetWeight();
	void PrintHeight();
	void PrintWeight();
	void PrintStats();
private:
	int Height;
	int Weight;

};

#endif