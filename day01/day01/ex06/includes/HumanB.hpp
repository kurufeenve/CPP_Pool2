#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "./../includes/Weapon.hpp"
# include <iostream>
# include <string>

class HumanB
{
private:
	Weapon	_wp;
	std::string _name;

public:
	HumanB();
	HumanB(std::string name);
	~HumanB();
	void	attack(void);
	void	setWeapon(Weapon wp);
};

#endif