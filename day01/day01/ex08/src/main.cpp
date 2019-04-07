#include "./../includes/Human.hpp"
#include <iostream>
#include <string>

int		main(void)
{
	Human		human;
	std::string	actions[] = {"melee", "range", "intimidating shout"};

	for (int i = 0; i < 3; i++)
	{
		human.action(actions[i], "Bob");
	}
	return (0);
}