#pragma once
#include<SFML/Graphics.hpp>

enum COLOR { Red, Blue, Green, Yellow, Orange, Purple, Nothing };

class Piece {

protected:
	COLOR clr;
	sf::Texture piece_tex;
	sf::Sprite piece;
public:
	bool isIn;
	int pos;
	int step; 
	Piece();
	Piece(int p,COLOR color);
	void printPiece(sf::RenderWindow& window);
	COLOR getClr();
};

