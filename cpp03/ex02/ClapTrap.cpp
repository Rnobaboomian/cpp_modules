#include "ClapTrap.hpp"

ClapTrap::~ClapTrap(){std::cout << UMAG <<UMAG << " ClapTrap : default destructor called " << RESET<< RESET<< std::endl;}


ClapTrap::ClapTrap( void )
{
	this->name = "ClapTrap";
	this->hit_point = 10;
	this->energy_point = 10;
	this->attack_damage = 0;
	std::cout << UMAG << " ClapTrap : default cunstructor called " <<  RESET<<std:: endl;
}

ClapTrap::ClapTrap( std::string name )
{
	this->name = name ;
	this->hit_point = 10;
	this->energy_point = 10;
	this->attack_damage = 0;
	std::cout << UMAG << " ClapTrap : custom cunstructor called " <<  RESET<<std:: endl;
}

ClapTrap::ClapTrap(const ClapTrap& copy)
{
	this->name = copy.name;
	this->hit_point = copy.hit_point;
	this->attack_damage = copy.attack_damage;
	this->energy_point = copy.energy_point;
	std::cout << UMAG << " ClapTrap : copy cunstructor called " << RESET<< std::endl;
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
		std::cout << UMAG << " ClapTrap you cant attack because you are ghost	👻" << RESET<<std::endl;
	else if(this->hit_point != 0 && this-> energy_point == 0)
		std::cout << UMAG << " ClapTrap you cant attack because you have no energy🤡" << RESET<<std::endl;
	else
		std::cout << UMAG << " ClapTrap " << this->name <<" attacks "
			<< target<<  " ,causing " << this->attack_damage << " points of damage! "
			<< RESET<<std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hit_point <= amount)
	{
		this->hit_point = 0;
		std::cout << UMAG << name << " enemy has no hitpoint " << RESET<< std::endl;
		return ;
	}
	this->hit_point -= amount;
	std::cout << UMAG << name << "damage " << amount << " hit point!" << RESET<< std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energy_point == 0)
	{
		std::cout << UMAG << name << "error no energy" << RESET<< std::endl;
		return ;
	}
	if (this->hit_point == 0)
		std::cout << UMAG << "repaired"<< RESET<<std::endl;
	this->hit_point += amount;
	this->energy_point--;
	std::cout << UMAG << name << "repaired" << amount << "hit point" << RESET<< std::endl;
}

void ClapTrap::set_name(std::string name)
{
	this->name = name;
}

std::string ClapTrap::get_name( void )
{
	return(this->name);
}

void ClapTrap::increment(std::string name,int amount)
{
	if(name == "attack")
		hit_point+=amount;
	else if(name == "takeDamage")
		hit_point += amount;
	else if(name == "beRepaired")
	{
		energy_point+=amount;
		hit_point+=amount;
	}
	else
		return ;
}
void ClapTrap::decrement(std::string name,int amount)
{
	if(name == "attack")
		hit_point-=amount;
	else if(name == "takeDamage")
		hit_point -= amount;
	else if(name == "beRepaired")
	{
		energy_point-= amount;
		hit_point-=amount;
	}
	else
		return ;
}

void ClapTrap::setter_all(std::string name,unsigned int amount)
{
	if(name == "hit_point")
		hit_point = amount;
	else if(name == "attack_damage")
		attack_damage = amount;
	else if(name == "energy_point")
		energy_point = amount;
	else
		return ;

}

int  ClapTrap::getter_all(std::string name)
{
	if(name == "hit_point")
		return(hit_point);
	else if(name == "attack_damage")
		return(attack_damage);
	else if(name == "energy_point")
		return(energy_point);

		return (-1);
}