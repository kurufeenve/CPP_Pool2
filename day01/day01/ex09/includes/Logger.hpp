#ifndef LOGGER_HPP
# define LOGGER_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <ratio>
#include <chrono>

class Logger
{
	private:
		void		logToConsole(std::string msg);
		void		logToFile(std::string msg);
		std::string	makeLogEntry(std::string msg);
		std::string	Name;

	public:
		Logger(std::string);
		~Logger();
		void		log(std::string const & dest, std::string const & message);
};

#endif
