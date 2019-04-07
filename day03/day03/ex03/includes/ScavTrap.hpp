#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include <sys/time.h>
#include "./../includes/ClapTrap.hpp"

class	ScavTrap : public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &f2);
		virtual ~ScavTrap();
		ScavTrap &operator= (const ScavTrap &frag);
		// void		meleeAttack(std::string const &target);
		// void		rangedAttack(std::string const &target);
		// void		takeDamage(unsigned int amount);
		// void		beRepaired(unsigned int amount);
		void		challengeNewcomer(std::string const & target);
};

#endif
