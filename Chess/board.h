#pragma once
#include<fstream>
#include<iostream>
#include<Windows.h>
#include"piece.h"

using namespace std;

class Board {
protected:
	int dim;
public:
	Piece*** board;
	Board(ifstream& rdr);
	void printBox(int sr, int sc, int rows, int cols, int clr,int clr2);
	void printOneCell(pos src);
	void printBoard();
	void MovePiece(pos Src, pos Des);
	void fakeboardinit(Piece*** &_board);
	void FakeUpdateB(Piece*** _board, pos Src, pos Des);
	pos findKing(Piece *** _board, int turn);
	void promote(pos Src,int turn);
};

