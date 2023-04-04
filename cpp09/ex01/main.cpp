#include "./RPN.hpp"

int main(int ac,char **av)
{
   if(ac < 2)
   {
      std::cerr << "bat arguments\n";
      return 1;
   }
   RPN *calc = RPN::getRPN(av[1]);
   try
   {
      std::cout << calc->start() << std::endl;
   }
   catch(const std::exception& e)
   {
      std::cerr << e.what() << '\n';
   }
}