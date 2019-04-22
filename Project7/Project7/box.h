#ifndef BOX_H
#define BOX_H
const char DEFAULTBORDER = '#';
const char DEFAULTFILL = '*';
const int DEFAULTMIN = 1;
const int DEFAULTMAX = 39;

class Box
{
public:
	Box(const int s, const char bord, const char fill);
	void Grow();
	void Shrink();
	int GetSize();
	int Perimeter();
	int Area();
	void SetBorder(const char);
	void SetFill(const char);
	void Draw();
	void Summary();
private:
	int Size;
	char FillChar;
	char BordChar;
};
#endif