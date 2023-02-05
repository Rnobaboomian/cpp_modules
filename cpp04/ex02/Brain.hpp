#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>


class Brain
{
private:
	std::string ideas[100];
public:
	Brain();
	Brain(Brain &copy);
	Brain &operator=(Brain &copy);
	void set_idea(int i,std::string string);
	std::string get_idea(int i)const;
	~Brain();
};





#endif