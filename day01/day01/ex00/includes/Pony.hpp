#ifndef PONY_HPP
# define PONY_HPP

# include <iostream>

class   Pony
{
	private:
		std::string _name;
		std::string _id;
		std::string _sex;
		std::string _thinkOf;

	public:
		Pony(void);
		Pony(std::string name,
			 std::string id,
			 std::string sex,
			 std::string thinkOf);
		~Pony(void);
		void	getFullInfo(void);
};

#endif