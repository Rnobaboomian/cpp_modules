#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap()
{
	setter_all("hit_point",100);
	setter_all("energy_point",100);
	setter_all("attack_damage",30);
	std::cout << UGRN << " FragTrap : default custructor called " << RESET <<std::endl;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy)
{
	setter_all("hit_point",100);
	setter_all("energy_point",100);
	setter_all("attack_damage",30);
	std::cout << UGRN << " FragTrap : copy constructor called " << RESET <<std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	setter_all("hit_point",100);
	setter_all("energy_point",100);
	setter_all("attack_damage",30);
	std::cout << UGRN << " FragTrap : custom constructor called " << RESET <<std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << UGRN << " FragTrap : default destructor called " << RESET <<std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &copy)
{
	if (this != &copy)
		ClapTrap::operator=(copy);
	std::cout << UGRN << "FragTrap oveload asignment operator called" << RESET <<std::endl;
	return(*this);
}

void FragTrap::attack(const std::string& target)
{
	if(this->hit_point == 0)
		std::cout << UGRN << " FragTrap : you cant attack because you are ghost	👻" <<RESET <<std::endl;
	else if(this->hit_point != 0 && this-> energy_point == 0)
		std::cout << UGRN << " FragTrap : you cant attack because you have no energy🤡" <<RESET <<std::endl;
	else
	{
		std::cout << UGRN << " FragTrap " << this->name <<" attacks "
			<< target<<  " ,causing " << this->attack_damage << " points of damage! "  <<RESET <<std::endl;
			hit_point -= attack_damage;
	}
}

void FragTrap::highFivesGuys( void )
{
	std::cout << UGRN << " FragTrap : " << name << " hey yo nigga " << std::endl;  
}
