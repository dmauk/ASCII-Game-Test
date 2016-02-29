#include "Player.h"

Player::Player()
{
	_x = 0;
	_y = 0;
};

void Player::init(int health, int attack, int defense, int level, int experience)
{
	_health = health;
	_attack = attack;
	_defense = defense;
	_level = level;
	_experience = experience;
}

void Player::setLocation(int x, int y)
{
	_x = x;
	_y = y;
}

void Player::getLocation(int &x, int &y)
{
	x = _x;
	y = _y; 
}
