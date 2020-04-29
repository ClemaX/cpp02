#ifndef FIXED_H
# define FIXED_H

class Fixed
{
private:
	static const int bits = 8;
	int value;
public:
	Fixed(void);
	Fixed(const Fixed&);
	~Fixed(void);

	int getRawBits(void);
	void setRawBits(int const raw);
};

#endif