#include <iostream>

int		main(void)
{
	std::string	str = "HI THIS IS BRAIN";
	std::string *pstr = &str;
	std::string &str_ref = str;

	std::cout << *pstr << "\n" << str_ref << std::endl;

	return 0;
}