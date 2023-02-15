#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <ostream>
#include "./Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	const std::string _name;
	bool _signed;
	const int req_grade;
	const int exec_grade;

public:
	AForm();
	~AForm();
	AForm(std::string name,int grade);
	AForm(std::string name,int grade,int req_grade);
	AForm(const AForm &copy);
	void beSigned(Bureaucrat &bur);
	const std::string getName()const;
	 int getGrade()const;
	 bool ifSigned()const;
	 int get_req();
	virtual void execute(Bureaucrat const &executor) = 0;
	 class GradeTooHighException : public std::exception
	{
		const char	*what() const throw();	
	};
	class GradeTooLowException : public std::exception
	{
		const char	*what() const throw();	
	};
	class FAILURE : public std::exception
	{
		const char *what() const throw();
	};
};


	
// const int AForm::req_grade = 70;


std::ostream &operator<<(std::ostream &dst,const AForm &src);


#endif