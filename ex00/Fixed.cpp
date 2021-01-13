#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed()
	: value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &toCopy)
{
	std::cout << "Copy constructor called" << std::endl;
	value = toCopy.value;
}

Fixed &Fixed::operator=(const Fixed &toAssign)
{
	std::cout << "Assignation operator called" << std::endl;
	value = toAssign.value;
	return (*this);
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
