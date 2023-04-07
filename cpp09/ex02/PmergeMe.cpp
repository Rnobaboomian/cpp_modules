#include "./PmergeMe.hpp"

PmergeMe *PmergeMe::instanace = NULL;


PmergeMe::PmergeMe(char **av)
{
    if(!this->instanace)
    {
        limit = 10;
        instanace = this;
        int i = 0;
        while (av[++i])
        {
            //input_list.insert(atoi(av[i]));
            input_deque.push_back(atoi(av[i]));
            input_vector.push_back(atoi(av[i]));
        }
    }
    else
        this->~PmergeMe();
    
}
PmergeMe::PmergeMe()
{
}

PmergeMe::~PmergeMe()
{
}

/* template <typename T>
void print_data(T &arr)
{
    typename T::iterator it = input_vector.begin();
    while (it != input_vector.end())
    {
        std::cout << *it << " ";
        ++it;
    }
    std::endl;
} */
////////////////////////////////////////////////////////////////////////////////

template <typename T>
void PmergeMe::merge(T& arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    T L(n1), R(n2);
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

template <typename T>
void PmergeMe::insertSort(T&arr,int left, int right)
{
      for (int i = left + 1; i <= right; i++) 
      {
        int key = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > key) 
        {
            arr[j + 1] = arr[j];
                    j--;
        }
        arr[j + 1] = key;
    }
}

template <typename T>
void PmergeMe::mergeSort(T& arr, int left, int right) 
{
    if (left < right) {
        if (right - left <= limit) 
            insertSort(arr,left,right);
        else 
        {
            int mid = left + (right - left) / 2;
            mergeSort(arr, left, mid);
            mergeSort(arr, mid + 1, right);
            merge(arr, left, mid, right);
        }
    }
}
void PmergeMe::hybridSort() 
{
   
    mergeSort(input_vector, 0, input_vector.size() - 1);
    std::vector<int>::iterator it = input_vector.begin();
    while (it != input_vector.end())
    {
        std::cout << *it << " ";
        ++it;
    }
    std:: cout << "\n";
    mergeSort(input_deque,0,input_deque.size() - 1);
    //std::deque<int>::iterator itt = input_deque.begin();
 /*    while (itt != input_deque.end())
    {
        std::cout << *itt << std::endl;
        ++itt;
    } */
    
}


/////////////////////////////////////////////////////////

bool PmergeMe::is_numeric(std::string const &str)
{
    std::string::const_iterator it = str.begin();
    while (it != str.end() && std::isdigit(*it))
        it++;
    return !str.empty() && it == str.end();
    
}

PmergeMe *PmergeMe::getMerge(char **av)
{
    if(!instanace)
        return new PmergeMe(av);
    return instanace; 
}

const char *PmergeMe::BADINPUT::what()const throw()
{
    return "error";
}