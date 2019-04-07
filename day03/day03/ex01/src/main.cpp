#include "./../includes/FragTrap.hpp"
#include "./../includes/ScavTrap.hpp"

int		main(void)
{
	FragTrap	Alice = FragTrap("Alice");
	ScavTrap	Bob = ScavTrap("Bob");

	Alice.rangedAttack("Pit");
	Alice.takeDamage(50);
	Alice.meleeAttack("Pit");
	Alice.takeDamage(20);
	Alice.rageOfGandi("Pit");
	Alice.beRepaired(60);
	Alice.vaulthunter_dot_exe("Pit");
	Alice.vaulthunter_dot_exe("Pit");
	Alice.vaulthunter_dot_exe("Pit");
	Alice.vaulthunter_dot_exe("Pit");
	Alice.vaulthunter_dot_exe("Pit");
	Alice.vaulthunter_dot_exe("Pit");
	Bob.challengeNewcomer("Pit");
	Bob.challengeNewcomer("Pit");
	Bob.challengeNewcomer("Pit");
	Bob.challengeNewcomer("Pit");
	Bob.challengeNewcomer("Pit");
	Bob.challengeNewcomer("Pit");
	Bob.challengeNewcomer("Pit");
	return (0);
}
