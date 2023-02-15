#ifndef SCALAR_HPP
#define SCALAR_HPP

#include <iostream>

class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(ScalarConverter &copy);
public:
	void convert(std::string &lit);
	ScalarConverter &operator=(ScalarConverter &copy);
	~ScalarConverter();
};

ScalarConverter &ScalarConverter::operator=(ScalarConverter &copy)
{
	(void)copy;
	return *this;
}

void ScalarConverter::convert(std::string &lit)
{
	std::string to_put = "";
	std::string nan[6] = {"-inf","+inf","nan","nanf","+inff","-inff"};
	for (size_t i = 0; i < 3; i++)
	{
		if(lit.compare(nan[i]) == 0)
		{
			
			to_put = nan[i];
			std::cout << " char :" << " impossible" << std::endl;
			std::cout << " int :" << " impossible" << std::endl;
			std::cout << " double :" << (to_put = (nan[i] == "nanf" ||nan[i] == "+inff" ||nan[i] == "-inff") ? nan[i].substr(0,nan[i].length() - 2) : nan[i] )<< std::endl;
			std::cout << " float :" << to_put << std::endl;
			return ;
		}
	}

	
}

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(ScalarConverter &copy)
{
	*this = copy;
}

ScalarConverter::~ScalarConverter(){}


#endif