#pragma once

#include <string>
#include "Player.h"
#include "Level.h"

using namespace std;

class Game
{
public:
	Game(string levelFileName);
	void play();
	void playerMove();
private:
	Player _player;
	Level _level;
};