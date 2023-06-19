#pragma once
#include"piece.h"
#include"utility.h"
class Rook :public Piece {
public:
	Rook(pos P, int c, char s);
	void print_piece(int r, int c, int clr_Sp) override;
	bool isValidMove(Piece*** Board, pos Src, pos Des)override;
	Rook* clone() const override;
};