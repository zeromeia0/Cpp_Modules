
#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << "Default ScalarConverter constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& newObj)
{
	std::cout << "ScalarConverter copy constructor called" << std::endl;
	*this = newObj;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& newObj)
{
	std::cout << "ScalarConverter copy assignment operator called" << std::endl;
	if (this != &newObj)
		*this = newObj;
	return (*this);
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "ScalarConverter destructor called" << std::endl;
}
