#include "Point.h"
#include "Board.h"
#include "Game.h"
#include "Play.h"
#include <string.h>

int main()
{
	int n = 100;
	_Common::fixConsoleWindow();
	_Common::setConsoleWindow(1000, 600);
	ScreenStartGame(n);
	system("pause");
}
