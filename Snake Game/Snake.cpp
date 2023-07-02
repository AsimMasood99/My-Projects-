#include <iostream>
#include <Windows.h>
#include<conio.h>
#include<ctime>
using namespace std;
const int rows = 80;
const int cols = 60;
enum direction { Up, Down, Left, Right };

struct pos {
	int r;
	int c;
};
struct snake {
	pos* sPos;
	int size;
	string name;
	direction dir;
	char sym;
	int clr;
	int score = 0;
};
void setclr(int clr)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), clr);
}
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
void SnakesPos(snake*& S, int nop) {
	for (int i = 0; i < nop; i++) {
		S[i].sPos = new pos[3];
	}
	switch (nop)
	{
	case 1: {
		S[0].sPos[0].r = 5;
		S[0].sPos[0].c = cols / 2;

		S[0].sPos[1].r = 5;
		S[0].sPos[1].c = cols / 2 - 1;

		S[0].sPos[2].r = 5;
		S[0].sPos[2].c = cols / 2 - 2;
		S[0].dir = Right;
		break;
	}
	case 2: {
		S[0].sPos[0].r = 5;
		S[0].sPos[0].c = cols / 2;

		S[0].sPos[1].r = 5;
		S[0].sPos[1].c = cols / 2 - 1;

		S[0].sPos[2].r = 5;
		S[0].sPos[2].c = cols / 2 - 2;
		S[0].dir = Right;

		S[1].sPos[0].r = 15;
		S[1].sPos[0].c = cols / 2;

		S[1].sPos[1].r = 15;
		S[1].sPos[1].c = cols / 2 - 1;

		S[1].sPos[2].r = 15;
		S[1].sPos[2].c = cols / 2 - 2;
		S[1].dir = Right;
		break;


	}
	case 3: {
		S[0].sPos[0].r = 5;
		S[0].sPos[0].c = cols / 2;

		S[0].sPos[1].r = 5;
		S[0].sPos[1].c = cols / 2 - 1;

		S[0].sPos[2].r = 5;
		S[0].sPos[2].c = cols / 2 - 2;
		S[0].dir = Right;

		S[1].sPos[0].r = 15;
		S[1].sPos[0].c = cols / 2;

		S[1].sPos[1].r = 15;
		S[1].sPos[1].c = cols / 2 - 1;

		S[1].sPos[2].r = 15;
		S[1].sPos[2].c = cols / 2 - 2;
		S[1].dir = Right;

		S[2].sPos[0].r = 75;
		S[2].sPos[0].c = cols / 2;

		S[2].sPos[1].r = 75;
		S[2].sPos[1].c = cols / 2 - 1;

		S[2].sPos[2].r = 75;
		S[2].sPos[2].c = cols / 2 - 2;
		S[2].dir = Right;
		break;

	}
	case 4: {
		S[0].sPos[0].r = 5;
		S[0].sPos[0].c = cols / 2;

		S[0].sPos[1].r = 5;
		S[0].sPos[1].c = cols / 2 - 1;

		S[0].sPos[2].r = 5;
		S[0].sPos[2].c = cols / 2 - 2;
		S[0].dir = Right;

		S[1].sPos[0].r = 15;
		S[1].sPos[0].c = cols / 2;

		S[1].sPos[1].r = 15;
		S[1].sPos[1].c = cols / 2 - 1;

		S[1].sPos[2].r = 15;
		S[1].sPos[2].c = cols / 2 - 2;
		S[1].dir = Right;

		S[2].sPos[0].r = 75;
		S[2].sPos[0].c = cols / 2;

		S[2].sPos[1].r = 75;
		S[2].sPos[1].c = cols / 2 - 1;

		S[2].sPos[2].r = 75;
		S[2].sPos[2].c = cols / 2 - 2;
		S[2].dir = Right;

		S[3].sPos[0].r = 65;
		S[3].sPos[0].c = cols / 2;

		S[3].sPos[1].r = 65;
		S[3].sPos[1].c = cols / 2 - 1;

		S[3].sPos[2].r = 65;
		S[3].sPos[2].c = cols / 2 - 2;
		S[3].dir = Right;
	}

	}

}
void init(snake*& S, int rows, int cols, int& nop) {
	gotoRowCol(40, 80);
	cout << "Enter no. of players: ";
	cin >> nop;
	S = new snake[nop];
	SnakesPos(S, nop);
	for (int i = 0; i < nop; i++) {
		S[i].size = 3;
		gotoRowCol((i * 2) + 43, 80);
		cout << "Enter name: ";
		cin >> S[i].name;
		S[i].sym = 'O';
		S[i].clr = 11 + i;
	}
}
void printBox(int sr, int sc, int rows, int cols, int clr, string msg, int clr2) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			gotoRowCol(sr + i, sc + j);
			setclr(clr);
			cout << char(-37);
		}
	}
	gotoRowCol(sr + 4, sc + 1);
	setclr((clr * 15) + clr2);
	cout << msg;
}
void printButtons() {
	system("cls");
	int dim = 10;
	printBox(1 * dim, 10 * dim, dim, dim, 3, "Level_1", 18);
	printBox(3 * dim, 10 * dim, dim, dim, 3, "Level_2", 18);
	printBox(5 * dim, 10 * dim, dim, dim, 3, "Level_3", 18);
	printBox(7 * dim, 10 * dim, dim, dim, 3, "Level_4", 18);
}
bool isVlaidClick(pos C) {
	if (C.c != 10)
		return false;
	if (C.r == 1 or C.r == 3 or C.r == 5 or C.r == 7)
		return true;
	return false;
}
void Click(pos& C) {
	int r, c;
	do {
		gotoRowCol(10, 80);
		cout << "Select a level: ";
		getRowColbyLeftClick(r, c);
		C.r = r / 10;
		C.c = c / 10;

	} while (!isVlaidClick(C));
}
void stage1() {
	setclr(4);
	for (int i = 20; i <= 40; i++) {
		gotoRowCol(20, i);
		cout << char(-37);
	}
	for (int i = 20; i <= 40; i++) {
		gotoRowCol(60, i);
		cout << char(-37);
	}
	setclr(15);
}
void stage2() {
	setclr(4);
	for (int i = 20; i <= 40; i++) {
		gotoRowCol(20, i);
		cout << char(-37);
	}
	for (int i = 20; i <= 40; i++) {
		gotoRowCol(60, i);
		cout << char(-37);
	}
	for (int i = 25; i <= 55; i++) {
		gotoRowCol(i, 30);
		cout << char(-37);
	}
	setclr(15);
}
void stage3() {
	setclr(4);
	for (int i = 10; i <= 22; i++) {
		gotoRowCol(20, i);
		cout << char(-37);
	}
	for (int i = 38; i <= 50; i++) {
		gotoRowCol(20, i);
		cout << char(-37);
	}
	for (int i = 10; i <= 22; i++) {
		gotoRowCol(60, i);
		cout << char(-37);
	}
	for (int i = 38; i <= 50; i++) {
		gotoRowCol(60, i);
		cout << char(-37);
	}
	for (int i = 20; i <= 40; i++) {
		gotoRowCol(40, i);
		cout << char(-37);
	}
	setclr(15);
}
void stage4() {
	setclr(4);
	gotoRowCol(2, 65);
	cout << "Earth is no more round. (CheckMate Round Earthers) ";
	for (int i = 10; i <= 22; i++) {
		gotoRowCol(20, i);
		cout << char(-37);
	}
	for (int i = 38; i <= 50; i++) {
		gotoRowCol(20, i);
		cout << char(-37);
	}
	for (int i = 10; i <= 22; i++) {
		gotoRowCol(60, i);
		cout << char(-37);
	}
	for (int i = 38; i <= 50; i++) {
		gotoRowCol(60, i);
		cout << char(-37);
	}
	for (int i = 25; i <= 55; i++) {
		gotoRowCol(i, 30);
		cout << char(-37);
	}
	setclr(15);
}
void printStage(pos C) {
	if (C.r == 1)
		stage1();
	else if (C.r == 3)
		stage2();
	else if (C.r == 5)
		stage3();
	else if (C.r == 7)
		stage4();
}
void printBoundry(int r, int c) {
	char sym = -37;
	setclr(4);
	for (int i = 0; i < cols; i++) {
		gotoRowCol(0, i);
		cout << sym;
	}
	for (int i = 0; i < cols; i++) {
		gotoRowCol(r, i);
		cout << sym;
	}
	for (int i = 0; i < rows; i++) {
		gotoRowCol(i, c - 1);
		cout << sym;
	}
	for (int i = 0; i < rows; i++) {
		gotoRowCol(i, 0);
		cout << sym;
	}
	setclr(15);

}
void printSnakes(snake* S, int nop) {
	for (int s = 0; s < nop; s++) {
		if (S[s].sPos != nullptr) {
			for (int i = 0; i < S[s].size; i++) {
				setclr(S[s].clr);
				gotoRowCol(S[s].sPos[i].r, S[s].sPos[i].c);
				cout << S[s].sym;
			}
		}
	}
}
void eraseSnake(snake* S, int nop) {
	for (int s = 0; s < nop; s++) {
		if (S[s].sPos != nullptr) {
			for (int i = 0; i < S[s].size; i++) {
				gotoRowCol(S[s].sPos[i].r, S[s].sPos[i].c);
				cout << ' ';
			}
		}
	}
}
void changeDirection(snake*& S, int keyPresed) {

	switch (keyPresed)
	{
	case 75:
		if (S[0].dir != Right)
			S[0].dir = Left;
		break;
	case 72:
		if (S[0].dir != Down)
			S[0].dir = Up;
		break;
	case 80:
		if (S[0].dir != Up)
			S[0].dir = Down;
		break;
	case 77:
		if (S[0].dir != Left)
			S[0].dir = Right;
		break;
		//-----------------------------
	case 97:
		if (S[1].dir != Right)
			S[1].dir = Left;
		break;
	case 119:
		if (S[1].dir != Down)
			S[1].dir = Up;
		break;
	case 115:
		if (S[1].dir != Up)
			S[1].dir = Down;
		break;
	case 100:
		if (S[1].dir != Left)
			S[1].dir = Right;
		break;
		// --------------------
	case 106:
		if (S[2].dir != Right)
			S[2].dir = Left;
		break;
	case 105:
		if (S[2].dir != Down)
			S[2].dir = Up;
		break;
	case 107:
		if (S[2].dir != Up)
			S[2].dir = Down;
		break;
	case 108:
		if (S[2].dir != Left)
			S[2].dir = Right;
		break;
		//------------------
	case 52:
		if (S[3].dir != Right)
			S[3].dir = Left;
		break;
	case 56:
		if (S[3].dir != Down)
			S[3].dir = Up;
		break;
	case 50:
		if (S[3].dir != Up)
			S[3].dir = Down;
		break;
	case 54:
		if (S[3].dir != Left)
			S[3].dir = Right;
		break;
	default:
		break;
	}
}
void move1step(snake S, int stage) {
	if (S.sPos == nullptr)
		return;
	for (int i = S.size - 1; i >= 1; i--) {
		S.sPos[i] = S.sPos[i - 1];
	}
	switch (S.dir) {
	case Up:
		S.sPos[0].r--;
		if (S.sPos[0].r == 0 and stage != 7)
			S.sPos[0].r = rows - 1;
		break;
	case Down:
		S.sPos[0].r++;
		if (S.sPos[0].r == rows and stage != 7)
			S.sPos[0].r = 1;
		break;
	case Left:
		S.sPos[0].c--;
		if (S.sPos[0].c == 0 and stage != 7)
			S.sPos[0].c = cols - 2;
		break;
	case Right:
		S.sPos[0].c++;
		if (S.sPos[0].c == cols - 1 and stage != 7)
			S.sPos[0].c = 1;
		break;
	}
}
bool isValidPlace(pos food, int stage) {
	switch (stage) {
	case 1: {
		if ((food.r == 20 or food.r == 60) and (food.c >= 20 and food.c <= 40))
			return false;
		break;
	}
	case 3: {
		if (food.c >= 20 and food.c <= 40 and (food.r == 20 or food.r == 60))
			return false;
		if (food.c == 30 and (food.r >= 25 and food.r <= 55))
			return false;
		break;
	}
	case 5: {
		if ((food.r == 20 or food.r == 60) and ((food.c >= 10 and food.c <= 22) or (food.c >= 38 and food.c <= 50)))
			return false;
		if (food.r == 40 and (food.c >= 25 and food.c <= 55))
			return false;
		break;
	}
	case 7: {
		if ((food.r == 20 or food.r == 60) and ((food.c >= 10 and food.c <= 22) or (food.c >= 38 and food.c <= 50)))
			return false;
		if (food.c == 30 and (food.r >= 25 and food.r <= 55))
			return false;
		break;
	}
	}
	return true;
}
void foodPlacer(pos& food, int Stage) {
	srand(time(0));
	do {
		food.r = (rand() % (rows - 2)) + 1;
		food.c = (rand() % (cols - 2)) + 1;
	} while (!isValidPlace(food, Stage));
	gotoRowCol(food.r, food.c);
	setclr(2);
	cout << char(-37);
}
void eraseFood(pos& food) {
	gotoRowCol(food.r, food.c);
	cout << " ";
}
bool didAte(snake* S, pos food, int nop, int& sNo) {
	for (int s = 0; s < nop; s++) {

		if (S[s].sPos != nullptr and S[s].sPos[0].r == food.r and S[s].sPos[0].c == food.c) {
			sNo = s;
			return true;
		}
	}
	return false;
}
void incSize(snake& S, int stage) {
	pos* newSnake = new pos[S.size + 1];
	int ri = S.sPos[S.size - 1].r;
	int ci = S.sPos[S.size - 1].c;
	move1step(S, stage);
	for (int i = 0; i < S.size; i++) {
		newSnake[i] = S.sPos[i];
	}
	newSnake[S.size].r = ri;
	newSnake[S.size].c = ci;

	S.size++;

	delete[]S.sPos;
	S.sPos = newSnake;
}
void printScore(snake* S, int n) {
	for (int i = 0; i < n; i++) {
		gotoRowCol(7 + (2 * i), cols + 5);
		cout << S[i].name << "'s Score: " << S[i].score << "    " << "Color: ";
		setclr(S[i].clr);
		cout << char(-37);
		setclr(15);
	}

}
bool didHitObstacle(snake S, int stage) {
	if (S.sPos == nullptr)
		return false;
	switch (stage) {
	case 1: {
		if ((S.sPos[0].r == 20 or S.sPos[0].r == 60) and (S.sPos[0].c >= 20 and S.sPos[0].c <= 40))
			return true;
		break;
	}
	case 3: {
		if (S.sPos[0].c >= 20 and S.sPos[0].c <= 40 and (S.sPos[0].r == 20 or S.sPos[0].r == 60))
			return true;
		if (S.sPos[0].c == 30 and (S.sPos[0].r >= 25 and S.sPos[0].r <= 55))
			return true;
		break;
	}
	case 5: {
		if ((S.sPos[0].r == 20 or S.sPos[0].r == 60) and ((S.sPos[0].c >= 10 and S.sPos[0].c <= 22) or (S.sPos[0].c >= 38 and S.sPos[0].c <= 50)))
			return true;
		if (S.sPos[0].r == 40 and (S.sPos[0].c >= 20 and S.sPos[0].c <= 40))
			return true;
		break;
	}
	case 7: {
		if ((S.sPos[0].r == 20 or S.sPos[0].r == 60) and ((S.sPos[0].c >= 10 and S.sPos[0].c <= 22) or (S.sPos[0].c >= 38 and S.sPos[0].c <= 50)))
			return true;
		if (S.sPos[0].c == 30 and (S.sPos[0].r >= 25 and S.sPos[0].r <= 55))
			return true;
		if (S.sPos[0].r == 0 or S.sPos[0].r == rows or S.sPos[0].c == 0 or S.sPos[0].c == 59)
			return true;
		break;
	}
	}
	return false;
}
bool isDead(snake* S, int nop, int& k, int stage) {
	bool isMySnake = false;
	for (int i = 0; i < nop; i++) {
		if (S[i].sPos == nullptr)
			continue;
		if (didHitObstacle(S[i], stage)) {
			k = i;
			return true;
		}
		for (int j = 0; j < nop; j++) {
			if (i == j)
				isMySnake = true;
			if (S[j].sPos == nullptr)
				continue;
			for (int s = 0; s < S[j].size; s++) {
				if (isMySnake) {
					isMySnake = false;
					continue;
				}
				if (S[i].sPos[0].r == S[j].sPos[s].r and S[i].sPos[0].c == S[j].sPos[s].c) {
					k = i;
					return true;
				}
			}
		}
	}
	return false;
}
void Normal()
{
	system("cls");
	snake* S;
	int nop;
	init(S, rows, cols, nop);
	printButtons();
	pos C;
	setclr(15);
	Click(C);
	system("cls");
	printBoundry(rows, cols);
	printStage(C);
	printScore(S, nop);
	pos food;
	char k;
	int sNo = 0;
	foodPlacer(food, C.r);
	int dedC = 0;
	while (true) {
		printSnakes(S, nop);
		if (_kbhit()) {
			k = _getch();
			if (k == -32) {
				k = _getch();
				changeDirection(S, k);
			}
			changeDirection(S, k);
		}
		Sleep(100);
		eraseSnake(S, nop);
		if (didAte(S, food, nop, sNo)) {
			incSize(S[sNo], C.r);
			foodPlacer(food, C.r);
			S[sNo].score++;
			setclr(15);
			gotoRowCol(4, cols + 5);
			printScore(S, nop);
		}

		int kn;
		if (isDead(S, nop, kn, C.r)) {
			if (nop == 1) {
				gotoRowCol(40, cols + 10);
				cout << "Game Over.";
				exit(0);
			}
			else {
				gotoRowCol(40, cols + 10);
				cout << S[kn].name << " is dead... :)";
				S[kn].sPos = nullptr;
				dedC++;
			}
		}
		if (dedC == nop) {
			gotoRowCol(40, cols + 10);
			cout << "Game Over.";
			exit(0);
		}
	}
}
void TimeBaseScore() {
	system("cls");
	gotoRowCol(40, 80);
	cout << "You have 30 Second to make 6 score.";
	Sleep(2000);
	system("cls");
	snake* S;
	int nop;
	init(S, rows, cols, nop);
	printButtons();
	pos C;
	setclr(15);
	Click(C);
	system("cls");
	printBoundry(rows, cols);
	printStage(C);
	printScore(S, nop);
	pos food;
	char k;
	int sNo = 0;
	foodPlacer(food, C.r);
	int dedC = 0;
	int start_t = time(0);
	while (true) {
		int end_t = time(0);
		setclr(15);
		gotoRowCol(5, 170);
		cout << "Timer: " << end_t - start_t << " sec";
		if (end_t - start_t == 30)
			exit(0);
		printSnakes(S, nop);
		if (_kbhit()) {
			k = _getch();
			if (k == -32) {
				k = _getch();
				changeDirection(S, k);
			}
			changeDirection(S, k);
		}
		Sleep(100);
		eraseSnake(S, nop);
		if (didAte(S, food, nop, sNo)) {
			incSize(S[sNo], C.r);
			foodPlacer(food, C.r);
			S[sNo].score++;
			setclr(15);
			gotoRowCol(4, cols + 5);
			printScore(S, nop);
		}
		for (int i = 0; i < nop; i++) {
			if (S[i].score == 2) {
				gotoRowCol(40, cols + 10);
				cout << S[i].name << " Wins";
				Sleep(1000);
				exit(0);
			}
		}
		for (int i = 0; i < nop; i++) {
			move1step(S[i], C.r);
		}
		int kn;
		if (isDead(S, nop, kn, C.r)) {
			if (nop == 1) {
				gotoRowCol(40, cols + 10);
				cout << "Game Over.";
				exit(0);
			}
			else {
				gotoRowCol(40, cols + 10);
				cout << S[kn].name << " is dead... :)";
				S[kn].sPos = nullptr;
				dedC++;
			}
		}
		if (dedC == nop) {
			gotoRowCol(40, cols + 10);
			cout << "Game Over.";
			exit(0);
		}
	}
}
void TimeBasedFood() {
	system("cls");
	gotoRowCol(40, 80);
	cout << "You have 5 Second to eat food and after that food will apperar in a new place";
	Sleep(2000);
	system("cls");
	snake* S;
	int nop;
	init(S, rows, cols, nop);
	printButtons();
	pos C;
	setclr(15);
	Click(C);
	system("cls");
	printBoundry(rows, cols);
	printStage(C);
	printScore(S, nop);
	pos food;
	char k;
	int sNo = 0;
	foodPlacer(food, C.r);
	int dedC = 0;
	int start_t = time(0);
	while (true) {
		int end_t = time(0);
		gotoRowCol(5, 170);
		cout << "Timer: " << end_t - start_t << " sec";
		if (end_t - start_t == 5) {
			eraseFood(food);
			foodPlacer(food, C.r);
			start_t = end_t;
		}

		printSnakes(S, nop);
		if (_kbhit()) {
			k = _getch();
			if (k == -32) {
				k = _getch();
				changeDirection(S, k);
			}
			changeDirection(S, k);
		}
		Sleep(100);
		eraseSnake(S, nop);
		if (didAte(S, food, nop, sNo)) {
			incSize(S[sNo], C.r);
			foodPlacer(food, C.r);
			S[sNo].score++;
			setclr(15);
			gotoRowCol(4, cols + 5);
			printScore(S, nop);
		}
		for (int i = 0; i < nop; i++) {
			move1step(S[i], C.r);
		}
		int kn;
		if (isDead(S, nop, kn, C.r)) {
			if (nop == 1) {
				gotoRowCol(40, cols + 10);
				cout << "Game Over.";
				exit(0);
			}
			else {
				gotoRowCol(40, cols + 10);
				cout << S[kn].name << " is dead... :)";
				S[kn].sPos = nullptr;
				dedC++;
			}
		}
		if (dedC == nop) {
			gotoRowCol(40, cols + 10);
			cout << "Game Over.";
			exit(0);
		}
	}
}

int main() {
	int col = 15;
	int row = 10;
	printBox(row * 5, col * 4, 10, col, 9, "Normal", 24);
	printBox(row * 5, col * 6, 10, col, 9, "Timed Food", 24);
	printBox(row * 5, col * 8, 10, col, 9, "Timed Score", 24);
	setclr(15);
	int r, c;
	do {
		gotoRowCol(70, 80);
		cout << "Select a mode...";
		getRowColbyLeftClick(r, c);
		r = r / 8;
		c = c / 15;
	} while ((r != 6 and r != 7) or (c != 4 and c != 6 and c != 8));
	switch (c) {
	case 4:
		Normal();
	case 8:
		TimeBaseScore();
	case 6:
		TimeBasedFood();
	}
	return 0;
}
