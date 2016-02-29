#include "Level.h"



Level::Level()
{
}

void Level::loadLevel(string levelFileName, Player &player)
{
	//Load Level
	ifstream file;
	file.open(levelFileName);
	if (file.fail())
	{
		perror(levelFileName.c_str());
		system("PAUSE");
		exit(1);
	}
	string line;
	while (getline(file, line))
	{
		_levelData.push_back(line);
	}
	file.close();

	//Process Level
	char tile;
	for (int i = 0; i < _levelData.size(); i++) {
		for (int j = 0; j < _levelData[i].size(); j++)
		{
			tile = _levelData[i][j];
			switch (tile) {
			case '@':
				player.setLocation(j, i);
				break;
			default:
				//cout << "Unrecognized tile" << endl;
				break;
			}
		}
	}
};

void Level::print()
{
	cout << string(100, '\n');
	for (int i = 0; i < _levelData.size(); i++)
	{
		cout << _levelData[i];
		cout << endl;
	}
	cout << endl;
}

void Level::movePlayer(char input, Player &player)
{
	int playerX;
	int playerY;
	player.getLocation(playerX, playerY);
	switch (input) {
	case 'w':
	case 'W':
		processPlayerMove(player, playerX, playerY - 1);
		break;
	case 's':
	case 'S':
		processPlayerMove(player, playerX, playerY + 1);
		break;
	case 'a':
	case 'A':
		processPlayerMove(player, playerX-1, playerY);
		break;
	case 'd':
	case 'D':
		processPlayerMove(player, playerX + 1, playerY);
		break;
	default:
		cout << "invalid input" << endl;
		system("PAUSE");
		break;
	}
}

char Level::getTile(int x, int y)
{
	return _levelData[y][x];
}

void Level::setTile(int x, int y, char tile)
{
	_levelData[y][x] = tile;
}

void Level::processPlayerMove(Player &player, int x, int y)
{
	int playerX;
	int playerY;
	player.getLocation(playerX, playerY);
	char moveTile;
	moveTile = getTile(x, y);
	switch (moveTile) {
	case '.':
		player.setLocation(x,y);
		setTile(playerX,playerY, '.');
		setTile(x,y, '@');
	}
}