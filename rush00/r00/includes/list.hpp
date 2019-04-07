//
// Created by Dmitro LITVINENKO on 2019-04-06.
//

#ifndef RUSH00_LIST_HPP
#define RUSH00_LIST_HPP

#include "GameObject.hpp"

typedef struct      s_list
{
	struct s_list   *next;
	GameObject      *object;
}                   t_list;

class list
{

public:

	list();
	list(const list &);
	~list();

	list &operator=(const list &);

	void            add(t_list*);
	void            del(t_list*);
	t_list          *lstnew(GameObject *content);
	void            iter(void (*f)(t_list*));

	int         lstSize;
	t_list      *head;

};

RUSH00_LIST_HPP
#endif //RUSH00_LIST_HPP
