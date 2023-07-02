#pragma once
#include<SFML/Graphics.hpp>
#include"Piece.h"
#include<iostream>
#include"Board.h"
#include<Windows.h>
#include"Player.h"
using namespace std;
using namespace sf;

class Ludo
{
	vector<Sprite> Dice;
	vector<Sprite> Awards;
	Texture dice1;
	Texture dice2;
	Texture dice3;
	Texture dice4;
	Texture dice5;
	Texture dice6;


	Texture awd1;
	Texture awd2;
	Texture awd3;
	Texture awd4;
	Texture awd5;
	Texture awd6;

	sf::Texture turn_T;

	int pd;
	int current_alloted_position;
public:
	int piece_moved;
	vector<int> dice_no;
	Board board;
	int no_of_Players;
	int turn;
	Player** Ps;
	bool cheating; // use the landing page shit
	Ludo(int nop, bool cheat);
	int Selection(Vector2f click);
	void changeTurn();
	void displayDice(RenderWindow& window);
	bool canMakeAMove(int die);
	bool isValidSelection(int x, int die, bool& WD);
	bool RollDice(RenderWindow& window, Vector2f click, bool& six);
	bool CheatRollDice(RenderWindow& window, int number, bool& six);
	int selectDices(Vector2f click);
	bool three_sixes();
	void printTurn(RenderWindow& window);
	bool areAllMovesDone();
	bool is_being_killed();
	void kill();
	void is_Done();
	void print_positions(RenderWindow& window);

};
