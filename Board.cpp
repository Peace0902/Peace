#include "Board.h"
#include "Play.h"
#include "Point.h"
#include <vector>
vector <_Point> win;
int _Board::getSize(){ return _size; }
int _Board::getLeft(){ return _left; }
int _Board::getTop(){ return _top; }
int _Board::getXAt(int i, int j)
{
	return _pArr[i][j].getX();
}
int _Board::getYAt(int i, int j)
{
	return _pArr[i][j].getY();
}
_Board::_Board()
{
	for (int i = 0; i < _size; i++)
	{
		delete[] _pArr[i];
	}
	delete[] _pArr;
}
_Board::_Board(int pSize, int pX, int pY)
{
	_size = pSize;
	_left = pX;
	_top = pY;
	_pArr = new _Point*[pSize];
	for (int i = 0; i < pSize; i++)
	{
		_pArr[i] = new _Point[pSize];
	}
}
void _Board::loadData(int i, int j, int k)
{
	if (_size == 0) return;
	_pArr[i][j].setX(4 * j + _left + 2);
	_pArr[i][j].setY(2 * i + _top + 1);
	_pArr[i][j].setCheck(k);
	if (k == -1)
	{
		Textcolor(Blue);	
		_Common::gotoXY(4 * j + _left + 2, 2 * i + _top + 1);
		cout << "X";
		CountX++;
	}
	if (k == 1)
	{
		Textcolor(Red);	
		_Common::gotoXY(4 * j + _left + 2, 2 * i + _top + 1);
		cout << "O";
		CountY++;
	}

}
void _Board::resetData()
{
	if (_size == 0) return;
	for (int i = 0; i < _size; i++)
	{
		for (int j = 0; j < _size; j++)
		{
			_pArr[i][j].setX(4 * j + _left + 2);
			_pArr[i][j].setY(2 * i + _top + 1);
			_pArr[i][j].setCheck(0);
		}
	}
	
}
void _Board::drawBoard()
{
	if (_size == 0) return;
	Textcolor(Green);
	for (int i = 0; i < SIZE * 2; i++)
	{
		Sleep(1);
		_Common::gotoXY(SIZE * 4, i + 1);
		if ((i + 1) % 2 == 1)
			cout << char(186);
		else
			cout << char(182);
	}
	for (int i = 0; i < SIZE * 2; i=i+2)
	{
		Sleep(1);
		_Common::gotoXY(0, i);
		for (int j = 0; j < SIZE * 4; j++)
		{
			if (j % 4 == 0)
				cout << char(197);
			else
			cout << char(196);
		}
	}
	for (int i = 0; i < SIZE * 2; i++)
	{
		Sleep(1);
		_Common::gotoXY(0, i + 1);
		if ((i + 1) % 2 == 1)
			cout << char(186);
		else
			cout << char(199);
	}
	for (int i = 1; i < SIZE * 2; i=i+2)
	{
		for (int j = 0; j < SIZE * 4; j=j+4)
		{
			Sleep(1);
			_Common::gotoXY(j, i);
			if (j == 0)
				continue;
			cout << char(179);
		}
	}
	_Common::gotoXY(0, 0);
	for (int i = 0; i < SIZE * 4; i++)
	{
		Sleep(1);
		if (i % 4 == 0)
			cout << char(209);
		else
			cout << char(205);
	}
	_Common::gotoXY(0, 0); cout << char(201);
	_Common::gotoXY(SIZE * 4, 0); cout << char(187);
	_Common::gotoXY(0, SIZE * 2);
	for (int i = 0; i < SIZE * 4; i++)
	{
		Sleep(1);
		if (i % 4 == 0)
			cout << char(207);
		else
			cout << char(205);
	}
	_Common::gotoXY(0, SIZE * 2); cout << char(200);
	_Common::gotoXY(SIZE * 4, SIZE * 2);
	cout << char(188);

	_Common::gotoXY(_pArr[0][0].getX(), _pArr[0][0].getY());
}

int _Board::checkBoard(int pX, int pY, bool pTurn) 
{
	for (int i = 0; i < _size; i++)
	{
		for (int j = 0; j < _size; j++)
		{
			if (_pArr[i][j].getX() == pX && _pArr[i][j].getY() == pY && _pArr[i][j].getCheck() == 0)
			{
				if (pTurn)
				{
					_pArr[i][j].setCheck(-1);
					CountX++;
				}	
				else
				{
					_pArr[i][j].setCheck(1);
					CountY++;
				}		
				return _pArr[i][j].getCheck();
			}
		}
	}
	return 0;
}

int _Board::checkWinHang(int x, int y, int value)
{
	int dong, cot;
	int loop = 1;
	int test = -1;
	int check2dau = 0;
	int countRowLeft = 0, countRowRight = 0;
	dong = (x - _left - 2) / 4;
	cot = (y - _top - 1) / 2;
	int trai, phai; 
	trai = phai = dong;
	while (_pArr[cot][trai].getCheck() == value)
	{
		win.push_back(_pArr[cot][trai]);
		countRowLeft++;
		if (trai == 0)
			break;
		trai--;
	}
	while (_pArr[cot][phai].getCheck() == value)
	{
		win.push_back(_pArr[cot][phai]);
		countRowRight++;
		if (phai == _size-1)
			break;
		phai++;
	}
	if (_pArr[cot][trai].getCheck() == -value && _pArr[cot][phai].getCheck() == -value)
		check2dau = 1;
	if ((countRowLeft + countRowRight - 1) == 5 && (check2dau == 0))
	{
		test = 1;
	}
	else
		test = 0;
	if (test == 1)
	{
		while (loop < 30)
		{
			Textcolor(rand() % 15 + 1);
			for (int i = 0; i < win.size(); i++)
			{
				_Common::gotoXY(win[i].getX(), win[i].getY());
				if (win[i].getCheck() == -1)
					cout << "X";
				else
					cout << "O";
			}
			Sleep(100);
			loop++;
		}
	}
	else win.clear();
	return test;
}
int _Board::checkWinCot(int x, int y, int value) 
{
	int dong, cot;
	int test = -1, loop = 1;
	int check2dau = 0;
	int countColTop = 0, countColBot = 0;
	dong = (x - _left - 2) / 4;
	cot = (y - _top - 1) / 2;
	int tren, duoi; 
	tren = duoi = cot;
	while (_pArr[tren][dong].getCheck() == value)
	{
		countColTop++;
		win.push_back(_pArr[tren][dong]);
		if (tren ==0)
			break;
		tren--;
	}
	while (_pArr[duoi][dong].getCheck() == value)
	{
		countColBot++;
		win.push_back(_pArr[duoi][dong]);
		if (duoi == _size-1)
			break;
		duoi++;
	}
	if (_pArr[tren][dong].getCheck() == -value && _pArr[duoi][dong].getCheck() == -value)
		check2dau = 1;
	if ((countColTop + countColBot - 1) == 5 && (check2dau == 0))
	{
		test=1;
	}
	else
		test=0;
	if (test == 1)
	{
		while (loop < 30)
		{
			Textcolor(rand() % 15 + 1);
			for (int i = 0; i < win.size(); i++)
			{
				_Common::gotoXY(win[i].getX(), win[i].getY());
				if (win[i].getCheck() == -1)
					cout << "X";
				else
					cout << "O";
			}
			Sleep(100);
			loop++;
		}
	}
	else win.clear();
	return test;
}
int _Board::checkDiagonal2(int x, int y, int value)
{
	int dong, cot;
	int test = -1, loop = 1;
	int check2dau = 0;
	int countDiaTop = 0, countDiaBot = 0;
	dong = (x - _left - 2) / 4;
	cot = (y - _top - 1) / 2;
	int tren, duoi;
	int phai, trai;
	tren = duoi = cot;
	phai = trai = dong;
	while (_pArr[tren][trai].getCheck() == value)
	{
		win.push_back(_pArr[tren][trai]);
		countDiaTop++;
		if (tren == 0 || trai == 0)
			break;
		tren--;
		trai--;
	}
		
	while (_pArr[duoi][phai].getCheck() == value)
	{
		win.push_back(_pArr[duoi][phai]);
		countDiaBot++;
		if (duoi == _size - 1 || phai == _size - 1)
			break;
		duoi++;
		phai++;
	}
	if (_pArr[tren][trai].getCheck() == -value && _pArr[duoi][phai].getCheck() == -value)
		check2dau = 1;
	if ((countDiaTop + countDiaBot - 1) == 5 && (check2dau == 0))
	{
		test=1;
	}
	else
		test=0;
	if (test == 1)
	{
		while (loop < 30)
		{
			Textcolor(rand() % 15 + 1);
			for (int i = 0; i < win.size(); i++)
			{
				_Common::gotoXY(win[i].getX(), win[i].getY());
				if (win[i].getCheck() == -1)
					cout << "X";
				else
					cout << "O";
			}
			Sleep(100);
			loop++;
		}
	}
	else win.clear();
	return test;
}
int _Board::checkDiagonal1(int x, int y, int value)
{
	int dong, cot;
	int test = -1, loop = 1;
	int check2dau = 0;
	int countDiaTop = 0, countDiaBot = 0;
	dong = (x - _left - 2) / 4;
	cot = (y - _top - 1) / 2;
	int tren, duoi;
	int phai, trai;
	tren = duoi = cot;
	phai = trai = dong;
	while (_pArr[tren][phai].getCheck() == value)
	{
		countDiaTop++;
		win.push_back(_pArr[tren][phai]);
		if (tren == 0 || phai==_size-1)
			break;
		tren--;
		phai++;
	}
	while (_pArr[duoi][trai].getCheck() == value)
	{
		win.push_back(_pArr[duoi][trai]);
		countDiaBot++;
		if (duoi == _size-1 || trai == 0)
			break;
		duoi++;
		trai--;
	}
	if (_pArr[tren][phai].getCheck() == -value && _pArr[cotduoi][trai].getCheck() == -value)
		check2dau = 1;
	if ((countDiaTop + countDiaBot - 1) == 5 && (check2dau == 0))
	{
		test= 1;
	}
	else
		test=0;
	if (test == 1)
	{
		while (loop < 30)
		{
			Textcolor(rand() % 15 + 1);
			for (int i = 0; i < win.size(); i++)
			{
				_Common::gotoXY(win[i].getX(), win[i].getY());
				if (win[i].getCheck() == -1)
					cout << "X";
				else
					cout << "O";
			}
			Sleep(100);
			loop++;
		}
	}
	else win.clear();
	return test;
}
int _Board::testBoard(int x,int y)
{
	if (checkWinHang(x, y, -1) == 1)
		return -1;
	if (checkWinCot(x, y, -1) == 1)
		return -1;
	if (checkDiagonal1(x, y, -1) == 1)
		return -1;
	if (checkDiagonal2(x, y, -1) == 1)
		return -1;
	if (checkWinHang(x, y, 1) == 1)
		return 1;
	if (checkWinCot(x, y, 1) == 1)
		return 1;
	if (checkDiagonal1(x, y, 1) == 1)
		return 1;
	if (checkDiagonal2(x, y, 1) == 1)
		return 1;
	if (CountX + CountY == SIZE*SIZE)
		return 0;
	return 2;
}
_Board::~_Board()
{
}

