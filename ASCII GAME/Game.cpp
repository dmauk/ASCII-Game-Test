#include "Game.h"
#include <conio.h>

Game::Game(string levelFileName)
{
	_player.init(1, 100, 10, 10, 0);
	_level.loadLevel(levelFileName,_player);
	cout << "level loaded"<<endl;
}

void Game::play() 
{
	bool isDone = false;
	while (isDone == false)
	{
		_level.print();
		playerMove();
	}
}

void Game::playerMove() {
	char input;
	cout << "Enter move" << endl;
	input = _getch();
	_level.movePlayer(input, _player);
}