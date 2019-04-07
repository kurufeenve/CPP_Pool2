#include "./../includes/Fixed.class.hpp"

const int Fixed::_noFixedBits = 8;

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called" << std::endl;
	this->_value = n << this->_noFixedBits;
}

Fixed::Fixed(const float f)
{
	std::cout << "Float constructor called" << std::endl;
	this->_value = roundf(f * (1 << this->_noFixedBits));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &f2)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = f2;
}

Fixed &Fixed::operator= (const Fixed &fixed)
{
	std::cout << "Assignation operator called" << std::endl;
	if (this != &fixed)
		this->_value = fixed.getRawBits();
	return *this;
}

int		Fixed::getRawBits(void) const
{
	return this->_value;
}

void	Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)this->_value / (float)(1 << this->_noFixedBits));
}

int 	Fixed::toInt(void) const
{
	return (this->_value / (1 << this->_noFixedBits));
}

std::ostream	&operator<< (std::ostream &out, Fixed const &f)
{
	out << f.toFloat();
	return (out);
}