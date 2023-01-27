#include "Zombie.hpp"
//default cunstructure and destructure
Zombie::Zombie(){}
Zombie::~Zombie(){
	std::cout << UBLU << Zombie::name 
		<<"  destructed!"
		<<RESET<< std::endl;
}

// custom cunstructure

Zombie::Zombie(std::string name)
{
	this->name = name;
}

//announce function

void Zombie::announce()
{
	std::cout << Zombie::name << " : " 
		<< " BraiiiiiiinnnzzzZ..." << std::endl;
}

