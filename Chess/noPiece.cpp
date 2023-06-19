#include "noPiece.h"

noPiece::noPiece(pos P, int c, char s) :
	Piece(P, c, s) 
{
}
void noPiece::print_piece(int r, int c, int clr_Sp) {
	return;
}
bool noPiece::isValidMove(Piece*** Board, pos Src, pos Des) {
	return false;
}

noPiece* noPiece::clone() const
{
	return new noPiece(*this);
}
