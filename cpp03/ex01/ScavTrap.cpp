#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap()
{
	setter_all("hit_point",100);
	setter_all("energy_point",50);
	setter_all("attack_damage",20);
	std::cout << "ScavTrap default cunstructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy)
{
	setter_all("hit_point",100);
	setter_all("energy_point",50);
	setter_all("attack_damage",20);
	std::cout << "ScavTrap copy cunstructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	setter_all("hit_point",100);
	setter_all("energy_point",50);
	setter_all("attack_damage",20);
	std::cout << "ScavTrap custom cunstructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap default destructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &copy)
{
	if (this != &copy)
		ClapTrap::operator=(copy);
	std::cout << "ScavTrap oveload asignment operator called" << std::endl;
	return(*this);
}

void ScavTrap::attack(const std::string& target)
{
	if(this->hit_point == 0)
		std::cout << " ScavTrap : you cant attack because you are ghost	👻" <<std::endl;
	else if(this->hit_point != 0 && this-> energy_point == 0)
		std::cout << " ScavTrap : you cant attack because you have no energy🤡" <<std::endl;
	else
	{
		std::cout << " ScavTrap " << this->name <<" attacks "
			<< target<<  " ,causing " << this->attack_damage << " points of damage! "  <<std::endl;
	}
}

void ScavTrap::guardGate( void )
{
	std::cout <<"ScavTrap :" << name << "is in gatekeeper mode" << std::endl;
}