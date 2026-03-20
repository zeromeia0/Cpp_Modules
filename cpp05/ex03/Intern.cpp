
#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Default Intern constructor called" << std::endl;
}

Intern::Intern(const Intern& newObj)
{
	std::cout << "Intern copy constructor called" << std::endl;
	*this = newObj;
}

Intern& Intern::operator=(const Intern& newObj)
{
	std::cout << "Intern copy assignment operator called" << std::endl;
	if (this != &newObj)
		*this = newObj;
	return (*this);
}

Intern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;
}
