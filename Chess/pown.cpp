#include "pown.h"

Pown::Pown(pos P, int c, char s) :
	Piece(P, c, s)
{
}

void Pown::print_piece(int r, int c, int clr_Sp) {
	int clr;
	if (sym == 'p')
		clr = 0;
	else
		clr = 1;
	char sym = -37;
	SetClr(clr);
	gotoRowCol(r + 2, c);
	for (int i = 1; i <= 4; i++) {
		SetClr(clr_Sp);
		cout << " ";
	}
	SetClr(clr);
	cout << sym << sym;
	gotoRowCol(r + 3, c);
	for (int i = 1; i <= 3; i++) {
		SetClr(clr_Sp);
		cout << " ";
	}
	SetClr(clr);
	for (int i = 1; i <= 4; i++) {
		cout << sym;
	}
	gotoRowCol(r + 4, c);
	SetClr(clr_Sp);
	cout << "  ";
	SetClr(clr);

	for (int i = 1; i <= 6; i++) {
		cout << sym;
	}
	gotoRowCol(r + 5, c);
	for (int i = 1; i <= 4; i++) {
		SetClr(clr_Sp);
		cout << " ";
	}

	SetClr(clr);

	cout << sym << sym;
	gotoRowCol(r + 6, c);
	for (int i = 1; i <= 4; i++) {
		SetClr(clr_Sp);
		cout << " ";
	}
	SetClr(clr);

	cout << sym << sym;
	gotoRowCol(r + 7, c);
	SetClr(clr_Sp);
	cout << "  ";
	SetClr(clr);

	for (int i = 1; i <= 6; i++) {
		cout << sym;
	}
	gotoRowCol(r + 8, c);
	SetClr(clr_Sp);
	cout << " ";
	SetClr(clr);

	for (int i = 1; i <= 8; i++) {
		cout << sym;
	}
}

bool Pown::isValidMove(Piece*** Board, pos Src, pos Des) {
	
	if (Board[Src.r][Src.c]->getSym() == 'p' and Board[Des.r][Des.c]->getSym() != '-' and Board[Des.r][Des.c]->getClr() != white and steps(Src,Des) == -1 ) {
		return isD2Move(Src, Des) or isD1move(Src,Des);
	}

	if (Board[Src.r][Src.c]->getSym() == 'P' and Board[Des.r][Des.c]->getSym() != '-' and Board[Des.r][Des.c]->getClr() != black and steps(Src, Des) == 1) {
		return isD2Move(Src, Des) or isD1move(Src, Des);
	}

	if (Board[Src.r][Src.c]->getSym() == 'p' and Src.r == 1 and isVerticalMove(Src, Des) and Board[Des.r][Des.c]->getSym() == '-') {
		if (steps(Src, Des) == -1 or steps(Src, Des) == -2)
			return true;
	}

	if (Board[Src.r][Src.c]->getSym() == 'P' and Src.r == 6 and isVerticalMove(Src, Des) and Board[Des.r][Des.c]->getSym() == '-') {
		if (steps(Src, Des) == 1 or steps(Src, Des) == 2)
			return true;
	}
	if (Board[Src.r][Src.c]->getSym() == 'p' and isVerticalMove(Src, Des) and Board[Des.r][Des.c]->getSym() == '-') {
		if (steps(Src, Des) == -1)
			return true;
	}
	if (Board[Src.r][Src.c]->getSym() == 'P' and isVerticalMove(Src, Des) and Board[Des.r][Des.c]->getSym() == '-') {
		if (steps(Src, Des) == 1)
			return true;
	}
	return false;
}

Pown* Pown::clone() const
{
	return new Pown(*this);
}
