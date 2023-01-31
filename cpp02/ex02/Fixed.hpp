#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>
# include <cmath>

class Fixed
{
	private:
		int					fixedPointValue; 	
		static const int	numOfFractionalBits = 8;

	public:
		Fixed(void);		
		Fixed(const Fixed &f);
		Fixed &operator=(const Fixed &f);
		~Fixed(void);	

		Fixed(const int nb);					
		Fixed(const float nb);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		int		toInt(void) const;
		float	toFloat(void) const;
		bool	operator>=(const Fixed &copy) const;
		bool	operator<=(const Fixed &copy) const;
		bool	operator==(const Fixed &copy) const;
		bool	operator!=(const Fixed &copy) const;
		bool	operator>(const Fixed &copy) const;
		bool	operator<(const Fixed &copy) const;

		Fixed	&operator++(void);
    	Fixed	operator++(int);
    	Fixed	&operator--(void);
    	Fixed	operator--(int);
		Fixed	operator+(const Fixed &copy) const;
		Fixed	operator-(const Fixed &copy) const;
		Fixed	operator*(const Fixed &copy) const;
		Fixed	operator/(const Fixed &copy) const;


    	static Fixed		&min(Fixed &a, Fixed &b);
    	static const Fixed	&min(const Fixed &a, const Fixed &b);
    	static Fixed		&max(Fixed &a, Fixed &b);
    	static const Fixed	&max(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<(std::ostream &o, const Fixed &i);

#endif
