#pragma once
#include"piece.h"

class King :public Piece {
public:
	King(pos P, int c, char s);
	void print_piece(int r, int c, int clr_Sp) override;
	bool isValidMove(Piece ***Board, pos Src, pos Des)override;
	King* clone() const override;
};

