#include "piece.h"

bool Piece::isHoriantalMove(pos s, pos d) {
	return (s.r == d.r);
}

bool Piece::isVerticalMove(pos s, pos d) {
	return (s.c == d.c);
}

bool Piece::isDiagonalMove(pos s, pos d) {
	int r = abs(d.r - s.r);
	int c = abs(d.c - s.c);
	return r == c;
}

bool Piece::isHorPathClr(Piece*** Board, pos s, pos d) {
	int sc, ec;
	if (s.c < d.c) {
		sc = s.c;
		ec = d.c;
	}
	else {
		sc = d.c;
		ec = s.c;
	}
	for (int i = sc + 1; i < ec; i++) {
		if (Board[s.r][i]->getSym() != '-')
			return false;
	}
	return true;
}

bool Piece::isVrtPathClr(Piece*** Board, pos s, pos d) {
	int sr, er;
	if (s.r < d.r) {
		sr = s.r;
		er = d.r;
	}
	else {
		sr = d.r;
		er = s.r;
	}
	for (int i = sr + 1; i < er; i++) {
		if (Board[i][s.c]->getSym() != '-')
			return false;
	}
	return true;
}

bool Piece::isD1PathClr(Piece*** Board, pos s, pos d) {
	if (s.r < d.r) {
		int t = d.r - s.r;
		for (int i = 1; i < t; i++) {
			if (Board[s.r + i][s.c + i]->getSym() != '-')
				return false;
		}
	}
	else {
		int t = s.r - d.r;
		for (int i = 1; i < t; i++) {
			if (Board[d.r + i][d.c + i]->getSym() != '-')
				return false;
		}
	}
	return true;
}

bool Piece::isD2PathClr(Piece*** Board, pos s, pos d) {
	if (s.r < d.r) {
		int t = d.r - s.r;
		for (int i = 1; i < t; i++) {
			if (Board[s.r + i][s.c - i]->getSym() != '-')
				return false;
		}
	}
	else {
		int t = s.r - d.r;
		for (int i = 1; i < t; i++) {
			if (Board[s.r - i][s.c + i]->getSym() != '-')
				return false;
		}
	}return true;
}

bool Piece::isD1move(pos s, pos d) {
	if (d.r > s.r and d.c > s.c)
		return true;
	if (s.r > d.r and s.c > d.c)
		return true;
	return false;
}

bool Piece::isD2Move(pos s, pos d) {
	if (d.r < s.r and d.c > s.c)
		return true;
	if (d.r > s.r and d.c < s.c)
		return true;
	return false;
}

int Piece::steps(pos s, pos d) {
	if (isHoriantalMove(s, d)) {
		return (s.c - d.c);
	}
	else if (isVerticalMove(s, d) or isDiagonalMove(s, d)) {
		return (s.r - d.r);
	}
	return 0;
}

Piece::Piece(pos A, int _clr, char s) {
	Position = A;
	clr = _clr;
	sym = s;
}

void Piece::setNewPosition(pos P) {
	Position = P;
}

char Piece::getSym() {
	return sym;
}

int Piece::getClr() {
	return clr;
}
