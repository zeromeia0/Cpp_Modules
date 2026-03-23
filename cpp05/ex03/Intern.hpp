
#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <iomanip>
# include <cmath>
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class AForm;
class Intern
{
	public:
		Intern();
		Intern(const Intern& newObj);
		Intern& operator=(const Intern& newObj);
		~Intern();
		AForm* makeForm(std::string formName, std::string target);
		AForm *makeShrubberyCreationForm(std::string target);
		AForm *makeRobotomyRequestForm(std::string target);
		AForm *makePresidentialPardonForm(std::string target);
};

#endif
