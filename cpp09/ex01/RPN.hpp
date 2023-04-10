#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <cmath>
#include <cstring>

class RPN
{
private:
    static RPN *instanace;
    std::stack<double>stk;
    std::string input;
private:
    RPN();
    RPN(std::string const &input);
    RPN(const RPN &copy);
    RPN &operator=(const RPN &copy);


private:
    class ERROR : public std::exception { const char *what() const throw();};

private:
    std::string trim(std::string const &str)const;
    double scanNum(char ch);
    bool isOperator(char ch);
    bool isOperand(char ch);
    double operation(double a, double b, char op);
    bool is_numeric(std::string const &str);
    int operator_count(std::string const &cpy);
    int operand_count(std::string const &cpy);
    void validate();
public:
   static RPN *getRPN(std::string const &input);
    ~RPN();
    double start();
};


#endif