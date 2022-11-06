#include "Common.h"
void _Common::gotoXY(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
_Common::_Common()
{
}


_Common::~_Common()
{
}
