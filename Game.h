#pragma once
#include "Board.h"
#include "Point.h"
#include "Play.h"
#include <Windows.h>
#include <fstream>
void P1();
void P2();
void P1WIN();
void P2WIN();
void Box();
void Draw();
void PDraw();
class _Game
{
	_Board* _b;		
	bool _turn;	
	int _x, _y;		
	int _command;
	bool _loop;	
	int scorep1;  
	int scorep2;
	int chedo; 
public:
	void setCountXY(){
		_b->CountX = 0;
		_b->CountY = 0;
	}
	int getScore1(){ return scorep1; }
	int getScore2(){ return scorep2; }
	void setScore1(){ scorep1 = 0; }
	void setScore2(){ scorep2 = 0; }
	int getCommand();
	void setCommand(int x){ _command = x; }
	bool isContinue();
	char waitKeyBoard();
	char askContinue();
public:
	void startGame();
	void exitGame(); 
public:
	int processFinish(int x,int y);
	bool processCheckBoard();
	void moveRight();
	void moveLeft();
	void moveUp();
	void moveDown();
	void setX(int x){ _x = x; }
	void setY(int y){ _y = y; }
	int getXatEnter();
	int getYatEnter();
	bool getTurn(){ return _turn; }
	void setTurn(){ _turn = !_turn; }
	int DemNuocCoDaDi();
public:
	_Game();
	_Game(int pSize, int pLeft, int pTop);
	~_Game();
};

