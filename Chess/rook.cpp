#include "rook.h"

Rook::Rook(pos P, int c, char s) :
	Piece(P, c, s)
{
}
void Rook::print_piece(int r, int c, int clr_Sp) {
	int clr1;
	if (sym == 'r')
		clr1 = 0;
	else  clr1 = 1;
	char sym = -37;
	gotoRowCol(r + 1, c);
	SetClr(clr_Sp);
	cout << "  ";
	SetClr(clr1);
	cout << sym;
	SetClr(clr_Sp);
	cout << " ";
	SetClr(clr1);
	cout << sym << sym;
	SetClr(clr_Sp);
	cout << " ";
	SetClr(clr1);
	cout << sym;
	gotoRowCol(r + 2, c);
	SetClr(clr_Sp);
	cout << "  ";
	SetClr(clr1);
	for (int i = 1; i <= 6; i++) {
		cout << sym;
	}
	gotoRowCol(r + 3, c);
	SetClr(clr_Sp);
	cout << "   ";
	SetClr(clr1);
	for (int i = 1; i <= 4; i++) {
		cout << sym;
	}
	gotoRowCol(r + 4, c);
	SetClr(clr_Sp);
	for (int i = 1; i <= 4; i++) {
		cout << " ";
	}
	SetClr(clr1);
	cout << sym << sym;
	gotoRowCol(r + 5, c);
	SetClr(clr_Sp);
	for (int i = 1; i <= 4; i++) {
		cout << " ";
	}
	SetClr(clr1);
	cout << sym << sym;
	gotoRowCol(r + 6, c);
	SetClr(clr_Sp);
	for (int i = 1; i <= 4; i++) {
		cout << " ";
	}
	SetClr(clr1);
	cout << sym << sym;
	gotoRowCol(r + 7, c);
	SetClr(clr_Sp);
	cout << "   ";
	SetClr(clr1);
	for (int i = 1; i <= 4; i++) {
		cout << sym;
	}
	gotoRowCol(r + 8, c);
	SetClr(clr_Sp);
	cout << "  ";
	SetClr(clr1);
	for (int i = 1; i <= 6; i++) {
		cout << sym;
	}
}

bool Rook::isValidMove(Piece*** Board, pos Src, pos Des) {
	if (isHoriantalMove(Src, Des)) {
		return isHorPathClr(Board, Src, Des);
	}
	else if (isVerticalMove(Src, Des)) {
		return isVrtPathClr(Board, Src, Des);
	}
	return false;
}

Rook* Rook::clone() const
{
	return new Rook(*this);
}
