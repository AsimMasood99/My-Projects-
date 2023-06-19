#pragma once
#include<iostream>
#include"utility.h"
using namespace std;
enum colour { white, black };

struct pos {
	int r;
	int c;
};

class Piece {

protected:
	pos Position;
	int clr;
	char sym;
	bool isHoriantalMove(pos s, pos d);
	bool isVerticalMove(pos s, pos d);
	bool isDiagonalMove(pos s, pos d);
	bool isHorPathClr(Piece ***Board, pos s, pos d);
	bool isVrtPathClr(Piece ***Board, pos s, pos d);
	bool isD1PathClr(Piece ***Board, pos s, pos d);
	bool isD2PathClr(Piece ***Board, pos s, pos d);
	bool isD1move(pos s, pos d);
	bool isD2Move(pos s, pos d);
	int steps(pos s, pos d);
public:

	Piece(pos A, int _clr, char s);
	char getSym();
	void setNewPosition(pos P);
	int getClr();
	virtual Piece* clone() const = 0;
	virtual void print_piece(int r, int c, int clr_Sp) = 0;
	virtual bool isValidMove(Piece ***Board, pos Src, pos Des) = 0;
};

