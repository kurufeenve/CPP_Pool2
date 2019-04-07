#include "./../includes/Logger.hpp"
#include <algorithm>

Logger::Logger(std::string name) : Name(name){}

void		Logger::logToConsole(std::string msg)
{
	std::cout << this->makeLogEntry(msg) << std::endl;
}

void		Logger::logToFile(std::string msg)
{
	std::ofstream LogFile;
	
	LogFile.open(this->Name, std::ofstream::out | std::ofstream::app);
	LogFile << this->makeLogEntry(msg) << std::endl;
	LogFile.close();
}

std::string	Logger::makeLogEntry(std::string msg)
{
	time_t		tt;
	std::string	res;
	std::string	two_dot;
	std::string	end_log;

	std::chrono::system_clock::time_point today = std::chrono::system_clock::now();
	tt = std::chrono::system_clock::to_time_t(today);
	res = "log: ";
	end_log = "<<END LOG\n";
	res += ctime(&tt) + msg + end_log;
	return res;
}

void		Logger::log(std::string const & dest, std::string const & message)
{
	void		(Logger::*logg[2])(std::string msg) = {&Logger::logToConsole, &Logger::logToFile};
	std::string	command[] = {"Console", "File", "console", "file"};

	for (int i = 0; i < 4; i++)
	{
		if (dest.compare(command[i]) == 0)
			(this->*logg[i % 2])(message);
	}
}
