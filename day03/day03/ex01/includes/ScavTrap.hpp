#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include <sys/time.h>

class	ScavTrap
{
	private:
		int			_hitPoints;
		int			_maxHitPoints;
		int			_energyPoints;
		int			_maxEnergypoints;
		int			_level;
		std::string	_name;
		int			_meleeAttackDamage;
		int			_rangeAttackDamage;
		int			_armorDamageReduction;
		int			_trueDmg;

	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &f2);
		~ScavTrap();
		ScavTrap &operator= (const ScavTrap &frag);
		void		meleeAttack(std::string const &target);
		void		rangedAttack(std::string const &target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
		void		challengeNewcomer(std::string const & target);
		int			getHitPoints() const;
		int			getMaxHitPoints() const;
		int			getEnergyPoints() const;
		int			getMaxEnergypoints() const;
		int			getLevel() const;
		std::string	getName() const;
		int			getMeleeAttackDamage() const;
		int			getRangeAttackDamage() const;
		int			getArmorDamageReduction() const;
};

#endif
