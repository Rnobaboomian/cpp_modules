#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <fstream>

enum enum_type {
	NONE,
	LITERAL,
	CHAR,
	INT,
	FLOAT,
	DOUBLE
};

class ScalarConverter {

private:
	char	_char;
	int		_int;
	float	_float;
	double	_double;

	bool	_isPossible;
	std::string _string;
	enum_type e_type;
public:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& copy);
	~ScalarConverter();
	ScalarConverter &operator=(const ScalarConverter &copy);
	
	void	setChar(char c);
	void	setInt(int i);
	void	setFloat(float f);
	void	setDouble(double d);
	void	setEnumType(void);
	void	setString(std::string s);

	char	getChar(void)			const;
	int		getInt(void)			const;
	float	getFloat(void)			const;
	double	getDouble(void)			const;
	std::string	getString(void)		const;
	enum_type	getEnumType(void)	const;

	bool	isChar(void) const;
	bool	isInt(void) const;
	bool	isFloat(void) const;
	bool	isDouble(void) const;
	bool	isPossible(void);
	bool	isLiteral(void) const;

	void	printChar(void) const;
	void	printInt(void) const;
	void	printFloat(void) const;
	void	printDouble(void) const;

	class ScalarConverterException : public std::exception {
		virtual const char* what() const throw() { 
			return "unknown type"; 
		}
	};

	void	convert(void);
};

std::ostream& operator<<(std::ostream& out, const ScalarConverter& obj);

#endif