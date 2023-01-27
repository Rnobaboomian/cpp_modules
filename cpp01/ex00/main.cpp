#include "Zombie.hpp"

int main()
{
	Zombie *heap;
	heap = newZombie("HEAP_ZOMBIE");
	heap->announce();
	randomChump("STACK_ZOMBIE");
	delete heap;
	return 1;
}