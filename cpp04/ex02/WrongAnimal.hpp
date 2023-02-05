#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include "Brain.hpp"
const std::string UBLK = "\e[4;30m";
const std::string URED = "\e[4;31m";
const std::string UGRN = "\e[4;32m";
const std::string UYEL = "\e[4;33m";
const std::string UBLU = "\e[4;34m";
const std::string UMAG = "\e[4;35m";
const std::string UCYN = "\e[4;36m";
const std::string UWHT = "\e[4;37m";
const std::string RESET = "\e[0;37m";

class WrongAnimal
{
protected:
	std::string _type;
private:
	
public:
	WrongAnimal();
	virtual ~WrongAnimal();
	 WrongAnimal(const WrongAnimal& copy);
	WrongAnimal &operator=(const WrongAnimal &copy);
	std::string getType( void ) const;
	void setType(const std::string name);
	virtual void makeSound( void )const = 0;
};


#endif