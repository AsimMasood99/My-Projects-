#include "Piece.h"

Piece::Piece() {
	clr = Nothing;
	pos = -1;
	step = 0;
}

Piece::Piece(int p, COLOR color) {
	pos = p;
	clr = color;
	switch (clr)
	{
	case Red:
		piece_tex.loadFromFile("red.png");
		break;
	case Blue:
		piece_tex.loadFromFile("blue.png");
		break;
	case Green:
		piece_tex.loadFromFile("green.png");
		break;
	case Yellow:
		piece_tex.loadFromFile("yellow.png");
		break;
	case Orange:
		piece_tex.loadFromFile("orange.png");
		break;
	case Purple:
		piece_tex.loadFromFile("purple.png");
		break;
	}
	piece.setTexture(piece_tex);
	step = 0;
	isIn = false;
}

void Piece::printPiece(sf::RenderWindow& window) {
	int boxSize = 90;
	piece.setScale(0.82f, 0.8f);
	if (clr == Green) {
		if (pos == -1)
			piece.setPosition(190, 170);
		else if (pos == -2)
			piece.setPosition(300, 170);
		else if (pos == -3)
			piece.setPosition(190, 290);
		else if (pos == -4)
			piece.setPosition(300, 290);
	}
	else if (clr == Orange) {
		if (pos == -1)
			piece.setPosition(990, 170);
		else if (pos == -2)
			piece.setPosition(1100, 170);
		else if (pos == -3)
			piece.setPosition(990, 290);
		else if (pos == -4)
			piece.setPosition(1100, 290);
	}
	else if (clr == Yellow) {
		if (pos == -1)
			piece.setPosition(1800, 160);
		else if (pos == -2)
			piece.setPosition(1910, 160);
		else if (pos == -3)
			piece.setPosition(1800, 280);
		else if (pos == -4)
			piece.setPosition(1910, 280);
	}
	else if (clr == Blue) {
		if (pos == -1)
			piece.setPosition(190, 980);
		else if (pos == -2)
			piece.setPosition(300, 980);
		else if (pos == -3)
			piece.setPosition(190, 1100);
		else if (pos == -4)
			piece.setPosition(300, 1100);
	}
	else if (clr == Purple) {
		if (pos == -1)
			piece.setPosition(990, 980);
		else if (pos == -2)
			piece.setPosition(1100, 980);
		else if (pos == -3)
			piece.setPosition(990, 1100);
		else if (pos == -4)
			piece.setPosition(1100, 1100);
	}
	else if (clr == Red) {
		if (pos == -1)
			piece.setPosition(1800, 980);
		else if (pos == -2)
			piece.setPosition(1910, 980);
		else if (pos == -3)
			piece.setPosition(1800, 1100);
		else if (pos == -4)
			piece.setPosition(1910, 1100);
	}

	

	if (pos >= 0 and pos <= 5) {
		piece.setPosition(25 + (pos * boxSize), 545);
	}
	else if (pos >= 6 and pos <= 11) {
		piece.setPosition(25 + 545, ((11 - pos) * boxSize)+ 10);
	}
	else if (pos == 12) {
		piece.setPosition(25 + 635, 10);
	}
	else if (pos >= 13 and pos <= 18) {
		piece.setPosition(25 + 725, ((pos - 13) * boxSize) + 10);
	}
	else if (pos >= 19 and pos <= 24) {
		piece.setPosition(((pos - 19) * boxSize) + 804 + 25, 545);
	}
	else if (pos >= 25 and pos <= 30) {
		piece.setPosition(1360 + 10, ((25 - pos) * boxSize) + 450 + 10);
	}
	else if (pos == 31) {
		piece.setPosition(25 + 1440, 10);
	}
	else if (pos >= 32 and pos <= 37) {
		piece.setPosition(25 + 1520, ((pos - 32) * boxSize) + 10);
	}
	else if (pos >= 38 and pos <= 43) {
		piece.setPosition(((pos - 38) * boxSize) + 1610 + 25, 550);
	}
	else if (pos == 44) {
		piece.setPosition(2090, 640);
	}
	else if (pos >= 45 and pos <= 50) {
		piece.setPosition(2090 - ((pos-45)*boxSize), 730);
	}
	else if (pos >= 51 and pos <= 56) {
		piece.setPosition(1545, ((pos - 51) * boxSize) + 820);
	}
	else if (pos == 57) {
		piece.setPosition(1455, 1265);
	}
	else if (pos >= 58 and pos <= 63) {
		piece.setPosition(1375, ((58 - pos) * boxSize) +1265);
	}
	else if (pos >= 64 and pos <= 69) {
		piece.setPosition(1285 - ((pos - 64) * boxSize), 730);
	}
	else if (pos >= 70 and pos <= 75) {
		piece.setPosition(735, ((pos - 70) * boxSize) + 820);
	}
	else if (pos == 76) {
		piece.setPosition(650, 1265);
	}
	else if (pos >= 77 and pos <= 82) {
		piece.setPosition( 560, ((77 - pos) * boxSize) + 1265);
	}
	else if (pos >= 83 and pos <= 88) {
		piece.setPosition(470 - ((pos - 83) * boxSize), 730);
	}
	else if (pos >= 89 and pos <= 90) {
		piece.setPosition(20, 640-((pos - 89 ) * boxSize) );
	}

	if (step >= 88) {
		if (clr == Green) {
			piece.setPosition(110 + ((step - 88) * boxSize), 640);
		}
		else if (clr == Orange) {
			piece.setPosition(640, ((step - 88) * boxSize) + 100);
		}
		else if (clr == Yellow) {
			piece.setPosition(1455, ((step - 88) * boxSize) + 100);
		}
		else if (clr == Red) {
			piece.setPosition(2010 - ((step - 88) * boxSize), 640);
		}
		else if (clr == Purple) {
			piece.setPosition(1455, 1180 - ((step - 88) * boxSize));
		}
		else if (clr == Blue) {
			piece.setPosition(640, 1180 - ((step - 88) * boxSize));
		}
	}

	window.draw(piece);
}

COLOR Piece::getClr() {
	return clr;
}


