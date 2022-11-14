#pragma once
#include "Point.h"
class _Board
{
private:
	int _size;
	int _left;
	int _top;
public:
	int getSize();
	int getLeft();
	int getTop();
	int getXAt(int, int);
	int getYAt(int, int);
	int get_Check(int i, int j){ return _pArr[i][j].getCheck(); }
	void loadData(int, int ,int);
	void resetData();
	void drawBoard();
	int checkBoard(int, int, bool);
	int testBoard(int x,int y);
public:
	int checkWinHang(int x, int y, int value);
	int checkWinCot(int x, int y, int value);
	int checkDiagonal1(int x, int y, int value);
	int checkDiagonal2(int x, int y, int value);
	int CountX; 
	int CountY;
public:
	_Board();
	_Board(int pSize,int pX,int pY);
	~_Board();
};

