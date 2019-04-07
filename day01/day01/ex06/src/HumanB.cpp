#include "./../includes/HumanB.hpp"

HumanB::HumanB(void) {}

HumanB::HumanB(std::string name) : _name(name) {}

HumanB::~HumanB(void) {}

void	HumanB::attack(void) {
	std::cout << this->_name << " attacks with \"AAAAAAAaaaaaaaaaaaa\" and his weapon is "
	<< this->_wp.getType() << std::endl;
}

void	HumanB::setWeapon(Weapon wp) {
	this->_wp = wp;
}
