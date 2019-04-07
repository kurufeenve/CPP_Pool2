#include "./../includes/Game.class.hpp"
#include <fstream>

Game::Game() {}

Game::Game(const Game &g) {

	*this = g;
}

Game::~Game() {}

Game	&Game::operator= (const Game &game) {

	if (this != &game) {

		this->_window = game._window;
		this->_gameInfo = game._gameInfo;
		this->_ch = game._ch;
		this->_p = game._p;
		this->_enemies = game._enemies;
		this->_bullets = game._bullets;
		this->_pbullets = game._pbullets;
		this->_stars = game._stars;
		this->_xD = game._xD;
	}
	return (*this);
}

void	Game::bulletColision(void) {

	t_list *pBullet = _pbullets.head, *toDel, *eBullet;
	
	while (pBullet) {
		eBullet = _bullets.head;
		while (eBullet) {
			if (eBullet->object->getX() == pBullet->object->getX()
			&&	eBullet->object->getY() == pBullet->object->getY()) {
				toDel = eBullet;
				eBullet = eBullet->next;
				delete toDel->object;
				_bullets.del(toDel);
				_score += 2;
			}
			else {
				eBullet = eBullet->next;
			}
		}
		pBullet = pBullet->next;
	}
}

void	Game::start(void) {

	this->_p = new Player(90, 78, 1, 1, 3);
	this->_xD = 0;

	initscr();
	cbreak();
	curs_set(0);
	keypad(stdscr, TRUE);
	noecho();
	this->_window = newwin(HEIGHT, WIDTH, WINY, WINX);
	refresh();
	this->_gameInfo = newwin(GI_HEIGHT, GI_WIDTH, GI_WINY, GI_WINX);
	refresh();
	nodelay(stdscr, TRUE);
	start_color();
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_YELLOW, COLOR_BLACK);
	init_pair(3, COLOR_RED, COLOR_BLACK);
	while (1)
	{
		size_t eventTime = clock();

		werase(this->_window);
		werase(this->_gameInfo);
		mvwprintw(this->_gameInfo, 1, 1, "Press ESC to exit");
		mvwprintw(this->_gameInfo, 2, 1, "lives: %d\n level: %d\n score: %d",
		this->_p->getLivesCount(), this->_p->getLevel(), this->_score);
		wattron(this->_window, COLOR_PAIR(1));
		mvwprintw(this->_window, this->_p->getY() - 1, this->_p->getX(), "^");
		mvwprintw(this->_window, this->_p->getY(), this->_p->getX() - 1, "/ \\");
		wattroff(this->_window, COLOR_PAIR(1));
		box(this->_window, 0, 0);
		box(this->_gameInfo, 0, 0);
		if (this->_score > 100)
			this->_p->setLevel(2);
		if (this->_score > 500)
			this->_p->setLevel(3);
		if (eventTime - this->_enemieEvent >= 100000) {
			this->moveEnemies();
			this->addEnemy();
			this->_enemieEvent = eventTime;
		}
		if (eventTime - this->_eBullet >= 1000000 / this->_p->getLevel())
		{
			t_list *lst = _enemies.head;
			while (lst) {
				this->addBullet(lst->object->getX(), lst->object->getY(), 1, &this->_bullets);
				lst = lst->next;
			}
			this->_eBullet = eventTime;
		}
		if (eventTime - this->_moveBull >= 50000  / this->_p->getLevel())
		{
			this->moveBullet(&this->_bullets);
			this->_moveBull = eventTime;
		}
		if (eventTime - this->_mvPlayerBull >= 10000)
		{
			this->moveBullet(&this->_pbullets);
			this->_mvPlayerBull = eventTime;
		}
		if (eventTime - this->_starTime >= 1000)
		{
			this->addStars();
			this->moveStars();
			this->_starTime = eventTime;
		}
		this->playerColision();
		this->playerBulletColision();
		this->bulletColision();
		this->showEnemies();
		wattron(this->_window, COLOR_PAIR(3));
		this->showBullet(&this->_bullets);
		wattroff(this->_window, COLOR_PAIR(3));
		wattron(this->_window, COLOR_PAIR(2));
		this->showBullet(&this->_pbullets);
		wattroff(this->_window, COLOR_PAIR(2));
		this->showStars();
		if ((this->_ch = getch()) != ERR)
		{
			if(this->_ch == 27 || this->_ch == 410)
			{
				endwin();
				break ;
			}
			else if (this->_ch == 259 && this->_p->getY() - 1 > 1)
				this->_p->setY(this->_p->getY() - 1);
			else if (this->_ch == 258 && this->_p->getY() + 1 < 79)
				this->_p->setY(this->_p->getY() + 1);
			else if (this->_ch == 260 && this->_p->getX() - 1 > 1)
				this->_p->setX(this->_p->getX() - 1);
			else if (this->_ch == 261 && this->_p->getX() + 1 < 178)
				this->_p->setX(this->_p->getX() + 1);
			else if (this->_ch == 32)
				addBullet(this->_p->getX(), this->_p->getY() - 1, -1, &this->_pbullets);
		}
		wrefresh(this->_window);
		wrefresh(this->_gameInfo);
		usleep(500);
	}
	delete(this->_p);
}

void	Game::playerColision(void) {

	t_list *enemy = this->_enemies.head;
	t_list *bullet = this->_bullets.head;
	unsigned int pX = this->_p->getX();
	unsigned int pY = this->_p->getY();
	while (enemy) {
		if ((enemy->object->getX() == pX && enemy->object->getY() == pY)
		|| (enemy->object->getY() == pY + 1 &&
			(enemy->object->getX() == pX - 1 || enemy->object->getX() == pX + 1)))
			{
				this->_p->die();
				delete enemy->object;
				this->_enemies.del(enemy);
				_score += 15;
			}
		enemy = enemy->next;
	}
	while (bullet) {
		if ((bullet->object->getX() == pX && bullet->object->getY() == pY)
		|| (bullet->object->getY() == pY + 1 &&
			(bullet->object->getX() == pX - 1 || bullet->object->getX() == pX + 1)))
			{
				this->_p->die();
				delete bullet->object;
				this->_bullets.del(bullet);
			}
		bullet = bullet->next;
	}
}

void	Game::playerBulletColision(void) {

	t_list *to_del;
	t_list *bullet = this->_pbullets.head;
	t_list *enemy;

	while (bullet) {
		enemy = _enemies.head;
		while (enemy) {
			if (enemy->object->getX() == bullet->object->getX()
			&&	enemy->object->getY() == bullet->object->getY()) {
				delete enemy->object;
				to_del = enemy;
				enemy = enemy->next;
				_enemies.del(to_del);
				_score += 15;
			}
			else {
				enemy = enemy->next;
			}
		}
		bullet = bullet->next;
	}
}

void	Game::addEnemy(void) {

	if (this->_enemies.lstSize < 90)
	{
		Enemy	*enemy = new Enemy(1, 1);
		t_list	*lstnew = _enemies.lstnew(enemy);
		this->_enemies.add(lstnew);
	}
}

void	Game::showEnemies(void) const {

	t_list *lst = _enemies.head;

	while (lst) {
		mvwprintw(this->_window, lst->object->getY(), lst->object->getX(),
		lst->object->getSymbol());
		lst = lst->next;
	}
}

void	Game::moveEnemies(void) {

	t_list	*lst = _enemies.head;
	int		direction = 1;

	while (lst) {
		lst->object->setY(lst->object->getY() + 1);
		if (direction == 1)
		{
			if (this->_xD == 2)
				direction = -1;
			if (lst->object->getX() + this->_xD < WIDTH - 1 && lst->object->getX() + this->_xD > 0)
				lst->object->setX(lst->object->getX() + this->_xD);
			this->_xD++;
		}
		if (direction == -1)
		{
			if (this->_xD == -2)
				direction = 1;
			if (lst->object->getX() + this->_xD < WIDTH - 1 && lst->object->getX() + this->_xD > 0)
				lst->object->setX(lst->object->getX() + this->_xD);
			this->_xD--;
		}
		if (lst->object->getY() >= HEIGHT - 1)
		{
			delete(lst->object);
			this->_enemies.del(lst);
		}
		lst = lst->next;
	}
}

void	Game::addBullet(unsigned int x, unsigned int y, int direction, list *l) {

	Bullet	*bullet = new Bullet(x, y, 1, 2, 1, direction);
	t_list	*lstnew = _bullets.lstnew(bullet);

	l->add(lstnew);
}

void	Game::moveBullet(list *l) {

	t_list	*lst = l->head;

	while(lst) {
		lst->object->setY(lst->object->getY() + ((Bullet*)lst->object)->_direction);
		lst = lst->next;
	}
	
}

void	Game::showBullet(list *l) const {

	t_list *lst = l->head;

	while (lst) {
		if (lst->object->getY() >= HEIGHT - 1 || lst->object->getY() == 0)
		{
			delete(lst->object);
			l->del(lst);
		}
		mvwprintw(this->_window, lst->object->getY(), lst->object->getX(),
		lst->object->getSymbol());
		lst = lst->next;
	}
}

void	Game::enemyBullet(void) {

	t_list *lst = _enemies.head;

	while (lst) {
		addBullet(lst->object->getX(), lst->object->getY() + 1, 1, &this->_bullets);
		lst = lst->next;
	}
}

void	Game::addStars(void) {

	GameObject	*star = new Star(0, 0, 1, 1, 1);
	t_list *lst = _stars.lstnew(star);
	this->_stars.add(lst);
}

void	Game::moveStars(void) {

	t_list	*lst = this->_stars.head;

	while(lst) {
		lst->object->setY(lst->object->getY() + 1);
		if (lst->object->getY() >= HEIGHT - 1)
		{
			delete(lst->object);
			this->_stars.del(lst);
		}
		lst = lst->next;
	}
}

void	Game::showStars(void) {

	t_list	*lst = this->_stars.head;

	while (lst) {
		mvwprintw(this->_window, lst->object->getY(), lst->object->getX(),
		lst->object->getSymbol());
		lst = lst->next;
	}
}
