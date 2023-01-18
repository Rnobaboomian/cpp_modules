#include <iostream>

int main(int ac,char **av)
{
	int i = 0,j = 0;
	if(ac == 1)
		std::cout << " LOUD AND UNBEARABLE FEEDBACK NOISE" <<std::endl;
	else
	{
		while(av[++i])
			while(av[i][j])
				std::cout <<(char)std::toupper(av[i][j++]); 
	}
	return(1);
}