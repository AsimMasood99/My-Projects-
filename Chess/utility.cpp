#include"utility.h"

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

void drawBox(int r, int c, int boxDim) {
	for (int i = c; i < c + boxDim; i++) {
		gotoRowCol(r, i);
		SetClr(9);
		cout << char(-37);
	}
	c = c + boxDim - 1;
	for (int i = r; i < r + boxDim; i++) {
		gotoRowCol(i, c);
		SetClr(9);
		cout << char(-37);
	}
	r = r + boxDim - 1;
	for (int i = c - 1; i > c - boxDim; i--) {
		gotoRowCol(r, i);
		SetClr(9);
		cout << char(-37);
	}
	c = c - boxDim + 1;
	for (int i = r - 1; i > r - boxDim; i--) {
		gotoRowCol(i, c);
		SetClr(9);
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
