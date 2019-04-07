//
// Created by Dmitro LITVINENKO on 2019-04-06.
//

#include "../includes/list.hpp"

static void cleanList(t_list *lst)
{
	if (lst)
	{
		cleanList(lst->next);
		delete lst;
	}
}

list::list() : lstSize(0), head(0)
{}

void    list::add(t_list *lstNew)
{
	if (lstNew)
	{
		lstSize++;
		lstNew->next = head;
		head = lstNew;
	}
}

t_list    *list::lstnew(GameObject *content)
{
	t_list *tmp = new t_list;

	tmp->next = 0;
	tmp->object = content;
	return tmp;
}

void    list::del(t_list *lst)
{
	t_list *tmp = head;
	t_list *prev;

	if (lst == head) {
		tmp = tmp->next;
		delete head;
		head = tmp;
		lstSize--;
		return ;
	}
	while (tmp && tmp != lst) {
		prev = tmp;
		tmp = tmp->next;
	}
	if (tmp) {
		tmp = tmp->next;
		delete prev->next;
		prev->next = tmp;
		lstSize--;
	}
	else {
		std::cerr << "Couldn't find list in chained list";
	}
}

list&   list::operator=(list const & object)
{
	(void)object;
	return *this;
}

void    list::iter(void (*f)(t_list*))
{
	t_list *tmp = head;

	while (tmp)
	{
		f(tmp);
		tmp = tmp->next;
	}
}

list::~list()
{
	cleanList(head);
}
