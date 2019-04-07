#include "./../includes/ScavTrap.hpp"

ScavTrap::ScavTrap() : _hitPoints(100), _maxHitPoints(100), _energyPoints(50), _maxEnergypoints(50),
_level(1), _name("FR4G-TP assault robot"), _meleeAttackDamage(20), _rangeAttackDamage(15),
_armorDamageReduction(3)
{
	std::cout << "ScavTrap default constructor called" << std::endl;
	return ;
}

ScavTrap::ScavTrap(std::string name) : _hitPoints(100), _maxHitPoints(100), _energyPoints(50),
_maxEnergypoints(50), _level(1), _name(name), _meleeAttackDamage(20), _rangeAttackDamage(15),
_armorDamageReduction(3)
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
		this->_hitPoints = frag.getHitPoints();
		this->_maxHitPoints = frag.getMaxHitPoints();
		this->_energyPoints = frag.getEnergyPoints();
		this->_maxEnergypoints = frag.getMaxEnergypoints();
		this->_level = frag.getLevel();
		this->_name = frag.getName();
		this->_meleeAttackDamage = frag.getMeleeAttackDamage();
		this->_rangeAttackDamage = frag.getRangeAttackDamage();
		this->_armorDamageReduction = frag.getArmorDamageReduction();
	}
	std::cout << "ScavTrap copied" << std::endl;
	return *this;
}

int			ScavTrap::getHitPoints() const
{
	return this->_hitPoints;
}

int			ScavTrap::getMaxHitPoints() const
{
	return this->_maxHitPoints;
}

int			ScavTrap::getEnergyPoints() const
{
	return this->_energyPoints;
}

int			ScavTrap::getMaxEnergypoints() const
{
	return this->_maxEnergypoints;
}

int			ScavTrap::getLevel() const
{
	return this->_level;
}

std::string	ScavTrap::getName() const
{
	return this->_name;
}

int			ScavTrap::getMeleeAttackDamage() const
{
	return this->_meleeAttackDamage;
}

int			ScavTrap::getRangeAttackDamage() const
{
	return this->_rangeAttackDamage;
}

int			ScavTrap::getArmorDamageReduction() const
{
	return this->_armorDamageReduction;
}

void		ScavTrap::meleeAttack(std::string const &target)
{
	std::string	tgt;
	tgt = target;
	if (target.length() == 0)
		tgt = "Unnown Enemy";
	std::cout << "ScavTrap '" + this->_name + "' attacks '" + tgt + "' causing " <<
	this->_meleeAttackDamage << " points of damage!\n" << std::endl;
}

void		ScavTrap::rangedAttack(std::string const &target)
{
	std::string	tgt;
	tgt = target;
	if (target.length() == 0)
		tgt = "Unnown Enemy";
	std::cout << "ScavTrap '" + this->_name + "' attacks '" + tgt + "' at range, causing " <<
	this->_rangeAttackDamage << " points of damage!\n" << std::endl;
}

void		ScavTrap::takeDamage(unsigned int amount)
{
	if ((int)amount < this->_armorDamageReduction)
		this->_trueDmg = 0;
	else
	{
		this->_trueDmg = amount - this->_armorDamageReduction;
		std::cout << "'" + this->_name + "' was damaged by " << this->_trueDmg << " points.\n" << std::endl;
	}
	if (this->_hitPoints < this->_trueDmg)
	{
		std::cout << "'" + this->_name + "' is not functioning! repairs needed!\n" << std::endl;
		this->_hitPoints = 0;
	}
	else
		this->_hitPoints -= this->_trueDmg;
}

void		ScavTrap::beRepaired(unsigned int amount)
{
	std::cout << "ScavTrap '" << this->_name + "' was repaired for " << amount << " points.\n" << std::endl;
	if ((this->_hitPoints = this->_hitPoints + amount) > this->_maxHitPoints)
		this->_hitPoints = this->_maxHitPoints;
	std::cout << "I am ready to go!\n" << std::endl;
}

void		ScavTrap::challengeNewcomer(std::string const & target)
{
	std::string chalenge[] = {"CHUBBY BUNNY CHALLENGE:\nCompete with your friends to see how many\n\
marshmallows you can fit into your mouth. Each time you put a marshmallow into your mouth,\n\
you have to say chubby bunny.", "THE POWDERED DONUT CHALLENGE:\nWe all love donuts, but have\n\
you tried the powdered donut challenge? Try eating 5 powdered donuts in less than 5 minutes \n\
without having anything to drink. Whoever finishes first wins.", "ICE BATH CHALLENGE:\n\
To do this ice bath challenge, you will have to get into either a bathtub or a kiddie pool full\n\
of water and ice. Don’t forget to have towels ready for when you are done with the challenge.",
"BLINDFOLDED MAKEUP CHALLENGE:\nThis challenge is a really goofy and fun one to do with your friends.\n\
Make sure that you have some eye masks or blindfolds to cover your eyes. Gather a nice of variety of\n\
makeup including lipstick, eye shadow, eyeliner, and blush. You can even include foundation and\n\
concealer if you like. Each participant in this challenge will be assigned to do makeup on another\n\
person. The person doing makeup will have to be blindfolded.", "EGG DROP CHALLENGE:\nYou may have\n\
done this experiment when you were in school, but it can also be a fun challenge to do with your\n\
friends. You will need raw eggs and various materials including tape, paper, newspaper, straws, and\n\
paper towels. You and your friends will each attempt to build something for the egg in a limited\n\
amount of time. Then you will drop the eggs from at least 2 stories high and you will see which\n\
eggs survive the fall."};
	int		i;
	struct timeval times;

	if (this->_energyPoints >= 10)
	{
		gettimeofday(&times,NULL);
		srand((times.tv_sec) + (times.tv_usec));
		i = rand() % 5;
		std::cout << target << " should do\n" << chalenge[i] << std::endl;
		this->_energyPoints -= 10;
	}
	else
		std::cout << "Out of energy..." << std::endl;
}
