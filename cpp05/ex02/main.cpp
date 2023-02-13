#include "./AForm.hpp"
#include "./Bureaucrat.hpp"
#include "./RobotomyRequestForm.hpp"
#include "./ShrubberyCreationForm.hpp"
#include "./PresidentialPardonForm.hpp"

int main()
{

	//AForm a; 				//compile error unimplemented pure virtual method 'execute' in 'AForm'
	
	std::cout << "__________________ START ORIGINAL '<<' OPERATOR __________________" << std::endl << std::endl;

	Bureaucrat a("Aramik", 70);
	
	std::cout << "Name:\t" << a.getName() << std::endl;
	std::cout << "Grade:\t" << a.getGrade() << std::endl << std::endl;
		
	Bureaucrat b("Vazgenchik", 120);

	std::cout << "Name:\t" << b.getName() << std::endl;
	std::cout << "Grade:\t" << b.getGrade() << std::endl << std::endl;
	
	std::cout << "__________________ END ORIGINAL '<<' OPERATOR __________________" << std::endl << std::endl;
	
	std::cout << "__________________ START OVERLOAD '<<' OPERATOR __________________" << std::endl << std::endl;

	std::cout << a << std::endl;
	std::cout << b << std::endl << std::endl;
	
	std::cout << "__________________ END OVERLOAD '<<' OPERATOR __________________" << std::endl << std::endl;

	std::cout << "__________________ START try and catch __________________" << std::endl << std::endl;
	
	try
	{
		Bureaucrat a_1("Karenchik", 120);
		ShrubberyCreationForm sh("Home");
		a_1.executeForm(sh);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat a_2("Tigranchik", 120);
		ShrubberyCreationForm sh_2("Home");
		sh_2.beSigned(a_2);
		a_2.executeForm(sh_2);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat a_3("Albertik", 10);
		ShrubberyCreationForm sh_3("Home",40);
		sh_3.beSigned(a_3);
		a_3.executeForm(sh_3);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat a_4("Silva", 100);
		PresidentialPardonForm sh_4("Harevan Silva");
		a_4.executeForm(sh_4);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	try
	{
		Bureaucrat a_5("Ani", 10);
		RobotomyRequestForm sh_5("Harevan Ani");
		
		sh_5.beSigned(a_5);
		a_5.executeForm(sh_5);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "__________________ END try and catch __________________" << std::endl << std::endl;


	return 0;
}