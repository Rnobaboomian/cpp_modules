#include "HumanA.hpp"
//#include "Weapon.hpp"

HumanA::HumanA(std::string name,Weapon &club)
{
	this->name = name;
	this->club = &club;
}
HumanA::HumanA(){}
HumanA::~HumanA(){}

void HumanA:: attack()
{
	std::cout << UMAG << HumanA::name << " attacks with their " 
			<< club->getType() << RESET << std::endl;
} 
