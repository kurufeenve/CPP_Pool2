#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>
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
		ClapTrap(int _hitPoints, int _maxHitPoints, int _energyPoints, int _maxEnergypoints,
int _level, std::string _name, int _meleeAttackDamage, int _rangeAttackDamage,
int _armorDamageReduction);
		ClapTrap(const ClapTrap &f2);
		virtual ~ClapTrap();
		ClapTrap &operator= (const ClapTrap &frag);
		virtual void		meleeAttack(std::string const &target);
		virtual void		rangedAttack(std::string const &target);
		virtual void		takeDamage(unsigned int amount);
		virtual void		beRepaired(unsigned int amount);
		int			getHitPoints() const;
		int			getMaxHitPoints() const;
		int			getEnergyPoints() const;
		int			getMaxEnergypoints() const;
		int			getLevel() const;
		std::string	getName() const;
		int			getMeleeAttackDamage() const;
		int			getRangeAttackDamage() const;
		int			getArmorDamageReduction() const;
		int			getTrueDmg() const;
		void		setHitPoints(int hp);
		void		setMaxHitPoints(int mhp);
		void		setEnergyPoints(int ep);
		void		setMaxEnergypoints(int mep);
		void		setLevel(int lvl);
		void		setName(std::string name);
		void		setMeleeAttackDamage(int amount);
		void		setRangeAttackDamage(int amount);
		void		setArmorDamageReduction(int amount);
		void		setTrueDmg(int amount);
};

#endif
