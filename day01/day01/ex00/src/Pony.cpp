#include "./../includes/Pony.hpp"

Pony::Pony(void) : _name("NAN"),
			 _id("NAN"),
			 _sex("NAN"),
			 _thinkOf("NAN") {}

Pony::Pony(std::string name,
		   std::string id,
		   std::string sex,
		   std::string thinkOf) :
			 _name(name),
			 _id(id),
			 _sex(sex),
			 _thinkOf(thinkOf) {}

Pony::~Pony(void) {}

void	Pony::getFullInfo(void) {
	std::cout << this->_name << this->_id
	<< this->_sex << this->_thinkOf << std::endl;
}
