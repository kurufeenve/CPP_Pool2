#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include <sys/time.h>
#include "./../includes/ClapTrap.hpp"

class	FragTrap : public ClapTrap
{
	private:
		int			_bottleAttackDamage;
		int			_kneeToBallsAttackDamage;
		int			_swearAttackDamage;
		int			_headToHeadAttackDamage;
		int			_rageOfGandiAttackDamage;

	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap &f2);
		virtual ~FragTrap();
		FragTrap &operator= (const FragTrap &frag);

		void		bottleAttack(std::string const &target);
		void		kneeToBallsAttack(std::string const &target);
		void		swearAttack(std::string const &target);
		void		headToHeadAttack(std::string const &target);
		void		rageOfGandi(std::string const &target);
		void		vaulthunter_dot_exe(std::string const & target);
};

#endif
