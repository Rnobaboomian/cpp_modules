
#include "./ScavTrap.hpp"
#include "./FragTrap.hpp"

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

	ScavTrap	s_trap;
	ScavTrap	a_1("name_1 ScavTrap");
	ScavTrap	b_1("name_2 ScavTrap");
	ScavTrap	c_1 = a_1;
	
	for (int i = 0; i < 5; i++)
		a_1.attack("urish name_1 ScavTrap");

	for (int i = 0; i < 5; i++)
		b_1.attack("urish name_2 ScavTrap");

	FragTrap	f_trap;
	FragTrap	a_2("name_1 FragTrap");
	FragTrap	b_2("name_2 FragTrap");
	FragTrap	c_2 = a_2;

	for (int i = 0; i < 5; i++)
		a_2.attack("urish name_1 FragTrap");

	for (int i = 0; i < 5; i++)
		b_2.attack("urish name_2 FragTrap");

	return 0;
}