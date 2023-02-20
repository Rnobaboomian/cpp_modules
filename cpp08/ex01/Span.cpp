#include "./Span.hpp"

Span::Span(const unsigned int N)
{
	this->N = N;
}
Span::Span()
{
	this->N = 0;
}
Span::Span(const Span &copy)
{
	this->N = copy.N;
	this->L = copy.L;
}

Span &Span::operator=(const Span &copy)
{
	if(this != &copy)
	{
		this->L = copy.L;
		this->N = copy.N;
	}
	return *this;
}

Span::~Span()
{
}

const char *Span::NOSPACE::what() const throw()
{
	return "no space left on the list";
}

void Span::addNumber(unsigned int num)
{
	if(this-> N <= 0)
		throw NOSPACE();
	this-> N--;
	this-> L.push_back(num);
}

const std::list< int >* Span::getList( void )const {
    return &L;
}

void Span::showlist(void)
{
    std::list<int>::iterator it;
    for (it = L.begin(); it != L.end(); ++it)
        std::cout << '\t' << *it;
    std:: cout << '\n';
}


unsigned int    Span::longestSpan( void ){
    if ( L.size() < 2 )
        throw std::out_of_range("Span::longestSpan: list is empty");
    return ( *std::max_element( L.begin(), L.end() ) - *std::min_element( L.begin(), L.end() ) );
}

unsigned int Span::shortestSpan( void ){
    if ( L.size() < 2 )
        throw std::out_of_range("Span::shortestSpan: list is empty");
    unsigned int  min = Span::longestSpan();
    for ( std::list<int>::const_iterator it = L.begin(); it != L.end(); ++it ) {
        for ( std::list<int>::const_iterator it2 = L.begin(); it2 != L.end(); ++it2 ) {
            if ( it == it2 ) continue;
            if ( std::abs( *it2 - *it ) <  static_cast< int >( min ) )
                min = std::abs( *it2 - *it );
        }
    }
    return min;
}

std::ostream& operator<<( std::ostream& os, const Span& span ) {
    for ( std::list<int>::const_iterator it = span.getList()->begin(); it != span.getList()->end(); ++it )
        os << *it << " ";
    return os;
}
