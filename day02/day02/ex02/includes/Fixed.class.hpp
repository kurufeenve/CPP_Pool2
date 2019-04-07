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
		bool operator>(const Fixed &fixed);
		bool operator<(const Fixed &fixed);
		bool operator>=(const Fixed &fixed);
		bool operator<=(const Fixed &fixed);
		bool operator==(const Fixed &fixed);
		bool operator!=(const Fixed &fixed);
		const Fixed operator+(const Fixed &fixed);
		const Fixed operator-(const Fixed &fixed);
		const Fixed operator*(const Fixed &fixed);
		const Fixed operator/(const Fixed &fixed);
		const Fixed &operator++(void);
		const Fixed &operator--(void);
		const Fixed operator++(int);
		const Fixed operator--(int);
		int					getRawBits(void) const;
		void				setRawBits(int const raw);
		float				toFloat(void) const;
		int 				toInt(void) const;
		static Fixed		&min(Fixed &f1, Fixed &f2);
		const static Fixed	&min(const Fixed &f1, const Fixed &f2);
		static Fixed		&max(Fixed &f1, Fixed &f2);
		const static Fixed	&max(const Fixed &f1, const Fixed &f2);
};
std::ostream	&operator<< (std::ostream &out, const Fixed &f);

#endif