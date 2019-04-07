#ifndef SUPERTRAP_HPP
# define SUPERTRAP_HPP

# include <iostream>
# include <sys/time.h>
# include "./../includes/ClapTrap.hpp"
# include "./../includes/FragTrap.hpp"
# include "./../includes/NinjaTrap.hpp"

class	SuperTrap : public FragTrap, public NinjaTrap
{
	public:
		SuperTrap();
		SuperTrap(std::string name);
		SuperTrap(const SuperTrap &f2);
		virtual ~SuperTrap();
		SuperTrap &operator= (const SuperTrap &frag);
};

#endif
