#include "./../includes/Zombie.hpp"

Zombie::Zombie(void) {}

Zombie::~Zombie(void) {}

void	Zombie::announce(void) const {
	std::cout << this->_name << " ("
	<< this->_type << ") Braiiiiiiinnnssss..." << std::endl;
}

void	Zombie::setName(std::string name) {
	this->_name = name;
}

void	Zombie::setType(std::string type) {
	this->_type = type;
}
