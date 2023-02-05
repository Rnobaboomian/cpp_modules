#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "Animal.hpp"

class WrongCat : public Animal
{
private:
	Brain *brain;
public:
	WrongCat();
	~WrongCat();
	WrongCat(const WrongCat& copy);
	WrongCat &operator=(const WrongCat &copy);
	void makeSound( void );
};



#endif