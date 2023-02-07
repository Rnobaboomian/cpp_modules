#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat temp1;
	
	std::cout << "Hi! My name is " << temp1.getName() << std::endl;
	std::cout << "My grade is " << temp1.getGrade() << std::endl;

	Bureaucrat tmp2("tmp2", 10);

	std::cout << "Hi! My name is " << tmp2.getName() << std::endl;
	std::cout << "My grade is " << tmp2.getGrade() << std::endl;
	
	Bureaucrat tmp3("tmp3", 50);

	std::cout << "Hi! My name is " << tmp3.getName() << std::endl;
	std::cout << "My grade is " << tmp3.getGrade() << std::endl << std::endl;

	std::cout << "___________________ START ORIGINAL OPERATOR '<<' ___________________" << std::endl << std::endl;

	std::cout << temp1.getName() << ", bureaucrat grade " << temp1.getGrade() << std::endl;
	std::cout << tmp2.getName() << ",\t bureaucrat grade " << tmp2.getGrade() << std::endl;
	std::cout << tmp3.getName() << ",\t bureaucrat grade " << tmp3.getGrade() << std::endl << std::endl; 

	std::cout << "___________________ END ORIGINAL OPERATOR '<<' ___________________" << std::endl << std::endl;

	std::cout << "___________________ START try and catch ___________________" << std::endl << std::endl;

	try
	{
		Bureaucrat tmp4("tmp4", 80);
		std::cout << "\n\t___________________ START OVERLOAD OPERATOR '<<' ___________________" << std::endl << std::endl;
		std::cout << tmp4 << std::endl;
		std::cout << "\n\t___________________ END OVERLOAD OPERATOR '<<' ___________________" << std::endl << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	try
	{
		Bureaucrat tmp5("tmp5", 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		
	}
	
	try
	{
		Bureaucrat tmp6("tmp6", 20);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << "___________________ END try and catch ___________________" << std::endl << std::endl;


	return 0;
}