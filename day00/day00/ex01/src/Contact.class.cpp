#include "./../includes/Contact.class.hpp"

Contact::Contact(void) : _firstName("NAN"),
						 _lastName("NAN"), 
						 _nickName("NAN"), 
						 _login("NAN"),
						 _postalAddress("NAN"),
						 _emailAddress("NAN"),
						 _phoneNumber("NAN"),
						 _birthdayDate("NAN"),
						 _favoriteMeal("NAN"),
						 _underwearColor("NAN"),
						 _darkestSecret("NAN") {}

Contact::Contact(std::string firstName,
				 std::string lastName,
				 std::string nickName,
				 std::string login,
				 std::string postalAddress,
				 std::string emailAddress,
				 std::string phoneNumber,
				 std::string birthdayDate,
				 std::string favoriteMeal,
				 std::string underwearColor,
				 std::string darkestSecret) :
				 _firstName(firstName),
				 _lastName(lastName),
				 _nickName(nickName),
				 _login(login),
				 _postalAddress(postalAddress),
				 _emailAddress(emailAddress),
				 _phoneNumber(phoneNumber),
				 _birthdayDate(birthdayDate),
				 _favoriteMeal(favoriteMeal),
				 _underwearColor(underwearColor),
				 _darkestSecret(darkestSecret) {} 

Contact::~Contact(void) {}

void    Contact::addContact(void)
{
    std::string	data;

	std::cin.clear();
	std::cout << "First Name: ";
	std::getline (std::cin, data);
	this->setFirstName(data);
	std::cout << "Last Name: ";
	std::getline (std::cin, data);
	this->setLastName(data);
	std::cout << "Nickname: ";
	std::getline (std::cin, data);
	this->setNickName(data);
	std::cout << "Login: ";
	std::getline (std::cin, data);
	this->setLogin(data);
	std::cout << "Postal Address: ";
	std::getline (std::cin, data);
	this->setPostalAddress(data);
	std::cout << "Email Address: ";
	std::getline (std::cin, data);
	this->setEmailAddress(data);
	std::cout << "Phone Number: ";
	std::getline (std::cin, data);
	this->setPhoneNumber(data);
	std::cout << "Birthday Date: ";
	std::getline (std::cin, data);
	this->setBirthdayDate(data);
	std::cout << "Favorite Meal: ";
	std::getline (std::cin, data);
	this->setFavoriteMeal(data);
	std::cout << "Underwear Color: ";
	std::getline (std::cin, data);
	this->setUnderwearColor(data);
	std::cout << "Darkest Secret: ";
	std::getline (std::cin, data);
	this->setDarkestSecret(data);
}

void		Contact::showContact(void)
{
	std::cout << "First Name: " << this->_firstName << "\n"
	<< "Last Name: " << this->_lastName << std::endl
	<< "Nickname: " << this->_nickName << std::endl
	<< "Login: " << this->_login << std::endl
	<< "Postal Address: " << this->_postalAddress << std::endl
	<< "Email Address: " << this->_emailAddress << std::endl
	<< "Phone Number: " << this->_phoneNumber << std::endl
	<< "Birthday Date: " << this->_birthdayDate << std::endl
	<< "Favorite Meal: " << this->_favoriteMeal << std::endl
	<< "Underwear Color: " << this->_underwearColor << std::endl
	<< "Darkest Secret: " << this->_darkestSecret << std::endl;
}

void		Contact::searchContact(void)
{
	if (this->_firstName.length() > 10)
	{
		std::cout << this->_firstName.substr(0, 9);
		std::cout << ".|";
	}
	else
	{
		std::cout << std::setw(10) << this->_firstName << "|";
	}
	if (this->_lastName.length() > 10)
	{
		std::cout << this->_lastName.substr(0, 9);
		std::cout << ".|";
	}
	else
	{
		std::cout << std::setw(10) << this->_lastName << "|";
	}
	if (this->_nickName.length() > 10)
	{
		std::cout << this->_nickName.substr(0, 9);
		std::cout << ".|";
	}
	else
	{
		std::cout << std::setw(10) << this->_nickName << "|";
	}
}

void		Contact::setFirstName(std::string str)
{
	this->_firstName = str;
	return ;
}

void		Contact::setLastName(std::string str)
{
	this->_lastName = str;
	return ;
}

void		Contact::setNickName(std::string str)
{
	this->_nickName = str;
	return ;
}

void		Contact::setLogin(std::string str)
{
	this->_login = str;
	return ;
}

void		Contact::setPostalAddress(std::string str)
{
	this->_postalAddress = str;
	return ;
}

void		Contact::setEmailAddress(std::string str)
{
	this->_emailAddress = str;
	return ;
}

void		Contact::setPhoneNumber(std::string str)
{
	this->_phoneNumber = str;
	return ;
}

void		Contact::setBirthdayDate(std::string str)
{
	this->_birthdayDate = str;
	return ;
}

void		Contact::setFavoriteMeal(std::string str)
{
	this->_favoriteMeal = str;
	return ;
}

void		Contact::setUnderwearColor(std::string str)
{
	this->_underwearColor = str;
	return ;
}

void		Contact::setDarkestSecret(std::string str)
{
	this->_darkestSecret = str;
	return ;
}
