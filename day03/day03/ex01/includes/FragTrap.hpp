#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include <sys/time.h>

class	FragTrap
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
		int			_bottleAttackDamage;
		int			_kneeToBallsAttackDamage;
		int			_swearAttackDamage;
		int			_headToHeadAttackDamage;
		int			_rageOfGandiAttackDamage;
		int			_armorDamageReduction;
		int			_trueDmg;

	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap &f2);
		~FragTrap();
		FragTrap &operator= (const FragTrap &frag);
		void		meleeAttack(std::string const &target);
		void		rangedAttack(std::string const &target);
		void		bottleAttack(std::string const &target);
		void		kneeToBallsAttack(std::string const &target);
		void		swearAttack(std::string const &target);
		void		headToHeadAttack(std::string const &target);
		void		rageOfGandi(std::string const &target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
		void		vaulthunter_dot_exe(std::string const & target);
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
