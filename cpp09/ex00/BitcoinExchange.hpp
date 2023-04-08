#ifndef BITCOIN_HPP
#define BITCOIN_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <cmath>

class BitcoinExchange
{
private:
    static BitcoinExchange *instance;
    std::map<std::string,float> rate;
    std::string currency_rate_path;
    std::string exchange_list_path;
    BitcoinExchange();
    BitcoinExchange(std::string const &currency_rate_path,std::string const &exchange_list_path);
    class OPEN_FAILURE : public std::exception
    {
        const char *what() const throw();
    };
    class BAD_FORMAT : public std::exception
    {
        const char *what() const throw();
    };
    struct BAD_INPUT : public std::exception
    {
            std::string input;
            BAD_INPUT(std::string input) : input(input){}
            ~BAD_INPUT() throw(){}
            const char *what() const throw()
            {
                std::string msg = "bad input => " + input;
                return msg.c_str(); 
            }

    };
    class NOT_POSITIVE : public std::exception
    {
        const char *what() const throw()
        {
            return "not a positive number";
        }
    };
    class TOO_LARGE : public std::exception
    {
        const char *what() const throw()
        {
            return "too large number";
        }
    };

    
public:
    static BitcoinExchange *getExchanger(std::string const &currency_rate_path,std::string const &exchange_list_path);
    void fill_rate();
    void validate(std::string const &text);
    void startExchange();
    ~BitcoinExchange();
    void getData();
    bool is_numeric(std::string const &str);
    void is_valid_date(std::string const &year,std::string const &month,std::string const &day);\
    void vlaue_validate(std::string const &value);
    std::string trim(std::string const &str)const;
};






#endif