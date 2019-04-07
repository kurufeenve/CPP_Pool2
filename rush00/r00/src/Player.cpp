//
// Created by Dmitro LITVINENKO on 2019-04-06.
//

#include "./../includes/Player.hpp"

Player::Player(const Player &object)
{
	operator=(object);
}

Player &Player::operator=(Player const &object)
{
	GameObject::operator=(object);
	return *this;
}

Player::Player(unsigned x, unsigned y, unsigned level, unsigned moveSpeed, unsigned livesCount)
		: GameObject(x, y, level, moveSpeed, livesCount, "^", "Player") {}

Player::Player() : GameObject(0, 0, 1, 2, 3, "^", "Player") {}

Player::~Player() {}

void    Player::die()
{
	if (getLivesCount() == 1)
	{
		std::cout << "You died." << std::endl;
		system("clear");
		system("stty sane");
		std::cout << "\x1b[31m\n  _____          __  __ ______    ______      ________ _____  _ \n / ____|   /\\   |  \\/  |  ____|  / __ \\ \\    / /  ____|  __ \\| |\n| |  __   /  \\  | \\  / | |__    | |  | \\ \\  / /| |__  | |__) | |\n| | |_ | / /\\ \\ | |\\/| |  __|   | |  | |\\ \\/ / |  __| |  _  /| |\n| |__| |/ ____ \\| |  | | |____  | |__| | \\  /  | |____| | \\ \\|_|\n \\_____/_/    \\_\\_|  |_|______|  \\____/   \\/   |______|_|  \\_(_)\n\x1b[0m" << std::endl;
		exit(0);
	}
	else
	{
		setLivesCount(getLivesCount() - 1);
		setX(90);
		setY(78);
	}
}
