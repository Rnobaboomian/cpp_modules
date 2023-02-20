#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
	this->_char = '\0';
	this->_int = 0;
	this->_float = 0.0f;
	this->_double = 0.0;
}
ScalarConverter::ScalarConverter(const ScalarConverter& copy) {
	*this = copy; 
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter& dcopy) {
	if (this != &dcopy)
	{
		this->_char = dcopy.getChar();
		this->_int = dcopy.getInt();
		this->_float = dcopy.getFloat();
		//this->_double = dcopy.getDouble();
	}
	return (*this);
}

/* Setters */

void	ScalarConverter::setChar(char c) {
	this->_char = c;
}
void	ScalarConverter::setInt(int i) {
	this->_int = i;
}
void	ScalarConverter::setFloat(float f) {
	this->_float = f;
}
void	ScalarConverter::setDouble(double d) {
	this->_double = d;
}
void	ScalarConverter::setEnumType(void) {
	if (isChar())
		this->e_type = CHAR;
	else if(isInt())
		this->e_type = INT;
	else if(isFloat())
		this->e_type = FLOAT;
	else if(isDouble())
		this->e_type = DOUBLE;
	else if(isLiteral())
		this->e_type = LITERAL;
	else
		this->e_type = NONE;
}
void	ScalarConverter::setString(std::string s) {
	this->_string = s;
    this->setEnumType();
    if (getEnumType() == NONE)
        throw ScalarConverter::ScalarConverterException();
}

/* Getters */
char	ScalarConverter::getChar(void)			const {
	return this->_char;
}
int		ScalarConverter::getInt(void)			const {
	return this->_int;
}
float	ScalarConverter::getFloat(void)			const {
	return this->_float;
}
double	ScalarConverter::getDouble(void)		const {
	return this->_double;
}
std::string	ScalarConverter::getString(void)	const {
	return this->_string;
}
enum_type	ScalarConverter::getEnumType(void)	const {
	return this->e_type;
}

/* Checks */

bool	ScalarConverter::isChar(void) const {
	if (_string.length() == 1 && std::isalpha(_string[0]) && std::isprint(_string[0]))
		return true;
	else
		return false;
}
bool	ScalarConverter::isInt(void) const {
	int i = 0;
	if (_string[i] == '-' || _string[i] == '+')
		i++;
	for(size_t j = 0; j < _string.length(); j++)
		if (!std::isdigit(_string[j]))
			return false;
	return true;
}
bool	ScalarConverter::isFloat(void) const {
    if ( _string.find('.') == std::string::npos
		|| _string.back() != 'f' 
        || _string.find( '.' ) == 0
		|| _string.find( '.' ) == _string.length() - 2 )
        return false;

    int dot_count = 0;
	size_t j = 0;
    if (_string[0] == '-' || _string[0] == '+')
        j++;
    for (; j < _string.length() - 1; j++)
	{
        if (_string[j] == '.')
            dot_count++;
        if ((!std::isdigit(_string[j]) && _string[j] != '.' ) || dot_count > 1)
            return false;
    }

    return true;
}
bool	ScalarConverter::isDouble(void) const {
    if ( _string.find( '.' ) == std::string::npos || _string.find( '.' ) == 0 
        || _string.find( '.' ) == _string.length() - 1 )
        return false;

    size_t j = 0;
    int dot_count = 0;
    if ( _string[j] == '-' || _string[j] == '+' )
        j++;
    for (; j < _string.length(); j++) {
        if (_string[j] == '.')
            dot_count++;
        if ((!std::isdigit( _string[j] ) && _string[j] != '.') || dot_count > 1)
            return false;
    }
    return true;
}
bool	ScalarConverter::isPossible(void) {
    try
    {
        if (e_type == INT )
            _int = std::stoi(_string);
		else if (e_type == FLOAT)
            _float = std::stof(_string);
		else if (e_type == DOUBLE)
            _double = std::stod(_string);
    }
    catch (std::exception& e)
    {
        _isPossible = true;
        return true;
    }
    return false;
}
bool	ScalarConverter::isLiteral(void) const {
    if ( (_isPossible ) || (_string.compare("nan") == 0 ) || ( _string.compare("nanf") == 0)
        || ( _string.compare( "+inf" ) == 0 ) || ( _string.compare( "+inff" ) == 0 ) 
        || ( _string.compare( "-inf" ) == 0 ) || ( _string.compare( "-inff" ) == 0 ) 
        || ( _string.compare( "-inff" ) == 0 ) || ( _string.compare( "-inff" ) == 0 )  
        || ( _string.compare( "+inff" ) == 0 ) || ( _string.compare( "+inff" ) == 0 ) )
            return true;
    return false;
}
/* Print */
void	ScalarConverter::printChar(void) const {
    if (this->isLiteral() || ( !std::isprint( _int ) && ( _int >= 127 )))
        std::cout << "not possible";
    else if (!std::isprint(this->_int))
        std::cout << "Not Displayable";
    else
        std::cout << "'" << getChar() << "'";
    std::cout << std::endl;
}

void	ScalarConverter::printInt(void) const {
    if (this->isLiteral() || (!std::isprint(_int) && (_int >= 127)))
        std::cout << "not possible";
    else
        std::cout << getInt();
    std::cout << std::endl;
}

void	ScalarConverter::printFloat(void) const {
    if (_string.compare("nan") == 0 || _string.compare("nanf") == 0)
        std::cout << "nanf";
    else if (_string.compare("+inff") == 0 || _string.compare("+inf") == 0)
        std::cout << "+inff";
    else if ( _string.compare( "-inff" ) == 0 || _string.compare("-inf") == 0)
        std::cout << "-inff";
    else if (_isPossible)
        std::cout << "not possible";
    else {
        if ( _float - static_cast<int> (_float) == 0 )
            std::cout << _float << ".0f";
        else
            std::cout << getFloat() << "f";
    }
    std::cout << std::endl;
}
void	ScalarConverter::printDouble(void) const {
    if (_string.compare("nan") == 0 || _string.compare("nanf") == 0)
        std::cout << "nan";
    else if (_string.compare("+inff") == 0 || _string.compare("+inf") == 0)
        std::cout << "+inf";
    else if (_string.compare("-inff") == 0 || _string.compare("-inf") == 0)
        std::cout << "-inf";
    else if (_isPossible)
        std::cout << "not possible";
    else
	{
        if (_double - static_cast<int>(_double) == 0)
            std::cout << _double << ".0";
        else
            std::cout << getDouble();
    }
    std::cout << std::endl;
}

void	ScalarConverter::convert() {
    if (isPossible())
        return;
    switch (e_type) {
    case CHAR:
        _char = _string[0];
        _int = static_cast< int >(_char);
        _float = static_cast< float >(_char);
        _double = static_cast< double >(_char);
        break;
    case INT:
        _int = std::stoi(_string);
        _float = static_cast< float >( _int );
        _double = static_cast< double >( _int );
        _char = static_cast< char >( _int );
        break;
    case FLOAT:
        _float = std::stof( _string );
        _int = static_cast< int >( _float );
        _double = static_cast< double >( _float );
        _char = static_cast< char >( _float );
        break;
    case DOUBLE:
        _double = std::stod( _string );
        _int = static_cast< int >( _double );
        _float = static_cast< float >( _double );
        _char = static_cast< char >( _double );
        break;
    default:
        break;
    }
}

std::ostream&    operator<<(std::ostream& out, const ScalarConverter& obj) {
    out << "char: "; obj.printChar();
    out << "int: "; obj.printInt();
    out << "float: "; obj.printFloat();
    out << "double: "; obj.printDouble();
    return out;
}

ScalarConverter::~ScalarConverter() {}
