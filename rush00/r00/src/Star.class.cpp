#include "./../includes/Star.class.hpp"

Star::Star() {}

Star::Star(const Star &object)
{
	operator=(object);
}

Star &Star::operator=(Star const &object)
{
	GameObject::operator=(object);
	return *this;
}

Star::Star(unsigned x, unsigned y, unsigned level, unsigned moveSpeed,
unsigned livesCount)
	: GameObject(x, y, level, moveSpeed, livesCount, ".", "Star") {
	
	int		i;

	i = rand() % 177 + 1;
	this->setX(i);
	this->setY(rand() % 79);
}

Star::~Star() {}

void	Star::die(void) {}
