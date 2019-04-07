#include "./../includes/Sed.class.hpp"

Sed::Sed(std::string filename, std::string f_nd, std::string r_place)
{
	if (f_nd.compare(r_place) == 0)
	{
		std::cout << "you are trying to replace the same." << std::endl;
		throw -1;
	}
	this->_replaceLen = r_place.length();
	this->_findLen = f_nd.length();
	this->_last = 0;
	this->_bool = 1;
	this->_myfile.open(filename);
	if (!this->_myfile)
	{
		std::cout << "not a file." << std::endl;
		throw -1;
	}
	while (std::getline(this->_myfile, this->_line))
			this->_res += this->_line;
	do {
		this->_last = this->_res.find(f_nd, this->_last);
		if (this->_last != std::string::npos)
		{
			this->_res.replace(this->_last, this->_findLen, r_place);
			this->_last += this->_replaceLen;
		}
		else
			this->_bool = 0;
	} while (this->_bool != 0);
	this->_resFile = filename + ".replace";
	std::ofstream outfile (this->_resFile);
	outfile << this->_res << std::endl;
	outfile.close();
	getMyFile().close();
}

Sed::~Sed() {}

std::ifstream	&Sed::getMyFile()
{
	return (this->_myfile);
}
