#pragma once
#include <Windows.h>

class _Common
{
public :
	static void fixConsoleWindow();
	static void gotoXY(int, int);
	static void setConsoleWindow(int w, int h);
public:
	_Common();
	~_Common();
};

