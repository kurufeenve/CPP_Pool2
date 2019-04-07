//
// Created by Dmitro LITVINENKO on 2019-04-06.
//

#ifndef RUSH00_PLAYER_HPP
#define RUSH00_PLAYER_HPP

#include "GameObject.hpp"
#include <string>

class Player : public GameObject
{

public:

	Player();
	Player(const Player &);
	Player(unsigned x, unsigned y, unsigned level, unsigned speed, unsigned life);
	~Player();

	Player &operator = (const Player &);

	void    die();

};

RUSH00_PLAYER_HPP
#endif //RUSH00_PLAYER_HPP
