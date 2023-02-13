#ifndef BUREACRAT_HPP
#define BUREACRAT_HPP

#include <iostream>
#include <ostream>
#include "./AForm.hpp"

class AForm;

class Bureaucrat
{
private:
	 const std::string name;
	int grade;
public:
	Bureaucrat();
	~Bureaucrat();
	Bureaucrat(std::string name, int grade);
	int getGrade()const;
	void increment( void );
	void decrement( void );
	std::string getName()const;
	 void signForm(AForm &form);
	 void executeForm( AForm& form);
	class GradeTooHighException : public std::exception
	{
		const char	*what() const throw();	
	};
	class GradeTooLowException : public std::exception
	{
		const char	*what() const throw();	
	};

};



	
std::ostream &operator<<(std::ostream &dst,const Bureaucrat &src);





#endif
