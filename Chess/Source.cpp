#include<iostream>
#include<Windows.h>
#include<conio.h>
#include"Chess.h"
using namespace std;
void printIntro(string& a, string& b) {
	gotoRowCol(39, 84);
	SetClr(3);
	cout << "Enter name of player 1: ";
	cin >> a;
	gotoRowCol(41, 84);
	cout << "Enter name of player 2: ";
	cin >> b;
	return;
}
int main() {
	pos Src, Des;
	bool** PossibleMoves;
	Piece*** fakeB;
	ifstream rdr("newGame.txt");
	string n1, n2;
	printIntro(n1, n2);
	Chess chess(rdr, n1, n2);
	system("cls");
	chess.printNew(5 * 10, 5 * 10, 10, 10);
	chess.printload(5 * 10, 9 * 10, 10, 10);
	do {
		chess.mouseClick(Src);
	} while (!chess.doLoad(Src));

	chess.chessBoard.printBoard();
	chess.printsave(10, 14 * 10, 10, 10);
	chess.printundo(3 * 10, 14 * 10, 10, 10);
	chess.printRedo(5 * 10, 14 * 10, 10, 10);
	state M;
	while (1) {

		chess.printTurnMsg(chess.turn);

		do
		{
			do {	
				chess.chessBoard.fakeboardinit(fakeB);
				chess.mouseClick(Src);
				if (Src.r == 1 and Src.c == 14) {
					chess.save();
					gotoRowCol(10, 108);
					cout << "Game Saved";
					chess.mouseClick(Src);
				}
				if (Src.r == 3 and Src.c == 14) {
					chess.Undo(M);
					chess.chessBoard.printOneCell(M.Src);
					chess.chessBoard.printOneCell(M.Des);
					chess.mouseClick(Src);

				}
				if (Src.r == 5 and Src.c == 14) {
					chess.Redo(M);
					chess.chessBoard.printOneCell(M.Src);
					chess.chessBoard.printOneCell(M.Des);
					chess.mouseClick(Src);

				}
				PossibleMoves = chess.canMove(chess.chessBoard.board, Src);
				chess.highLight(PossibleMoves, Src);

			} while (!chess.isValidSelection(chess.chessBoard.board, Src));

			chess.mouseClick(Des);
			chess.unhighLight(PossibleMoves, Des);
			chess.chessBoard.FakeUpdateB(fakeB, Src, Des);
		} while (!chess.isLigalMove(chess.chessBoard.board, Src, Des) or !chess.isValidDestination(chess.chessBoard.board, Des) or chess.selfCheck(fakeB));
		chess.updateMove(M, Src, Des);
		gotoRowCol(10, 108);
		cout << "                   ";
		gotoRowCol(11, 108);
		cout << "                   ";
		gotoRowCol(12, 108);
		cout << "                   ";
		// castel
			
		chess.chessBoard.MovePiece(Src, Des);
		if (chess.isPromoted(Des)) {
			chess.chessBoard.promote(Des, chess.turn);
		}
		if (chess.StallMate(chess.chessBoard.board)) {
			chess.chessBoard.printOneCell(Src);
			chess.chessBoard.printOneCell(Des);
			SetClr(3);
			gotoRowCol(10, 108);
			cout << "*******************";
			gotoRowCol(11, 108);
			cout << "*    StallMate    *";
			gotoRowCol(12, 108);
			cout << "*******************";
			break;
		}

		if (chess.CheckMate(chess.chessBoard.board)) {
			chess.chessBoard.printOneCell(Src);
			chess.chessBoard.printOneCell(Des);
			SetClr(3);
			gotoRowCol(10, 108);
			cout << "*******************";
			gotoRowCol(11, 108);
			cout << "*    CHECKMATE    *";
			gotoRowCol(12, 108);
			cout << "*******************";
			break;
		}

		if (chess.check(chess.chessBoard.board)) {
			SetClr(4);
			gotoRowCol(10, 108);
			cout << "*******************";
			gotoRowCol(11, 108);
			cout << "*      CHECK      *";
			gotoRowCol(12, 108);
			cout << "*******************";
		}
		chess.chessBoard.printOneCell(Src);
		chess.chessBoard.printOneCell(Des);
		chess.turn = chess.changeTurn(chess.turn);

	}
	_getch();
	_getch();
	return 0;
}

//Phase 0: all required classes and attributes
//Phase 1 : allocated memory and move pieces all around simply no legalities
//Phase 2 : legalities of all the pieces
//Phase 3 : complete chess, all legalities, checkmate, stalemate, check.Highlight, undo& redo, save & load
