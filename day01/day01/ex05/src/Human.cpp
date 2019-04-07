#include "./../includes/Human.hpp"

Human::Human() {}

Human::~Human() {}

std::string	Human::identify(void) {
	return (this->_brain.identify());
}

Brain		Human::getBrain(void) {
	return (this->_brain);
}
