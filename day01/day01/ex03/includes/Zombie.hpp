#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie
{
private:
	std::string _name;
	std::string _type;
public:
	Zombie(void);
	~Zombie(void);
	void	announce(void) const;
	void	setName(std::string name);
	void	setType(std::string type);
};

#endif