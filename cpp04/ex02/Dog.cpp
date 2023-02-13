#include "Dog.hpp"

Dog::Dog(const Dog& copy) : Animal(copy)
{
	brain = new Brain(*copy.brain);
	std::cout << " Dog : copy cunstructor called " << std::endl;
}

Dog &Dog::operator=(const Dog &copy)
{
	if(this != &copy)
	{
		Animal::operator=(copy);
		*brain = *copy.brain;
	}
	std::cout << " Dog : copy assignment operator called " << std::endl;
	return(*this);
}

Dog::Dog() : Animal()
{
	setType("Dog");
	brain = new Brain();
	std::cout << " Dog : default cunstructor called " << std::endl;
}

Dog::~Dog()
{
	delete brain;
	std::cout << " Dog : destructor called called " << std::endl;
}

void Dog::makeSound( void )const
{
	if(_type == "Dog" || _type == "Dog")
		std::cout << (_type == "Dog" ? "meoww" : "bark!") << std::endl;
}