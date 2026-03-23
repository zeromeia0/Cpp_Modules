
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

AForm* Intern::makeForm(std::string name, std::string target)
{
	std::string formName[3] = {"Shrubery", "Robotomy", "president"};
	AForm*(Intern::*formCreator[3])(std::string) = {&Intern::makeShrubberyCreationForm, &Intern::makeRobotomyRequestForm, &Intern::makePresidentialPardonForm};
	for (int i = 0; i < 3; i++)
	{
		if (name == formName[i])
		{
			std::cout << "Intern creates [" << name << "] form\n";
			return ((this->*formCreator[i])(target));
		}
	}
	std::cout << "Invalid input\n";
	return (NULL);
}

AForm *Intern::makeShrubberyCreationForm(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm *Intern::makeRobotomyRequestForm(std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm *Intern::makePresidentialPardonForm(std::string target)
{
	return (new PresidentialPardonForm(target));
}

Intern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;
}
