#ifndef CAT_CLASS_HPP
# define CAT_CLASS_HPP

# include <iostream>
# include <string>
# include <fstream>

class Cat
{
private:
	
public:
	Cat();
	~Cat();
	static void	read(std::string file);
};

#endif
