#ifndef EASY_HPP
#define EASY_HPP

#include <iostream>
#include <vector>


template <typename T>

void easyfind(T &to_search, int to_find)
{
	if(std::find(to_search.begin(),to_search.end(),to_find) != to_search.end())
		std::cout << to_find << " found " << std::endl;
	else
		std::cerr << to_find << " could not found " << std::endl;
}

#endif