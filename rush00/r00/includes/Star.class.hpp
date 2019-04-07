#ifndef STAR_HPP
# define STAR_HPP

# include "GameObject.hpp"

class Star : public GameObject
{

public:

	Star();
	Star(const Star &);
	Star(unsigned x, unsigned y, unsigned level, unsigned moveSpeed,
	unsigned livesCount);
	~Star();
	void	die(void);

	Star &operator=(const Star &);

};

#endif