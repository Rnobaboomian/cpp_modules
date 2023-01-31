#include "Fixed.hpp"

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
	std::cout << UMAG << "member func() get_rawbits_called" << RESET << std::endl;
	return(this->fixed_point);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << UMAG << "member func() set_rawbits_called" << RESET << std::endl;
	this->fixed_point = raw;
}

Fixed &Fixed::operator=(const Fixed &copy)
{
	std::cout << UCYN << "overload operator called " << RESET << std::endl;
	this->fixed_point = copy.getRawBits();
	return(*this);	
}