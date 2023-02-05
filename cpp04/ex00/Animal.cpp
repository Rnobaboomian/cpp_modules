#include "Animal.hpp"


Animal::Animal(const Animal& copy)
{
	this->_type = copy._type;
	std::cout << " Animal : copy cunstructor called " << std::endl;
}

Animal &Animal::operator=(const Animal &copy)
{
	if(this != &copy)
		this->_type = copy._type;
	std::cout << " Animal : copy assignment operator called " << std::endl;
	return(*this);
}

Animal::Animal()
{
	_type = "Animal : unknown";
	std::cout << " Animal : default cunstructor called " << std::endl;
}

Animal::~Animal()
{
	std::cout << " Animal : destructor called called " << std::endl;
}

void Animal::makeSound( void )const
{
	if(_type == "Cat" || _type == "Dog")
		std::cout << (_type == "Cat" ? "meoww" : "bark!") << std::endl;
}

void Animal::setType(std::string name)
{
	this->_type = name;
}

std::string Animal::getType( void )const
{
	return this->_type;
}