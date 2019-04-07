#ifndef ZOMBIEHORDE_HPP
# define ZOMBIEHORDE_HPP

# include "./../includes/Zombie.hpp"
# include <iostream>

class ZombieHorde
{
private:
	int		_numZombie;
	Zombie	*_horde;

public:
	ZombieHorde();
	ZombieHorde(int	N);
	~ZombieHorde();
	void	announce(void);
};

#endif
