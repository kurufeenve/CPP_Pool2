#include "./../includes/FragTrap.hpp"
#include "./../includes/ScavTrap.hpp"

int		main(void)
{
	// all parent methods are virtual so when we keep offsprings in pointer array of parent class
	// we cat use offspring specific methods while running array in the cycle
	FragTrap	a = FragTrap("R2D2");
	ScavTrap	b = ScavTrap("Jocker");
	ClapTrap	(*c[]) = {&a, &b};

	// a.rangedAttack("bobby");
	// a.takeDamage(50);
	// a.meleeAttack("bobby");
	// b.meleeAttack("Siri");
	for (int i = 0; i < 2; i++)
		c[i]->meleeAttack("tommy");
	// a.takeDamage(20);
	// a.rageOfGandi("Bobby");
	// a.beRepaired(60);
	// a.vaulthunter_dot_exe("Bobby");
	// a.vaulthunter_dot_exe("Bobby");
	// a.vaulthunter_dot_exe("Bobby");
	// a.vaulthunter_dot_exe("Bobby");
	// a.vaulthunter_dot_exe("Bobby");
	// a.vaulthunter_dot_exe("Bobby");
	// b.challengeNewcomer("Bobby");
	// b.challengeNewcomer("Bobby");
	// b.challengeNewcomer("Bobby");
	// b.challengeNewcomer("Bobby");
	// b.challengeNewcomer("Bobby");
	// b.challengeNewcomer("Bobby");
	// b.challengeNewcomer("Bobby");
	// std::cout << a.getName() << b.getName() << std::endl;
	return (0);
}
