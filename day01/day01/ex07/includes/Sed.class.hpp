#ifndef SED_CLASS_HPP
# define SED_CLASS_HPP

#include <iostream>
#include <fstream>
#include <string>

class	Sed
{
	private:
		std::ifstream	_myfile;
		std::string		_res;
		std::string		_line;
		size_t			_last;
		size_t			_replaceLen;
		size_t			_findLen;
		int				_bool;
		std::string		_resFile;

	public:
		Sed(std::string filename, std::string find, std::string replace);
		~Sed();
		std::ifstream	&getMyFile();
};

# endif
