#include <iostream>
#include <fstream>
#include <iomanip>
#include<Windows.h>
#include<conio.h>
using namespace std;
const int rows = 100;
const int cols = 200;

enum { white, black };
struct pos {
	int r, c;
};

struct cap
{
	char p;
	int c = 0;
};

void getRowColbyLeftClick(int& rpos, int& cpos)
{
	HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
	DWORD Events;
	INPUT_RECORD InputRecord;
	SetConsoleMode(hInput, ENABLE_PROCESSED_INPUT | ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS);
	do
	{
		ReadConsoleInput(hInput, &InputRecord, 1, &Events);
		if (InputRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
		{
			cpos = InputRecord.Event.MouseEvent.dwMousePosition.X;
			rpos = InputRecord.Event.MouseEvent.dwMousePosition.Y;
			break;
		}
	} while (true);
}
void gotoRowCol(int rpos, int cpos)
{
	COORD scrn;
	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X = cpos;
	scrn.Y = rpos;
	SetConsoleCursorPosition(hOuput, scrn);
}
void SetClr(int clr) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), clr);
}
void init(char**& board, int& dim, int& turn, string pnames[2]) {
	ifstream rdr("BSCS22077-newgame.txt");
	system("cls");
	SetClr(15);
	cout << "Enter name of player 1: ";
	cin >> pnames[0];
	cout << "Enter name of player 2: ";
	cin >> pnames[1];
	turn = white;
	rdr >> dim;
	board = new char* [dim];
	for (int i = 0; i < dim; i++) {
		board[i] = new char[dim];
	}
	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++) {
			rdr >> board[i][j];
		}
	}

}
void print_P(char sym1, int r, int c, int clr_Sp) {
	int clr;
	if (sym1 == 'p' or sym1 == '(')
		clr = 5;
	else if (sym1 == '0')
	{
		clr = 3;
	}
	else if (sym1 == 'a') {
		clr = 4;
	}
	else
		clr = 6;
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
void print_Rook(char s, int r, int c, int clr_sp) {
	int clr1;
	if (s == 'r' or s == ',')
		clr1 = 5;
	else if (s == '4')
	{
		clr1 = 3;
	}
	else if (s == 'e') {
		clr1 = 4;
	}
	else  clr1 = 6;
	char sym = -37;
	gotoRowCol(r + 1, c);
	SetClr(clr_sp);
	cout << "  ";
	SetClr(clr1);
	cout << sym;
	SetClr(clr_sp);
	cout << " ";
	SetClr(clr1);
	cout << sym << sym;
	SetClr(clr_sp);
	cout << " ";
	SetClr(clr1);
	cout << sym;
	gotoRowCol(r + 2, c);
	SetClr(clr_sp);
	cout << "  ";
	SetClr(clr1);
	for (int i = 1; i <= 6; i++) {
		cout << sym;
	}
	gotoRowCol(r + 3, c);
	SetClr(clr_sp);
	cout << "   ";
	SetClr(clr1);
	for (int i = 1; i <= 4; i++) {
		cout << sym;
	}
	gotoRowCol(r + 4, c);
	SetClr(clr_sp);
	for (int i = 1; i <= 4; i++) {
		cout << " ";
	}
	SetClr(clr1);
	cout << sym << sym;
	gotoRowCol(r + 5, c);
	SetClr(clr_sp);
	for (int i = 1; i <= 4; i++) {
		cout << " ";
	}
	SetClr(clr1);
	cout << sym << sym;
	gotoRowCol(r + 6, c);
	SetClr(clr_sp);
	for (int i = 1; i <= 4; i++) {
		cout << " ";
	}
	SetClr(clr1);
	cout << sym << sym;
	gotoRowCol(r + 7, c);
	SetClr(clr_sp);
	cout << "   ";
	SetClr(clr1);
	for (int i = 1; i <= 4; i++) {
		cout << sym;
	}
	gotoRowCol(r + 8, c);
	SetClr(clr_sp);
	cout << "  ";
	SetClr(clr1);
	for (int i = 1; i <= 6; i++) {
		cout << sym;
	}
}
void print_King(char s, int r, int c, int clrsp) {
	int clr;
	if (s == 'k')
		clr = 5;
	else clr = 6;
	char sym = -37;
	gotoRowCol(r, c);
	SetClr(clrsp);
	cout << "    ";
	SetClr(clr);
	cout << sym << sym;
	gotoRowCol(r + 1, c);
	SetClr(clrsp);
	cout << "   ";
	SetClr(clr);
	for (int i = 1; i <= 4; i++) {
		cout << sym;
	}
	gotoRowCol(r + 2, c);
	SetClr(clrsp);
	cout << "  ";
	SetClr(clr);
	for (int i = 1; i <= 6; i++) {
		cout << sym;
	}
	gotoRowCol(r + 3, c);
	SetClr(clrsp);
	cout << "   ";
	SetClr(clr);
	for (int i = 1; i <= 4; i++) {
		cout << sym;
	}
	gotoRowCol(r + 4, c);
	SetClr(clrsp);
	cout << "    ";
	SetClr(clr);
	for (int i = 1; i <= 2; i++) {
		cout << sym;
	}
	gotoRowCol(r + 6, c);
	SetClr(clrsp);
	cout << "    ";
	SetClr(clr);
	for (int i = 1; i <= 2; i++) {
		cout << sym;
	}
	gotoRowCol(r + 7, c);
	SetClr(clrsp);
	cout << "    ";
	SetClr(clr);
	for (int i = 1; i <= 2; i++) {
		cout << sym;
	}
	gotoRowCol(r + 5, c);
	SetClr(clrsp);
	cout << "   ";
	SetClr(clr);
	for (int i = 1; i <= 4; i++) {
		cout << sym;
	}
	gotoRowCol(r + 8, c);
	SetClr(clrsp);
	cout << "  ";
	SetClr(clr);
	for (int i = 1; i <= 6; i++) {
		cout << sym;
	}
	gotoRowCol(r + 9, c);
	SetClr(clrsp);
	cout << " ";
	SetClr(clr);
	for (int i = 1; i <= 8; i++) {
		cout << sym;
	}

}
void print_bishop(char s, int r, int c, int clrsp) {
	int clr;
	if (s == 'b' or s == '.')
		clr = 5;
	else if (s == '5')
	{
		clr = 3;
	}
	else if (s == 'f') {
		clr = 4;
	}
	else
		clr = 6;
	char sym = -37;
	gotoRowCol(r + 1, c);
	SetClr(clrsp);
	cout << "    ";
	SetClr(clr);
	cout << sym << sym;
	gotoRowCol(r + 2, c);
	SetClr(clrsp);
	cout << "    ";
	SetClr(clr);
	cout << sym << sym << sym;
	gotoRowCol(r + 3, c);
	SetClr(clrsp);
	cout << "   ";
	SetClr(clr);
	cout << sym << sym << sym;
	SetClr(clrsp);
	cout << " ";
	SetClr(clr);
	cout << sym;
	gotoRowCol(r + 4, c);
	SetClr(clrsp);
	cout << "  ";
	SetClr(clr);
	for (int i = 1; i <= 4; i++) {
		cout << sym;
	}SetClr(clrsp);
	cout << " ";
	SetClr(clr);
	cout << sym;
	gotoRowCol(r + 5, c);
	SetClr(clrsp);
	for (int i = 1; i <= 4; i++) {
		cout << " ";
	}
	SetClr(clr);
	cout << sym << sym;
	SetClr(clrsp);
	cout << " ";
	SetClr(clr);
	cout << sym;
	gotoRowCol(r + 6, c);
	SetClr(clrsp);
	for (int i = 1; i <= 4; i++) {
		cout << " ";
	}
	SetClr(clr);
	cout << sym << sym;
	SetClr(clrsp);
	cout << " ";
	SetClr(clr);
	cout << sym;
	gotoRowCol(r + 7, c);
	SetClr(clrsp);
	cout << "   ";
	SetClr(clr);
	for (int i = 1; i <= 4; i++) {
		cout << sym;
	}
	gotoRowCol(r + 8, c);
	SetClr(clrsp);
	cout << "  ";
	SetClr(clr);
	for (int i = 1; i <= 6; i++) {
		cout << sym;
	}

}
void print_Knight(char s, int r, int c, int clrsp) {
	int clr;
	if (s == 'n' or s == '*') {
		clr = 5;
	}
	else if (s == '2')
	{
		clr = 3;
	}
	else if (s == 'c') {
		clr = 4;
	}
	else clr = 6;
	char sym = -37;
	gotoRowCol(r + 1, c);
	SetClr(clrsp);
	cout << " ";
	SetClr(clr);
	for (int i = 1; i <= 5; i++) {
		cout << sym;
	}
	gotoRowCol(r + 2, c);
	SetClr(clrsp);
	cout << "  ";
	SetClr(clr);
	for (int i = 1; i <= 5; i++) {
		cout << sym;
	}
	gotoRowCol(r + 3, c);
	SetClr(clrsp);
	cout << "   ";
	SetClr(clr);
	for (int i = 1; i <= 5; i++) {
		cout << sym;
	}
	gotoRowCol(r + 4, c);
	SetClr(clrsp);
	cout << "   ";
	SetClr(clr);
	cout << sym;
	SetClr(clrsp);
	cout << " ";
	SetClr(clr);
	for (int i = 1; i <= 4; i++) {
		cout << sym;
	}
	gotoRowCol(r + 5, c);
	SetClr(clrsp);
	cout << "   ";
	SetClr(clr);
	for (int i = 1; i <= 6; i++) {
		cout << sym;
	}
	gotoRowCol(r + 6, c);
	SetClr(clrsp);
	cout << "   ";
	SetClr(clr);
	for (int i = 1; i <= 3; i++) {
		cout << sym;
	}
	SetClr(clrsp);
	cout << " ";
	SetClr(clr);
	cout << sym << sym;
	gotoRowCol(r + 7, c);
	SetClr(clrsp);
	for (int i = 1; i <= 7; i++) {
		cout << " ";
	}
	SetClr(clr);
	cout << sym << sym;
	gotoRowCol(r + 8, c);
	SetClr(clrsp);
	cout << "   ";
	SetClr(clr);
	for (int i = 1; i <= 6; i++) {
		cout << sym;
	}
}
void print_lance(char s, int r, int c, int clrsp) {
	int clr;
	if (s == 'l' or s == ')')
		clr = 5;
	else if (s == '1')
	{
		clr = 3;
	}
	else if (s == 'j') {
		clr = 4;
	}
	else
		clr = 6;
	char sym = -37;
	gotoRowCol(r + 1, c);
	SetClr(clrsp);
	cout << "    ";
	SetClr(clr);
	for (int i = 1; i <= 2; i++) {
		cout << sym;
	}
	gotoRowCol(r + 2, c);
	SetClr(clrsp);
	cout << "   ";
	SetClr(clr);
	for (int i = 1; i <= 4; i++) {
		cout << sym;
	}
	gotoRowCol(r + 3, c);
	SetClr(clrsp);
	cout << "    ";
	SetClr(clr);
	for (int i = 1; i <= 2; i++) {
		cout << sym;
	}
	gotoRowCol(r + 4, c);
	SetClr(clrsp);
	cout << "  ";
	SetClr(clr);
	for (int i = 1; i <= 6; i++) {
		cout << sym;
	}
	gotoRowCol(r + 5, c);
	SetClr(clrsp);
	cout << "    ";
	SetClr(clr);
	for (int i = 1; i <= 2; i++) {
		cout << sym;
	}
	gotoRowCol(r + 6, c);
	SetClr(clrsp);
	cout << "    ";
	SetClr(clr);
	for (int i = 1; i <= 2; i++) {
		cout << sym;
	}
	gotoRowCol(r + 7, c);
	SetClr(clrsp);
	cout << "   ";
	SetClr(clr);
	for (int i = 1; i <= 4; i++) {
		cout << sym;
	}
	gotoRowCol(r + 8, c);
	SetClr(clrsp);
	cout << "  ";
	SetClr(clr);
	for (int i = 1; i <= 6; i++) {
		cout << sym;
	}
}
void print_GG(char s, int r, int c, int clrsp) {
	int clr;
	if (s == 'g')
		clr = 5;
	else
		clr = 6;
	char sym = -37;
	gotoRowCol(r + 2, c);
	SetClr(clrsp);
	cout << "  ";
	SetClr(clr);
	cout << sym;
	SetClr(clrsp);
	cout << " ";
	SetClr(clr);
	cout << sym << sym;
	SetClr(clrsp);
	cout << " ";
	SetClr(clr);
	cout << sym;
	gotoRowCol(r + 3, c);
	SetClr(clrsp);
	cout << "  ";
	SetClr(clr);
	cout << sym;
	SetClr(clrsp);
	cout << " ";
	SetClr(clr);
	cout << sym << sym;
	SetClr(clrsp);
	cout << " ";
	SetClr(clr);
	cout << sym;
	gotoRowCol(r + 4, c);
	SetClr(clrsp);
	cout << " ";
	SetClr(clr);
	cout << sym;
	SetClr(clrsp);
	cout << " ";
	SetClr(clr);
	cout << sym;
	SetClr(clrsp);
	cout << "  ";
	SetClr(clr);
	cout << sym;
	SetClr(clrsp);
	cout << " ";
	SetClr(clr);
	cout << sym;
	gotoRowCol(r + 5, c);
	SetClr(clrsp);
	cout << "   ";
	SetClr(clr);
	for (int i = 1; i <= 4; i++) {
		cout << sym;
	}
	gotoRowCol(r + 6, c);
	SetClr(clrsp);
	cout << "    ";
	SetClr(clr);
	for (int i = 1; i <= 2; i++) {
		cout << sym;
	}
	gotoRowCol(r + 7, c);
	SetClr(clrsp);
	cout << "   ";
	SetClr(clr);
	for (int i = 1; i <= 4; i++) {
		cout << sym;
	}
	gotoRowCol(r + 8, c);
	SetClr(clrsp);
	cout << "  ";
	SetClr(clr);
	for (int i = 1; i <= 6; i++) {
		cout << sym;
	}

}
void print_ss(char s, int r, int c, int clrsp) {
	int clr;
	if (s == 's' or s == '+')
		clr = 5;
	else if (s == '3')
	{
		clr = 3;
	}
	else if (s == 'd') {
		clr = 4;
	}
	else
		clr = 6;
	char sym = -37;
	gotoRowCol(r + 1, c);
	SetClr(clrsp);
	cout << "   ";
	SetClr(clr);
	for (int i = 1; i <= 4; i++) {
		cout << sym;
	}
	gotoRowCol(r + 2, c);
	SetClr(clrsp);
	cout << "  ";
	SetClr(clr);
	for (int i = 1; i <= 6; i++) {
		cout << sym;
	}
	gotoRowCol(r + 3, c);
	SetClr(clrsp);
	cout << " ";
	SetClr(clr);
	cout << sym;
	SetClr(clrsp);
	cout << " ";
	SetClr(clr);
	for (int i = 1; i <= 4; i++) {
		cout << sym;
	}
	SetClr(clrsp);
	cout << " ";
	SetClr(clr);
	cout << sym;
	gotoRowCol(r + 4, c);
	SetClr(clrsp);
	cout << " ";
	SetClr(clr);
	cout << sym;
	SetClr(clrsp);
	cout << "  ";
	SetClr(clr);
	cout << sym << sym;
	SetClr(clrsp);
	cout << "  ";
	SetClr(clr);
	cout << sym;
	gotoRowCol(r + 5, c);
	SetClr(clrsp);
	cout << "  ";
	SetClr(clr);
	cout << sym;
	SetClr(clrsp);
	cout << " ";
	SetClr(clr);
	cout << sym << sym;
	SetClr(clrsp);
	cout << " ";
	SetClr(clr);
	cout << sym;
	gotoRowCol(r + 6, c);
	SetClr(clrsp);
	cout << "    ";
	SetClr(clr);
	cout << sym << sym;
	gotoRowCol(r + 7, c);
	SetClr(clrsp);
	cout << "   ";
	SetClr(clr);
	for (int i = 1; i <= 4; i++) {
		cout << sym;
	}
	gotoRowCol(r + 8, c);
	SetClr(clrsp);
	cout << "  ";
	SetClr(clr);
	for (int i = 1; i <= 6; i++) {
		cout << sym;
	}

}
void printB(char** board, int dim) {
	system("cls");
	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++) {
			cout << setw(2) << board[i][j];
		}
		cout << endl;
	}
}
void printmsg(string name) {
	cout << name << "'s turn" << endl;
}
bool isBlackpiece(char sym) {
	if ((sym >= 'A' and sym <= 'Z') or (sym >= '!' and sym <= '&') or (sym >= '0' and sym <= '5'))
		return true;
	return false;
}
bool isWhitepiece(char sym) {
	if (((sym >= 'a' and sym <= 'z') or (sym >= '(' and sym <= '.')) and sym != '-')
		return true;
	return false;
}
bool isHoriantalMove(pos s, pos d) {
	return (s.r == d.r);
}
bool isVerticalMove(pos s, pos d) {
	return (s.c == d.c);
}
bool isDiagonalMove(pos s, pos d) {
	int r = abs(d.r - s.r);
	int c = abs(d.c - s.c);
	return r == c;
}
bool ismypiece(char sym, int turn) {
	if (turn == 0) {
		return isWhitepiece(sym);
	}
	return isBlackpiece(sym);
}
bool isValidSorce(char** b, pos s, int dim, int turn) {
	if (s.r < 0 or s.r >= dim or s.c < 0 or s.c >= dim)
		return false;
	if (!ismypiece(b[s.r][s.c], turn))
		return false;
	return true;
}
void mouseClick(pos& s, int rows, int cols) {
	int r, c;
	getRowColbyLeftClick(r, c);
	s.r = r / rows;
	s.c = c / cols;
}
bool isValidDest(char** b, char sym, pos d, int dim, int turn) {
	if (d.r < 0 or d.r >= dim or d.c < 0 or d.c >= dim)
		return false;
	if (ismypiece(b[d.r][d.c], turn))
		return false;
	return true;
}
bool isHorPathClr(char** b, pos s, pos d) {
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
		if (b[s.r][i] != '-')
			return false;
	}
	return true;
}
bool isVrtPathClr(char** b, pos s, pos d) {
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
		if (b[i][s.c] != '-')
			return false;
	}
	return true;
}
bool isD1PathClr(char** b, pos s, pos d) {
	if (s.r < d.r) {
		int t = d.r - s.r;
		for (int i = 1; i < t; i++) {
			if (b[s.r + i][s.c + i] != '-')
				return false;
		}
	}
	else {
		int t = s.r - d.r;
		for (int i = 1; i < t; i++) {
			if (b[s.r + i][s.c - i] != '-')
				return false;
		}
	}
	return true;
}
bool isD2PathClr(char** b, pos s, pos d) {
	if (s.r < d.r) {
		int t = d.r - s.r;
		for (int i = 1; i < t; i++) {
			if (b[s.r + i][s.c - i] != '-')
				return false;
		}
	}
	else {
		int t = s.r - d.r;
		for (int i = 1; i < t; i++) {
			if (b[s.r - i][s.c + i] != '-')
				return false;
		}
	}return true;
}
bool isD1move(pos s, pos d) {
	if (d.r > s.r and d.c > s.c)
		return true;
	if (s.r > d.r and s.c > d.c)
		return true;
	return false;
}
bool isD2Move(pos s, pos d) {
	if (d.r < s.r and d.c > s.c)
		return true;
	if (d.r > s.r and d.c < s.c)
		return true;
}
int steps(pos s, pos d) {
	if (isHoriantalMove(s, d)) {
		return (s.c - d.c);
	}
	else if (isVerticalMove(s, d) or isDiagonalMove(s, d)) {
		return (s.r - d.r);
	}
	return 0;
}
bool Lance(char** b, pos s, pos d) {
	if (((b[s.r][s.c] >= 'a' and b[s.r][s.c] <= 'z') or b[s.r][s.c] == ')' or b[s.r][s.c] == 'b') and steps(s, d) < 0) {
		return (isVerticalMove(s, d) and isVrtPathClr(b, s, d));
	}
	else if (((b[s.r][s.c] >= 'A' and b[s.r][s.c] <= 'Z') or b[s.r][s.c] == '"' or b[s.r][s.c] == '1') and
		steps(s, d) > 0) {
		return (isVerticalMove(s, d) and isVrtPathClr(b, s, d));
	}
	return false;
}
bool Bishop(char** b, pos s, pos d) {
	if (isD1move(s, d)) {
		return (isDiagonalMove(s, d) and isD1PathClr(b, s, d));
	}
	else if (isD2Move(s, d)) {
		return (isDiagonalMove(s, d) and isD2PathClr(b, s, d));
	}
	return false;
}
bool Rook(char** b, pos s, pos d) {
	if (isHoriantalMove(s, d)) {
		return isHorPathClr(b, s, d);
	}
	else if (isVerticalMove(s, d)) {
		return isVrtPathClr(b, s, d);
	}
	return false;
}
bool King(char** b, pos s, pos d) {
	if (abs(steps(s, d)) == 1) {
		return Rook(b, s, d) or Bishop(b, s, d);
	}
	return false;
}
bool Pown(char** b, pos s, pos d) {
	if (!isVerticalMove(s, d))
		return false;
	if (b[s.r][s.c] == 'p' or b[s.r][s.c] == '(' or b[s.r][s.c] == 'a') {
		if (steps(s, d) == -1)
			return true;
	}
	if (b[s.r][s.c] <= 'P' or b[s.r][s.c] == '!' or b[s.r][s.c] == '0') {
		if (steps(s, d) == 1)
			return true;
	}
	return false;
}
bool GoldGeneral(char** b, pos s, pos d) {
	if ((b[s.r][s.c] >= 'a' and b[s.r][s.c] <= 'z') or b[s.r][s.c] == 'a' or b[s.r][s.c] == 'd' or b[s.r][s.c] == 'j' or b[s.r][s.c] == 'c') {
		if (isDiagonalMove(s, d) and steps(s, d) == 1)
			return false;
	}
	if (b[s.r][s.c] >= 'A' and b[s.r][s.c] <= 'Z' or b[s.r][s.c] == '0' or b[s.r][s.c] == '3' or b[s.r][s.c] == '1' or b[s.r][s.c] == '2') {
		if (isDiagonalMove(s, d) and steps(s, d) == -1)
			return false;
	}
	return King(b, s, d);
}
bool SilverGeneral(char** b, pos s, pos d) {
	if (isHoriantalMove(s, d))
		return false;
	if ((b[s.r][s.c] >= 'a' and b[s.r][s.c] <= 'z') or b[s.r][s.c] == '+' or b[s.r][s.c] == 'd') {
		if (isVerticalMove(s, d) and steps(s, d) == 1)
			return false;
	}
	if ((b[s.r][s.c] >= 'A' and b[s.r][s.c] <= 'Z') or b[s.r][s.c] == '$' or b[s.r][s.c] == '3') {
		if (isVerticalMove(s, d) and steps(s, d) == -1)
			return false;
	}
	return King(b, s, d);
}
bool Knight(char** b, pos s, pos d) {
	int r = d.r - s.r;
	int c = d.c - s.c;
	if (((b[s.r][s.c] >= 'a' and b[s.r][s.c] <= 'z') or b[s.r][s.c] == '*' or b[s.r][s.c] == 'c') and r == 2 and
		abs(c) == 1) {
		return true;
	}
	if (((b[s.r][s.c] >= 'A' and b[s.r][s.c] <= 'Z') or b[s.r][s.c] == '#' or b[s.r][s.c] == '2') and r == -2 and
		abs(c) == 1) {
		return true;
	}
	return false;
}
bool isValidMove(char** b, pos s, pos d) {
	switch (b[s.r][s.c]) {
	case '"':
	case ')':
	case 'l':
	case 'L':
		return Lance(b, s, d);

	case '&':
	case '.':
	case 'b':
	case 'B':
		return Bishop(b, s, d);

	case '%':
	case ',':
	case 'r':
	case 'R':
		return Rook(b, s, d);

	case 'k':
	case 'K':
		return King(b, s, d);

	case '!':
	case '(':
	case 'p':
	case 'P':
		return Pown(b, s, d);

	case 'g':
	case 'G':
		return GoldGeneral(b, s, d);

	case '$':
	case '+':
	case 's':
	case 'S':
		return SilverGeneral(b, s, d);

	case '*':
	case '#':
	case 'n':
	case 'N':
		return Knight(b, s, d);

	case '0':
	case 'a':
		return GoldGeneral(b, s, d);
	case '1':
	case 'j':
		return GoldGeneral(b, s, d);
	case '2':
	case 'c':
		return GoldGeneral(b, s, d);
	case '3':
	case 'd':
		return GoldGeneral(b, s, d);
	case '4':
	case 'e':
		return King(b, s, d) or Rook(b, s, d);
	case '5':
	case 'f':
		return King(b, s, d) or Bishop(b, s, d);
	}
	return false;
}
void selectPos(pos& s) {
	SetClr(15);
	char sy; int sr;
	cin >> sy >> sr;
	s.c = sy - 'A';
	sr--;
	s.r = sr;
}
void UpdateB(char** b, pos s, pos d) {
	char sym = b[s.r][s.c];
	b[s.r][s.c] = '-';
	b[d.r][d.c] = sym;
}
int changeTurn(int turn) {
	turn++;
	turn = turn % 2;
	return turn;
}
void printBox(int sr, int sc, int rows, int cols, int clr, char sym, int clr2) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			gotoRowCol(sr + i, sc + j);
			SetClr(clr);
			cout << char(-37);
		}
	}
	SetClr(clr2);
	if (sym == 'p' or sym == 'P' or sym == '!' or sym == '(' or sym == '0' or sym == 'a')
		print_P(sym, sr, sc, clr2);
	else if (sym == 'r' or sym == 'R' or sym == '%' or sym == ',' or sym == '4' or sym == 'e') {
		print_Rook(sym, sr, sc, clr2);
	}
	else if (sym == 'k' or sym == 'K') {
		print_King(sym, sr, sc, clr2);
	}
	else if (sym == 'b' or sym == 'B' or sym == '&' or sym == '.' or sym == 'f' or sym == '5') {
		print_bishop(sym, sr, sc, clr2);
	}
	else if (sym == 'n' or sym == 'N' or sym == '*' or sym == '#' or sym == '2' or sym == 'c') {
		print_Knight(sym, sr, sc, clr2);
	}
	else if (sym == 'l' or sym == 'L' or sym == ')' or sym == '"' or sym == 'j' or sym == '1') {
		print_lance(sym, sr, sc, clr2);
	}
	else if (sym == 'g' or sym == 'G')
		print_GG(sym, sr, sc, clr2);
	else if (sym == 's' or sym == 'S' or sym == '+' or sym == '$' or sym == '3' or sym == 'd')
		print_ss(sym, sr, sc, clr2);
	else {
		gotoRowCol(sr + rows / 2, sc + cols / 2);
		if (sym != '-')
			cout << sym;
	}
}
void printgrid(char** b, int dim, int rows, int cols) {
	SetClr(0);
	system("cls");
	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++) {
			if ((i + j) % 2 == 0)
				printBox(i * rows, j * cols, rows, cols, 15, b[i][j], 240);
			else
				printBox(i * rows, j * cols, rows, cols, 8, b[i][j], 128);
		}
	}
}
void print1cell(char** b, pos s, int rows, int cols) {
	if ((s.r + s.c) % 2 == 0)
		printBox(s.r * rows, s.c * cols, rows, cols, 15, b[s.r][s.c], 240);
	else
		printBox(s.r * rows, s.c * cols, rows, cols, 8, b[s.r][s.c], 128);
}
pos findKing(char** b, int dim, int turn) {
	pos k;
	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++) {
			if (turn == 0 and b[i][j] == 'k') {
				k.r = i;
				k.c = j;
				return k;
			}
			else if (b[i][j] == 'K') {
				k.r = i;
				k.c = j;
				return k;
			}
		}
	}
}
bool check(char** b, int dim, int turn) {
	turn = changeTurn(turn);
	pos d = findKing(b, dim, turn);
	turn = changeTurn(turn);
	pos s;
	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++) {
			s.r = i;
			s.c = j;
			if (isValidSorce(b, s, dim, turn) and isValidDest(b, b[s.r][s.c], d, dim, turn) and isValidMove(b, s, d)) {
				return true;
			}
		}
	}
	return false;
}
bool** canMove(char** b, pos s, int dim, int turn) {
	bool** M;
	M = new bool* [dim];
	for (int i = 0; i < dim; i++) {
		M[i] = new bool[dim] {false};
	}
	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++) {
			pos d;
			d.r = i;
			d.c = j;
			if (isValidMove(b, s, d) and isValidDest(b, b[s.r][s.c], d, dim, turn) and isValidSorce(b, s, dim, turn))
				M[i][j] = true;

		}
	}
	return M;
}
void drawBox(int r, int c, int boxDim) {
	for (int i = c; i < c + boxDim; i++) {
		gotoRowCol(r, i);
		SetClr(4);
		cout << char(-37);
	}
	c = c + boxDim - 1;
	for (int i = r; i < r + boxDim; i++) {
		gotoRowCol(i, c);
		SetClr(4);
		cout << char(-37);
	}
	r = r + boxDim - 1;
	for (int i = c - 1; i > c - boxDim; i--) {
		gotoRowCol(r, i);
		SetClr(4);
		cout << char(-37);
	}
	c = c - boxDim + 1;
	for (int i = r - 1; i > r - boxDim; i--) {
		gotoRowCol(i, c);
		SetClr(4);
		cout << char(-37);
	}
}
void eraseBox(int r, int c, int boxDim, int clr) {
	for (int i = c; i < c + boxDim; i++) {
		gotoRowCol(r, i);
		SetClr(clr);
		cout << char(-37);
	}
	c = c + boxDim - 1;
	for (int i = r; i < r + boxDim; i++) {
		gotoRowCol(i, c);
		SetClr(clr);
		cout << char(-37);
	}
	r = r + boxDim - 1;
	for (int i = c - 1; i > c - boxDim; i--) {
		gotoRowCol(r, i);
		SetClr(clr);
		cout << char(-37);
	}
	c = c - boxDim + 1;
	for (int i = r - 1; i > r - boxDim; i--) {
		gotoRowCol(i, c);
		SetClr(clr);
		cout << char(-37);
	}
}
void highLight(bool** M, pos s, int dim, int boxDim) {
	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++) {
			if (M[i][j]) {
				int r = i * boxDim, c = j * boxDim;
				drawBox(r, c, boxDim);
			}
		}
	}
}
void unhighLight(bool** M, pos s, int dim, int boxDim) {
	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++) {
			if (M[i][j] and (i + j) % 2 == 0) {
				int r = i * boxDim, c = j * boxDim;
				eraseBox(r, c, boxDim, 15);
			}
			else if (M[i][j] and (i + j) % 2 != 0) {
				int r = i * boxDim, c = j * boxDim;
				eraseBox(r, c, boxDim, 8);
			}
		}
	}
}
void fakeboardinit(char**& fb, char** b, int dim) {
	fb = new char* [dim];
	for (int i = 0; i < dim; i++) {
		fb[i] = new char[dim];
	}
	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++) {
			fb[i][j] = b[i][j];
		}
	}
}
void FakeUpdateB(char** b, pos s, pos d) {
	char sym = b[s.r][s.c];
	b[s.r][s.c] = '-';
	b[d.r][d.c] = sym;
}
bool canBePromoted(char** b, char sym, pos d) {

	if (sym == 'K' or sym == 'k' or sym == 'g' or sym == 'G')
		return false;
	if (sym >= '0' and sym <= '5')
		return false;
	if ((sym >= 'a' and sym <= 'j') and sym != 'b')
		return false;
	if (sym >= 'a' and sym <= 'z') {
		if (d.r >= 6)
			return true;
	}
	if (sym >= '(' and sym <= '.' and sym != '-') {
		if (d.r < 6)
			return true;
	}
	if (sym >= 'A' and sym <= 'Z') {
		if (d.r <= 2)
			return true;
	}
	if (sym >= '!' and sym <= '&') {
		if (d.r > 2)
			return true;
	}
	return false;
}
void tempPromote(char** b, pos d) {
	char sym = b[d.r][d.c];
	switch (sym) {
	case 'P': {
		b[d.r][d.c] = '!';
		break;
	}
	case 'L': {
		b[d.r][d.c] = '"';
		break;
	}
	case 'N': {
		b[d.r][d.c] = '#';
		break;
	}
	case 'S': {
		b[d.r][d.c] = '$';
		break;
	}
	case 'R': {
		b[d.r][d.c] = '%';
		break;
	}
	case 'B': {
		b[d.r][d.c] = '&';
		break;
	}
	case 'p': {
		b[d.r][d.c] = '(';
		break;
	}
	case 'l': {
		b[d.r][d.c] = ')';
		break;
	}
	case 'n': {
		b[d.r][d.c] = '*';
		break;
	}
	case 's': {
		b[d.r][d.c] = '+';
		break;
	}
	case 'r': {
		b[d.r][d.c] = ',';
		break;
	}
	case 'b': {
		b[d.r][d.c] = '.';
		break;
	}
	case '!': {
		b[d.r][d.c] = 'P';
		break;
	}
	case '"': {
		b[d.r][d.c] = 'L';
		break;
	}
	case '#': {
		b[d.r][d.c] = 'N';
		break;
	}
	case '$': {
		b[d.r][d.c] = 'S';
		break;
	}
	case '%': {
		b[d.r][d.c] = 'R';
		break;
	}
	case '&': {
		b[d.r][d.c] = 'B';
		break;
	}
	case '(': {
		b[d.r][d.c] = 'p';
		break;
	}
	case ')': {
		b[d.r][d.c] = 'l';
		break;
	}
	case '*': {
		b[d.r][d.c] = 'n';
		break;
	}
	case '+': {
		b[d.r][d.c] = 's';
		break;
	}
	case ',': {
		b[d.r][d.c] = 'r';
		break;
	}
	case '.': {
		b[d.r][d.c] = 'b';
		break;
	}
	}
}
void promote(char**& b, pos d) {
	char sym = b[d.r][d.c];
	switch (sym) {
	case 'P': {
		b[d.r][d.c] = '0';
		break;
	}
	case 'L': {
		b[d.r][d.c] = '1';
		break;
	}
	case 'N': {
		b[d.r][d.c] = '2';
		break;
	}
	case 'S': {
		b[d.r][d.c] = '3';
		break;
	}
	case 'R': {
		b[d.r][d.c] = '4';
		break;
	}
	case 'B': {
		b[d.r][d.c] = '5';
		break;
	}
	case 'p': {
		b[d.r][d.c] = 'a';
		break;
	}
	case 'l': {
		b[d.r][d.c] = 'j';
		break;
	}
	case 'n': {
		b[d.r][d.c] = 'c';
		break;
	}
	case 's': {
		b[d.r][d.c] = 'd';
		break;
	}
	case 'r': {
		b[d.r][d.c] = 'e';
		break;
	}
	case 'b': {
		b[d.r][d.c] = 'f';
		break;
	}
	}
}
bool selfCheck(char** b, int dim, int turn) {
	pos d = findKing(b, dim, turn);
	turn = changeTurn(turn);
	pos s;
	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++) {
			s.r = i;
			s.c = j;
			if (isValidSorce(b, s, dim, turn) and isValidDest(b, b[s.r][s.c], d, dim, turn) and isValidMove(b, s, d)) {
				return true;
			}
		}
	}
	return false;
}
void printsave(int sr, int sc, int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			gotoRowCol(sr + i, sc + j);
			SetClr(14);
			cout << char(-37);
		}
	}
	gotoRowCol(sr + (sr / 2), sc + 3);
	SetClr(239);
	cout << "Save";
}
void printload(int sr, int sc, int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			gotoRowCol(sr + i, sc + j);
			SetClr(2);
			cout << char(-37);
		}
	}
	gotoRowCol(sr + 5, sc + 3);
	SetClr(47);
	cout << "Load";
}
void printNew(int sr, int sc, int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			gotoRowCol(sr + i, sc + j);
			SetClr(14);
			cout << char(-37);
		}
	}
	gotoRowCol(sr + 5, sc + 4);
	SetClr(239);
	cout << "New";
}
bool doSave(pos s) {
	if (s.r == 1 and s.c == 14)
		return true;
	else
		return false;
}
void save(char** b, int dim, int turn, cap p1[], cap p2[]) {
	ofstream save("BSCS22077-load.txt");

	save << dim << " " << turn << endl;
	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++) {
			save << b[i][j];
		}
		save << endl;
	}
	for (int i = 0; i < 7; i++)
	{
		if (p1[i].c == 0)
		{
			save << '-';
		}
		for (int j = 1; j <= p1[i].c; j++)
		{
			save << p1[i].p;
		}
	}
	save << endl;
	for (int i = 0; i < 7; i++)
	{
		if (p2[i].c == 0)
		{
			save << '-';
		}
		for (int j = 1; j <= p2[i].c; j++)
		{
			save << p2[i].p;
		}
	}

}
void Load(char**& b, int& dim, int& turn, cap p1[], cap p2[]) {
	ifstream load("savegame.txt");
	load >> dim;
	load >> turn;
	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++) {
			load >> b[i][j];
		}
	}
	char sym;
	load >> sym;
	char c1 = sym;
	for (int i = 0; i < 7; i++)
	{

		if (c1 >= 'a' and c1 <= 'z') {
			for (int j = 0; j < 7; j++)
			{
				if (c1 == p1[j].p)
				{
					p1[j].c++;
				}
			}
		}
		load >> c1;
		if (c1 == sym and sym != '-')
			i--;
		sym = c1;
	}
	for (int i = 0; i < 7; i++)
	{
		if (c1 >= 'A' and c1 <= 'Z')
		{
			for (int j = 0; j < 7; j++)
			{
				if (c1 == p2[j].p)
				{
					p2[j].c++;
				}
			}
		}
		load >> c1;
		if (c1 == sym and sym != '-')
		{
			i--;
		}
		sym = c1;
	}

}
bool doLoad(pos s, char**& b, int& dim, int& turn, string pnames[], cap p1[], cap p2[]) {
	if (s.r == 5 and s.c == 5) {
		init(b, dim, turn, pnames);
		return true;
	}
	else if (s.r == 5 and s.c == 9) {
		init(b, dim, turn, pnames);
		Load(b, dim, turn, p1, p2);
		return true;
	}
	else return false;
}
void initcapArr(cap p1[], cap p2[]) {
	p1[0].p = 'p';
	p1[1].p = 'l';
	p1[2].p = 'n';
	p1[3].p = 's';
	p1[4].p = 'g';
	p1[5].p = 'r';
	p1[6].p = 'b';
	p2[0].p = 'P';
	p2[1].p = 'L';
	p2[2].p = 'N';
	p2[3].p = 'S';
	p2[4].p = 'G';
	p2[5].p = 'R';
	p2[6].p = 'B';

}
void printCapturedPieces(cap p1[], cap p2[], int boxd) {
	for (int i = 0; i < 7; i++) {
		printBox(4 * boxd, (11 + i) * boxd, 10, 10, 15, p1[i].p, 240);
		gotoRowCol((5 * boxd) + 1, ((11 + i) * boxd) + 5);
		SetClr(15);
		cout << p1[i].c;
	}
	for (int i = 0; i < 7; i++) {
		printBox(7 * boxd, (11 + i) * boxd, 10, 10, 15, p2[i].p, 240);
		gotoRowCol((8 * boxd) + 1, ((11 + i) * boxd) + 5);
		SetClr(15);
		cout << p2[i].c;
	}
}
bool didCapture(char** b, pos d) {
	if (b[d.r][d.c] != '-') {
		return true;
	}
	else return false;
}
void unpromote(char& sym) {
	switch (sym) {
	case'0':
	case'!': {
		sym = 'P';
		break;
	}
	case '1':
	case'"': {
		sym = 'L';
		break;
	}
	case '2':
	case'#': {
		sym = 'N';
		break;
	}
	case '3':
	case'$': {
		sym = 'S';
		break;
	}
	case '4':
	case'%': {
		sym = 'R';
		break;
	}
	case '5':
	case'&': {
		sym = 'B';
		break;
	}
	case 'a':
	case'(': {
		sym = 'p';
		break;
	}
	case 'j':
	case')': {
		sym = 'l';
		break;
	}
	case 'c':
	case'*': {
		sym = 'n';
		break;
	}
	case 'd':
	case'+': {
		sym = 's';
		break;
	}
	case 'e':
	case',': {
		sym = 'r';
		break;
	}
	case 'f':
	case'.': {
		sym = 'b';
		break;
	}
	}
}
void capture(cap p1[], cap p2[], char sym, pos d, int turn) {
	unpromote(sym);
	if (sym >= 'a' and sym <= 'z')
		sym = toupper(sym);
	else
		sym = tolower(sym);
	if (turn == 0) {
		for (int i = 0; i < 7; i++) {
			if (sym == p1[i].p) {
				p1[i].c++;
				return;
			}
		}
	}
	else {
		for (int i = 0; i < 7; i++) {
			if (sym == p2[i].p) {
				p2[i].c++;
				return;
			}
		}
	}
}
bool doWnatToDrop(pos d, int turn) {
	if (turn == 0) {
		if (d.r == 4 and (d.c >= 11 and d.c <= 11 + 6))
			return true;
	}
	else if (turn == 1) {
		if (d.r == 7 and (d.c >= 11 and d.c <= 11 + 6))
			return true;
	}
	return false;
}
bool isCheckMate(char** b, int turn, int dim) {
	turn = changeTurn(turn);
	char** fkarr;
	bool** M;
	pos s;
	pos d;
	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++) {
			s.r = i;
			s.c = j;
			if (isValidSorce(b, s, dim, turn)) {
				M = canMove(b, s, dim, turn);
				for (int m = 0; m < dim; m++) {
					for (int n = 0; n < dim; n++) {
						fakeboardinit(fkarr, b, dim);
						if (M[m][n]) {
							d.r = m;
							d.c = n;
							FakeUpdateB(fkarr, s, d);
							if (!selfCheck(fkarr, dim, turn))
								return false;
						}
					}
				}
			}
		}
	}
	return true;
}
bool canDrop(char** b, char sym, pos d, int dim, int turn, cap p1[], cap p2[]) {
	if (turn == 0) {
		for (int i = 0; i < 7; i++) {
			if (sym == p1[i].p)
				if (p1[i].c == 0)
					return false;
		}
	}
	if (turn == 1) {
		for (int i = 0; i < 7; i++) {
			if (sym == p2[i].p)
				if (p2[i].c == 0)
					return false;
		}
	}
	if (b[d.r][d.c] != '-')
		return false;
	if (sym == 'p' or sym == 'P') {
		for (int i = 0; i < dim; i++) {
			if (b[i][d.c] == sym) {
				return false;
			}
		}

	}
	if (sym == 'p' or sym == 'l') {
		if (d.r == 8)
			return false;
	}
	if (sym == 'n') {
		if (d.r >= 7)
			return false;
	}
	if (sym == 'P' or sym == 'L') {
		if (d.r == 0)
			return false;
	}
	if (sym == 'N') {
		if (d.r <= 1)
			return false;
	}
	return true;
}
bool** allPossiblePositions(char** b, char sym, int dim, int turn, cap p1[], cap p2[]) {
	pos d;
	bool** posible;
	posible = new bool* [dim];
	for (int i = 0; i < dim; i++) {
		posible[i] = new bool[dim] {false};
	}
	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++) {
			d.r = i;
			d.c = j;
			if (canDrop(b, sym, d, dim, turn, p1, p2)) {
				posible[i][j] = true;
			}
		}
	}
	return posible;
}
char whichsym(pos s) {
	if (s.r == 4) {
		if (s.c == 11)
			return 'p';
		else if (s.c == 12)
			return 'l';
		else if (s.c == 13)
			return 'n';
		else if (s.c == 14)
			return 's';
		else if (s.c == 15)
			return 'g';
		else if (s.c == 16)
			return 'r';
		else if (s.c == 17)
			return 'b';
	}
	else if (s.r == 7) {
		if (s.c == 11)
			return 'P';
		else if (s.c == 12)
			return 'L';
		else if (s.c == 13)
			return 'N';
		else if (s.c == 14)
			return 'S';
		else if (s.c == 15)
			return 'G';
		else if (s.c == 16)
			return 'R';
		else if (s.c == 17)
			return 'B';
	}
	return '\0';
}
void highlightDrop(char** b, char sym, int dim, bool** posible) {
	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++) {
			if (posible[i][j])
				drawBox(i * 10, j * 10, 10);
		}
	}
}
void unhilte(char** b, char sym, int dim, bool** posible) {
	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++) {
			if (posible[i][j] and (i + j) % 2 == 0) {
				int r = i * 10, c = j * 10;
				eraseBox(r, c, 10, 15);
			}
			else if (posible[i][j] and (i + j) % 2 != 0) {
				int r = i * 10, c = j * 10;
				eraseBox(r, c, 10, 8);
			}
		}
	}
}
void drop(char**& b, char sym, pos d, cap p1[], cap p2[]) {
	b[d.r][d.c] = sym;
	if (sym >= 'a' and sym >= 'z')
	{
		for (int i = 0; i < 7; i++)
		{
			if (p1[i].p == sym)
			{
				p1[i].c--;
			}

		}
	}
	if (sym >= 'A' and sym >= 'Z')
	{
		for (int i = 0; i < 7; i++)
		{
			if (p2[i].p == sym)
			{
				p2[i].c--;
			}

		}
	}
}

int main() {
	int boxd = 10;
	char** b;
	int dim, turn;
	string Pnames[2];
	pos src;
	pos des;
	pos lod;
	bool** M;
	pos d;
	char** fb;
	cap p1[7];
	cap p2[7];
	bool** p = new bool* [10];
	char dsym;
	initcapArr(p1, p2);
	printNew(5 * boxd, 5 * boxd, 10, 10);
	printload(5 * boxd, 9 * boxd, 10, 10);
	bool drp = false;
	SetClr(0);
	do {
		mouseClick(lod, 10, 10);
	} while (!doLoad(lod, b, dim, turn, Pnames, p1, p2));
	system("cls");
	printgrid(b, dim, boxd, boxd);
	printsave(boxd, 14 * boxd, 10, 10);
	printCapturedPieces(p1, p2, boxd);
	while (true) {
		SetClr(15);
		gotoRowCol(rows - 1, 0);
		printmsg(Pnames[turn]);
		do {
			do {
				fakeboardinit(fb, b, dim);
				mouseClick(src, boxd, boxd);
				if (doSave(src)) {
					gotoRowCol(rows - 20, cols - 50);
					cout << "Saved";
					save(b, dim, turn, p1, p2);
				}
				gotoRowCol(rows - 1, 0);
				cout << "Selected " << char(src.c + 'A') << src.r << endl;
				if (doWnatToDrop(src, turn)) {
					dsym = whichsym(src);
					p = allPossiblePositions(b, dsym, dim, turn, p1, p2);
					highlightDrop(b, dsym, dim, p);
					drp = true;
				}
				M = canMove(b, src, dim, turn);
				if (!drp)
					highLight(M, src, dim, boxd);
			} while (!isValidSorce(b, src, dim, turn) and !drp);
			mouseClick(des, boxd, boxd);
			if (drp and canDrop(b, dsym, des, dim, turn, p1, p2)) {
				drop(b, dsym, des, p1, p2);
				unhilte(b, dsym, dim, p);
				print1cell(b, src, boxd, boxd);
				print1cell(b, des, boxd, boxd);
			}
			unhighLight(M, src, dim, boxd);
			SetClr(15);
			if (isValidDest(b, b[src.r][src.c], des, dim, turn) and isValidMove(b, src, des)) {
				if (canBePromoted(b, b[src.r][src.c], des)) {
					char ans;
					gotoRowCol(rows - 2, 10);
					cout << "Do you want to promote: ";
					cin >> ans;
					if (ans == 'y') {
						promote(b, src);
					}
					else {
						tempPromote(b, src);
					}
				}
			}

			FakeUpdateB(fb, src, des);
			if (drp)
			{
				break;
			}
		} while (!isValidDest(b, b[src.r][src.c], des, dim, turn) or !isValidMove(b, src, des) or selfCheck(fb, dim, turn));
		
		if (isCheckMate(b, turn, dim)) {
			UpdateB(b, src, des);
			print1cell(b, des, boxd, boxd);
			gotoRowCol(rows - 15, cols - 50);
			cout << "check mate....";
			exit(0);
		}
		if (didCapture(b, des)) {
			capture(p1, p2, b[des.r][des.c], des, turn);
			printCapturedPieces(p1, p2, boxd);

		}
		if (!drp)
			UpdateB(b, src, des);
		if (check(b, dim, turn)) {
			gotoRowCol(rows - 3, 0);
			cout << "Check" << endl;
		}
		if (!drp)
		{
			print1cell(b, src, boxd, boxd);
			print1cell(b, des, boxd, boxd);
		}
		drp = false;
		turn = changeTurn(turn);
	}
	// ----
	return _getch();
}