#pragma once
#include<string>
#include<Windows.h>
#include<iostream>
#include"piece.h"

using namespace std;

class Player {
private:
	string name;
public:
	Player(string n);
	string getPlayerName();
	static void getRowColbyLeftClick(int& rpos, int& cpos);
	pos SelectPos();
};

