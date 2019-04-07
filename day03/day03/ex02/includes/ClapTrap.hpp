#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <sys/time.h>

class	ClapTrap
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
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &f2);
		virtual ~ClapTrap();
		ClapTrap &operator= (const ClapTrap &frag);
		virtual void		meleeAttack(std::string const &target);
		virtual void		rangedAttack(std::string const &target);
		virtual void		takeDamage(unsigned int amount);
		virtual void		beRepaired(unsigned int amount);
		virtual int			getHitPoints() const;
		virtual int			getMaxHitPoints() const;
		virtual int			getEnergyPoints() const;
		virtual int			getMaxEnergypoints() const;
		virtual int			getLevel() const;
		virtual std::string	getName() const;
		virtual int			getMeleeAttackDamage() const;
		virtual int			getRangeAttackDamage() const;
		virtual int			getArmorDamageReduction() const;
};

#endif
