#include "Phonebook.hpp"

Phonebook::Phonebook(){};
Phonebook::~Phonebook(){};

/*******************************UTILS*************************************/
int Phonebook::ft_free(int i)
{
	contact[i].setFirstname("");
	contact[i].setLastname("");
	contact[i].setNickname("");
	contact[i].setPhoneNumber("");
	contact[i].setSecret("");
	return 0;
}
/****************************** ADD COMMAND************************************/

int is_digit(std::string str)
{
	int i = -1;
	while(str[++i])
		if(str[i] < '0' || str[i] > '9')
			return(0);
	return(1);
}

void Phonebook::Add()
{
	std::string name,last_name,nickname,phone,darkest_sec;
	static int index = 0;
	if(index == 8) //to change the oldest one if the number of contacts reach 8;
		index = 0;
	
	std::cout <<"please enter name :" << std::endl;
	std::cin >>name;
	
	std::cout <<"please enter last name :" << std::endl;
	std::cin >>last_name;
	
	std::cout <<"please enter nickname :" << std::endl;
	std::cin >>nickname;
	
	std::cout <<"please enter phone :" << std::endl;
	std::cin >>phone;
	
	std::cout <<"please enter darkest secret :" << std::endl;
	std::cin >>darkest_sec;
	
	std:: cout << "done!" << std::endl;
	//check if there is a  empty field or not
	if(is_digit(phone))
	{
		contact[index].setFirstname(name);
		contact[index].setLastname(last_name);
		contact[index].setPhoneNumber(phone);
		contact[index].setNickname(nickname);
		contact[index].setSecret(darkest_sec);
		index++;
	}
	else
		std::cout << "phone number must be numeric!" << std::endl;
	return;
}

/*******************************SEARCH COMMAND*********************************/

void display(std::string name)
{
	if(name.length() > 9)
		std::cout << name.substr(0,9) << "." << "|";
	else
		std::cout << std::setw(10) << name << "|";
}

void Phonebook::show(int i)
{
		if(Phonebook::contact[i].getFirstname() != "")
		{	
			std::cout << UMAG << i << std::endl
					<< contact[i].getFirstname() << std::endl
					<< contact[i].getLastname()  << std::endl
					<< contact[i].getPhoneNumber()  << std::endl
					<< contact[i].getNickname()  << std::endl
					<< contact[i].getSecret()  << std::endl;
			std::cout << RESET << std:: endl;
		}
}

void Phonebook::search()
{
	int id;
	for (size_t i = 0; i < 8; i++)
	{
		if(Phonebook::contact[i].getFirstname() != "")
		{	
			std::cout << std::setw(10) << i << "|";
					display(contact[i].getFirstname());
					display(contact[i].getLastname());
					display(contact[i].getPhoneNumber());
			std::cout << "" << std:: endl;
		}		
	}
			while (1)
			{
				if(contact[0].getFirstname() == "")
					break;
				std::cout << "please enter index" << std:: endl;
                std::cin >> id;
                if (std::cin.eof())
                {
                    std::cout << "Error 3: Bad input" << std::endl;
                    return;
                }
                if (std::cin.fail() ||  contact[id].getFirstname().length() == 0)
                {
                    std::cout << "There is no contact under this index" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(256, '\n');
                    continue ;
                }
				if(id < 0)
					break ;
                
                Phonebook::show(id);
                std::cin.ignore(256, '\n');
                break ;
			}
}

/*********************************EXIT COMMAND**********************************/

void Phonebook::ft_exit()
{
	for (size_t i = 0; i < 8; i++)
		ft_free(i);
}