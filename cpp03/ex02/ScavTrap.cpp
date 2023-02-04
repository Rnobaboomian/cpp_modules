#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap()
{
	setter_all("hit_point",100);
	setter_all("energy_point",50);
	setter_all("attack_damage",20);
	std::cout << UBLU << " ScavTrap : default cunstructor called " << RESET<<std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy)
{
	setter_all("hit_point",100);
	setter_all("energy_point",50);
	setter_all("attack_damage",20);
	std::cout << UBLU << " ScavTrap : copy cunstructor called " << RESET<<std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	setter_all("hit_point",100);
	setter_all("energy_point",50);
	setter_all("attack_damage",20);
	std::cout << UBLU << " ScavTrap : custom cunstructor called " << RESET<<std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << UBLU << " ScavTrap : default destructor called " << RESET<<std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &copy)
{
	if (this != &copy)
		ClapTrap::operator=(copy);
	std::cout << UBLU << " ScavTrap : oveload asignment operator called " << RESET<<std::endl;
	return(*this);
}

void ScavTrap::attack(const std::string& target)
{
	if(this->hit_point == 0)
		std::cout << UBLU << " ScavTrap : you cant attack because you are ghost	👻" <<RESET<<std::endl;
	else if(this->hit_point != 0 && this-> energy_point == 0)
		std::cout << UBLU << " ScavTrap : you cant attack because you have no energy🤡" <<RESET<<std::endl;
	else
	{
		std::cout << UBLU << " ScavTrap " << this->name <<" attacks "
			<< target<<  " ,causing " << this->attack_damage << " points of damage! " <<RESET<<std::endl;
			hit_point -= attack_damage;
	}
}

void ScavTrap::guardGate( void )
{
	std::cout << UBLU <<"ScavTrap :" << name << "is in gatekeeper mode" << RESET<<std::endl;
}