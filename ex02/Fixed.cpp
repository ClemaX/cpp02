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
	os << f.toFloat();
	return (os);
}

bool Fixed::operator<(const Fixed &f) const
{
	return (value < f.value);
}

bool Fixed::operator>(Fixed const &f) const
{
	return (value > f.value);
}
bool Fixed::operator<=(Fixed const &f) const
{
	return (value <= f.value);
}
bool Fixed::operator>=(Fixed const &f) const
{
	return (value >= f.value);
}
bool Fixed::operator==(Fixed const &f) const
{
	return (value == f.value);
}
bool Fixed::operator!=(Fixed const &f) const
{
	return (value != f.value);
}

Fixed Fixed::operator+(Fixed const &f) const
{
	Fixed res;
	res.value = value + f.value;
	return (res);
}
Fixed Fixed::operator-(Fixed const &f) const
{
	Fixed res;
	res.value = value - f.value;
	return (res);
}
Fixed Fixed::operator*(Fixed const &f) const
{
	Fixed res;
	res.value = (static_cast<long>(value) * f.value) >> bits;
	return (res);
}
Fixed Fixed::operator/(Fixed const &f) const
{
	Fixed res;
	res.value = (value / f.value) << bits;
	return (res);
}

Fixed &Fixed::operator++(void)
{
	value++;
	return (*this);
}

Fixed &Fixed::operator--(void)
{
	value--;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed res;
	res.value = value;
	operator++();
	return (res);

}
Fixed Fixed::operator--(int)
{
	Fixed res;
	res.value = value;
	operator--();
	return (res);
}

Fixed const &min(const Fixed &a, const Fixed &b)
{
	return (a < b ? a : b);
}

Fixed const &max(const Fixed &a, const Fixed &b)
{
	return (a > b ? a : b);
}
