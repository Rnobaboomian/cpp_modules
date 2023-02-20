#include "./A.hpp"
#include "B.hpp"
#include "./C.hpp"

#include <iostream>
#include <time.h>
#include <unistd.h>

Base *generate(void)
{
	srand(time(NULL));
	static int a = std::rand();
	if( a  % 4 == 2)
		return( new A);
	else if( a % 3 == 1)
		return (new B);
	else
		return (new C);
}

void identify(Base *ptr)
{
	//dynamic cast throw an exeption when it passes with refferance

			if(dynamic_cast <A*>(ptr))
				std::cout << "A" << std::endl;
			else if(dynamic_cast <B*>(ptr))
				std::cout << "B" << std::endl;
			else if(dynamic_cast <C*>(ptr))
				std::cout << "C" << std::endl;
			else
				std::cerr << "could not cast" << std::endl;

}
void identify(Base &ptr)
{
	try
	{
			(void)dynamic_cast <A&>(ptr);
			std::cout << "A" <<std::endl; 
			return ;
		
	}
	catch(...){}
	try
	{
			(void)dynamic_cast <B&>(ptr);
			std::cout << "B" <<std::endl; 
			return ;
	}
	catch(...){}
	try
	{
			(void)dynamic_cast <C&>(ptr);
			std::cout << "C" <<std::endl;
			return ;
	}
	catch(...)
	{
		std::cerr << "could not cast" << std::endl;
	}
	
	
}

int     main( void )
{
    Base*   a = generate();
    Base*   b = generate();
    Base*   c = generate();
    Base*   d = generate();

    std::cout << "/* **************************************** */" << std::endl;

    std::cout << "a* = "; identify( a );
    std::cout << "a& = "; identify( *a ); std::cout << std::endl;

    std::cout << "b* = "; identify( b );
    std::cout << "b& = "; identify( *b ); std::cout << std::endl;

    std::cout << "c* = "; identify( c );
    std::cout << "c& = "; identify( *c ); std::cout << std::endl;

    std::cout << "d* = "; identify( d );
    std::cout << "d& = "; identify( *d ); std::cout << std::endl;

    std::cout << "/* ***************************************** */" << std::endl;


    delete a;
    delete b;
    delete c;
    delete d;

    return (0);
}