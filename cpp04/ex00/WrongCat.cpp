#include "WrongCat.hpp"

WrongCat::WrongCat(const WrongCat& copy) : Animal(copy)
{
	std::cout << " WrongCat : copy cunstructor called " << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &copy)
{
	if(this != &copy)
		Animal::operator=(copy);
	std::cout << " WrongCat : copy assignment operator called " << std::endl;
	return(*this);
}

WrongCat::WrongCat() : Animal()
{
	setType("WrongCat");
	std::cout << " WrongCat : default cunstructor called " << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << " WrongCat : destructor called called " << std::endl;
}

void WrongCat::makeSound( void )
{
	if(_type == "WrongCat" || _type == "Dog")
		std::cout << (_type == "WrongCat" ? "meoww" : "bark!") << std::endl;
}