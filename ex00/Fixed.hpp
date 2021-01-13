#pragma once

class Fixed
{
private:
	static const int bits = 8;
	int value;

public:
	Fixed();
	~Fixed();

	Fixed(const Fixed &toCopy);
	Fixed &operator=(const Fixed &toAssign);

	int getRawBits(void);
	void setRawBits(int const raw);
};
