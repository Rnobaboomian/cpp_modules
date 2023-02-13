#include "./RobotomyRequestForm.hpp"

std::string RobotomyRequestForm::getTarget()const
{
	return this->target;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << this->getName() << " :  desstructor called " <<std::endl;
}

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy", 72, 45)
{
	target = "";
	std::cout << this->getName() << " : default constructor called " <<std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& new_target) : AForm("Robotomy", 72, 45)
{
	std::cout << this->getName()<< " : custom constructor called " <<std::endl;
	target = new_target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
{
	std::cout << this->getName() << " : copy constructor called " << std::endl;
	this->target = other.target;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor)
{
	this->beSigned(const_cast<Bureaucrat &>(executor));
	if(executor.getGrade() > 150 || executor.getGrade() < 1)
		throw AForm::GradeTooHighException();
	if(!this->ifSigned())
		throw AForm::FAILURE();
	if(std::rand() % 2 == 0)
		std::cout << this->getName() << " robotomized " << std::endl;
	else
		std::cout << this->getName() << " could not robotomize " << std::endl;


}