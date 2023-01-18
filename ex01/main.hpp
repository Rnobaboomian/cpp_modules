#ifndef MAIN_HPP
#define MAIN_HPP

class phonebook
{
private:
	
public:
	char *name;
	char *last_name;
	char *nickname;
	char *phone_number;
	char *darkest_secret;
	phonebook();
	~phonebook();

phonebook::phonebook(char *name,char *last_name,char *nickname,char *phone_number,char *darkest_secret)
{
	this->name = name;
	this->last_name = last_name;
	this->nickname = nickname;
	this->phone_number = phone_number;
	this->darkest_secret = darkest_secret;
}

phonebook::~phonebook()
{
}

};

#endif