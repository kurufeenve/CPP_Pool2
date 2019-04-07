#include "./../includes/FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap( 100, 100, 100, 100, 1, "FR4G-TP FragTrap robot", 30, 20, 5 ),
_bottleAttackDamage(6), _kneeToBallsAttackDamage(50), _swearAttackDamage(100),
_headToHeadAttackDamage(15), _rageOfGandiAttackDamage(2147483647)
{
	std::cout << "FragTrap default constructor called" << std::endl;
	return ;
}

FragTrap::FragTrap(std::string name) : ClapTrap( 100, 100, 100, 100, 1, name, 30, 20, 5 ),
_bottleAttackDamage(6), _kneeToBallsAttackDamage(50), _swearAttackDamage(100),
_headToHeadAttackDamage(15), _rageOfGandiAttackDamage(2147483647)
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
	std::cout << "FragTrap copied" << std::endl;
	return *this;
}

void		FragTrap::bottleAttack(std::string const &target)
{
	std::string	tgt;
	tgt = target;
	if (target.length() == 0)
		tgt = "Unnown Enemy";
	std::cout << "FR4G-TP '" + this->getName() + "' takes an empty bottle of Hennessy and hits '" +
	tgt + "' causing " << this->_bottleAttackDamage << " points of damage!\n" << std::endl;
}

void		FragTrap::kneeToBallsAttack(std::string const &target)
{
	std::string	tgt;
	tgt = target;
	if (target.length() == 0)
		tgt = "Unnown Enemy";
	std::cout << "FR4G-TP '" + this->getName() + "' hit '" + tgt + "'s' balls with it's knee causing " <<
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
	std::cout << "FR4G-TP '" + this->getName() + "' grabs head of the '" + tgt + "' and hits with his own head causing " <<
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

	if (this->getEnergyPoints() >= 25)
	{
		gettimeofday(&times,NULL);
		srand((times.tv_sec) + (times.tv_usec));
		i = rand() % 5;
		(this->*randAttack[i])(target);
		this->setEnergyPoints(this->getEnergyPoints() - 25);
	}
	else
		std::cout << "Out of energy..." << std::endl;
}
