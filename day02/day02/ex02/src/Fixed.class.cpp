#include "./../includes/Fixed.class.hpp"

const int Fixed::_noFixedBits = 8;

Fixed::Fixed()
{
	this->_value = 0;
}

Fixed::Fixed(const int n)
{
	this->_value = n << this->_noFixedBits;
}

Fixed::Fixed(const float f)
{
	this->_value = roundf(f * (1 << this->_noFixedBits));
}

Fixed::~Fixed() {}

Fixed::Fixed(const Fixed &f2)
{
	*this = f2;
}

Fixed &Fixed::operator= (const Fixed &fixed)
{
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

bool Fixed::operator>(const Fixed &fixed)
{
	return (this->toFloat() > fixed.toFloat());
}

bool Fixed::operator<(const Fixed &fixed)
{
	return (this->toFloat() < fixed.toFloat());
}

bool Fixed::operator>=(const Fixed &fixed)
{
	return (this->toFloat() >= fixed.toFloat());
}

bool Fixed::operator<=(const Fixed &fixed)
{
	return (this->toFloat() <= fixed.toFloat());
}

bool Fixed::operator==(const Fixed &fixed)
{
	return (this->toFloat() == fixed.toFloat());
}

bool Fixed::operator!=(const Fixed &fixed)
{
	return (this->toFloat() != fixed.toFloat());
}

const Fixed Fixed::operator+(const Fixed &fixed)
{
	return Fixed(this->toFloat() + fixed.toFloat());
}

const Fixed Fixed::operator-(const Fixed &fixed)
{
	return Fixed(this->toFloat() - fixed.toFloat());
}

const Fixed Fixed::operator*(const Fixed &fixed)
{
	return Fixed(this->toFloat() * fixed.toFloat());
}

const Fixed Fixed::operator/(const Fixed &fixed)
{
	if (fixed._value != 0)
		return Fixed(this->toFloat() / fixed.toFloat());
	else
	{
		std::cout << "Exception! division by 0 -> result unknown. Set to 0." << std::endl;
		return Fixed(0);
	}
}

const Fixed &Fixed::operator++(void)
{
	_value += 1;
	return *this;
}

const Fixed &Fixed::operator--(void)
{
	_value -= 1;
	return *this;
}

const Fixed Fixed::operator++(int)
{
	Fixed const	tmp = *this;

	++*this;
	return tmp;
}

const Fixed Fixed::operator--(int)
{
	Fixed	tmp = *this;

	--*this;
	return tmp;
}

Fixed		&Fixed::min(Fixed &f1, Fixed &f2)
{
	return (f1 > f2 ? f2 : f1);
}

const Fixed	&Fixed::min(const Fixed &f1, const Fixed &f2)
{
	return (f1.toFloat() > f2.toFloat() ? f2 : f1);
}

Fixed		&Fixed::max(Fixed &f1, Fixed &f2)
{
	return (f1 > f2 ? f1 : f2);
}

const Fixed	&Fixed::max(const Fixed &f1, const Fixed &f2)
{
	return (f1.toFloat() > f2.toFloat() ? f1 : f2);
}