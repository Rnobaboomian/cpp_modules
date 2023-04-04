#include "./BitcoinExchange.hpp"

BitcoinExchange *BitcoinExchange::instance = NULL;

BitcoinExchange *BitcoinExchange::getExchanger(std::string const &currency_rate_path,std::string const &exchange_list_path)
{
    if(!instance)
        instance = new BitcoinExchange(currency_rate_path, exchange_list_path);
    return instance;
}

BitcoinExchange::BitcoinExchange(std::string const &currency_rate_path,std::string const &exchange_list_path)
: currency_rate_path(currency_rate_path),exchange_list_path(exchange_list_path)
{
    if(!instance)
        instance = this;
    else
    {
        this->~BitcoinExchange();
        std::cout << " no no noo nooo !!!" << std::endl;
    }
}

BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::~BitcoinExchange()
{}


void BitcoinExchange::getData()
{
    std:: cout << this->currency_rate_path << " ;\n" << this->exchange_list_path << " ;\n";
}

void BitcoinExchange::fill_rate()
{
    std::ifstream input(this->currency_rate_path);
    if(!input)
        throw OPEN_FAILURE();
    std::string line;
    std::string date;
    std::string rate;
    int index = 0;
    size_t i = 0;
    while (std::getline(input, line)) 
	{
        if(i++ < 1)
            continue;
        index = line.find_first_of(',',0);
        date = line.substr(0,index);
        rate = line.substr(index + 1,line.size() - index);
        this->rate.insert(std::pair<std::string,float>(date,std::stof(rate)));
        
    }
   /*  std::map<std::string,float>::iterator it = this->rate.begin();
    while (it != this->rate.end())
    {
        std::cout << "[ " << it->first << " ] = " << it->second << std::endl;
        it++;
        break;
    } */
    

}

void BitcoinExchange::startExchange()
{
    std::ifstream input(this->exchange_list_path);
    if(!input)
        throw BAD_FORMAT();
    std::string date_;
    std::string value;
    std::string line;
     std::size_t index = 0;
     size_t i = 0;
    while (std::getline(input, line)) 
	{
    try
    {
        if(line.size() == 0)
            throw BAD_FORMAT();
        if(i++ < 1)
            continue;
        index = line.find_first_of('|',0);
        if(index == std::string::npos)
        {
            throw BAD_FORMAT();
            continue;
        }
            validate(line);
            date_ = trim(line.substr(0,index));
            value = trim(line.substr(index + 1,line.size() - index));
            std::map<std::string,float>::iterator it = rate.lower_bound(date_);
            if(it->first != date_)
            {
                if (it == rate.begin())
                    throw BAD_FORMAT();
                --it;
            }
            std::cout << date_ << " => " << value << " = " << std::stof(value) * it->second << std::endl;
    }
    catch (const std::invalid_argument &e)
    {
            (void)e;
            std::cerr << "ERROR: not a number " << '\n';
    }
    catch(const std::out_of_range &e)
    {
        std::cerr << "ERROR: overflow!!" << e.what() << '\n';

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
        
                
    }

    
}

void BitcoinExchange::validate(std::string const &text)
{
    if(std::count(text.begin(),text.end(),'|') != 1)
        throw BAD_FORMAT();
    std::string date_;
    std::string value;
    std::size_t index;
    index = text.find_first_of('|',0);
    if(index == std::string::npos)
        throw BAD_FORMAT();
    if(text.size() < index + 1)
        throw BAD_FORMAT();
    date_ = trim(text.substr(0,index));
    value = trim(text.substr(index + 1,text.size() - index));
    vlaue_validate(value);
    if(std::count(date_.begin(),date_.end(),'-') != 2)
        throw BAD_FORMAT();
    std::string year;
    std::string month;
    std::string day;
    std::size_t first;
    std::size_t last;
    if(date_.length() != 10)
        throw BAD_FORMAT();
    first = date_.find_first_of('-',0);
    last = date_.find_first_of('-',first + 1);
    year = date_.substr(0,first);
    month = date_.substr(first + 1,(last - first) - 1);
    day = date_.substr(last + 1,date_.size() - (first + last));
    is_valid_date(year,month,day);
}

std::string BitcoinExchange::trim(std::string const &str)const 
{
    size_t start_pos = str.find_first_not_of(" \t\n");
    size_t end_pos = str.find_last_not_of(" \t\n");

    if (start_pos == std::string::npos || end_pos == std::string::npos) {
        return "";
    }

    return str.substr(start_pos, end_pos - start_pos + 1);
}


const char *BitcoinExchange::OPEN_FAILURE::what()const throw()
{
    return "cannot open the file";
}
const char *BitcoinExchange::BAD_FORMAT::what()const throw()
{
    return "error";
}

bool BitcoinExchange::is_numeric(std::string const &str)
{
    std::string::const_iterator it = str.begin();
    while (it != str.end() && std::isdigit(*it))
        it++;
    return !str.empty() && it == str.end();
    
}

void BitcoinExchange::is_valid_date(std::string const &year,std::string const &month,std::string const &day)
{
    float D;
    float Y ;
    float M;
    D = std::stof(day);
    Y = std::stof(year);
    M = std::stof(month);
   // std::cout << " year is ==> " + year << " month is ==> " + month << " day is ==> " + day <<std::endl;
    if(day.size() == 0 || month.size() == 0 || year.size() == 0)
        throw BAD_FORMAT();
    if(!(is_numeric(year) && is_numeric(month) && is_numeric(day)))
        throw BAD_FORMAT();
    if( (D <= 0 || D > 31) || (Y <= 0) || (M > 12 || M <= 0))
        throw BAD_FORMAT();
}

void BitcoinExchange::vlaue_validate(std::string const &value)
{
         if((std::stof(value) > 1000 || std::stof(value) < 0))
                throw BAD_FORMAT();
  
    
}