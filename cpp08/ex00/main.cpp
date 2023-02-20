#include "./easyfind.hpp"
#include <list>

int main(int ac,char **av)
{
	if(ac != 2)
	{
		std::cerr << "bad arguments " << std::endl;
		return 1;
	}
	try
	{
		int arr[] = {1,2,3,4,5,6,7,8,9,0};
		std::vector <int> v1(arr,arr + sizeof(arr) / sizeof(int));
		easyfind(v1,std::stoi(av[1]));
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}