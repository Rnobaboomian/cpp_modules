#include "./BitcoinExchange.hpp"

int main(int ac,char **av)
{
    if(ac != 2)
        return 1;
    try
    {
        BitcoinExchange *exchange = BitcoinExchange::getExchanger("./data.csv",av[1]);
        exchange->fill_rate();
        exchange->startExchange();
        delete exchange;
    }
    catch(const std::exception& e)
    {
        std::cerr  << URED << e.what() <<  RESET <<'\n';
    }
    
    return 1;
}