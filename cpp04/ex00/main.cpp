#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const WrongAnimal* m = new WrongAnimal();
	const  WrongAnimal* l = new WrongCat();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	std::cout << m->getType() << " " << std::endl;
	std::cout << l->getType() << " " << std::endl;
	m->makeSound();
	l->makeSound();
	meta->makeSound();
	delete meta;
	delete j;
	delete i;
	delete m;
	delete l;

	return 0;
}