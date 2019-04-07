#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP

# include <iostream>
# include "./../includes/ClapTrap.hpp"
# include "./../includes/FragTrap.hpp"
# include "./../includes/ScavTrap.hpp"

class	NinjaTrap : virtual public ClapTrap
{

	public:
		NinjaTrap();
		NinjaTrap(std::string name);
		NinjaTrap(const NinjaTrap &f2);
		virtual ~NinjaTrap();
		NinjaTrap &operator= (const NinjaTrap &frag);
		void	ninjaShoebox(ClapTrap &target) const;
		void	ninjaShoebox(FragTrap &target) const;
		void	ninjaShoebox(ScavTrap &target) const;
		void	ninjaShoebox(NinjaTrap &target) const;
};

#endif
