#ifndef PRESIDENT
#define PRESIDENT

#include "./AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
	std::string target;
public:
	PresidentialPardonForm();
	PresidentialPardonForm(const std::string& new_target);
	PresidentialPardonForm(const PresidentialPardonForm& other);
	~PresidentialPardonForm();

	std::string	getTarget() const;
	void		execute(Bureaucrat const &executor) ;
};


#endif