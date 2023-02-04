#include "./ClapTrap.hpp"

int main()
{
	ClapTrap	c_trap;
	ClapTrap	a("name_1");
	ClapTrap	b("name_2");
	ClapTrap	c = a;
	
	for (int i = 0; i < 5; i++)
		a.attack("urish name_1");

	for (int i = 0; i < 5; i++)
		b.attack("urish name_2");
	return 0;
}