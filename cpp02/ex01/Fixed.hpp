#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

const std::string UBLK = "\e[4;30m";
const std::string URED = "\e[4;31m";
const std::string UGRN = "\e[4;32m";
const std::string UYEL = "\e[4;33m";
const std::string UBLU = "\e[4;34m";
const std::string UMAG = "\e[4;35m";
const std::string UCYN = "\e[4;36m";
const std::string UWHT = "\e[4;37m";
const std::string RESET = "\e[0;37m";

class Fixed
{
private:
	int fixed_point;
	static const int fractional_bits = 8;
public:
	Fixed( void );
	Fixed(const int  num);
	Fixed(const float  num);
	~Fixed();
	Fixed(const Fixed  &copy);
	Fixed &operator=(Fixed const &copy);
	int getRawBits( void )const ;
	void setRawBits( int const raw );
	int toInt()const;
	float to_float()const;
};

std::ostream &operator<<(std::ostream &ostream,const Fixed &copy);


#endif
