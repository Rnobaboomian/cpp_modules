#include "Cat.hpp"

Cat::Cat(const Cat& copy) : Animal(copy)
{
	std::cout << " Cat : copy cunstructor called " << std::endl;
}

Cat &Cat::operator=(const Cat &copy)
{
	if(this != &copy)
		Animal::operator=(copy);
	std::cout << " Cat : copy assignment operator called " << std::endl;
	return(*this);
}

Cat::Cat() : Animal()
{
	setType("Cat");
	std::cout << " Cat : default cunstructor called " << std::endl;
}

Cat::~Cat()
{
	std::cout << " Cat : destructor called called " << std::endl;
}

void Cat::makeSound( void )const 
{
	if(_type == "Cat" || _type == "Dog")
		std::cout << (_type == "Cat" ? "meoww" : "bark!") << std::endl;
}
