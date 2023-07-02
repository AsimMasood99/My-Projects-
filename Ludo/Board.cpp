#include "Board.h"
#include<iostream>

Board::Board(int nop)
{
	board_T.loadFromFile("bord.png");
	Board_S.setTexture(board_T);
	Board_S.setScale(0.9f, 0.9f);

	if (nop == 6) {

		for (int i = 0, j = -1; i < 24; i++) {
			if (i < 4)
				pieces.push_back(new Piece(j, Green));
			else if (i < 8)
				pieces.push_back(new Piece(j, Orange));
			else if (i < 12)
				pieces.push_back(new Piece(j, Yellow));
			else if (i < 16)
				pieces.push_back(new Piece(j, Blue));
			else if (i < 20)
				pieces.push_back(new Piece(j, Purple));
			else if (i < 24)
				pieces.push_back(new Piece(j, Red));
			if (j == -4)
				j = 0;
			j--;
		}
	}
	else if (nop == 2) {
		for (int i = 0, j = -1; i < 8; i++) {
			if (i < 4)
				pieces.push_back(new Piece(j, Green));
			else if (i < 8)
				pieces.push_back(new Piece(j, Red));
			if (j == -4)
				j = 0;
			j--;
		}
		pieces[0]->pos = 83;
		pieces[0]->step = 81;
		
		pieces[1]->pos = 84;
		pieces[1]->step = 82;
		
		pieces[2]->pos = 85;
		pieces[2]->step = 83;

		pieces[3]->pos = 86;
		pieces[3]->step = 84;
	}
	else if (nop == 4) {
		for (int i = 0, j = -1; i < 16; i++) {
			if (i < 4)
				pieces.push_back(new Piece(j, Green));
			else if (i < 8)
				pieces.push_back(new Piece(j, Yellow));
			else if (i < 12)
				pieces.push_back(new Piece(j, Blue));
			else if (i < 16)
				pieces.push_back(new Piece(j, Red));
			if (j == -4)
				j = 0;
			j--;
		}
	}
}

void Board::printBoard(sf::RenderWindow& Window, int nop) {
	Window.draw(Board_S);

	if (nop == 6) {
		for (int i = 0; i < 24; i++) {
			if (pieces[i] != nullptr) {
				pieces[i]->printPiece(Window);
			}
		}
	}
	else if (nop == 2) {
		for (int i = 0; i < 8; i++) {
			if (pieces[i] != nullptr) {
				pieces[i]->printPiece(Window);
			}
		}
	}
	else if (nop == 4) {
		for (int i = 0; i < 16; i++) {
			if (pieces[i] != nullptr) {
				pieces[i]->printPiece(Window);
			}
		}
	}
	return;
}

void Board::move(int die, int _pos, int turn, int& piece_moved, int nop) {
	if ((die == 1 or die == 6) and _pos <= -1 and _pos >= -24) {
		if (nop == 6) {
			if (turn == 0 and _pos <= -1 and _pos >= -4) {
				pieces[(_pos + 1) * (-1)]->pos = 1; // green 
			}
			else if (turn == 1 and _pos <= -5 and _pos >= -8) {
				pieces[(_pos + 1) * (-1)]->pos = 14; // orange
			}
			else if (turn == 2 and _pos <= -9 and _pos >= -12) {
				pieces[(_pos + 1) * (-1)]->pos = 33; // yellow
			}
			else if (turn == 5 and _pos <= -13 and _pos >= -16) {
				pieces[(_pos + 1) * (-1)]->pos = 78; // blue
			}
			else if (turn == 4 and _pos <= -17 and _pos >= -20) {
				pieces[(_pos + 1) * (-1)]->pos = 59; // purple
			}
			else if (turn == 3 and _pos <= -21 and _pos >= -24) {
				pieces[(_pos + 1) * (-1)]->pos = 46; // red
			}
		}
		else if (nop == 4) {
			if (turn == 0 and _pos <= -1 and _pos >= -4) {
				pieces[(_pos + 1) * (-1)]->pos = 1; // green 
			}
			else if (turn == 1 and _pos <= -9 and _pos >= -12) {
				pieces[(_pos + 1) * (-1) - 4]->pos = 33; // yellow
			}
			else if (turn == 3 and _pos <= -13 and _pos >= -16) {
				pieces[(_pos + 1) * (-1) - 4]->pos = 78; // blue
			}
			else if (turn == 2 and _pos <= -21 and _pos >= -24) {
				pieces[(_pos + 1) * (-1) - 8]->pos = 46; // red
			}
		}
		else if (nop == 2) {
			if (turn == 0 and _pos <= -1 and _pos >= -4) {
				pieces[(_pos + 1) * (-1)]->pos = 1; // green 
			}
			else if (turn == 1 and _pos <= -21 and _pos >= -24) {
				pieces[(_pos + 1) * (-1) - 16]->pos = 46; // red
			}
		}
	}
	else {
		if(nop == 6) {
			if (turn == 0) {
				for (int i = 0; i < 4; i++) {
					if (pieces[i]->pos == _pos or pieces[i]->step == _pos - 2) {
						pieces[i]->pos += die;
						pieces[i]->step += die;
						piece_moved = i;
						if (pieces[i]->step >= 88) {
							pieces[i]->pos = -99;
						}
						if (pieces[i]->step >= 93)
						{
							pieces[i]->step = 93;
							pieces[i]->isIn = true;
						}
						return;
					}
				}
			}
			else if (turn == 1) {
				for (int i = 4; i < 8; i++) {
					if (pieces[i]->pos == _pos or pieces[i]->step == _pos - 7) {
						pieces[i]->step += die;
						pieces[i]->pos += die;
						if (pieces[i]->pos > 89) {
							pieces[i]->pos -= 90;
						}
						piece_moved = i;
						if (pieces[i]->step >= 88) {
							pieces[i]->pos = -99;
						}
						if (pieces[i]->step >= 93)
						{
							pieces[i]->step = 93;
							pieces[i]->isIn = true;
						}
						return;
					}
				}
			}
			else if (turn == 2) {
				for (int i = 8; i < 12; i++) {
					if (pieces[i]->pos == _pos or pieces[i]->step == _pos - 12) {
						pieces[i]->step += die;
						pieces[i]->pos += die;
						if (pieces[i]->pos > 89) {
							pieces[i]->pos -= 90;
						}
						piece_moved = i;
						if (pieces[i]->step >= 88) {
							pieces[i]->pos = -99;
						}
						if (pieces[i]->step >= 93)
						{
							pieces[i]->step = 93;
							pieces[i]->isIn = true;
						}
						return;
					}
				}
			}
			else if (turn == 5) {
				for (int i = 12; i < 16; i++) {
					if (pieces[i]->pos == _pos or pieces[i]->step == _pos - 27) {
						pieces[i]->step += die;
						pieces[i]->pos += die;
						if (pieces[i]->pos > 89) {
							pieces[i]->pos -= 90;
						}
						piece_moved = i;
						if (pieces[i]->step >= 88) {
							pieces[i]->pos = -99;
						}
						if (pieces[i]->step >= 93)
						{
							pieces[i]->step = 93;
							pieces[i]->isIn = true;
						}
						return;
					}
				}
			}
			else if (turn == 4) {
				for (int i = 16; i < 20; i++) {
					if (pieces[i]->pos == _pos or pieces[i]->step == _pos - 22) {
						pieces[i]->step += die;
						pieces[i]->pos += die;
						if (pieces[i]->pos > 89) {
							pieces[i]->pos -= 90;
						}
						piece_moved = i;
						if (pieces[i]->step >= 88) {
							pieces[i]->pos = -99;
						}
						if (pieces[i]->step >= 93)
						{
							pieces[i]->step = 93;
							pieces[i]->isIn = true;
						}
						return;
					}
				}
			}
			else if (turn == 3) {
				for (int i = 20; i < 24; i++) {
					if (pieces[i]->pos == _pos or pieces[i]->step == _pos - 17) {
						pieces[i]->step += die;
						pieces[i]->pos += die;
						if (pieces[i]->pos > 89) {
							pieces[i]->pos -= 90;
						}
						piece_moved = i;
						if (pieces[i]->step >= 88) {
							pieces[i]->pos = -99;
						}
						if (pieces[i]->step >= 93)
						{
							pieces[i]->step = 93;
							pieces[i]->isIn = true;
						}
						return;
					}
				}
			}
		}

		else if (nop == 4) {
			if (turn == 0) {
				for (int i = 0; i < 4; i++) {
					if (pieces[i]->pos == _pos or pieces[i]->step == _pos - 2) {
						pieces[i]->pos += die;
						pieces[i]->step += die;
						piece_moved = i;
						if (pieces[i]->step >= 88) {
							pieces[i]->pos = -99;
						}
						if (pieces[i]->step >= 93)
						{
							pieces[i]->step = 93;
							pieces[i]->isIn = true;
						}
						return;
					}
				}
			}
			else if (turn == 1) {
				for (int i = 4; i < 8; i++) {
					if (pieces[i]->pos == _pos or pieces[i]->step == _pos - 12) {
						pieces[i]->step += die;
						pieces[i]->pos += die;
						if (pieces[i]->pos > 89) {
							pieces[i]->pos -= 90;
						}
						piece_moved = i;
						if (pieces[i]->step >= 88) {
							pieces[i]->pos = -99;
						}
						if (pieces[i]->step >= 93)
						{
							pieces[i]->step = 93;
							pieces[i]->isIn = true;
						}
						return;
					}
				}
			}
			else if (turn == 3) {
				for (int i = 8; i < 12; i++) {
					if (pieces[i]->pos == _pos or pieces[i]->step == _pos - 27) {
						pieces[i]->step += die;
						pieces[i]->pos += die;
						if (pieces[i]->pos > 89) {
							pieces[i]->pos -= 90;
						}
						piece_moved = i;
						if (pieces[i]->step >= 88) {
							pieces[i]->pos = -99;
						}
						if (pieces[i]->step >= 93)
						{
							pieces[i]->step = 93;
							pieces[i]->isIn = true;
						}
						return;
					}
				}
			}
			else if (turn == 2) {
				for (int i = 12; i < 16; i++) {
					if (pieces[i]->pos == _pos or pieces[i]->step == _pos - 17) {
						pieces[i]->step += die;
						pieces[i]->pos += die;
						if (pieces[i]->pos > 89) {
							pieces[i]->pos -= 90;
						}
						piece_moved = i;
						if (pieces[i]->step >= 88) {
							pieces[i]->pos = -99;
						}
						if (pieces[i]->step >= 93)
						{
							pieces[i]->step = 93;
							pieces[i]->isIn = true;
						}
						return;
					}
				}
			}
		}
		else if (nop == 2) {
			if (turn == 0) {
				for (int i = 0; i < 4; i++) {
					if (pieces[i]->pos == _pos or pieces[i]->step == _pos - 2) {
						pieces[i]->pos += die;
						pieces[i]->step += die;
						piece_moved = i;
						if (pieces[i]->step >= 88) {
							pieces[i]->pos = -99;
						}
						if (pieces[i]->step >= 93)
						{
							pieces[i]->step = 93;
							pieces[i]->isIn = true;
						}
						cout << "Steps: "<< pieces[i]->step<<endl;
						return;
					}
					cout << "nope\n";
				}
			}
			
			else if (turn == 1) {
				for (int i = 4; i < 8; i++) {
					if (pieces[i]->pos == _pos or pieces[i]->step == _pos - 17) {
						pieces[i]->step += die;
						pieces[i]->pos += die;
						if (pieces[i]->pos > 89) {
							pieces[i]->pos -= 90;
						}
						piece_moved = i;
						if (pieces[i]->step >= 88) {
							pieces[i]->pos = -99;
						}
						if (pieces[i]->step >= 93)
						{
							pieces[i]->step = 93;
							pieces[i]->isIn = true;
						}
						
						return;
					}
				}
			}
		}
	}
}

