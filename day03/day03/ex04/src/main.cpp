#include <iostream>
#include <sys/time.h>
#include "./../includes/ClapTrap.hpp"
#include "./../includes/FragTrap.hpp"
#include "./../includes/ScavTrap.hpp"
#include "./../includes/NinjaTrap.hpp"
#include "./../includes/SuperTrap.hpp"

int		main(void)
{
	// inherited parent methods are virtual so when we keep offsprings in pointer array of parent class
	// we cat use offspring specific methods while running array in the cycle
	ClapTrap	clap;
	FragTrap	a = FragTrap("R2D2");
	ScavTrap	b = ScavTrap("Jocker");
	ClapTrap	(*c[]) = {&a, &b};
	NinjaTrap	nin("ninja");
	SuperTrap	super;

	a.rangedAttack("bobby");
	a.takeDamage(50);
	a.meleeAttack("bobby");
	b.meleeAttack("Siri");
	for (int i = 0; i < 2; i++)
		c[i]->meleeAttack("tommy");
	a.takeDamage(20);
	a.rageOfGandi("Bobby");
	a.beRepaired(60);
	a.vaulthunter_dot_exe("Bobby");
	a.vaulthunter_dot_exe("Bobby");
	a.vaulthunter_dot_exe("Bobby");
	a.vaulthunter_dot_exe("Bobby");
	a.vaulthunter_dot_exe("Bobby");
	a.vaulthunter_dot_exe("Bobby");
	b.challengeNewcomer("Bobby");
	b.challengeNewcomer("Bobby");
	b.challengeNewcomer("Bobby");
	b.challengeNewcomer("Bobby");
	b.challengeNewcomer("Bobby");
	b.challengeNewcomer("Bobby");
	b.challengeNewcomer("Bobby");
	std::cout << a.getName() << b.getName() << std::endl;
	nin.ninjaShoebox(clap);
	nin.ninjaShoebox(a);
	nin.ninjaShoebox(b);
	nin.ninjaShoebox(nin);
	super.vaulthunter_dot_exe("booby");
	super.vaulthunter_dot_exe("booby");
	super.vaulthunter_dot_exe("booby");
	super.vaulthunter_dot_exe("booby");
	super.vaulthunter_dot_exe("booby");
	super.vaulthunter_dot_exe("booby");
	super.vaulthunter_dot_exe("booby");
	super.ninjaShoebox(clap);
	super.ninjaShoebox(a);
	super.ninjaShoebox(b);
	super.ninjaShoebox(nin);
	return (0);
}
