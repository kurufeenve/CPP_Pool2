#ifndef GAME_CLASS_HPP
# define GAME_CLASS_HPP

# include <curses.h>
# include <iostream>
# include <unistd.h>
# include "Player.hpp"
# include "Enemy.hpp"
# include "Bullet.hpp"
# include "list.hpp"
# include "Star.class.hpp"

# define HEIGHT 80
# define WIDTH 180
# define WINX 0
# define WINY 0
# define GI_HEIGHT 80
# define GI_WIDTH 60
# define GI_WINX 185
# define GI_WINY 0
# define ESC 27
# define P_COLOR 1

class Game
{
private:
	WINDOW		*_window;
	WINDOW		*_gameInfo;
	int			_ch;
	Player		*_p;
	list		_enemies;
	list		_bullets;
	list		_pbullets;
	list		_stars;
	size_t		_enemieEvent;
	size_t		_eBullet;
	size_t		_moveBull;
	size_t		_mvPlayerBull;
	size_t		_starTime;
	int			_xD;
	int			_score;

public:
	Game();
	Game(const Game &g);
	~Game();
	Game &operator= (const Game &game);

	void	start(void);
	void	addEnemy(void);
	void	showEnemies(void) const;
	void	moveEnemies(void);
	void	playerColision(void);
	void	playerBulletColision(void);
	void	bulletColision(void);
	void	addBullet(unsigned int x, unsigned int y, int direction, list *l);
	void	moveBullet(list *l);
	void	showBullet(list *l) const;
	void	enemyBullet(void);
	void	addStars(void);
	void	moveStars(void);
	void	showStars(void);
};

#endif
