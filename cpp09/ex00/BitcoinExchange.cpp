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

    // ignoring the first raw
    std::getline(input, line);

    while (std::getline(input, line)) 
	{
        index = line.find_first_of(',',0);
        date = line.substr(0,index);
        rate = line.substr(index + 1,line.size() - index);
        this->rate.insert(std::pair<std::string,float>(date,std::atof(rate.c_str())));
    }
}

void BitcoinExchange::startExchange()
{
    std::ifstream input(this->exchange_list_path);
    if(!input)
    {
        std::cerr << "cant open the file\n";
        return ;
    }
    std::string date_;
    std::string value;
    std::string line;
     std::size_t index = 0;
     size_t i = 0;
    int j = 0;
    while (std::getline(input, line)) 
	{
        try
        {
            if(line.size() == 0)
            {
                throw BAD_INPUT(line);
            }
            if(i++ < 1)
                continue;
            index = line.find_first_of('|',0);
            if(index == std::string::npos)
            {
                throw BAD_INPUT(line);
                continue;
            }
                validate(line);
                date_ = trim(line.substr(0,index));
                value = trim(line.substr(index + 1,line.size() - index));
                std::map<std::string,float>::iterator it = rate.lower_bound(date_);
                if(it->first != date_)
                {
                    if(it == rate.begin() && it->first != date_)
                        throw BAD_INPUT(date_);
                    if(it != rate.begin())
                        --it;
                }
                std::cout << j << " : " << date_ << " => " << value << " = " << main_value * it->second << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << j << " : " << URED << e.what() <<  RESET <<'\n';
        } 
          j++;      
    }

    
}

void BitcoinExchange::validate(std::string const &text)
{
    if(std::count(text.begin(),text.end(),'|') != 1)
    {
        throw BAD_INPUT(text);
    }
    std::string date_;
    std::string value;
    std::size_t index;
    index = text.find_first_of('|',0);
    if(index == std::string::npos)
    {
        throw BAD_INPUT(text);
    }
    if(text.size() < index + 1)
    {
        throw BAD_INPUT(text);
    }
    date_ = trim(text.substr(0,index));
    value = trim(text.substr(index + 1,text.size() - index));
    vlaue_validate(value);
    if(std::count(date_.begin(),date_.end(),'-') != 2)
    {
        throw BAD_INPUT(date_);
    }
    std::string year;
    std::string month;
    std::string day;
    std::size_t first;
    std::size_t last;
    if(date_.length() != 10)
    {
        throw BAD_INPUT(date_);
    }
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

bool BitcoinExchange::is_numeric(std::string const &str)
{
    std::string::const_iterator it = str.begin();
    while (it != str.end() && (std::isdigit(*it) || *it == '.'))
        it++;
    return !str.empty() && it == str.end();
    
}

void BitcoinExchange::is_valid_date(std::string const &year,std::string const &month,std::string const &day)
{
    float D;
    float Y ;
    float M;
    D = std::atof(day.c_str());
    Y = std::atof(year.c_str());
    M = std::atof(month.c_str());
    std::string msg = year + "-" + month + "-" + day;
    if(day.size() == 0 || month.size() == 0 || year.size() == 0)
    {
        throw BAD_INPUT(msg);
    }
    if(!(is_numeric(year) && is_numeric(month) && is_numeric(day)))
    {
        throw BAD_INPUT(msg);
    }
    if(!valid_input_date(Y,M,D))
    {
        throw BAD_INPUT(msg);
    }
}

void BitcoinExchange::vlaue_validate(std::string const &value_)
{
    char	*endptr;
    float	value = strtof(value_.c_str(), &endptr);
    if (*endptr != '\0')
		throw BAD_FORMAT("value must be a numeric! => " + value_);
	if (value == -HUGE_VALF)
		throw BAD_FORMAT("overflow -inf!");
	if (value < 0)
		throw BAD_FORMAT("value must be a positive number! => " + value_);
	if (value == HUGE_VALF)
		throw BAD_FORMAT("overflow +inf!");
    if(value > 1000)
        throw TOO_LARGE();
    this->main_value = value;
}

bool BitcoinExchange::valid_input_date(int year,int month,int day)
{
    if(1000 <= year  && year <= 3000)
    {
        if((month==1 || month==3 || month==5|| month==7|| month==8||month==10||month==12) && day>0 && day<=31)
            return true;
        else if((month==4 || month==6 || month==9|| month==11) && (day>0 && day<=30))
            return true;
        else if(month==2)
        {
            int leapYear = (year%400==0 || (year%100!=0 && year%4==0));
            return (day > 0 && day <= 28 + leapYear);
        }
        else
            return false;
    }
    else
        return false;
}