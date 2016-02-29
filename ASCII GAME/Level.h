#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include "Player.h"
using namespace std;

class Level
{
public:
	Level();
	void loadLevel(string levelFileName, Player &player);
	void print();
	void movePlayer(char input, Player &player);
	char getTile(int x, int y);
	void setTile(int x, int y, char tile);
private:
	void processPlayerMove(Player &player, int x, int y);
	vector <string> _levelData;

};

