#ifndef CLAP_TRAP_HPP
#define CLAP_TRAP_HPP

#include <iostream>

const std::string UBLK = "\e[4;30m";
const std::string URED = "\e[4;31m";
const std::string UGRN = "\e[4;32m";
const std::string UYEL = "\e[4;33m";
const std::string UBLU = "\e[4;34m";
const std::string UMAG = "\e[4;35m";
const std::string UCYN = "\e[4;36m";
const std::string UWHT = "\e[4;37m";
const std::string RESET = "\e[0;37m";

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