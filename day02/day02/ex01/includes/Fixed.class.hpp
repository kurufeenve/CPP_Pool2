#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

#include <iostream>
#include <cmath>

class	Fixed
{
	private:
		int					_value;
		static const int	_noFixedBits;

	public:
		Fixed();
		Fixed(const int n);
		Fixed(const float f);
		~Fixed();
		Fixed(const Fixed &f2);
		Fixed &operator= (const Fixed &fixed);
		int				getRawBits(void) const;
		void			setRawBits(int const raw);
		float			toFloat(void) const;
		int 			toInt(void) const;
};
std::ostream	&operator<< (std::ostream &out, const Fixed &f);
#endif