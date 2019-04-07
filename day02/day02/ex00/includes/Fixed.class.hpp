#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

#include <iostream>

class	Fixed
{
	private:
		int					_value;
		static const int	_noFixedBits;

	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed &f2);
		Fixed& operator= (const Fixed &fixed);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif