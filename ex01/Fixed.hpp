#ifndef FIXED_H
# define FIXED_H

# include <iostream>
# include <cmath> // Allowed: roundf

class Fixed
{
private:
	static const int bits = 8;
	int value;

public:
	Fixed(void);
	Fixed(const int);
	Fixed(const float);

	Fixed(const Fixed &);
	~Fixed(void);

	int getRawBits(void);
	void setRawBits(int const raw);

	float toFloat(void) const;
	int toInt(void) const;

	friend std::ostream &operator<<(std::ostream &os, Fixed const &f);
};

#endif