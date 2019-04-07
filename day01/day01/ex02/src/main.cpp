#include "./../includes/ZombieEvent.hpp"

int		main(void)
{
	Zombie		*Alice;
	Zombie		*Bob;
	ZombieEvent	event;

	srand(time(NULL));
	event.setZombieType("green");
	Alice = event.randomChump();
	Bob = event.randomChump();

	return (0);
}
