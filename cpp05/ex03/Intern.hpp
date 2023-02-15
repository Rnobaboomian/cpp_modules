#ifndef INTERN_HPP
#define INTERN_HPP

#include "./AForm.hpp"
#include "./PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"


class Intern
{
private:
	AForm *shuru(const std::string &target);
	AForm *president(const std::string &target);
	AForm *roboto(const std::string &target);
public:
	Intern();
	~Intern();
	Intern(const Intern &copy);
	Intern& operator = (const Intern &copy);
	AForm	*makeForm(const std::string	&form, const std::string &target);
	
	class exe : public std::exception
	{
		const char	*what() const throw();
	};

};






#endif