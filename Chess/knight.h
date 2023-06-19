#pragma once
#include"piece.h"

class Knight :public Piece {
public:
	Knight(pos P, int c, char s);
	void print_piece(int r, int c, int clr_Sp) override;
	bool isValidMove(Piece*** Board, pos Src, pos Des)override;
	Knight* clone() const override;
};


