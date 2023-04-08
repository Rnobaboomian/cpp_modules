#include "./BitcoinExchange.hpp"

int main(int ac,char **av)
{
    if(ac != 2)
        return 1;
    BitcoinExchange *exchange = BitcoinExchange::getExchanger("./data.csv",av[1]);
    exchange->fill_rate();
    exchange->startExchange();
    delete exchange;
    return 1;
}