#ifndef MUTANT_HPP
#define MUTANT_HPP


#include <iostream>
#include <algorithm>
#include <list>
#include <stack>
#include <deque>


template< typename T, class Container = std::deque< T > > 
class MutantStack : public std::stack< T, Container >
{
private:
public:

    MutantStack( void ) {};
    ~MutantStack( void ) {};

    MutantStack( const MutantStack& rhs ) { *this = rhs; }
    MutantStack&    operator=( const MutantStack& rhs ) {
        std::stack< T, Container >::operator=( rhs );
        return *this;
    }

    typedef typename Container::iterator    iterator;
	typedef typename Container::const_iterator  const_iterator;
	typedef typename Container::reverse_iterator reverse_iterator;
	typedef typename Container::const_reverse_iterator const_reverse_iterator;

    iterator    begin() 
	{ 
		return this->c.begin(); 
	}
    iterator    end() 
	{ 
		return this->c.end(); 
	}
	const_iterator begin()const
	{
		return (this ->c.begin());
	}
	const_iterator end() const
	{
		return (this ->c.end());
	} 

	reverse_iterator rbegin()
	{
		return(this->c.rbegin());
	}
	reverse_iterator rend()
	{
		return(this->c.rend());
	}
	const_reverse_iterator rbegin() const
	{
		return(this->c.rbegin());
	}
	const_reverse_iterator rend() const 
	{
		return(this->c.rend());
	}
};

#endif
/* #include <stack>
#include <deque>
#include <iostream>

template <typename TEM, typename Con = std::deque<TEM> > 

class MutantStack : public std::stack<TEM,Con>
{

public:
	MutantStack(){};
	MutantStack(const MutantStack &copy) : std::stack<TEM,Con>(copy)
	{
		*this = copy;
	};
	~MutantStack(){};
	MutantStack &operator=(MutantStack &copy)
	{
		if(this != &copy)
			this->std::stack<TEM,Con>::operator=(cpoy);
		return(*this);
	}
	typedef typename std::stack<TEM,Con>::container_type iterator; iterator;
	typedef typename std::stack<TEM,Con>::container_type const_iterator; const_iterator;
	typedef typename std::stack<TEM,Con>::container_type reverse_iterator; reverse_iterator;
	typedef typename std::stack<TEM,Con>::container_type const_reverse_iterator; const_reverse_iterator;

	iterator begin()
	{
		return (this ->std::stack<TEM,Con>::c.begin());
	}
	iterator end()
	{
		return (this ->std::stack<TEM,Con>::c.end());
	}
	const_iterator begin()const
	{
		return (this ->std::stack<TEM,Con>::c.begin());
	}
	const_iterator end() const
	{
		return (this ->std::stack<TEM,Con>::c.end());
	} 



	reverse_iterator rbegin()
	{
		return(this->std::stack<TEM,Con>::c.rbegin());
	}
	reverse_iterator rend()
	{
		return(this->std::stack<TEM,Con>::c.rend());
	}
	const_reverse_iterator rbegin() const
	{
		return(this->std::stack<TEM,Con>::c.rbegin());
	}
	const_reverse_iterator rend() const 
	{
		return(this->std::stack<TEM,Con>::c.rend());
	}



}; */