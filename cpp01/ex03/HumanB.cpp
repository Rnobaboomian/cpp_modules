#include "HumanB.hpp"
HumanB::HumanB(std::string name)
{
	this->name = name;
}
HumanB::HumanB(){}
HumanB::~HumanB(){}

void HumanB:: attack()
{
	std::cout <<UBLU << HumanB::name << " attacks with their " 
			<< club->getType() << RESET<< std::endl;
}

void HumanB::setWeapon(Weapon &club)
{
	this->club = &club;
}
