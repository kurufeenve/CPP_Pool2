#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "./../includes/Weapon.hpp"
# include <iostream>
# include <string>

class HumanA
{
private:
	std::string _name;
	Weapon		&_wp;

public:
	HumanA(std::string name, Weapon &wp); // no default constructor is not available here
	~HumanA();
	void		attack(void);
};

#endif
