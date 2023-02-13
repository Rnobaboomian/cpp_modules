#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
private:
	/* data */
public:
	Dog();
	~Dog();
	Dog(const Dog& copy);
	Dog &operator=(const Dog &copy);
	void makeSound( void )const;
};




#endif