#include "./../includes/FragTrap.hpp"

FragTrap::FragTrap() : _hitPoints(100), _maxHitPoints(100), _energyPoints(100), _maxEnergypoints(100),
_level(1), _name("FR4G-TP assault robot"), _meleeAttackDamage(30), _rangeAttackDamage(20),
_bottleAttackDamage(6), _kneeToBallsAttackDamage(50), _swearAttackDamage(100),
_headToHeadAttackDamage(15), _rageOfGandiAttackDamage(2147483647), _armorDamageReduction(5)
{
	std::cout << "FragTrap default constructor called" << std::endl;
	return ;
}

FragTrap::FragTrap(std::string name) : _hitPoints(100), _maxHitPoints(100), _energyPoints(100),
_maxEnergypoints(100), _level(1), _name(name), _meleeAttackDamage(30), _rangeAttackDamage(20),
_bottleAttackDamage(6), _kneeToBallsAttackDamage(50), _swearAttackDamage(100),
_headToHeadAttackDamage(15), _rageOfGandiAttackDamage(2147483647), _armorDamageReduction(5)
{
	std::cout << "FragTrap string constructor called" << std::endl;
	return ;
}

FragTrap::FragTrap(const FragTrap &f2)
{
	*this = f2;
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap &FragTrap::operator= (const FragTrap &frag)
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
	std::cout << "FragTrap copied" << std::endl;
	return *this;
}

int			FragTrap::getHitPoints() const
{
	return this->_hitPoints;
}

int			FragTrap::getMaxHitPoints() const
{
	return this->_maxHitPoints;
}

int			FragTrap::getEnergyPoints() const
{
	return this->_energyPoints;
}

int			FragTrap::getMaxEnergypoints() const
{
	return this->_maxEnergypoints;
}

int			FragTrap::getLevel() const
{
	return this->_level;
}

std::string	FragTrap::getName() const
{
	return this->_name;
}

int			FragTrap::getMeleeAttackDamage() const
{
	return this->_meleeAttackDamage;
}

int			FragTrap::getRangeAttackDamage() const
{
	return this->_rangeAttackDamage;
}

int			FragTrap::getArmorDamageReduction() const
{
	return this->_armorDamageReduction;
}

void		FragTrap::meleeAttack(std::string const &target)
{
	std::string	tgt;
	tgt = target;
	if (target.length() == 0)
		tgt = "Unnown Enemy";
	std::cout << "FR4G-TP '" + this->_name + "' attacks '" + tgt + "' causing " <<
	this->_meleeAttackDamage << " points of damage!\n" << std::endl;
}

void		FragTrap::rangedAttack(std::string const &target)
{
	std::string	tgt;
	tgt = target;
	if (target.length() == 0)
		tgt = "Unnown Enemy";
	std::cout << "FR4G-TP '" + this->_name + "' attacks '" + tgt + "' at range, causing " <<
	this->_rangeAttackDamage << " points of damage!\n" << std::endl;
}

void		FragTrap::takeDamage(unsigned int amount)
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

void		FragTrap::beRepaired(unsigned int amount)
{
	std::cout << "'" << this->_name + "' was repaired for " << amount << " points.\n" << std::endl;
	if ((this->_hitPoints = this->_hitPoints + amount) > this->_maxHitPoints)
		this->_hitPoints = this->_maxHitPoints;
	std::cout << "I am ready to go!\n" << std::endl;
}

void		FragTrap::bottleAttack(std::string const &target)
{
	std::string	tgt;
	tgt = target;
	if (target.length() == 0)
		tgt = "Unnown Enemy";
	std::cout << "FR4G-TP '" + this->_name + "' takes an empty bottle of Hennessy and hits '" +
	tgt + "' causing " << this->_bottleAttackDamage << " points of damage!\n" << std::endl;
}

void		FragTrap::kneeToBallsAttack(std::string const &target)
{
	std::string	tgt;
	tgt = target;
	if (target.length() == 0)
		tgt = "Unnown Enemy";
	std::cout << "FR4G-TP '" + this->_name + "' hit '" + tgt + "'s' balls with it's knee causing " <<
	this->_kneeToBallsAttackDamage << " points of damage and pain from hell!\n" << std::endl;
}

void		FragTrap::swearAttack(std::string const &target)
{
	std::string	tgt;
	tgt = target;
	if (target.length() == 0)
		tgt = "Unnown Enemy";
	std::cout << "FR4G-TP: 'Your mom is so fat that she cannot fit into hula hoop'. '" + tgt + "' receives " <<
	this->_swearAttackDamage << " points of butthurt!\n" << std::endl;
}

void		FragTrap::headToHeadAttack(std::string const &target)
{
	std::string	tgt;
	tgt = target;
	if (target.length() == 0)
		tgt = "Unnown Enemy";
	std::cout << "FR4G-TP '" + this->_name + "' grabs head of the '" + tgt + "' and hits with his own head causing " <<
	this->_headToHeadAttackDamage << " points of damage and pain from hell!\n" << std::endl;
}

void		FragTrap::rageOfGandi(std::string const &target)
{
	std::string does_not_matter;

	does_not_matter = target;
	std::cout << "Gandi apears from nowhere. He was so kind that his unsigned evil flipped from 0\n\
to 255 value. He kills everything with the rage of DOOM guy and nuclear warheads causing ultimate massive\n\
destructions and gennocide. Everyone take " << this->_rageOfGandiAttackDamage << " points of dammage.\n" << std::endl;
	this->takeDamage(2147483647);
}

void		FragTrap::vaulthunter_dot_exe(std::string const & target)
{
	void	(FragTrap::*randAttack[])(std::string const &target) = {&FragTrap::bottleAttack,
	&FragTrap::kneeToBallsAttack, &FragTrap::swearAttack, &FragTrap::headToHeadAttack, &FragTrap::rageOfGandi};
	int		i;
	struct timeval times;

	if (this->_energyPoints >= 25)
	{
		gettimeofday(&times,NULL);
		srand((times.tv_sec) + (times.tv_usec));
		i = rand() % 5;
		(this->*randAttack[i])(target);
		this->_energyPoints -= 25;
	}
	else
		std::cout << "Out of energy..." << std::endl;
}
