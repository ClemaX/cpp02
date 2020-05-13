#include "Fixed.hpp"

Fixed::Fixed(void)
	: value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int i)
	: value(i << bits)
{
}

Fixed::Fixed(const float f)
	: value(f * (1 << bits))
{
}

Fixed::Fixed(const Fixed& toCopy)
	: value(toCopy.value)
{
	std::cout << "Assignation operator called" << std::endl;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void)
{
	std::cout << "getRawBits member function called" << std::endl;
	return (value);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	value = raw;
}

int Fixed::toInt(void) const
{
	return (roundf(toFloat()));
}

float Fixed::toFloat(void) const
{
	return (static_cast<float>(value) / (1 << bits));
}

std::ostream &operator<< (std::ostream &os, const Fixed &f)
{
	return (os << f.toFloat());
}