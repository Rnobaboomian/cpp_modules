#ifndef SHUR_HPP
#define SHUR_HPP

#include <iostream>
#include <fstream>
#include "./AForm.hpp"

class ShrubberyCreationForm  :public AForm
{
private:
	const std::string target;

public:
	ShrubberyCreationForm();
	~ShrubberyCreationForm();
	ShrubberyCreationForm(ShrubberyCreationForm &copy);
	ShrubberyCreationForm(std::string target,int grade);
	ShrubberyCreationForm(std::string target);
	void execute(Bureaucrat const &executor);
};






#endif