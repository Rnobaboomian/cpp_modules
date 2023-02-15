#include "./Intern.hpp"

int main()
{

	try
	{
			Intern someRandomIntern;
			AForm* rrf;
			rrf = someRandomIntern.makeForm("ShrubberyCreationForm", "Bender");
			std::cout << " rrf name is : " << rrf->getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}