#include "./../includes/HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &wp) : _name(name), _wp(wp) {}

HumanA::~HumanA(void) {}

void	HumanA::attack(void) {
	std::cout << this->_name << " attacks with \"AAAAAAAaaaaaaaaaaaa\" and his weapon is "
	<< this->_wp.getType() << std::endl;
}
