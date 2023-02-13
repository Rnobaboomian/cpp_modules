#ifndef ROBOT_HPP
#define ROBOT_HPP

#include "./AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
	std::string target;
public:
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string& new_target);
	RobotomyRequestForm(const RobotomyRequestForm& other);
	~RobotomyRequestForm();

	std::string	getTarget() const;
	void		execute(Bureaucrat const &executor) ;
};

#endif