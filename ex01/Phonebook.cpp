#include "Phonebook.hpp"

/*******************************UTILS*************************************/
int Phonebook::ft_free(int i)
{
	contact[i].name = "";
	contact[i].last_name = "";
	contact[i].nickname = "";
	contact[i].phone_number = "";
	contact[i].darkest_secret = "";
	return 0;
}
/****************************** ADD COMMAND************************************/

void Phonebook::Add()
{
	static int index = 0;
	if(index == 8) //to change the oldest one if the number of contacts reach 8;
		index = 0;
	
	std::cout <<"please enter name :" << std::endl;
	std::cin >>Phonebook::contact[index].name;
	
	std::cout <<"please enter last name :" << std::endl;
	std::cin >>Phonebook::contact[index].last_name;
	
	std::cout <<"please enter nickname :" << std::endl;
	std::cin >>Phonebook::contact[index].nickname;
	
	std::cout <<"please enter phone :" << std::endl;
	std::cin >>Phonebook::contact[index].phone_number;
	
	std::cout <<"please enter darkest secret :" << std::endl;
	std::cin >>Phonebook::contact[index].darkest_secret;

	//check if there is a  empty field or not
	if(Phonebook::contact[index].name == ""  ||Phonebook::contact[index].name == ""
	||Phonebook::contact[index].name == ""||Phonebook::contact[index].name == ""
	||Phonebook::contact[index].name == "" || Phonebook::contact[index].name == "" )
		ft_free(index);
	else
		index++;
}

/*******************************SEARCH COMMAND*********************************/

void Phonebook::search()
{
	for (size_t i = 0; i < 8; i++)
	{
		if(Phonebook::contact[i].name != "")
		{
			std::cout << Phonebook::contact[i].name << "|"
					<< Phonebook::contact[i].last_name << "|"
					<< Phonebook::contact[i].nickname << "|"
					<< Phonebook::contact[i].phone_number << "|" <<std::endl;
		}
	}
	
}

/*********************************EXIT COMMAND**********************************/

void Phonebook::ft_exit()
{
	for (size_t i = 0; i < 8; i++)
		ft_free(i);
}