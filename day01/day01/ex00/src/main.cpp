#include "./../includes/Pony.hpp"
#include <iostream>

void	ponyOnTheStack(void) {
	Pony	pony = Pony("cristi\n", "0454897\n", "NO\n", "None\n");

	std::cout << "pony on the stack" << std::endl;
	pony.getFullInfo();
	std::cout << "trying to delete from stack" << std::endl;
	pony.~Pony();
	std::cout << "result" << std::endl;
	pony.getFullInfo();
	
}

void	ponyOnTheHeap(void) {
	Pony	*pony = new Pony("cristi\n", "0454897\n", "NO\n", "None\n");

	std::cout << "print info" << std::endl;
	pony->getFullInfo();
	std::cout << "trying to delete from heap" << std::endl;
	delete(pony);
	//pony = NULL;
	std::cout << "result" << std::endl;
	pony->getFullInfo();
}

int		main(void)
{
	ponyOnTheStack();
	std::cout << std::endl;
	ponyOnTheHeap();
	//system("leaks pony");
	return (0);
}