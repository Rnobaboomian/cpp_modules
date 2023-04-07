#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <iostream>
#include <list>
#include <vector>
#include <deque>

class PmergeMe
{
private:
    static PmergeMe *instance;
    std::vector<int>input_vector;
    std::deque<int>input_deque;
    std::vector<std::string>input_list;
private:
    class BADINPUT : std::exception
    {
        const char *what()const throw();
    };
public:
    PmergeMe();
    PmergeMe(char **av);
    ~PmergeMe();
    PmergeMe *getMerge(char **av);
};


PmergeMe::PmergeMe(char **av)
{
    int i = -1;
    while (av[++i])
        input_list.push_back(av[i]);
    
}
PmergeMe::PmergeMe()
{
}

PmergeMe::~PmergeMe()
{
}



#endif