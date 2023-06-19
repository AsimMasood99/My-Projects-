#pragma once
#include"piece.h"

class Pown :public Piece {
public:
	Pown(pos P, int c, char s);
	void print_piece(int r, int c, int clr_Sp) override;
	bool isValidMove(Piece*** Board, pos Src, pos Des)override;
	Pown* clone() const override;
};
