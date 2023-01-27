#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include "contact.hpp"

#define UBLK "\e[4;30m"
#define URED "\e[4;31m"
#define UGRN "\e[4;32m"
#define UYEL "\e[4;33m"
#define UBLU "\e[4;34m"
#define UMAG "\e[4;35m"
#define UCYN "\e[4;36m"
#define UWHT "\e[4;37m"
#define RESET "\e[0;37m"

class Phonebook
{
private:
	Contact contact[8];
public:
	Phonebook();
	~Phonebook();

	void Add();
	int ft_free(int i);
	void search();
	void ft_exit();
	void show(int i);

};

#endif