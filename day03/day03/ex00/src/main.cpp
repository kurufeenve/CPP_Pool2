#include "./../includes/FragTrap.hpp"

int		main(void)
{
	FragTrap	Alice = FragTrap("Alice");

	Alice.rangedAttack("Bob");
	Alice.takeDamage(50);
	Alice.meleeAttack("Bob");
	Alice.takeDamage(20);
	Alice.rageOfGandi("Bob");
	Alice.beRepaired(60);
	Alice.vaulthunter_dot_exe("Bob");
	Alice.vaulthunter_dot_exe("Bob");
	Alice.vaulthunter_dot_exe("Bob");
	Alice.vaulthunter_dot_exe("Bob");
	Alice.vaulthunter_dot_exe("Bob");
	Alice.vaulthunter_dot_exe("Bob");
	return (0);
}