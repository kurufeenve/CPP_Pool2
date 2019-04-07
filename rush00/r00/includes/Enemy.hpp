//
// Created by Dmitro LITVINENKO on 2019-04-06.
//

#ifndef RUSH00_ENEMY_HPP
#define RUSH00_ENEMY_HPP

#include "GameObject.hpp"

class Enemy : public GameObject
{

private:

	int     _boxX;
	int     _boxY;
	int     _direction;

public:

	Enemy();
	Enemy(const Enemy &);
	Enemy(unsigned, unsigned);
	~Enemy();

	void    die();

	Enemy &operator=(const Enemy &);

};

RUSH00_ENEMY_HPP
#endif //RUSH00_ENEMY_HPP
