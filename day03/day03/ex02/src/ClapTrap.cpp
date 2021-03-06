#include "./../includes/ClapTrap.hpp"

ClapTrap::ClapTrap() : _hitPoints(100), _maxHitPoints(100), _energyPoints(50), _maxEnergypoints(50),
_level(1), _name("FR4G-TP ClapTrap robot"), _meleeAttackDamage(20), _rangeAttackDamage(15),
_armorDamageReduction(3)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
	return ;
}

ClapTrap::ClapTrap(std::string name) : _hitPoints(100), _maxHitPoints(100), _energyPoints(50),
_maxEnergypoints(50), _level(1), _name(name), _meleeAttackDamage(20), _rangeAttackDamage(15),
_armorDamageReduction(3)
{
	std::cout << "ClapTrap string constructor called" << std::endl;
	return ;
}

ClapTrap::ClapTrap(const ClapTrap &f2)
{
	*this = f2;
	std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap &ClapTrap::operator= (const ClapTrap &frag)
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
	std::cout << "ClapTrap copied" << std::endl;
	return *this;
}

int			ClapTrap::getHitPoints() const
{
	return this->_hitPoints;
}

int			ClapTrap::getMaxHitPoints() const
{
	return this->_maxHitPoints;
}

int			ClapTrap::getEnergyPoints() const
{
	return this->_energyPoints;
}

int			ClapTrap::getMaxEnergypoints() const
{
	return this->_maxEnergypoints;
}

int			ClapTrap::getLevel() const
{
	return this->_level;
}

std::string	ClapTrap::getName() const
{
	return this->_name;
}

int			ClapTrap::getMeleeAttackDamage() const
{
	return this->_meleeAttackDamage;
}

int			ClapTrap::getRangeAttackDamage() const
{
	return this->_rangeAttackDamage;
}

int			ClapTrap::getArmorDamageReduction() const
{
	return this->_armorDamageReduction;
}

void		ClapTrap::meleeAttack(std::string const &target)
{
	std::string	tgt;
	tgt = target;
	if (target.length() == 0)
		tgt = "Unnown Enemy";
	std::cout << "ClapTrap '" + this->_name + "' attacks '" + tgt + "' causing " <<
	this->_meleeAttackDamage << " points of damage!\n" << std::endl;
}

void		ClapTrap::rangedAttack(std::string const &target)
{
	std::string	tgt;
	tgt = target;
	if (target.length() == 0)
		tgt = "Unnown Enemy";
	std::cout << "ClapTrap '" + this->_name + "' attacks '" + tgt + "' at range, causing " <<
	this->_rangeAttackDamage << " points of damage!\n" << std::endl;
}

void		ClapTrap::takeDamage(unsigned int amount)
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

void		ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "ClapTrap '" << this->_name + "' was repaired for " << amount << " points.\n" << std::endl;
	if ((this->_hitPoints = this->_hitPoints + amount) > this->_maxHitPoints)
		this->_hitPoints = this->_maxHitPoints;
	std::cout << "I am ready to go!\n" << std::endl;
}
