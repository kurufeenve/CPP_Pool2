#include <iostream>
#include <fstream>
#include <string>
#include "./../includes/Sed.class.hpp"

int		main(int argc, char **argv)
{
	Sed				*sed;
	
	if (argc != 4)
	{
		std::cout << "wrong number of arguments." << std::endl;
		exit(0);
	}
	try
	{
		sed = new Sed(argv[1], argv[2], argv[3]);
	}
	catch(int e) {
		exit(e);
	}
	delete sed;
	return (0);
}