#include "./../includes/Brain.hpp"

Brain::Brain(void) {}

Brain::~Brain(void) {}

std::string		Brain::identify(void) {
	std::stringstream	ptr;
	std::string			address;

	ptr << this;
	address = ptr.str();
	return (address);
}
