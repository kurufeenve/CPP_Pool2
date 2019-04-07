//
// Created by Dmitro LITVINENKO on 2019-04-06.
//

#include "../includes/list.hpp"

int     main(void) {

	list list;

	list.add(list.lstnew(0));
	list.add(list.lstnew(0));
	list.add(list.lstnew(0));
	list.add(list.lstnew(0));
	list.add(list.lstnew(0));

	t_list *tmp;
	list.add((tmp = list.lstnew(0)));
	list.add(list.lstnew(0));
	list.add(list.lstnew(0));
	list.add(list.lstnew(0));
	list.add(list.lstnew(0));

	std::cout << list.lstSize;
	list.del(tmp);
	list.del(tmp);
	return 0;
}
