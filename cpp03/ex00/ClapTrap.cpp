#include "ClapTrap.hpp"

ClapTrap::~ClapTrap(){std::cout << " default destructor called " << std::endl;}


ClapTrap::ClapTrap( void )
{
	this->name = "unknown";
	this->hit_point = 10;
	this->energy_point = 10;
	this->attack_damage = 0;
	std::cout << " default cunstructor called " << std:: endl;
}

ClapTrap::ClapTrap( std::string name )
{
	this->name = name ;
	this->hit_point = 10;
	this->energy_point = 10;
	this->attack_damage = 0;
	std::cout << " custom cunstructor called " << std:: endl;
}

ClapTrap::ClapTrap(const ClapTrap& copy)
{
	this->name = copy.name;
	this->hit_point = copy.hit_point;
	this->attack_damage = copy.attack_damage;
	this->energy_point = copy.energy_point;
	std::cout << " copy cunstructor called " << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &copy)
{
	this->name =copy.name;
	this->hit_point = copy.hit_point;
	this->energy_point = copy.energy_point;
	this->attack_damage = copy.attack_damage;
	return(*this);
}


void ClapTrap::attack(const std::string &target)
{
	if(this->hit_point == 0)
		std::cout << " you cant attack because you are ghost	👻" <<std::endl;
	else if(this->hit_point != 0 && this-> energy_point == 0)
		std::cout << " you cant attack because you have no energy🤡" <<std::endl;
	else
		std::cout << " ClapTrap " << this->name <<" attacks "
			<< target<<  " ,causing " << this->attack_damage << " points of damage! "
			<<std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hit_point <= amount)
	{
		this->hit_point = 0;
		std::cout << name << " enemy has no hitpoint " << std::endl;
		return ;
	}
	this->hit_point -= amount;
	std::cout << name << "damage " << amount << " hit point!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energy_point == 0)
	{
		std::cout << name << "error no energy" << std::endl;
		return ;
	}
	if (this->hit_point == 0)
		std::cout << "repaired"<<std::endl;
	this->hit_point += amount;
	this->energy_point--;
	std::cout << name << "repaired" << amount << "hit point" << std::endl;
}