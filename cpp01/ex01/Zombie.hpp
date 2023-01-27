#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

/* color define*/
#define UBLK "\e[4;30m"
#define URED "\e[4;31m"
#define UGRN "\e[4;32m"
#define UYEL "\e[4;33m"
#define UBLU "\e[4;34m"
#define UMAG "\e[4;35m"
#define UCYN "\e[4;36m"
#define UWHT "\e[4;37m"
#define RESET "\e[0;37m"

#include <iostream>

class Zombie
{
private:
	std::string name;
public:
	Zombie();
	Zombie(std::string name);
	~Zombie();
	void announce();
	void announce(int N,Zombie *zomb);
	void set_name(std::string name);
	
};

Zombie *zombieHorde(int N, std::string name);

#endif