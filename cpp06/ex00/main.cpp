#include "ScalarConverter.hpp"

int main( int ac, char ** av )
{
    if (ac != 2)
	{
        std::cout << "arguments must be 2" << std::endl;
        return 0;
    }

    ScalarConverter c;

    try
    {
        c.setString(av[1]);
        c.convert();

        std::cout << c;
		// std::cout << "Char: ";
		// c.printChar();
		// std::cout << "Int: ";
		// c.printInt();
		// std::cout << "Float: ";
		// c.printFloat();
		// std::cout << "Double: ";
		// c.printDouble();
    }
    catch( const std::exception& e ) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    

    return 0;
}