#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

class Harl
{
private:
	void debug( void );
	void info( void );
	void warning( void );
	void error( void );
public:
	Harl();
	~Harl();
	void complain( std::string level );
};

Harl::Harl(/* args */)
{
}

Harl::~Harl()
{
}

void Harl::debug( void )
{
	std::cout << "I love having extra bacon for my"
			 << "7XL-double-cheese-triple-pickle-specialketchup burger."
			<<"I really do!" << std::endl;
}
void Harl::info( void )
{

}
void Harl::warning( void )
{

}
void Harl::error( void )
{

}


#endif