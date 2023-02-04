#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
private:
public:
	FragTrap( void );
	~FragTrap();
	FragTrap& operator=(const FragTrap &copy);
	void attack(const std::string& target);
	void guardGate( void );
	FragTrap(std::string name);
	FragTrap(const FragTrap &copy);
	void highFivesGuys( void );
};


#endif