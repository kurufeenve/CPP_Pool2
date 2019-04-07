#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include <sys/time.h>
#include "./../includes/ClapTrap.hpp"

class	ScavTrap : virtual public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &f2);
		virtual ~ScavTrap();
		ScavTrap &operator= (const ScavTrap &frag);
		void		challengeNewcomer(std::string const & target);
};

#endif
