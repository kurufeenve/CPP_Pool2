#include "./../includes/SuperTrap.hpp"

SuperTrap::SuperTrap() : ClapTrap( 100, 100, 120, 120, 1, "FR4G-TP NinjaTrap robot", 60, 20, 5 )
{
	std::cout << "SuperTrap default constructor called" << std::endl;
	return ;
}

SuperTrap::SuperTrap(std::string name) : ClapTrap( 100, 100, 120, 120, 1, name, 60, 20, 5 )
{
	std::cout << "SuperTrap string constructor called" << std::endl;
	return ;
}

SuperTrap::SuperTrap(const SuperTrap &f2)
{
	*this = f2;
	std::cout << "SuperTrap copy constructor called" << std::endl;
}

SuperTrap::~SuperTrap()
{
	std::cout << "SuperTrap destructor called" << std::endl;
}

SuperTrap &SuperTrap::operator= (const SuperTrap &frag)
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
	std::cout << "SuperTrap copied" << std::endl;
	return *this;
}
