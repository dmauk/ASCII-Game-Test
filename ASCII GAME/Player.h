#pragma once

class Player {
public:
	//Constructors
	Player();
	void init(int health, int attack, int defense, int level, int experience);

	//Functions
	void setLocation(int x, int y);
	void getLocation(int &x, int& y);

private:
	//Stats
	int _health;
	int _attack;
	int _defense;
	int _level;
	int _experience;
	
	//Location
	int _x;
	int _y;
};