#pragma once
#include"piece.h"

class Bishop :public Piece {
public:
	Bishop(pos P, int c, char s);
	void print_piece(int r, int c, int clr_Sp) override;
	bool isValidMove(Piece ***Board, pos Src, pos Des)override;
	Bishop* clone() const override;
};

