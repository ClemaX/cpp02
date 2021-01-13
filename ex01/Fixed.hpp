#pragma once

#include <iostream>
#include <cmath> // Allowed: roundf

class Fixed
{
private:
	static const int bits = 8;
	int value;

public:
	Fixed();
	~Fixed();

	Fixed(const int);
	Fixed(const float);
	Fixed(const Fixed &toCopy);

	Fixed	&operator=(const Fixed &toAssign);

	int		getRawBits(void);
	void	setRawBits(int const raw);

	float	toFloat(void) const;
	int		toInt(void) const;
};

std::ostream	&operator<<(std::ostream &os, const Fixed &val);
