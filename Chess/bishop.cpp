#include "bishop.h"

Bishop::Bishop(pos P, int c, char s) :
	Piece(P, c, s)
{
}

void Bishop::print_piece(int r, int c, int clr_Sp) {
	int clr;
	if (sym == 'b')
		clr = 0;
	else
		clr = 1;
	char sym = -37;
	gotoRowCol(r + 1, c);
	SetClr(clr_Sp);
	cout << "    ";
	SetClr(clr);
	cout << sym << sym;
	gotoRowCol(r + 2, c);
	SetClr(clr_Sp);
	cout << "    ";
	SetClr(clr);
	cout << sym << sym << sym;
	gotoRowCol(r + 3, c);
	SetClr(clr_Sp);
	cout << "   ";
	SetClr(clr);
	cout << sym << sym << sym;
	SetClr(clr_Sp);
	cout << " ";
	SetClr(clr);
	cout << sym;
	gotoRowCol(r + 4, c);
	SetClr(clr_Sp);
	cout << "  ";
	SetClr(clr);
	for (int i = 1; i <= 4; i++) {
		cout << sym;
	}SetClr(clr_Sp);
	cout << " ";
	SetClr(clr);
	cout << sym;
	gotoRowCol(r + 5, c);
	SetClr(clr_Sp);
	for (int i = 1; i <= 4; i++) {
		cout << " ";
	}
	SetClr(clr);
	cout << sym << sym;
	SetClr(clr_Sp);
	cout << " ";
	SetClr(clr);
	cout << sym;
	gotoRowCol(r + 6, c);
	SetClr(clr_Sp);
	for (int i = 1; i <= 4; i++) {
		cout << " ";
	}
	SetClr(clr);
	cout << sym << sym;
	SetClr(clr_Sp);
	cout << " ";
	SetClr(clr);
	cout << sym;
	gotoRowCol(r + 7, c);
	SetClr(clr_Sp);
	cout << "   ";
	SetClr(clr);
	for (int i = 1; i <= 4; i++) {
		cout << sym;
	}
	gotoRowCol(r + 8, c);
	SetClr(clr_Sp);
	cout << "  ";
	SetClr(clr);
	for (int i = 1; i <= 6; i++) {
		cout << sym;
	}
}

bool Bishop::isValidMove(Piece ***Board ,pos Src, pos Des) {
	if (isD1move(Src, Des)) {
		return (isDiagonalMove(Src, Des) and isD1PathClr(Board, Src, Des));
	}
	else if (isD2Move(Src, Des)) {
		return (isDiagonalMove(Src,Des) and isD2PathClr(Board, Src, Des));
	}
	return false;
}

Bishop* Bishop::clone() const
{
	return new Bishop(*this);
}
