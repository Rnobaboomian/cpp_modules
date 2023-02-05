#include "WrongAnimal.hpp"


WrongAnimal::WrongAnimal(const WrongAnimal& copy)
{
	this->_type = copy._type;
	std::cout << " WrongAnimal : copy cunstructor called " << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &copy)
{
	if(this != &copy)
		this->_type = copy._type;
	std::cout << " WrongAnimal : copy assignment operator called " << std::endl;
	return(*this);
}

WrongAnimal::WrongAnimal()
{
	_type = "WrongAnimal : unknown";
	std::cout << " WrongAnimal : default cunstructor called " << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << " WrongAnimal : destructor called called " << std::endl;
}

void WrongAnimal::makeSound( void )const
{
	if(_type == "Cat" || _type == "Dog")
		std::cout << (_type == "Cat" ? "meoww" : "bark!") << std::endl;
}

void WrongAnimal::setType(std::string name)
{
	this->_type = name;
}

std::string WrongAnimal::getType( void )const
{
	return this->_type;
}