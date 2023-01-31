#include <iostream>
#define UBLK "\e[4;30m"
#define URED "\e[4;31m"
#define UGRN "\e[4;32m"
#define UYEL "\e[4;33m"
#define UBLU "\e[4;34m"
#define UMAG "\e[4;35m"
#define UCYN "\e[4;36m"
#define UWHT "\e[4;37m"
#define RESET "\e[0;37m"

int main()
{

	std::string string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string &stringREF = string;

	std::cout << UMAG<< "memory address of the string variable :" << &string << std::endl;
	std::cout << " memory address held by stringPTR :" << stringPTR << std::endl;
	std::cout << "memory address held by stringREF :" << &stringREF << RESET<< std::endl;
	std::cout << UBLU<< "The value of the string variable : " << string << std::endl;
	std::cout << "The value pointed to by stringPTR : " << *stringPTR << std::endl;
	std::cout << "The value pointed to by stringREF : " << stringREF  << RESET<< std::endl;

}
