#include "./../includes/ZombieEvent.hpp"

ZombieEvent::ZombieEvent(void) {}

ZombieEvent::~ZombieEvent(void) {}

void		ZombieEvent::setZombieType(std::string type) {
	this->_type = type;
}

Zombie		*ZombieEvent::newZombie(std::string name) {
	Zombie	*zombie = new Zombie();

	zombie->setName(name);
	zombie->setType(this->_type);
	return (zombie);
}

Zombie		*ZombieEvent::randomChump(void) {
	Zombie	*zombie = new Zombie();
	std::string	names[] = {"sweet brains", "giant brains", "dick brains", "your mom's brains"};
	int			i;

	i = rand() % 4;
	zombie->setName(names[i]);
	zombie->setType(this->_type);
	zombie->announce();
	return (zombie);
}
