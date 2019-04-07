#include "./../includes/Human.hpp"

void	Human::meleeAttack(std::string const & target)
{
	std::cout << "Human is going to attack with a melee weapon on " << target << std::endl;
}

void	Human::rangedAttack(std::string const & target)
{
	std::cout << "Human is going to attack with a range weapon on " << target << std::endl;
}

void	Human::intimidatingShout(std::string const & target)
{
	std::cout << "Human is going to attack with a intimidating shout on " << target << std::endl;
}

void	Human::action(std::string const & action_name, std::string const & target)
{
	void	(Human::*act[])(std::string const & target) = {&Human::meleeAttack,
	&Human::rangedAttack, &Human::intimidatingShout};
	std::string	name[] = {"melee", "range", "intimidating shout"};
	for (int i = 0; i < 3; i++)
	{
		if (name[i] == action_name)
		{
			(this->*act[i])(target);
			break ;
		}
	}
}