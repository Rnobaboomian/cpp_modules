#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("shuruberry",137,145),target("default")
{
	std::cout << target<< " : default cunstructor called " << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
		std::cout << target << " : destructor called " << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &copy) : AForm(copy),target(copy.target)
{
	std::cout << target << " : copy cunstructor called " << std::endl;
}
ShrubberyCreationForm::ShrubberyCreationForm(std::string target,int grade) :AForm(target,grade,145),target(target)
{
	std::cout << target << " : custom cunstructor called " << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm(target,137,145)
{
		std::cout << target << " : custom cunstructor called " << std::endl;

}

static void draw(std::ofstream &file)
{
 file<<	"     v"  <<std::endl;
 file<<  "     >X<" <<std::endl;
 file<<   "     A" <<std::endl;
 file<<  "     d$b" <<std::endl;
 file<<   "  .d\\$$b." <<std::endl;
 file<<  " .d$i$$\\$$b." <<std::endl;
 file<<  "    d$$@" <<std::endl;
 file<<  "   d\\$$$i" <<std::endl;
 file<< "  .d$$$\\$$$" <<std::endl;
 file<<" .d$$@$$$$\\$$ib" <<std::endl;
 file<< "    d$$i$$" <<std::endl;
 file<< "   d\\$$$$@$" <<std::endl;
 file<<"  .d$@$$\\$$$$$@b" <<std::endl;
 file<<".d$$$$i$$$\\$$$$$$b" <<std::endl;
 file<< "       ##" <<std::endl;
 file<<  "      ##" <<std::endl;
 file<<  "      ### mh" <<std::endl;

}

void ShrubberyCreationForm::execute(Bureaucrat const &executor)
{
	this->beSigned(const_cast<Bureaucrat &>(executor));
	if(this->ifSigned())
	{
		std::string filename = this->target + "_shrubbery";
		std::ofstream file(filename);
		if(!file)
			std::cerr << " can not create file " << std::endl;
		else
		{
			draw(file);
		}
	}
}