#include "Ludo.h"


Ludo::Ludo(int nop, bool cheat) :
	board(nop)
{
	no_of_Players = nop;
	Ps = new Player * [no_of_Players];
	for (int i = 0; i < no_of_Players; i++) {
		Ps[i] = new Player("anonamous");
	}
	cheating = cheat;

	dice1.loadFromFile("D1.png");
	dice2.loadFromFile("D2.png");
	dice3.loadFromFile("D3.png");
	dice4.loadFromFile("D4.png");
	dice5.loadFromFile("D5.png");
	dice6.loadFromFile("D6.png");


	Dice.push_back(Sprite(dice1));
	Dice.push_back(Sprite(dice2));
	Dice.push_back(Sprite(dice3));
	Dice.push_back(Sprite(dice4));
	Dice.push_back(Sprite(dice5));
	Dice.push_back(Sprite(dice6));


	awd1.loadFromFile("1st_trophy.png");
	awd2.loadFromFile("2nd_trophy.png");
	awd3.loadFromFile("3rd_trophy.png");
	awd4.loadFromFile("4th_trophy.png");
	awd5.loadFromFile("5th_trophy.png");
	awd6.loadFromFile("6th_trophy.png");

	Awards.push_back(Sprite(awd1));
	Awards.push_back(Sprite(awd2));
	Awards.push_back(Sprite(awd3));
	Awards.push_back(Sprite(awd4));
	Awards.push_back(Sprite(awd5));
	Awards.push_back(Sprite(awd6));


	pd = 1;
	turn = 0;
}

int Ludo::Selection(Vector2f click) {
	int boxSize = 90;
	// in Home

	// green
	if (click.x >= 167 and click.x <= 257 and click.y >= 165 and click.y <= 255) {
		return -1;
	}
	else if (click.x >= 281 and click.x <= 371 and click.y >= 165 and click.y <= 255) {
		return -2;
	}
	else if (click.x >= 167 and click.x <= 257 and click.y >= 284 and click.y <= 374) {
		return -3;
	}
	else if (click.x >= 281 and click.x <= 371 and click.y >= 284 and click.y <= 374) {
		return -4;
	}
	// Orange
	else if (click.x >= 972 and click.x <= 1062 and click.y >= 165 and click.y <= 255) {
		return -5;
	}
	else if (click.x >= 1087 and click.x <= 1177 and click.y >= 165 and click.y <= 255) {
		return -6;
	}
	else if (click.x >= 972 and click.x <= 1062 and click.y >= 284 and click.y <= 374) {
		return -7;
	}
	else if (click.x >= 1087 and click.x <= 1177 and click.y >= 284 and click.y <= 374) {
		return -8;
	}
	// Yellow

	else if (click.x >= 1778 and click.x <= 1868 and click.y >= 165 and click.y <= 255) {
		return -9;
	}
	else if (click.x >= 1892 and click.x <= 1982 and click.y >= 165 and click.y <= 255) {
		return -10;
	}
	else if (click.x >= 1778 and click.x <= 1868 and click.y >= 284 and click.y <= 374) {
		return -11;
	}
	else if (click.x >= 1892 and click.x <= 1982 and click.y >= 284 and click.y <= 374) {
		return -12;
	}
	// Blue

	else if (click.x >= 167 and click.x <= 257 and click.y >= 976 and click.y <= 1066) {
		return -13;
	}
	else if (click.x >= 281 and click.x <= 371 and click.y >= 976 and click.y <= 1066) {
		return -14;
	}
	else if (click.x >= 167 and click.x <= 257 and click.y >= 1095 and click.y <= 1185) {
		return -15;
	}
	else if (click.x >= 281 and click.x <= 371 and click.y >= 1095 and click.y <= 1185) {
		return -16;
	}

	// Purple

	else if (click.x >= 972 and click.x <= 1062 and click.y >= 976 and click.y <= 1066) {
		return -17;
	}
	else if (click.x >= 1087 and click.x <= 1177 and click.y >= 976 and click.y <= 1066) {
		return -18;
	}
	else if (click.x >= 972 and click.x <= 1062 and click.y >= 1095 and click.y <= 1185) {
		return -19;
	}
	else if (click.x >= 1087 and click.x <= 1177 and click.y >= 1095 and click.y <= 1185) {
		return -20;
	}
	// Red

	else if (click.x >= 1778 and click.x <= 1868 and click.y >= 976 and click.y <= 1066) {
		return -21;
	}
	else if (click.x >= 1892 and click.x <= 1982 and click.y >= 976 and click.y <= 1066) {
		return -22;
	}
	else if (click.x >= 1778 and click.x <= 1868 and click.y >= 1095 and click.y <= 1185) {
		return -23;
	}
	else if (click.x >= 1892 and click.x <= 1982 and click.y >= 1095 and click.y <= 1185) {
		return -24;
	}

	// OnBoard
	else if (click.y >= 540 and click.y <= 630 and click.x <= 540) {
		return click.x / 90;
	}
	else if (click.x >= 540 and click.x <= 630 and click.y <= 540) {
		return 12 - (click.y / 90);
	}
	else if (click.x >= 630 and click.x <= 720 and click.y <= 90) {
		return 12;
	}
	else if (click.x >= 720 and click.x <= 810 and click.y <= 540) {
		return (click.y / 90) + 13;
	}
	else if (click.y >= 540 and click.y <= 630 and click.x >= 810 and click.x <= 1345) {
		return (click.x / 90) + 10;
	}
	else if (click.x >= 1345 and click.x <= 1435 and click.y <= 540) {
		return 31 - (click.y / 90);
	}
	else if (click.x >= 1435 and click.x <= 1525 and click.y <= 90) {
		return 31;
	}
	else if (click.x >= 1525 and click.x <= 1615 and click.y <= 540) {
		return (click.y / 90) + 32;
	}
	else if (click.y >= 540 and click.y <= 630 and click.x >= 1615 and click.x <= 2155) {
		return (click.x / 90) + 20;
	}
	else if (click.x >= 2065 and click.x <= 2155 and click.y >= 630 and click.y <= 720) {
		return 44;
	}
	else if (click.y >= 720 and click.y <= 810 and click.x >= 1615 and click.x <= 2155) {
		return 69 - (click.x / 90);
	}
	else if (click.x >= 1525 and click.x <= 1615 and click.y >= 810) {
		return (click.y / 90) + 42;
	}
	else if (click.x >= 1435 and click.x <= 1525 and click.y >= 1260) {
		return 57;
	}
	else if (click.x >= 1345 and click.x <= 1435 and click.y >= 810) {
		return 73 - (click.y / 90);
	}
	else if (click.y >= 720 and click.y <= 810 and click.x >= 810 and click.x <= 1345) {
		return 79 - (click.x / 90);
	}
	else if (click.x >= 720 and click.x <= 810 and click.y >= 810) {
		return 61 + (click.y / 90);
	}
	else if (click.x >= 630 and click.x <= 720 and click.y >= 1260) {
		return 76;
	}
	else if (click.x >= 540 and click.x <= 630 and click.y >= 810) {
		return 92 - (click.y / 90);
	}
	else if (click.y >= 720 and click.y <= 810 and click.x <= 540) {
		return 89 - (click.x / 90);
	}
	else if (click.y >= 630 and click.y <= 720 and click.x <= 90) {
		return 89;
	}
	// going in
	else if (click.y >= 630 and click.y <= 720 and click.x >= 90 and click.x <= 540) {
		return 89 + (click.x / 90);
		// setps for green // 
	}
	else if (click.x >= 630 and click.x <= 720 and click.y >= 90 and click.y <= 540) {
		return 94 + (click.y / 90);
		// orange // 
	}
	else if (click.x >= 1435 and click.x <= 1525 and click.y >= 90 and click.y <= 540) {
		return 99 + (click.y / 90);
		// yellow // 
	}
	else if (click.y >= 630 and click.y <= 720 and click.x >= 1615 and click.x <= 2065) {
		return ((click.x / 90) - 127) * (-1) + 1;

		// setps for red // 
	}
	else if (click.x >= 1435 and click.x <= 1525 and click.y >= 810 and click.y <= 1260) {
		return ((click.y / 90) - 123) * (-1) + 1;
		// purple // 
	}
	else if (click.x >= 630 and click.x <= 720 and click.y >= 810 and click.y <= 1260) {
		return ((click.y / 90) - 128) * (-1) + 1;
	}
	return -99;
}

void Ludo::changeTurn() {

	if (no_of_Players == 6) {
		if (turn != 5) {
			turn++;
			return;
		}
	}
	if (no_of_Players == 4) {
		if (turn != 3) {
			turn++;
			return;
		}
	}
	if (no_of_Players == 2) {
		if (turn != 1) {
			turn++;
			return;
		}
	}
	turn = 0;
}

bool Ludo::canMakeAMove(int die) {
	if (no_of_Players == 6) {
		switch (turn) {
		case 0:
			for (int i = 0; i < 4; i++) {
				if (board.pieces[i]->pos > 0 or board.pieces[i]->step > 87 and board.pieces[i]->step + die <= 93) {
					return true;
				}
			}
			break;
		case 1:
			for (int i = 4; i < 8; i++) {
				if (board.pieces[i]->pos > 0) {
					return true;
				}
			}
			break;
		case 2:
			for (int i = 8; i < 12; i++) {
				if (board.pieces[i]->pos > 0) {
					return true;
				}
			}
			break;
		case 5:
			for (int i = 12; i < 16; i++) {
				if (board.pieces[i]->pos > 0) {
					return true;
				}
			}
			break;
		case 4:
			for (int i = 16; i < 20; i++) {
				if (board.pieces[i]->pos > 0) {
					return true;
				}
			}
			break;
		case 3:
			for (int i = 20; i < 24; i++) {
				if (board.pieces[i]->pos > 0) {
					return true;
				}
			}
			break;
		}
	}

	else if (no_of_Players == 4) {
		switch (turn) {
		case 0:
			for (int i = 0; i < 4; i++) {
				if (board.pieces[i]->pos > 0) {
					return true;
				}
			}
			break;
		case 1:
			for (int i = 4; i < 8; i++) {
				if (board.pieces[i]->pos > 0) {
					return true;
				}
			}
			break;
		case 3:
			for (int i = 8; i < 12; i++) {
				if (board.pieces[i]->pos > 0) {
					return true;
				}
			}
			break;
		case 2:
			for (int i = 12; i < 16; i++) {
				if (board.pieces[i]->pos > 0) {
					return true;
				}
			}
			break;

		}
	}
	else if (no_of_Players == 2) {
		switch (turn) {
		case 0:
			for (int i = 0; i < 4; i++) {
				if (board.pieces[i]->pos > 0 or board.pieces[i]->step > 87 and board.pieces[i]->step + die <= 93) {
					return true;
				}
			}
			break;
		case 1:
			for (int i = 4; i < 8; i++) {
				if (board.pieces[i]->pos > 0) {
					return true;
				}
			}
			break;
		}
	}
	return dice_no[die] == 1 or dice_no[die] == 6;
}

bool Ludo::isValidSelection(int x, int die, bool& WD)
{
	if (x != -99 and x < 0 and (die != 1 and die != 6)) {
		WD = true;
		return false;
	}
	else {
		WD = false;
	}

	if (x < 0 and (die == 1 or die == 6)) {
		if (no_of_Players == 6) {
			if (turn == 0) {
				for (int i = 0; i < 4; i++) {
					if (board.pieces[i]->pos == x) //green
						return true;
				}
			}
			if (turn == 1) {
				for (int i = 4; i < 8; i++) {
					if (board.pieces[i]->pos == (x + 4)) // orange
						return true;
				}
			}
			if (turn == 2) {
				for (int i = 8; i < 12; i++) {
					if (board.pieces[i]->pos == (x + 8)) // yellow
						return true;
				}
			}
			if (turn == 5) {
				for (int i = 12; i < 16; i++) {
					if (board.pieces[i]->pos == (x + 12)) // blue
						return true;
				}
			}
			if (turn == 4) {
				for (int i = 16; i < 20; i++) {
					if (board.pieces[i]->pos == (x + 16)) // purple
						return true;
				}
			}
			if (turn == 3) {
				for (int i = 20; i < 24; i++) {
					if (board.pieces[i]->pos == (x + 20)) // red
						return true;
				}
			}
		}
		else if (no_of_Players == 4) {
			if (turn == 0) {
				for (int i = 0; i < 4; i++) {
					if (board.pieces[i]->pos == x) // green
						return true;
				}
			}
			if (turn == 1) {
				for (int i = 4; i < 8; i++) {
					if (board.pieces[i]->pos == (x + 8)) // yellow
						return true;
				}
			}
			if (turn == 3) {
				for (int i = 8; i < 12; i++) {
					if (board.pieces[i]->pos == (x + 12)) // blue
						return true;
				}
			}
			if (turn == 2) {
				for (int i = 12; i < 16; i++) {
					if (board.pieces[i]->pos == (x + 20)) // red
						return true;
				}
			}
		}
		else if (no_of_Players == 2) {
			if (turn == 0) {
				for (int i = 0; i < 4; i++) {
					if (board.pieces[i]->pos == x) // green
						return true;
				}
			}
			if (turn == 1) {
				for (int i = 4; i < 8; i++) {
					if (board.pieces[i]->pos == (x + 20)) // red
					{
						return true;
					}
				}
			}
		}
	}

	else if (x > 89) {
		if (no_of_Players == 6) {
			if (turn == 0) {
				for (int i = 0; i < 4; i++) {
					if (board.pieces[i]->step == x - 2) // green
						return true;
				}
			}
			if (turn == 1) {
				for (int i = 4; i < 8; i++) {
					if (board.pieces[i]->step == (x - 7)) // orange
						return true;
				}
			}
			if (turn == 2) {
				for (int i = 8; i < 12; i++) {
					if (board.pieces[i]->step == (x - 12)) // yellow
						return true;
				}
			}
			if (turn == 5) {
				for (int i = 12; i < 16; i++) {
					if (board.pieces[i]->step == (x - 27)) // blue
						return true;
				}
			}
			if (turn == 4) {
				for (int i = 16; i < 20; i++) {
					if (board.pieces[i]->step == (x - 22))
						return true;
				}
			}
			if (turn == 3) {
				for (int i = 20; i < 24; i++) {
					if (board.pieces[i]->step == (x - 17)) // red
						return true;
				}
			}
		}
		else if (no_of_Players == 4) {
			if (turn == 0) {
				for (int i = 0; i < 4; i++) {
					if (board.pieces[i]->step == x - 2)
						return true;
				}
			}
			if (turn == 1) {
				for (int i = 4; i < 8; i++) {
					if (board.pieces[i]->step == (x - 12))
						return true;
				}
			}
			if (turn == 3) {
				for (int i = 8; i < 12; i++) {
					if (board.pieces[i]->step == (x - 27))
						return true;
				}
			}
			if (turn == 2) {
				for (int i = 12; i < 16; i++) {
					if (board.pieces[i]->step == (x - 17))
						return true;
				}
			}
		}
		else if (no_of_Players == 2) {
			if (turn == 0) {
				for (int i = 0; i < 4; i++) {
					if (board.pieces[i]->step == x - 2)
						return true;
				}
			}
			if (turn == 1) {
				for (int i = 4; i < 8; i++) {
					if (board.pieces[i]->step == (x - 17))
						return true;
				}
			}
		}
	}

	else {
		if (no_of_Players == 6) {
			if (turn == 0) {
				for (int i = 0; i < 4; i++) {
					if (board.pieces[i]->pos == x)
						return true;
				}
			}
			if (turn == 1) {
				for (int i = 4; i < 8; i++) {
					if (board.pieces[i]->pos == (x))
						return true;
				}
			}
			if (turn == 2) {
				for (int i = 8; i < 12; i++) {
					if (board.pieces[i]->pos == (x))
						return true;
				}
			}
			if (turn == 5) {
				for (int i = 12; i < 16; i++) {
					if (board.pieces[i]->pos == (x))
						return true;
				}
			}
			if (turn == 4) {
				for (int i = 16; i < 20; i++) {
					if (board.pieces[i]->pos == (x))
						return true;
				}
			}
			if (turn == 3) {
				for (int i = 20; i < 24; i++) {
					if (board.pieces[i]->pos == (x))
						return true;
				}
			}
		}
		else if (no_of_Players == 4) {
			if (turn == 0) {
				for (int i = 0; i < 4; i++) {
					if (board.pieces[i]->pos == x)
						return true;
				}
			}
			if (turn == 1) {
				for (int i = 4; i < 8; i++) {
					if (board.pieces[i]->pos == (x))
						return true;
				}
			}
			if (turn == 3) {
				for (int i = 8; i < 12; i++) {
					if (board.pieces[i]->pos == (x))
						return true;
				}
			}
			if (turn == 2) {
				for (int i = 12; i < 16; i++) {
					if (board.pieces[i]->pos == (x))
						return true;
				}
			}
		}
		else if (no_of_Players == 2) {
			if (turn == 0) {
				for (int i = 0; i < 4; i++) {
					if (board.pieces[i]->pos == x)
						return true;
				}
			}
			if (turn == 1) {
				for (int i = 4; i < 8; i++) {
					if (board.pieces[i]->pos == (x)) {
						return true;
					}
				}
			}
		}
	}
	cout << "ourt";
	return false;
}

void Ludo::displayDice(RenderWindow& window) {
	if (dice_no.size() == 0) {
		Dice[pd - 1].setPosition(1255, 630);
		Dice[pd - 1].setScale(0.4f, 0.4f);
		window.draw(Dice[pd - 1]);
		return;
	}

	for (int i = 0; i < dice_no.size(); i++) {
		Dice[dice_no[i] - 1].setPosition(1255 - (i * 180), 630);
		Dice[dice_no[i] - 1].setScale(0.4f, 0.4f);
		window.draw(Dice[dice_no[i] - 1]);
	}
}

bool Ludo::RollDice(RenderWindow& window, Vector2f click, bool& six) {
	if (!(click.x >= 1255 and click.x <= 1345 and click.y >= 630 and click.y <= 720))
		return false;
	srand(time(0));
	for (int i = 0; i < 10; i++) {
		int r = rand() % 6;
		Dice[r].setPosition(1255, 630);
		Dice[r].setScale(0.4f, 0.4f);
		window.draw(Dice[r]);
		window.display();
		Sleep(100);
	}
	int _dice_no = rand() % 6 + 1;
	dice_no.push_back(_dice_no);
	if (_dice_no == 6)
		six = true;
	else
		six = false;

	Dice[_dice_no - 1].setPosition(1255, 630);
	Dice[_dice_no - 1].setScale(0.4f, 0.4f);
	window.draw(Dice[_dice_no - 1]);
	window.display();
	pd = dice_no[0];
	cout << "Success" << endl;
	return true;
}

bool Ludo::CheatRollDice(RenderWindow& window, int number, bool& six)
{
	if (number < 1 or number>6)
		return false;
	dice_no.push_back(number);
	if (number == 6)
		six = true;
	else
		six = false;

	Dice[number - 1].setPosition(1255, 630);
	Dice[number - 1].setScale(0.4f, 0.4f);
	window.draw(Dice[number - 1]);
	window.display();
	cout << "Dice: " << number << endl;
	pd = dice_no[0];
	return true;
}

int Ludo::selectDices(Vector2f click) {
	cout << "Stt: " << dice_no.size();
	if (dice_no.size() == 1)
		return 1;
	if (click.x >= 1255 and click.x <= (1255 + 90) and click.y >= 630 and click.y <= 630 + 90 and (dice_no.size() == 2 or dice_no.size() == 3)) {
		return 1;
	}
	else if (click.x >= (1255 - 180) and click.x <= (1255 + 90 - 180) and click.y >= 630 and click.y <= (630 + 90) and (dice_no.size() == 2 or dice_no.size() == 3)) {
		return 2;
	}
	else if (click.x >= (1255 - 2 * 180) and click.x <= (1255 + 90 - 2 * 180) and click.y >= 630 and click.y <= 630 + 90 and dice_no.size() == 3) {
		return 3;
	}
	return -99;
}

bool Ludo::three_sixes() {
	if (dice_no.size() != 3)
		return false;

	for (int i = 0; i < 3; i++) {
		if (dice_no[i] != 6)
			return false;
	}

	return true;
}

void Ludo::printTurn(RenderWindow& window) {

	turn_T.loadFromFile("sins.png");
	Sprite turn_sp(turn_T);
	turn_sp.setScale(0.4f, 0.4f);
	if (no_of_Players == 6) {
		if (turn == 0) {
			turn_sp.setPosition(0, 360);
		}
		else if (turn == 1) {
			turn_sp.setPosition(805, 360);
		}
		else if (turn == 2) {
			turn_sp.setPosition(1610, 360);
		}
		else if (turn == 5) {
			turn_sp.setPosition(0, 1170);
		}
		else if (turn == 4) {
			turn_sp.setPosition(805, 1170);
		}
		else if (turn == 3) {
			turn_sp.setPosition(1610, 1170);
		}
	}
	else if (no_of_Players == 4) {
		if (turn == 0) {
			turn_sp.setPosition(0, 360);
		}
		else if (turn == 2) {
			turn_sp.setPosition(1610, 360);
		}
		else if (turn == 3) {
			turn_sp.setPosition(0, 1170);
		}
		else if (turn == 2) {
			turn_sp.setPosition(1610, 1170);
		}
	}

	else if (no_of_Players == 2) {
		if (turn == 0) {
			turn_sp.setPosition(0, 360);
		}
		else if (turn == 1) {
			turn_sp.setPosition(1610, 1170);
		}
	}
	window.draw(turn_sp);
}

bool Ludo::areAllMovesDone()
{
	if (Ps[turn]->moves == 0)
		return true;
	return false;
}

bool Ludo::is_being_killed()
{

	if (no_of_Players == 6) {
		for (int i = 0; i < 24; i++) {
			if (i == piece_moved)
				continue;
			if (board.pieces[i]->pos == board.pieces[piece_moved]->pos and board.pieces[i]->getClr() != board.pieces[piece_moved]->getClr() and (board.pieces[i]->pos != 1 and board.pieces[i]->pos != 9 and board.pieces[i]->pos != 14 and board.pieces[i]->pos != 28 and board.pieces[i]->pos != 33 and board.pieces[i]->pos != 41 and board.pieces[i]->pos != 46 and board.pieces[i]->pos != 54 and board.pieces[i]->pos != 59 and board.pieces[i]->pos != 73 and board.pieces[i]->pos != 78 and board.pieces[i]->pos != 86 and board.pieces[i]->pos >= 0 and board.pieces[i]->pos != -99))
				return true;
		}
	}
	else if (no_of_Players == 4) {
		for (int i = 0; i < 16; i++) {
			if (i == piece_moved)
				continue;
			if (board.pieces[i]->pos == board.pieces[piece_moved]->pos and board.pieces[i]->getClr() != board.pieces[piece_moved]->getClr() and (board.pieces[i]->pos != 1 and board.pieces[i]->pos != 9 and board.pieces[i]->pos != 14 and board.pieces[i]->pos != 28 and board.pieces[i]->pos != 33 and board.pieces[i]->pos != 41 and board.pieces[i]->pos != 46 and board.pieces[i]->pos != 54 and board.pieces[i]->pos != 59 and board.pieces[i]->pos != 73 and board.pieces[i]->pos != 78 and board.pieces[i]->pos != 86 and board.pieces[i]->pos >= 0 and board.pieces[i]->pos != -99))
				return true;
		}
	}
	else if (no_of_Players == 2) {
		for (int i = 0; i < 8; i++) {
			if (i == piece_moved)
				continue;
			if (board.pieces[i]->pos == board.pieces[piece_moved]->pos and board.pieces[i]->getClr() != board.pieces[piece_moved]->getClr() and (board.pieces[i]->pos != 1 and board.pieces[i]->pos != 9 and board.pieces[i]->pos != 14 and board.pieces[i]->pos != 28 and board.pieces[i]->pos != 33 and board.pieces[i]->pos != 41 and board.pieces[i]->pos != 46 and board.pieces[i]->pos != 54 and board.pieces[i]->pos != 59 and board.pieces[i]->pos != 73 and board.pieces[i]->pos != 78 and board.pieces[i]->pos != 86 and board.pieces[i]->pos >= 0 and board.pieces[i]->pos != -99))
				return true;
		}
	}

	return false;
}

void Ludo::kill() {
	COLOR clr;
	if (turn == 0)
		clr = Green;
	else if (turn == 1)
		clr = Orange;
	else if (turn == 2)
		clr = Yellow;
	else if (turn == 3)
		clr = Red;
	else if (turn == 4)
		clr = Purple;
	else if (turn == 5)
		clr = Blue;

	if (no_of_Players == 6) {
		for (int i = 0; i < 24; i++) {
			if (i == piece_moved)
				continue;
			if (board.pieces[i]->pos == board.pieces[piece_moved]->pos) {
				int j = (i / 4);
				for (int k = j * 4, l = -1; j < k + 4; k++, l--) {
					if (board.pieces[k]->pos != l) {
						board.pieces[i]->pos = l;
						board.pieces[i]->step = 0;
						return;
					}
					if (l == -4)
						l = 0;
				}
			}
		}
	}
	else if (no_of_Players == 4) {
		for (int i = 0; i < 16; i++) {
			if (i == piece_moved)
				continue;
			if (board.pieces[i]->pos == board.pieces[piece_moved]->pos) {
				int j = (i / 4);
				for (int k = j * 4, l = -1; j < k + 4; k++, l--) {
					if (board.pieces[k]->pos != l) {
						board.pieces[i]->pos = l;
						board.pieces[i]->step = 0;
						return;
					}
					if (l == -4)
						l = 0;
				}
			}
		}
	}

	else if (no_of_Players == 2) {
		for (int i = 0; i < 8; i++) {
			if (i == piece_moved)
				continue;
			if (board.pieces[i]->pos == board.pieces[piece_moved]->pos) {
				int j = (i / 4);
				for (int k = j * 4, l = -1; j < k + 4; k++, l--) {
					if (board.pieces[k]->pos != l) {
						board.pieces[i]->pos = l;
						board.pieces[i]->step = 0;
						return;
					}
					if (l == -4)
						l = 0;
				}
			}
		}
	}
}

void Ludo::is_Done() {
	bool tr = true;
	if (no_of_Players == 6) {
		if (turn == 0 and !Ps[turn]->isDone) {
			for (int i = 0; i < 4; i++) {
				if (!board.pieces[i]->isIn)
					return;
			}
			Ps[turn]->isDone = true;
			Ps[turn]->Position = ++current_alloted_position;

			return;
		}
		else if (turn == 1 and !Ps[turn]->isDone) {
			for (int i = 4; i < 8; i++) {
				if (!board.pieces[i]->isIn)
					return;
			}
			Ps[turn]->isDone = true;
			Ps[turn]->Position = ++current_alloted_position;
			return;
		}
		else if (turn == 2 and !Ps[turn]->isDone) {
			for (int i = 8; i < 12; i++) {
				if (!board.pieces[i]->isIn)
					return;
			}
			Ps[turn]->isDone = true;
			Ps[turn]->Position = ++current_alloted_position;
			return;
		}
		else if (turn == 5 and !Ps[turn]->isDone) {
			for (int i = 12; i < 16; i++) {
				if (!board.pieces[i]->isIn)
					return;
			}
			Ps[turn]->isDone = true;
			Ps[turn]->Position = ++current_alloted_position;
			return;
		}
		else if (turn == 4 and !Ps[turn]->isDone) {
			for (int i = 16; i < 20; i++) {
				if (!board.pieces[i]->isIn)
					return;
			}
			Ps[turn]->isDone = true;
			Ps[turn]->Position = ++current_alloted_position;
			return;
		}
		else if (turn == 3 and !Ps[turn]->isDone) {
			for (int i = 0; i < 4; i++) {
				if (!board.pieces[i]->isIn)
					return;
			}
			Ps[turn]->isDone = true;
			Ps[turn]->Position = ++current_alloted_position;
			return;
		}
	}
	else if (no_of_Players == 4) {
		if (turn == 0 and !Ps[turn]->isDone) {
			for (int i = 0; i < 4; i++) {
				if (!board.pieces[i]->isIn)
					return;
			}
			Ps[turn]->isDone = true;
			Ps[turn]->Position = ++current_alloted_position;

			return;
		}
		else if (turn == 1 and !Ps[turn]->isDone) {
			for (int i = 4; i < 8; i++) {
				if (!board.pieces[i]->isIn)
					return;
			}
			Ps[turn]->isDone = true;
			Ps[turn]->Position = ++current_alloted_position;
			return;
		}
		else if (turn == 3 and !Ps[turn]->isDone) {
			for (int i = 8; i < 12; i++) {
				if (!board.pieces[i]->isIn)
					return;
			}
			Ps[turn]->isDone = true;
			Ps[turn]->Position = ++current_alloted_position;
			return;
		}
		else if (turn == 2 and !Ps[turn]->isDone) {
			for (int i = 12; i < 16; i++) {
				if (!board.pieces[i]->isIn)
					return;
			}
			Ps[turn]->isDone = true;
			Ps[turn]->Position = ++current_alloted_position;
			return;
		}
	}
	else if (no_of_Players == 2) {
		if (turn == 0 and !Ps[turn]->isDone) {
			for (int i = 0; i < 4; i++) {
				if (!board.pieces[i]->isIn)
					return;
			}
			Ps[turn]->isDone = true;
			++current_alloted_position;
			Ps[turn]->Position = current_alloted_position;
			return;
		}
		else if (turn == 1 and !Ps[turn]->isDone) {
			for (int i = 4; i < 8; i++) {
				if (!board.pieces[i]->isIn)
					return;
			}
			Ps[turn]->isDone = true;
			Ps[turn]->Position = ++current_alloted_position;
			return;
		}
	}
}

void Ludo::print_positions(RenderWindow& window) {
	for (int i = 0; i < Awards.size(); i++) {
		Awards[i].setScale(0.4, 0.4);
	}

	if (no_of_Players == 6) {
		if (Ps[0]->isDone)
		{
			Awards[Ps[0]->Position - 1].setPosition(0, 0);
			window.draw(Awards[Ps[0]->Position - 1]);
		}
		else if (Ps[1]->isDone)

		{
			Awards[Ps[1]->Position - 1].setPosition(810, 0);
			window.draw(Awards[Ps[1]->Position - 1]);
		}
		else if (Ps[2]->isDone)

		{
			Awards[Ps[2]->Position - 1].setPosition(1617, 0);
			window.draw(Awards[Ps[2]->Position - 1]);
		}
		else if (Ps[3]->isDone)
		{
			Awards[Ps[3]->Position - 1].setPosition(2129, 840);
			window.draw(Awards[Ps[3]->Position - 1]);
		}
		else if (Ps[4]->isDone)
		{
			Awards[Ps[4]->Position - 1].setPosition(1290, 840);
			window.draw(Awards[Ps[4]->Position - 1]);
		}
		else if (Ps[5]->isDone)
		{
			Awards[Ps[5]->Position - 1].setPosition(485, 840);
			window.draw(Awards[Ps[5]->Position - 1]);
		}

	}
	else if (no_of_Players == 4) {
		if (Ps[0]->isDone)
		{
			Awards[Ps[0]->Position - 1].setPosition(0, 0);
			window.draw(Awards[Ps[0]->Position - 1]);
		}
		else if (Ps[1]->isDone)
		{
			Awards[Ps[1]->Position - 1].setPosition(1617, 0);
			window.draw(Awards[Ps[1]->Position - 1]);
		}
		else if (Ps[2]->isDone)
		{
			Awards[Ps[2]->Position - 1].setPosition(2129, 840);
			window.draw(Awards[Ps[2]->Position - 1]);
		}
		else if (Ps[3]->isDone)
		{
			Awards[Ps[3]->Position - 1].setPosition(485, 840);
			window.draw(Awards[Ps[3]->Position - 1]);
		}

	}
	else if (no_of_Players == 2) {
		if (Ps[0]->isDone)
		{
			Awards[Ps[0]->Position - 1].setPosition(0, 0);
			window.draw(Awards[Ps[0]->Position - 1]);
		}
		else if (Ps[1]->isDone)
		{
			Awards[Ps[1]->Position - 1].setPosition(2129, 840);
			window.draw(Awards[Ps[1]->Position - 1]);
		}
	}
}