#include "./../includes/Contact.class.hpp"

int		main(void)
{
	int			i = 0;
	std::string command;
	Contact		Contact[8];

	std::cout << "ADD - add new User" << std::endl;
	std::cout << "SEARCH - search User" << std::endl;
	std::cout << "EXIT - erase all contacts and exit the program" << std::endl;
	std::cout << "Type your command: ";

	while (command.compare("EXIT"))
	{
		std::getline (std::cin, command);
		if (i >= 8)
		{
			std::cout << "Oh, Sir, it seems that the phonebook is full. You can \
cry in the corner now." << std::endl;
		}
		if (!command.compare("ADD") && i < 8)
		{
			Contact[i].addContact();
			std::cout << std::endl << "New Contact added." << std::endl << std::endl; 
			i++;
		}
		if (!command.compare("SEARCH"))
		{
			std::cout << "|" << std::setw(10) << "INDEX" << "|"
			<< std::setw(10) << "First Name" << "|" << std::setw(10)
			<< "Last Name" << "|" << std::setw(10) << "NickName" << "|"
			<< std::endl;
			for (int j = 0; j < i; j++)
			{
				std::cout << "|" << std::setw(10) << (j + 1) << "|";
				Contact[j].searchContact();
				std::cout << std::endl;
			}
			std::cin >> command;
			int j = atoi(command.c_str()) - 1;
			if (j >= 0 && j < i)
				Contact[j].showContact();
		}
		if (std::cin.eof() == 1)
		{
			std::cout << "\n\nGERARA HERE!\n" << std::endl;
			break ;
		}
	}
	return (0);
}
