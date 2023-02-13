#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
private:
	Brain *brain;
public:
	using Animal::setType;
	Cat();
	~Cat();
	Cat(const Cat& copy);
	Cat &operator=(const Cat &copy);
	void makeSound( void )const;
};



#endif