#pragma once
#include<SFML/Graphics.hpp>
#include"Piece.h"
#include<vector>
using namespace std;
class Board
{
protected:
	int dim; // Matlab kitna players ka lia board hona ha generate
	sf::Texture board_T;
	sf::Sprite Board_S;


public:
	Board(int nop);
	vector<Piece*> pieces;
	void printBoard(sf::RenderWindow& Window,int nop);
	void move(int die, int pos,int turn,int &piece_moved,int nop);
};

