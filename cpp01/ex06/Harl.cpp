#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void Harl::complain( std::string level )
{
	typedef void (Harl::*method)(void);
	method methods[4] = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};
	std::string names[4] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};
	size_t i = 0;
	for (;i <= 4  && level.compare(names[i]) ; i++)
		for (; i == 4;)
		{
			std::cerr << URED << "errorrr!" << RESET<< std::endl;
			return ;
		}
	(this->*methods[i])();
}

void Harl::debug( void )
{
	std::cout << UBLU << "[DEBUG]\n  I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << RESET << std::endl;
}
void Harl::info( void )
{
	std::cout << UMAG << "[INFO]\n  I cannot believe adding extra bacon costs more money. You didn’t put"
				<< "enough bacon in my burger! If you did, I wouldn’t be asking for more!"  << RESET << std::endl;
}
void Harl::warning( void )
{
	std::cout << UCYN<< "[WARNING]\n  I think I deserve to have some extra bacon for free. I’ve been coming for"
					<< "years whereas you started working here since last month." << RESET<< std::endl;
}
void Harl::error( void )
{
	std::cout << UGRN << "[ERROR]\n This is unacceptable! I want to speak to the manager now." << RESET << std::endl;
}