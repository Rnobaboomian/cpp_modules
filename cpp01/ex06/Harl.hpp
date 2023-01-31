#ifndef HARL_HPP
#define HARL_HPP

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




#endif