#include "Form.hpp"

const std::string Form::getName()const
{
	return _name;
}

const int Form::getGrade()const
{
	return ;
}

std::ostream&	operator << (std::ostream &dst,const Form& src)
{
	dst << src.getName() << " GRADE " << src.getGrade();
	return dst;
}

Form::Form() : req_grade(70),exec_grade(0),_name("default_Form")
{
	std::cout << _name << " default custrutor called" << std::endl;
}

Form::Form(std::string name,int grade):req_grade(70),exec_grade(grade),_name(name)
{
	std::cout << _name << " custom cunstructor called " << std::endl;
}

Form::~Form()
{
	std::cout << _name << " destructor called" << std::endl;
}