#include "./../includes/Cat.class.hpp"

int		main(int ac, char **av) {
	for (int i = 1; i < ac; i++) {
		Cat::read(av[i]);
	}
	return (0);
}
