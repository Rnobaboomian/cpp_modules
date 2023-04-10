#include "PmergeMe.hpp"
#include <iostream>


int main(int ac,char **av)
{
    if(ac < 2)
        return 1;

    int i = 0;
    PmergeMe *sorter;
    sorter = PmergeMe::getMerge(av);
    while (av[++i])
    {
        if(sorter->is_numeric(av[i]) == false || atoi(av[i]) < 0)
        {
            std::cerr << "error" << std::endl;
            delete sorter;
            exit (1);
        }
    }
    sorter->hybridSort();
    delete sorter;
}