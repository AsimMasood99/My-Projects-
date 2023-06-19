#include "queen.h"

Queen::Queen(pos P, int c, char s) :
	Piece(P, c, s)
{
}
void Queen::print_piece(int r, int c, int clr_Sp) {
	int clr;
	if (sym == 'q')
		clr = 0;
	else
		clr = 1;
	char sym = -37;
	gotoRowCol(r + 1, c);
	SetClr(clr_Sp);
	cout << "   ";
	SetClr(clr);
	for (int i = 1; i <= 4; i++) {
		cout << sym;
	}
	gotoRowCol(r + 2, c);
	SetClr(clr_Sp);
	cout << "  ";
	SetClr(clr);
	for (int i = 1; i <= 6; i++) {
		cout << sym;
	}
	gotoRowCol(r + 3, c);
	SetClr(clr_Sp);
	cout << " ";
	SetClr(clr);
	cout << sym;
	SetClr(clr_Sp);
	cout << " ";
	SetClr(clr);
	for (int i = 1; i <= 4; i++) {
		cout << sym;
	}
	SetClr(clr_Sp);
	cout << " ";
	SetClr(clr);
	cout << sym;
	gotoRowCol(r + 4, c);
	SetClr(clr_Sp);
	cout << " ";
	SetClr(clr);
	cout << sym;
	SetClr(clr_Sp);
	cout << "  ";
	SetClr(clr);
	cout << sym << sym;
	SetClr(clr_Sp);
	cout << "  ";
	SetClr(clr);
	cout << sym;
	gotoRowCol(r + 5, c);
	SetClr(clr_Sp);
	cout << "  ";
	SetClr(clr);
	cout << sym;
	SetClr(clr_Sp);
	cout << " ";
	SetClr(clr);
	cout << sym << sym;
	SetClr(clr_Sp);
	cout << " ";
	SetClr(clr);
	cout << sym;
	gotoRowCol(r + 6, c);
	SetClr(clr_Sp);
	cout << "    ";
	SetClr(clr);
	cout << sym << sym;
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

bool Queen::isValidMove(Piece*** Board, pos Src, pos Des) {
	if (abs(steps(Src, Des)) == 1) {

		if (isD1move(Src, Des)) {
			return (isDiagonalMove(Src, Des) and isD1PathClr(Board, Src, Des));
		}
		else if (isD2Move(Src, Des)) {
			return (isDiagonalMove(Src, Des) and isD2PathClr(Board, Src, Des));
		}
		else if (isHoriantalMove(Src, Des)) {
			return isHorPathClr(Board, Src, Des);
		}
		else if (isVerticalMove(Src, Des)) {
			return isVrtPathClr(Board, Src, Des);
		}
	}
	if (isD1move(Src, Des)) {
		return (isDiagonalMove(Src, Des) and isD1PathClr(Board, Src, Des));
	}
	else if (isD2Move(Src, Des)) {
		return (isDiagonalMove(Src, Des) and isD2PathClr(Board, Src, Des));
	}
	if (isHoriantalMove(Src, Des)) {
		return isHorPathClr(Board, Src, Des);
	}
	else if (isVerticalMove(Src, Des)) {
		return isVrtPathClr(Board, Src, Des);
	}
	return false;
}

Queen* Queen::clone() const
{
	return new Queen(*this);
}
