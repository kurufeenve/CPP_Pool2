#include "./../includes/ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap( 100, 100, 50, 50, 1, "FR4G-TP ScavTrap robot", 20, 15, 3 )
{
	std::cout << "ScavTrap default constructor called" << std::endl;
	return ;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap( 100, 100, 50, 50, 1, name, 20, 15, 3 )
{
	std::cout << "ScavTrap string constructor called" << std::endl;
	return ;
}

ScavTrap::ScavTrap(const ScavTrap &f2)
{
	*this = f2;
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap &ScavTrap::operator= (const ScavTrap &frag)
{
	if (this != &frag)
	{
		this->setHitPoints(frag.getHitPoints());
		this->setMaxHitPoints(frag.getMaxHitPoints());
		this->setEnergyPoints(frag.getEnergyPoints());
		this->setMaxEnergypoints(frag.getMaxEnergypoints());
		this->setLevel(frag.getLevel());
		this->setName(frag.getName());
		this->setMeleeAttackDamage(frag.getMeleeAttackDamage());
		this->setRangeAttackDamage(frag.getRangeAttackDamage());
		this->setArmorDamageReduction(frag.getArmorDamageReduction());
	}
	std::cout << "ScavTrap copied" << std::endl;
	return *this;
}

void		ScavTrap::challengeNewcomer(std::string const & target)
{
	std::string chalenge[] = {"CHUBBY BUNNY CHALLENGE:\nCompete with your friends to see how many\n\
marshmallows you can fit into your mouth. Each time you put a marshmallow into your mouth,\n\
you have to say chubby bunny.\n", "THE POWDERED DONUT CHALLENGE:\nWe all love donuts, but have\n\
you tried the powdered donut challenge? Try eating 5 powdered donuts in less than 5 minutes \n\
without having anything to drink. Whoever finishes first wins.\n", "ICE BATH CHALLENGE:\n\
To do this ice bath challenge, you will have to get into either a bathtub or a kiddie pool full\n\
of water and ice. Don’t forget to have towels ready for when you are done with the challenge.\n",
"BLINDFOLDED MAKEUP CHALLENGE:\nThis challenge is a really goofy and fun one to do with your friends.\n\
Make sure that you have some eye masks or blindfolds to cover your eyes. Gather a nice of variety of\n\
makeup including lipstick, eye shadow, eyeliner, and blush. You can even include foundation and\n\
concealer if you like. Each participant in this challenge will be assigned to do makeup on another\n\
person. The person doing makeup will have to be blindfolded.\n", "EGG DROP CHALLENGE:\nYou may have\n\
done this experiment when you were in school, but it can also be a fun challenge to do with your\n\
friends. You will need raw eggs and various materials including tape, paper, newspaper, straws, and\n\
paper towels. You and your friends will each attempt to build something for the egg in a limited\n\
amount of time. Then you will drop the eggs from at least 2 stories high and you will see which\n\
eggs survive the fall.\n"};
	int		i;
	struct timeval times;

	if (this->getEnergyPoints() >= 10)
	{
		gettimeofday(&times,NULL);
		srand((times.tv_sec) + (times.tv_usec));
		i = rand() % 5;
		std::cout << target << " should do\n" << chalenge[i] << std::endl;
		this->setEnergyPoints(this->getEnergyPoints() - 10);
	}
	else
		std::cout << "Out of energy..." << std::endl;
}
