
#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <iomanip>
# include <cmath>
#include "AForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(const Intern& newObj);
		Intern& operator=(const Intern& newObj);
		~Intern();
		AForm* makeForm(std::string formName, std::string target);
};

#endif
