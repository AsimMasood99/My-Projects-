#include "knight.h"
Knight::Knight(pos P, int c, char s) :
	Piece(P, c, s)
{
}
void Knight::print_piece(int r, int c, int clr_Sp) {
	int clr;
	if (sym == 'n') {
		clr = 0;
	}
	else clr = 1;
	char sym = -37;
	gotoRowCol(r + 1, c);
	SetClr(clr_Sp);
	cout << " ";
	SetClr(clr);
	for (int i = 1; i <= 5; i++) {
		cout << sym;
	}
	gotoRowCol(r + 2, c);
	SetClr(clr_Sp);
	cout << "  ";
	SetClr(clr);
	for (int i = 1; i <= 5; i++) {
		cout << sym;
	}
	gotoRowCol(r + 3, c);
	SetClr(clr_Sp);
	cout << "   ";
	SetClr(clr);
	for (int i = 1; i <= 5; i++) {
		cout << sym;
	}
	gotoRowCol(r + 4, c);
	SetClr(clr_Sp);
	cout << "   ";
	SetClr(clr);
	cout << sym;
	SetClr(clr_Sp);
	cout << " ";
	SetClr(clr);
	for (int i = 1; i <= 4; i++) {
		cout << sym;
	}
	gotoRowCol(r + 5, c);
	SetClr(clr_Sp);
	cout << "   ";
	SetClr(clr);
	for (int i = 1; i <= 6; i++) {
		cout << sym;
	}
	gotoRowCol(r + 6, c);
	SetClr(clr_Sp);
	cout << "   ";
	SetClr(clr);
	for (int i = 1; i <= 3; i++) {
		cout << sym;
	}
	SetClr(clr_Sp);
	cout << " ";
	SetClr(clr);
	cout << sym << sym;
	gotoRowCol(r + 7, c);
	SetClr(clr_Sp);
	for (int i = 1; i <= 7; i++) {
		cout << " ";
	}
	SetClr(clr);
	cout << sym << sym;
	gotoRowCol(r + 8, c);
	SetClr(clr_Sp);
	cout << "   ";
	SetClr(clr);
	for (int i = 1; i <= 6; i++) {
		cout << sym;
	}
}

bool Knight::isValidMove(Piece*** Board, pos Src, pos Des) {
	int r = Des.r - Src.r;
	int c = Des.c - Src.c;
	if ((r == 2 or r == -2) and abs(c) == 1) {
		return true;
	}
	if ((c == 2 or c == -2) and abs(r) == 1) {
		return true;
	}
	return false;
}

Knight* Knight::clone() const
{
	return new Knight(*this);	
}
