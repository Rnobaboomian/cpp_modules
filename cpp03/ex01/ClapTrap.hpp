#ifndef CLAP_TRAP_HPP
#define CLAP_TRAP_HPP

#include <iostream>


class ClapTrap
{
protected:
	std::string name;
	unsigned int	hit_point;
	unsigned int energy_point;
	unsigned int attack_damage;
public:
	ClapTrap(void);
	~ClapTrap();
	ClapTrap( std::string name );
	ClapTrap(const ClapTrap& copy);
	void set_name(std::string name);
	void increment(std::string name,int amount);
	void decrement(std::string name,int amount);
	void setter_all(std::string name,unsigned int amount);
	int  getter_all(std::string name);
	std::string get_name( void );
	ClapTrap &operator=(const ClapTrap &copy);
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};




#endif