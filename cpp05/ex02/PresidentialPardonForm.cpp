#include "./PresidentialPardonForm.hpp"

std::string PresidentialPardonForm::getTarget() const
{	
	return this->target;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << this->getName() << " : destructor called " <<std::endl;

}

PresidentialPardonForm::PresidentialPardonForm() : AForm("Robotomy", 72, 45)
{
	target = "";
	std::cout << this->getName() << " : default constructor called " <<std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& new_target) : AForm("president", 72, 45)
{
	std::cout << this->getName()<< " : custom constructor called " <<std::endl;
	target = new_target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
{
	std::cout << this->getName() << " : copy constructor called " << std::endl;
	this->target = other.target;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor)
{
	this->beSigned(const_cast<Bureaucrat &>(executor));
	if(executor.getGrade() > 150 || executor.getGrade() < 1)
		throw AForm::GradeTooHighException();
	if(!this->ifSigned())
		throw AForm::FAILURE();
	if(this->ifSigned())
		std::cout << this->getName() << " has been pardoned by Zaphod Beeblebrox " << std::endl;
	else
		std::cout << this->getName() << " had not been pardoned by Zaphod Beeblebrox " << std::endl;
}