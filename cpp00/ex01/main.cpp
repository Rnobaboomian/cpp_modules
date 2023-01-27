#include "./Phonebook.hpp"


int main(void)
{
	std::string read_line;
	Phonebook ph;
	while (1)
	{
		getline(std::cin, read_line);
		if (std::cin.eof())
			return 1;
		if(read_line[0])
		{
			if(read_line.compare("ADD") == 0)
				ph.Add();
			else if(read_line.compare("SEARCH") == 0)
				ph.search();
			else if(read_line.compare("EXIT") == 0)
			{
				ph.ft_exit();
				ph.~Phonebook();
				break ;
			}
			else
				std::cout << "wrong command" <<std::endl;
		}		
	}
	return(1);
}