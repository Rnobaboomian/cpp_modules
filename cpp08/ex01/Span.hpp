#ifndef SPAN_HPP
#define SPAN_HPP

#include <list>
#include <iostream>
#include <iterator>

class Span
{
private:
	unsigned int N;
	std::list <int>L;
public:
	Span();
	Span(const Span &copy);
	Span &operator=(const Span &copy);
	void addNumber(unsigned int num);
	void showlist(void);
	unsigned int shortestSpan();
	unsigned int longestSpan();
	const std::list< int > *getList( void )const;
	Span(const unsigned int N);
	~Span();

	class NOSPACE : public std::exception
	{
		const char *what() const throw();
	};
};



#endif