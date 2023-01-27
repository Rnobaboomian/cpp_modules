#include "./Zombie.hpp"

int main()
{
	Zombie *zomb = zombieHorde(4,"foo");
	zomb->announce(4,zomb);
	delete [] zomb;
	return 1;
}