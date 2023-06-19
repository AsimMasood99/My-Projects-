#include <iostream>
#include <cmath>
#include <fstream>
#include<Windows.h>
const int cols = 150;
const int rows = 100;
using namespace std;
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
void SetClr(int clr)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), clr);
}
void printCircle(int h, int k, int r, char sym = -37) {
	for (int th = 0; th < 360; th++) {
		float rad = th * 3.14 / 180;
		int x = ceil(r * cos(rad)) + h;
		int y = ceil(r * sin(rad)) + k;
		gotoRowCol(y, x);
		if (x < cols and x>0 and y < rows and y>0) {
			cout << sym;
		}
	}
}
void bubbling1(int Point[10][2], int rad) {
	system("cls");
	while (true) {
		for (int i = 0; i < 10; i++) {
			for (int r = 0; r <= rad; r++) {
				printCircle(Point[i][0], Point[i][1], r);
				Sleep(20);
				printCircle(Point[i][0], Point[i][1], r, ' ');
			}
			for (int r = rad; r >= 0; r--) {
				printCircle(Point[i][0], Point[i][1], r);
				Sleep(20);
				printCircle(Point[i][0], Point[i][1], r, ' ');
			}
		}
	}
}
void bubbling2(int Point[10][2], int rad) {
	system("cls");
	for (int r = 0; r <= rad; r++) {
		for (int i = 0; i < 10; i++) {
			printCircle(Point[i][0], Point[i][1], r);
		}
		Sleep(30);
		for (int i = 0; i < 10; i++) {
			printCircle(Point[i][0], Point[i][1], r, ' ');
		}
	}
	for (int r = rad; r >= 0; r--) {
		for (int i = 0; i < 10; i++) {
			printCircle(Point[i][0], Point[i][1], r);
		}
		Sleep(30);
		for (int i = 0; i < 10; i++) {
			printCircle(Point[i][0], Point[i][1], r, ' ');
		}
	}
}
int minRad(int arr[10][3], int c) {
	int min = arr[0][c];
	for (int i = 1; i < 10; i++) {
		if (arr[i][c] < min)
			min = arr[i][c];
	}
	return min;
}
int minRad1(int arr[10][4], int c) {
	int min = arr[0][c];
	for (int i = 1; i < 10; i++) {
		if (arr[i][c] < min)
			min = arr[i][c];
	}
	return min;
}
void bubbling3() {
	system("cls");
	while (true) {
		int arr[10][3]; int i = 0;
		for (int i = 0; i < 10; i++) {
			int r = (rand() % 20) + 5;
			int y = rand() % (rows - (r));
			int x = rand() % (cols - (r));
			arr[i][2] = r;
			arr[i][0] = x;
			arr[i][1] = y;
		}
		int min = minRad(arr, 2);
		int delta[10];
		for (int i = 0; i < 10; i++) {
			delta[i] = arr[i][2] / min;
		}
		int radii[10] = {};
		for (int i = 0; i < min; i++) {
			for (int i = 0; i < 10; i++) {
				printCircle(arr[i][0], arr[i][1], radii[i]);
			}
			Sleep(50);
			for (int i = 0; i < 10; i++) {
				printCircle(arr[i][0], arr[i][1], radii[i], ' ');
				radii[i] += delta[i];
			}
		}
	}
}
void bubbling4() {
	system("cls");
	while (true) {
		int arr[10][4]; int i = 0;
		for (int i = 0; i < 10; i++) {
			int sr = (rand() % 5) + 5;
			int er = (rand() % 25) + 5;
			int y = rand() % (rows - (er));
			int x = rand() % (cols - (er));
			arr[i][2] = sr;
			arr[i][3] = er;
			arr[i][0] = x;
			arr[i][1] = y;
		}
		int min = minRad1(arr, 3);
		int delta[10];
		for (int i = 0; i < 10; i++) {
			delta[i] = arr[i][2] / min;
		}
		int radii[10] = {};
		for (int i = 0; i < 10; i++) {
			radii[i] = arr[i][2];
		}
		for (int i = 0; i < min; i++) {
			for (int i = 0; i < 10; i++) {
				printCircle(arr[i][0], arr[i][1], radii[i]);
			}
			Sleep(50);
			for (int i = 0; i < 10; i++) {
				printCircle(arr[i][0], arr[i][1], radii[i], ' ');
				radii[i] += delta[i];
			}
		}
	}
}
int main()
{
	int choice;
	cout << "1. Bubbling Pattern 1\n"
		"Bubbing Pattern 2\n"
		"Bubbling Pattern 3\n"
		"Enter Choice: ";
	cin >> choice;
	switch (choice)
	{
	case 1: {
		int arr[10][2] = { {40,2},{27,6},{13,13},{26,16},{74,11},{42,10},{78,1},{6,2},{3,17},{3,17 } };
		bubbling1(arr, 10);
		break;
	}
	case 2: {
		int arr[10][2] = { {40,2},{27,6},{13,13},{26,16},{74,11},{42,10},{78,1},{6,2},{3,17},{3,17 } };
		bubbling2(arr, 10);
		break;
	}
	case 3: {
		bubbling3();
		break;
	}
	case 4: {
		bubbling4();
		break;
	}

	}

}