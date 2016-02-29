#include <stdio.h>
#include <conio.h>
#include <string>
#include <cstdlib>
#include "Game.h"

using namespace std;

int main()
{

	Game game("level0.txt");
	game.play();
	return 0;
}