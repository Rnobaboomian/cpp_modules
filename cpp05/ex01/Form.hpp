#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <ostream>

class Form
{
private:
	const std::string _name;
	bool _signed;
	const int req_grade;
	const int exec_grade;

public:
	Form();
	~Form();
	Form(std::string name,int grade);
	const std::string Form::getName()const;
	const int Form::getGrade()const;
};



std::ostream &operator<<(std::ostream &dst,const Form &src);


#endif