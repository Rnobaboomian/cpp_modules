#include <iostream>

int main(void)
{
	char read_line[2];
	while (1)
	{
		std:: cin >> read_line;
		if(*read_line)
		{
			std::cout << read_line <<std::endl;
			std::cout << std::strlen(read_line) <<std::endl;
		}
	}
	return(1);
}