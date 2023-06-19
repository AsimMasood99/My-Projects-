#include "Chess.h"
#include"rook.h"
#include"bishop.h"
#include"pown.h"
#include"king.h"
#include"queen.h"
#include"knight.h"
#include"noPiece.h"
using namespace std;

Chess::Chess(ifstream& rdr, string n1, string n2) :
	chessBoard(rdr)
{
	dim = 8;
	Ps = new Player * [2];
	Ps[0] = new Player(n1);
	Ps[1] = new Player(n2);
	turn = white;
}

int Chess::changeTurn(int turn) {
	turn++;
	turn = turn % 2;
	return turn;
}


void Chess::printTurnMsg(int turn) {
	SetClr(15);
	gotoRowCol(4, 108);
	cout << "                                                                                           ";
	gotoRowCol(4, 108);
	SetClr(4);
	cout << Ps[turn]->getPlayerName() << "'s Turn\n";
}

bool Chess::isValidSelection(Piece*** b, pos Src) {
	if (Src.c < 0 or Src.r < 0 or Src.c >= dim or Src.r >= dim)
		return false;
	if (b[Src.r][Src.c]->getSym() == '-')
		return false;
	if (b[Src.r][Src.c]->getClr() != turn)
		return false;
	return true;
}

bool Chess::isValidDestination(Piece*** b, pos Des) {
	if (Des.r < 0 or Des.r >= dim or Des.c < 0 or Des.c >= dim)
		return false;
	if (b[Des.r][Des.c]->getSym() == '-')
		return true;
	if (b[Des.r][Des.c]->getClr() == turn)
		return false;
	return true;
}

bool Chess::isLigalMove(Piece*** b, pos Src, pos Des) {
	return b[Src.r][Src.c]->isValidMove(b, Src, Des);
}

void Chess::mouseClick(pos& src) {
	int r, c;
	getRowColbyLeftClick(r, c);
	src.r = r / 10;
	src.c = c / 10;
}

bool** Chess::canMove(Piece*** b, pos Src) {
	bool** M;
	Piece*** fb;
	M = new bool* [dim];
	for (int i = 0; i < dim; i++) {
		M[i] = new bool[dim] {false};
	}
	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++) {
			chessBoard.fakeboardinit(fb);
			pos d;
			d.r = i;
			d.c = j;
			chessBoard.FakeUpdateB(fb, Src, d);
			if (isLigalMove(b, Src, d) and isValidDestination(b, d) and isValidSelection(b, Src) and !selfCheck(fb))
				M[i][j] = true;

		}
	}
	return M;
}

void Chess::highLight(bool** M, pos Src) {
	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++) {
			if (M[i][j]) {
				int r = i * 10, c = j * 10;
				drawBox(r, c, 10);
			}
		}
	}
}

void Chess::unhighLight(bool** M, pos Src) {
	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++) {
			if (M[i][j] and (i + j) % 2 == 0) {
				int r = i * 10, c = j * 10;
				eraseBox(r, c, 10, 12);
			}
			else if (M[i][j] and (i + j) % 2 != 0) {
				int r = i * 10, c = j * 10;
				eraseBox(r, c, 10, 14);
			}
		}
	}
}

bool Chess::check(Piece*** b) {
	turn = changeTurn(turn);
	pos d = chessBoard.findKing(b, turn);
	turn = changeTurn(turn);
	pos s;
	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++) {
			s.r = i;
			s.c = j;
			if (isValidSelection(b, s) and isValidDestination(b, d) and isLigalMove(b, s, d)) {
				return true;
			}
		}
	}
	return false;
}

bool Chess::selfCheck(Piece*** b) {
	pos d = chessBoard.findKing(b, turn);
	turn = changeTurn(turn);
	pos s;
	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++) {
			s.r = i;
			s.c = j;
			if (isValidSelection(b, s) and isValidDestination(b, d) and isLigalMove(b, s, d)) {
				turn = changeTurn(turn);
				return true;
			}
		}
	}
	turn = changeTurn(turn);
	return false;
}

bool Chess::CheckMate(Piece*** B) {
	turn = changeTurn(turn);
	Piece*** fkarr;
	bool** M;
	pos s;
	pos d;
	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++) {
			s.r = i;
			s.c = j;
			if (isValidSelection(chessBoard.board, s)) {
				M = canMove(chessBoard.board, s);
				for (int m = 0; m < dim; m++) {
					for (int n = 0; n < dim; n++) {
						chessBoard.fakeboardinit(fkarr);
						if (M[m][n]) {
							d.r = m;
							d.c = n;
							chessBoard.FakeUpdateB(fkarr, s, d);
							if (!selfCheck(fkarr)) {
								turn = changeTurn(turn);
								return false;
							}
						}
					}
				}
			}
		}
	}
	turn = changeTurn(turn);
	return true;
}

bool Chess::StallMate(Piece*** B)
{
	turn = changeTurn(turn);
	bool** M;
	if (check(B)) {
		turn = changeTurn(turn);
		return false;
	}
	pos s;
	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++) {
			s.r = i;
			s.c = j;
			if (isValidSelection(chessBoard.board, s)) {
				M = canMove(chessBoard.board, s);
				for (int m = 0; m < dim; m++) {
					for (int n = 0; n < dim; n++) {
						if (M[m][n]) {
							turn = changeTurn(turn);
							return false;
						}
					}
				}
			}
		}
	}
	turn = changeTurn(turn);
	return true;
}

bool Chess::isPromoted(pos Src)
{
	if (chessBoard.board[Src.r][Src.c]->getSym() == 'p' and Src.r == 7)
		return true;
	if (chessBoard.board[Src.r][Src.c]->getSym() == 'P' and Src.r == 0)
		return true;
	return false;
}

void Chess::printNew(int sr, int sc, int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			gotoRowCol(sr + i, sc + j);
			SetClr(12);
			cout << char(-37);
		}
	}
	gotoRowCol(sr + 5, sc + 4);
	SetClr(15 * 13 + 12);
	cout << "New";
}

void Chess::printload(int sr, int sc, int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			gotoRowCol(sr + i, sc + j);
			SetClr(12);
			cout << char(-37);
		}
	}
	gotoRowCol(sr + 5, sc + 3);
	SetClr(15 * 13 + 12);
	cout << "Load";
}

bool Chess::doSave(pos s) {
	if (s.r == 1 and s.c == 14)
		return true;
	else
		return false;
}

void Chess::save() {
	ofstream save("BSCS22077-load.txt");

	save << dim << " " << turn << endl;
	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++) {
			save << chessBoard.board[i][j]->getSym();
		}
		save << endl;
	}
}

void Chess::Load() {
	ifstream load("BSCS22077-load.txt");
	load >> dim;
	load >> turn;
	pos a;
	char sym;
	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++) {
			a.r = i;
			a.c = j;
			load >> sym;
			switch (sym) {
			case '-':
				chessBoard.board[i][j] = new noPiece(a, white, '-');
				break;
			case 'p':
				chessBoard.board[i][j] = new Pown(a, white, 'p');
				break;
			case 'r':
				chessBoard.board[i][j] = new Rook(a, white, 'r');
				break;
			case 'k':
				chessBoard.board[i][j] = new King(a, white, 'k');
				break;
			case 'n':
				chessBoard.board[i][j] = new Knight(a, white, 'n');
				break;
			case 'q':
				chessBoard.board[i][j] = new Queen(a, white, 'q');
				break;
			case 'b':
				chessBoard.board[i][j] = new Bishop(a, white, 'b');
				break;
			case 'P':
				chessBoard.board[i][j] = new Pown(a, black, 'P');
				break;
			case 'R':
				chessBoard.board[i][j] = new Rook(a, black, 'R');
				break;
			case 'K':
				chessBoard.board[i][j] = new King(a, black, 'K');
				break;
			case 'N':
				chessBoard.board[i][j] = new Knight(a, black, 'N');
				break;
			case 'Q':
				chessBoard.board[i][j] = new Queen(a, black, 'Q');
				break;
			case 'B':
				chessBoard.board[i][j] = new Bishop(a, black, 'B');
				break;
			}
		}
	}
}

bool Chess::doLoad(pos s) {
	if (s.r == 5 and s.c == 5) {
		return true;
	}
	else if (s.r == 5 and s.c == 9) {
		Load();
		return true;
	}
	else return false;
}

void Chess::printsave(int sr, int sc, int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			gotoRowCol(sr + i, sc + j);
			SetClr(3);
			cout << char(-37);
		}
	}
	gotoRowCol(sr + (sr / 2), sc + 3);
	SetClr(15*3+7);
	cout << "Save";
}

void Chess::printundo(int sr, int sc, int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			gotoRowCol(sr + i, sc + j);
			SetClr(12);
			cout << char(-37);
		}
	}
	gotoRowCol(sr + 5, sc + 3);
	SetClr(15 * 13 + 12);
	cout << "Undo";
}

void Chess::updateMove(state &M, pos S, pos D) {
	M.Src = S;
	M.Des = D;
	M.oldP = chessBoard.board[D.r][D.c]->clone();
	M.newP = chessBoard.board[S.r][S.c]->clone();
	M.turn = turn;
}

void Chess::Undo(state M) {
	chessBoard.board[M.Src.r][M.Src.c] = M.newP->clone();
	chessBoard.board[M.Des.r][M.Des.c] = M.oldP->clone();
	turn = M.turn;
}

void Chess::printRedo(int sr, int sc, int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			gotoRowCol(sr + i, sc + j);
			SetClr(12);
			cout << char(-37);
		}
	}
	gotoRowCol(sr + 5, sc + 3);
	SetClr(15 * 13 + 12);
	cout << "Redo";
}

void Chess::Redo(state M) {
	chessBoard.board[M.Src.r][M.Src.c] = M.oldP->clone();
	chessBoard.board[M.Des.r][M.Des.c] = M.newP->clone();
	turn = M.turn;
}