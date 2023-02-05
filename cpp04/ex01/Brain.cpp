#include "Brain.hpp"

Brain::Brain(Brain &copy)
{
	for (size_t i = 0; i < 100; i++)
		ideas[i] = copy.ideas[i];
	
	std::cout << "Brain copy cunstructor called" << std::endl;
}

Brain &Brain::operator=(Brain &copy)
{
	if(this != &copy)
			for (size_t i = 0; i < 100; i++)
				ideas[i] = copy.ideas[i];
	return(*this);
}

Brain::Brain()
{
	std::cout << " brain : default cunstructor called" << std::endl;
}

Brain::~Brain()
{
	std::cout << " brain : default cunstructor called" << std::endl;
}

void Brain::set_idea(int i,std::string string)
{
	this->ideas[i] = string;
}

std::string Brain::get_idea(int i)const
{
	return(this->ideas[i]);
}