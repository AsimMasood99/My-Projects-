#pragma once
#include"piece.h"

class noPiece :public Piece{

public:
	noPiece(pos P, int c, char s);
	void print_piece(int r, int c, int clr_Sp) override;
	bool isValidMove(Piece*** Board, pos Src, pos Des)override;
	noPiece * clone() const override;
};

