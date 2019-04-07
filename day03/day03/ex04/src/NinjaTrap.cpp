#include "./../includes/NinjaTrap.hpp"

NinjaTrap::NinjaTrap() : ClapTrap( 60, 60, 120, 120, 1, "FR4G-TP NinjaTrap robot", 60, 5, 0 )
{
	std::cout << "NinjaTrap default constructor called" << std::endl;
	return ;
}

NinjaTrap::NinjaTrap(std::string name) : ClapTrap( 60, 60, 120, 120, 1, name, 60, 5, 0 )
{
	std::cout << "NinjaTrap string constructor called" << std::endl;
	return ;
}

NinjaTrap::NinjaTrap(const NinjaTrap &f2)
{
	*this = f2;
	std::cout << "NinjaTrap copy constructor called" << std::endl;
}

NinjaTrap::~NinjaTrap()
{
	std::cout << "NinjaTrap destructor called" << std::endl;
}

NinjaTrap &NinjaTrap::operator= (const NinjaTrap &frag)
{
	if (this != &frag)
	{
		this->setHitPoints(frag.getHitPoints());
		this->setMaxHitPoints(frag.getMaxHitPoints());
		this->setEnergyPoints(frag.getEnergyPoints());
		this->setMaxEnergypoints(frag.getMaxEnergypoints());
		this->setLevel(frag.getLevel());
		this->setName(frag.getName());
		this->setMeleeAttackDamage(frag.getMeleeAttackDamage());
		this->setRangeAttackDamage(frag.getRangeAttackDamage());
		this->setArmorDamageReduction(frag.getArmorDamageReduction());
	}
	std::cout << "NinjaTrap copied" << std::endl;
	return *this;
}

void	NinjaTrap::ninjaShoebox(ClapTrap &target) const
{
	std::cout << "Hey! '" << target.getName() << "' Dean, to the physics department. 'Why do I always\n\
have to give you guys so much money,\n\
for laboratories and expensive equipment and stuff. Why couldn't you be like the math department\n\
- all they need is money for pencils, paper and waste-paper baskets. Or even better, like the philosophy\n\
department. All they need are pencils and paper.'\n" << std::endl;
}

void	NinjaTrap::ninjaShoebox(FragTrap &target) const
{
	std::cout << "Hey! '" << target.getName() << "' A family was visiting an Indian reservation\n\
when they happen upon an old tribesman laying\n\
face down in the middle of the road with his ear pressed firmly against the blacktop. The father of the\n\
family asked the old tribesman what he was doing. The tribesman began to speak... 'woman, late thirties,\n\
three kids, one barking dog in late model, Four door station wagon, traveling at 65 m.p.h.'\n\
'That's amazing' exclaimed the father. 'You can tell all of that by just listening to the ground'?\n\
'No', said the old tribesman. 'They just ran over me five minutes ago!'\n" << std::endl;
}

void	NinjaTrap::ninjaShoebox(ScavTrap &target) const
{
	std::cout << "Hey! '" << target.getName() << "' A bus stops and two\n\
Italian men get on. They seat themselves and engage in animated\n\
conversation. The lady sitting behind them ignores their conversation at first, but her attention is\n\
galvanized when she hears one of the men say the following: 'Emma come first. Den I come. Den two asses\n\
come together. I come once-a-more. Two asses, they come together again. I come again and pee twice. Den I\n\
come one lasta time.' 'You foul-mouthed swine,' retorted the lady indignantly. 'In this country we don\'t\n\
talk about our sex lives in public!' 'Hey, coola down lady,' said the man. 'Who talking abouta sexa?\n\
Imma justa tellun my frienda how to spella 'Mississippi'!\n" << std::endl;
}

void	NinjaTrap::ninjaShoebox(NinjaTrap &target) const
{
	std::cout << "Hey! '" << target.getName() << "' A vampire bat came flapping in\n\
for the night covered in fresh blood and parked himself\n\
on the ceiling of the cave to get some sleep. Pretty soon all the other bats smelled the blood and started\n\
hassling him about where he got it. He told them to piss off and let him get some sleep, but they persisted\n\
until he finally gave in. 'Okay, follow me' he said and flapped out of the cave with hundreds of bats behind\n\
him. Down through a valley they went, across a river and into a forest of trees. Finally he slowed down and\n\
all the other bats excitedly milled around him. 'Now, do you see that giant oak over there?' he asked.\n\
'YES, YES, YES' all the other bats SCREAMED in a frenzy.\n\
'Good' said the first bat, 'because I fuckin didn\'t!'\n" << std::endl;
}
