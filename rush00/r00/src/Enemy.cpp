//
// Created by Dmitro LITVINENKO on 2019-04-06.
//

#include "./../includes/Enemy.hpp"
#include <fstream>

Enemy::Enemy(const Enemy &object)
{
	operator=(object);
}

Enemy &Enemy::operator=(Enemy const &object)
{
	GameObject::operator=(object);
	return *this;
}

Enemy::Enemy(unsigned level, unsigned speed)
	: GameObject(0, 0, level, speed, 1, "E", "Enemy") {

		int		x;

		x = rand() % 177 + 1;
		this->setX(x);
		this->setY(2);
		this->_boxX = 0;
		this->_boxY = 0;
		this->_direction = 0;
	}

Enemy::~Enemy() {}

Enemy::Enemy() {}

void    Enemy::die() {}
