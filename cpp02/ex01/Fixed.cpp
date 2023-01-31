#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(const int num)
{
	std::cout << UBLU << "INT cunstructor called" << RESET << std::endl;
	this->fixed_point = num << Fixed::fractional_bits;
}
Fixed::Fixed(const float num)
{
	std::cout << UBLU << "float cunstructor called" << RESET << std::endl;
	this->fixed_point = roundf(num * (1 << Fixed::fractional_bits));
}

Fixed::Fixed( void )
{
	std::cout << UBLU << "default cunstructor called" << RESET << std::endl;
	this->fixed_point = 0;
}
Fixed::Fixed(Fixed const &copy)
{
	std::cout << UBLU << "copy cunstructor called" << RESET << std::endl;
	*this = copy;
}

Fixed::~Fixed()
{
	std::cout << URED << "default destructor called" << RESET << std::endl;
}

int Fixed::getRawBits( void )const
{
	return(this->fixed_point);
}

void Fixed::setRawBits(int const raw)
{
	this->fixed_point = raw;
}

Fixed &Fixed::operator=(const Fixed &copy)
{
	std::cout << UCYN << "copy asignment operator called " << RESET << std::endl;
	this->fixed_point = copy.getRawBits();
	return(*this);	
}

int Fixed::toInt( void )const
{
	return this->fixed_point >> Fixed::fractional_bits;
}

float Fixed::to_float( void )const
{
	return static_cast<float>(this->fixed_point) / (1 << Fixed::fractional_bits);
}

std::ostream &operator<<(std::ostream &ostream,const Fixed &copy)
{
	ostream << copy.to_float();
	return ostream;
}