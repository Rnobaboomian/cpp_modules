#include "./AForm.hpp"

const std::string AForm::getName()const
{
	return _name;
}

 int AForm::getGrade()const
{
	return exec_grade;
}

std::ostream&	operator << (std::ostream &dst,const AForm& src)
{
	dst << src.getName() << " GRADE " << src.getGrade();
	return dst;
}

AForm::AForm() :_name("default_AForm"),req_grade(70),exec_grade(90)
{
	_signed = false;
	std::cout << _name << " default custrutor called" << std::endl;
}

AForm::AForm(std::string name,int grade):_name(name),req_grade(70),exec_grade(grade)
{
	std::cout << _name << " custom cunstructor called " << std::endl;
}

AForm::~AForm()
{
	std::cout << _name << " destructor called" << std::endl;
}

void AForm::beSigned(Bureaucrat &bur)
{
	int i = bur.getGrade();
	if(i < 1)
		throw AForm::GradeTooHighException();
	if(i > 150)
		throw AForm::GradeTooLowException();
	if(i <  req_grade)
		_signed = true;
	else
		_signed = false;
	bur.signForm(*this);
}

const char	*AForm::GradeTooHighException::what() const throw() 
{ 
	return "Aform : HIGHHHHHHHHHHH"; 

}
const char	*AForm::GradeTooLowException::what() const throw() 
{
	 return "Aform : LOWWWWWW"; 
}

const char *AForm::FAILURE::what() const throw()
{
	return "FAILEDDD!";
}

bool AForm::ifSigned()const
{
	return _signed;
}

 int AForm::get_req()
{
	return req_grade;
}

AForm::AForm(std::string name,int grade,int req_grade):_name(name),req_grade(req_grade),exec_grade(grade)
{
	_signed = false;
	std::cout << " custom cunstructor called " << std::endl;
}

AForm::AForm(const AForm &copy) : _name(copy._name),req_grade(copy.req_grade),exec_grade(copy.exec_grade)
{
	this->_signed = copy._signed;

}
