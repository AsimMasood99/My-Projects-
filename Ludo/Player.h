#pragma once
#include<string>

using namespace std;


class Player
{
	string Pname;
	
public:
	bool isDone;
	int moves;
	int Position;	 
	Player(string name);
};
