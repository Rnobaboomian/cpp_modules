#include "./Zombie.hpp"

Zombie::Zombie(){}
Zombie::~Zombie(){
	std::cout <<UCYN << Zombie::name<< ":  delault destructure called!"
			<< RESET <<std::endl;
}

Zombie::Zombie(std::string name)
{
	std::cout<< "COnstructor called " << std::endl;
	this->name = name;
}

void Zombie::announce()
{
	std::cout << Zombie::name <<std::endl;
}
void Zombie::announce(int N,Zombie *zomb)
{
	int i = -1;
	while(++i < N)
		std::cout << zomb[i].name <<std::endl;
}

void Zombie::set_name(std::string name)
{
	this->name = name;
}