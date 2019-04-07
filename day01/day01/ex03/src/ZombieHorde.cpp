#include "./../includes/ZombieHorde.hpp"
#include <sys/time.h>

ZombieHorde::ZombieHorde(int N) {
	std::string	names[] = {"Nola", "Shalon", "Asuncion", "your mom's brains",
		"Evalyn", "Shawn", "Quinton", "Shakita", "Omar", "Micheal", "Harriett", 
		"Kayce", "Matthew", "Jutta", "Sudie", "Moises", "Dena", "Krystin"};
	
	std::string	types[] = {"green", "yelow", "white", "blue",
		"black", "brown", "rose", "rose gold", "cyan", "gold", "opsidian black", 
		"red", "olive", "IP67", "IP65", "tank", "gnome", "worm"};
	
	struct timeval time;
	gettimeofday(&time, NULL);
	srand((time.tv_sec * 100000) + (time.tv_usec / 100000));
	
	if (N <= 0)
		std::cout << "There is no horde" << std::endl;
	else
	{
		this->_numZombie = N;
		this->_horde = new Zombie[N];
		for (int i = 0; i < N; i++)
		{
			this->_horde[i].setType(types[rand() % 18]);
			this->_horde[i].setName(names[rand() % 18]);
		}
	}
}

ZombieHorde::~ZombieHorde() {
	if (this->_numZombie > 0)
		delete [] this->_horde;
}

void	ZombieHorde::announce(void)
{
	for (int i = 0; i < this->_numZombie; i++)
		this->_horde[i].announce();
}
