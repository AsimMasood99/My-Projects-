#pragma once
#include"piece.h"

class Queen :public Piece {
public:
	Queen(pos P, int c, char s);
	void print_piece(int r, int c, int clr_Sp) override;
	bool isValidMove(Piece*** Board, pos Src, pos Des)override;
	Queen* clone() const override;
};
