#include "Fixed.hpp"
#include "Fixed.hpp"

Fixed::Fixed(void) {
	fixedPointValue = 0;
}
Fixed::Fixed(const Fixed &f) {
	*this = f;
}
Fixed &Fixed::operator=(const Fixed &f) {
	if (this != &f)
		this->setRawBits(f.getRawBits());
	return (*this);
}
int	Fixed::getRawBits(void) const {
	return(this->fixedPointValue);
}
void	Fixed::setRawBits(int const raw) {
	this->fixedPointValue = raw;
}
Fixed::Fixed(const int nb) {
	this->setRawBits(nb << this->numOfFractionalBits);
}
Fixed::Fixed(const float nb)
{
	this->setRawBits((int)roundf(nb * (1 << this->numOfFractionalBits)));
}
float   Fixed::toFloat(void) const
{
    return static_cast<float>(this->fixedPointValue) / (1 << this->numOfFractionalBits);
}
int	Fixed::toInt(void) const
{
	return (this->fixedPointValue >> this->numOfFractionalBits);
}
std::ostream &operator<<(std::ostream &oper, Fixed const &f)
{
	oper << f.toFloat();
	return (oper);
}

Fixed::~Fixed(void){}
bool	Fixed::operator>(const Fixed &copy) const
{
	return (this->getRawBits() > copy.getRawBits());
}

bool	Fixed::operator<(const Fixed &copy) const
{
	return (this->getRawBits() < copy.getRawBits());
}

bool	Fixed::operator>=(const Fixed &copy) const
{
	return (this->getRawBits() >= copy.getRawBits());
}

bool	Fixed::operator<=(const Fixed &copy) const
{
	return (this->getRawBits() <= copy.getRawBits());
}

bool	Fixed::operator==(const Fixed &copy) const
{
	return (this->getRawBits() == copy.getRawBits());
}

bool	Fixed::operator!=(const Fixed &copy) const
{
	return (this->getRawBits() != copy.getRawBits());
}

Fixed	Fixed::operator+(const Fixed &copy) const
{
	return (Fixed(this->toFloat() + copy.toFloat()));
}

Fixed	Fixed::operator-(const Fixed &copy) const
{
	return (Fixed(this->toFloat() - copy.toFloat()));
}

Fixed	Fixed::operator*(const Fixed &copy) const
{
	return (Fixed(this->toFloat() * copy.toFloat()));
}

Fixed	Fixed::operator/(const Fixed &copy) const
{
	return (Fixed(this->toFloat() / copy.toFloat()));
}

Fixed	&Fixed::operator++(void)
{
	++this->fixedPointValue;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp(*this);
	++this->fixedPointValue;
	return (tmp);
}

Fixed	&Fixed::operator--(void)
{
	--this->fixedPointValue;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp(*this);
	--this->fixedPointValue;
	return (tmp);
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return a;
	return b;
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return a;
	return b;
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return a;
	return b;
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return a;
	return b;
}
