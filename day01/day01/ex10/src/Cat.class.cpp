#include "./../includes/Cat.class.hpp"

Cat::Cat(void) {}

Cat::~Cat(void) {}

void	Cat::read(std::string file) {
	std::fstream	fh;
	std::string		res;

	fh.open(file.c_str());
	if (fh.is_open()) {
		while (getline(fh, res)) {
			std::cout << res << std::endl;
		}
		fh.close();
	}
	else {
		std::cout << file << " no such file" << std::endl;
	}
	
}
