#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>

class Contact
{
	private:
	public:
	std::string name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;
};


class Phonebook
{
private:
	Contact contact[8];
public:
Phonebook()
{
}

~Phonebook()
{
}

void Add();
int ft_free(int i);
void search();
void ft_exit();

};

#endif