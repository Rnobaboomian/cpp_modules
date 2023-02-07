#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
	this->grade = grade;
	std:: cout << name << " custom cunstructor called " << std::endl;
}

Bureaucrat::Bureaucrat(): name("Bureacrat")
{
	
	this->grade = 0;
	std:: cout << name << " default construtor called" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << name << " destructor called " << std::endl;
}

const char	*Bureaucrat::GradeTooHighException::what() const throw() 
{ 
	return "HIGHHHHHHHHHHH"; 

}
const char	*Bureaucrat::GradeTooLowException::what() const throw() 
{
	 return "LOWWWWWW"; 
}


int Bureaucrat::getGrade()const
{
	return(this->grade);
}

std::string Bureaucrat::getName()const
{
	return(this->name);
}

void Bureaucrat::increment( void )
{
	if(grade == 1)
		Bureaucrat::GradeTooHighException();
	else
		this->grade--;
}
void Bureaucrat::decrement( void )
{
	if(grade >= 150)
		Bureaucrat::GradeTooLowException();
	else
		this->grade++;
}

std::ostream&	operator << (std::ostream &dst,const Bureaucrat& src)
{
	dst << src.getName() << " GRADE " << src.getGrade();
	return dst;
}