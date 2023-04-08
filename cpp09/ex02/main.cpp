#include "./PmergeMe.hpp"
#include <iostream>
int main(int ac,char **av)
{
    if(ac < 2)
        return 1;
            int i = 0;
            std::vector<int> vec_list;
            std::deque<int> deq_list;
            PmergeMe *sorter;
            sorter = PmergeMe::getMerge(av);
            while (av[++i])
            {
                if(sorter->is_numeric(av[i]) == false || atoi(av[i]) < 0)
                {
                    std::cerr << "error" << std::endl;
                    return 1;
                }
            }
            sorter->hybridSort();
            
}