#include "board.h"
#include"noPiece.h"
#include"pown.h"
#include"bishop.h"
#include"rook.h"
#include"knight.h"
#include"king.h"
#include"queen.h"



void Board::printBox(int sr, int sc, int rows, int cols, int clr, int clr2) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			gotoRowCol(sr + i, sc + j);
			
			SetClr(clr);
			cout << char(-37);
		}
	}
	board[sr / rows][sc / cols]->print_piece(sr, sc, clr2);
	//SetClr(clr2);
}

Board::Board(ifstream& rdr) {
	char sym;
	rdr >> dim;
	pos a;
	board = new Piece * *[dim];
	for (int i = 0; i < this->dim; i++) {
		board[i] = new Piece * [dim];
	}
	for (int i = 0; i < this->dim; i++) {
		for (int j = 0; j < this->dim; j++) {
			a.r = i;
			a.c = j;
			rdr >> sym;
			switch (sym) {
			case '-':
				board[i][j] = new noPiece(a, white, '-');
				break;
			case 'p':
				board[i][j] = new Pown(a, white, 'p');
				break;
			case 'r':
				board[i][j] = new Rook(a, white, 'r');
				break;
			case 'k':
				board[i][j] = new King(a, white, 'k');
				break;
			case 'n':
				board[i][j] = new Knight(a, white, 'n');
				break;
			case 'q':
				board[i][j] = new Queen(a, white, 'q');
				break;
			case 'b':
				board[i][j] = new Bishop(a, white, 'b');
				break;
			case 'P':
				board[i][j] = new Pown(a, black, 'P');
				break;
			case 'R':
				board[i][j] = new Rook(a, black, 'R');
				break;
			case 'K':
				board[i][j] = new King(a, black, 'K');
				break;
			case 'N':
				board[i][j] = new Knight(a, black, 'N');
				break;
			case 'Q':
				board[i][j] = new Queen(a, black, 'Q');
				break;
			case 'B':
				board[i][j] = new Bishop(a, black, 'B');
				break;
			}
		}
	}
}

void Board::printBoard() {
	int rows = 10;
	int cols = 10;
	SetClr(0);
	system("cls");
	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++) {
			if ((i + j) % 2 == 0)
				printBox(i * rows, j * cols, rows, cols, 12,15*13);
			else
				printBox(i * rows, j * cols, rows, cols, 14, 15*15);
		}
	}
	SetClr(4);
}

void Board::printOneCell(pos src) {
	int rows = 10;
	int cols = 10;
	if ((src.r + src.c) % 2 == 0)
		printBox(src.r * rows, src.c * cols, rows, cols, 12, 15 * 13);
	else
		printBox(src.r * rows, src.c * cols, rows, cols, 14, 15 * 15);
}

void Board::MovePiece(pos Src, pos Des) {
	board[Des.r][Des.c] = board[Src.r][Src.c];
	board[Des.r][Des.c]->setNewPosition(Des);
	board[Src.r][Src.c] = new noPiece(Src, white, '-');
}

void Board::fakeboardinit(Piece*** &_board) {

	_board = new Piece * *[dim];
	for (int i = 0; i < this->dim; i++) {
		_board[i] = new Piece * [dim];
	}

	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++) {
			_board[i][j] = board[i][j];
		}
	}
}

void Board::FakeUpdateB(Piece ***_board, pos Src, pos Des) {
	_board[Des.r][Des.c] = _board[Src.r][Src.c];
	_board[Des.r][Des.c]->setNewPosition(Des);
	_board[Src.r][Src.c] = new noPiece(Src, white, '-');
}

pos Board::findKing(Piece ***_board, int turn) {
	pos k;
	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++) {
			if (turn == 0 and _board[i][j]->getSym() == 'k') {
				k.r = i;
				k.c = j;
				return k;
			}
			else if (_board[i][j]->getSym() == 'K') {
				k.r = i;
				k.c = j;
				return k;
			}
		}
	}
}

void Board::promote(pos Src, int turn) {
	char n;
	do {
		gotoRowCol(10, 108);
		cout << "Promote to ??? q: Queen, r: Rook, b: Bishop, n: Knight";

		cin >> n;
	} while (n != 'q' and n != 'r' and n != 'b' and n != 'n');
	if (n == 'q') {
		if (turn == 0) {
			delete board[Src.r][Src.c];
			board[Src.r][Src.c] = new Queen(Src, white, 'q');
		}
		else {
			delete board[Src.r][Src.c];
			board[Src.r][Src.c] = new Queen(Src, black, 'Q');
		}
	}
	else if (n == 'r') {
		if (turn == 0) {
			delete board[Src.r][Src.c];
			board[Src.r][Src.c] = new Rook(Src, white, 'r');
		}
		else {
			delete board[Src.r][Src.c];
			board[Src.r][Src.c] = new Rook(Src, black, 'R');
		}
	}
	else if (n == 'b') {
		if (turn == 0) {
			delete board[Src.r][Src.c];
			board[Src.r][Src.c] = new Bishop(Src, white, 'b');
		}
		else {
			delete board[Src.r][Src.c];
			board[Src.r][Src.c] = new Bishop(Src, black, 'B');
		}
	}
	else if (n == 'n') {
		if (turn == 0) {
			delete board[Src.r][Src.c];
			board[Src.r][Src.c] = new Knight(Src, white, 'n');
		}
		else {
			delete board[Src.r][Src.c];
			board[Src.r][Src.c] = new Knight(Src, black, 'N');
		}
	}
}