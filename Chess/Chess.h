#pragma once
#include<iostream>
#include<Windows.h>
#include<fstream>
#include"piece.h"
#include"board.h"
#include"player.h"
#include"utility.h"
using namespace std;

struct state {
	pos Src;
	pos Des;
	Piece* oldP;
	Piece* newP;
	int turn;
};

class Chess
{
protected:
	Player **Ps;
	int dim;
public:
	//pos Src, Des;
	int turn;
	Board chessBoard;
	Chess(ifstream& rdr, string n1, string n2);
	int changeTurn(int turn);
	void printTurnMsg(int turn);
	bool isValidSelection(Piece *** b,pos Src);
	bool isValidDestination(Piece*** b, pos Des);
	bool isLigalMove(Piece*** b, pos Src, pos Des);
	void mouseClick(pos& src);
	bool** canMove(Piece ***b,pos Src);
	void highLight(bool** M, pos Src);
	void unhighLight(bool** M, pos Src);
	bool check(Piece*** b);
	bool selfCheck(Piece*** b);
	bool CheckMate(Piece*** B);
	bool StallMate(Piece*** B);
	bool isPromoted(pos Src);
	void printNew(int sr, int sc, int rows, int cols);
	void printload(int sr, int sc, int rows, int cols);
	void printundo(int sr, int sc, int rows, int cols);
	bool doSave(pos s);
	void save();
	void Load();
	bool doLoad(pos s);
	void printsave(int sr, int sc, int rows, int cols);
	void updateMove(state &M, pos S, pos D);
	void Undo(state M);
	void printRedo(int sr, int sc, int rows, int cols);
	void Redo(state M);
};

