#include "./Intern.hpp"

AForm *Intern::shuru(const std::string &target)
{
	return (new ShrubberyCreationForm(target));
	
}
AForm *Intern::president(const std::string &target)
{
	return (new PresidentialPardonForm(target));
}
AForm *Intern::roboto(const std::string &target)
{
	return (new RobotomyRequestForm(target));
}

Intern::Intern()
{
	std:: cout << " intern  constructor called " << std::endl;

}
Intern::Intern(const Intern &copy)
{
	(void) copy;
	std:: cout << " intern copy constructor called " << std::endl;
}

Intern &Intern::operator=(const Intern &copy)
{
	if(this != &copy){}
		return(*this);
}

Intern::~Intern()
{
	std:: cout << " intern  destructor called " << std::endl;
}

const char *Intern::exe::what() const throw()
{
	return " there is no such a form! ";
}

AForm *Intern::makeForm(const std::string &form,const std::string &target)
{

	typedef AForm * (Intern::* formMethod)(const std::string &target);
  	formMethod method[3] = {
		&Intern::president,
		&Intern::roboto,
		&Intern::shuru
	};
	std::string name[3] = {
		"PresidentialPardonForm",
		"RobotomyRequestForm",
		"ShrubberyCreationForm"
	};
	for (size_t i = 0; i < 3; i++)
	{
		if(form.compare(name[i]) == 0)
		{
			std:: cout << " intern  make " << form << std::endl;
			return((this->*method[i])(target));
		}
	}
	throw Intern::exe();
	
}