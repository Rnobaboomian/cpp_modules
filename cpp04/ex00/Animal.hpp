#ifndef ANIMAL_HPP
#define ANIMAL_HPP

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

class Animal
{
protected:
	std::string _type;
private:
	
public:
	Animal();
	virtual ~Animal();
	 Animal(const Animal& copy);
	Animal &operator=(const Animal &copy);
	std::string getType( void ) const;
	void setType(const std::string name);
	virtual void makeSound( void )const;
};


#endif