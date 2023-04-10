#ifndef BITCOIN_HPP
#define BITCOIN_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <cmath>

const std::string UBLK = "\e[4;30m";
const std::string URED = "\e[4;31m";
const std::string UGRN = "\e[4;32m";
const std::string UYEL = "\e[4;33m";
const std::string UBLU = "\e[4;34m";
const std::string UMAG = "\e[4;35m";
const std::string UCYN = "\e[4;36m";
const std::string UWHT = "\e[4;37m";
const std::string RESET = "\e[0;37m";

class BitcoinExchange
{
private:
    float main_value;
    static BitcoinExchange *instance;
    std::map<std::string,float> rate;
    std::string currency_rate_path;
    std::string exchange_list_path;
    BitcoinExchange();
    BitcoinExchange(std::string const &currency_rate_path,std::string const &exchange_list_path);
    BitcoinExchange(const BitcoinExchange &copy);
    BitcoinExchange &operator=(const BitcoinExchange &copy);
protected:
    class OPEN_FAILURE : public std::exception
    {
        const char *what() const throw();
    };
    struct BAD_FORMAT : public std::exception
    {
         std::string msg;
        BAD_FORMAT(std::string input) : msg("error : " + input){}
        BAD_FORMAT():msg("error"){};
        ~BAD_FORMAT() throw(){}
        const char *what() const throw()
        {
            return msg.c_str(); 
        }
    };
    struct BAD_INPUT : public std::exception
    {
            //std::string input;
            std::string msg;
            BAD_INPUT(std::string input) : msg("bad input => " + input){}
            ~BAD_INPUT() throw(){}
            const char *what() const throw()
            {
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
    void is_valid_date(std::string const &year,std::string const &month,std::string const &day);
    bool valid_input_date(int year,int month,int day);
    void vlaue_validate(std::string const &value);
    std::string trim(std::string const &str)const;
};

#endif