//
// Created by Dmitro LITVINENKO on 2019-04-06.
//

#ifndef RUSH00_BULLET_HPP
#define RUSH00_BULLET_HPP

#include "GameObject.hpp"

class Bullet : public GameObject
{

public:

	Bullet();
	Bullet(const Bullet &);
	Bullet(unsigned x, unsigned y, unsigned level, unsigned moveSpeed,
	unsigned livesCount, int direction);
	~Bullet();
	void	die(void);

	Bullet &operator=(const Bullet &);

	static unsigned _bulletCount;
	int             _direction;

};

RUSH00_BULLET_HPP
#endif //RUSH00_BULLET_HPP
