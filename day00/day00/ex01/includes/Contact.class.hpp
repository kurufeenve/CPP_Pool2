#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

# include <iostream>
# include <iomanip>

class   Contact
{
        private:
            std::string _firstName;
            std::string _lastName;
            std::string _nickName;
            std::string _login;
            std::string _postalAddress;
            std::string _emailAddress;
            std::string _phoneNumber;
            std::string _birthdayDate;
            std::string _favoriteMeal;
            std::string _underwearColor;
            std::string _darkestSecret;

        public:
            Contact(void);
            Contact(std::string firstName,
                    std::string lastName,
                    std::string nickName,
                    std::string login,
                    std::string postalAddress,
                    std::string emailAddress,
                    std::string phoneNumber,
                    std::string birthdayDate,
                    std::string favoriteMeal,
                    std::string underwearColor,
                    std::string darkestSecret);
            ~Contact(void);
            void        addContact(void);
            void        searchContact(void);
            void        showContact(void);
            void        setFirstName(std::string);
            void        setLastName(std::string);
            void        setNickName(std::string);
            void        setLogin(std::string);
            void		setPostalAddress(std::string);
            void		setEmailAddress(std::string);
            void		setPhoneNumber(std::string);
            void		setBirthdayDate(std::string);
            void		setFavoriteMeal(std::string);
            void		setUnderwearColor(std::string);
            void		setDarkestSecret(std::string);

};

# endif