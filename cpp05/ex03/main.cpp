#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

void sign_and_execute(Bureaucrat &a, AForm *f)
{
	if (f == NULL)
		return ;
	a.signForm(*f);
	a.executeForm(*f);
	delete f;
}

void test_forms(std::string b_name, int b_grade, std::string target)
{
	AForm *f = NULL;
	try
	{
		Bureaucrat a(b_name, b_grade);
		Intern someRandomIntern;
		f = someRandomIntern.makeForm("Shrubery", target);
		sign_and_execute(a, f);
		f = someRandomIntern.makeForm("Robotomy", target);
		sign_and_execute(a, f);
		f = someRandomIntern.makeForm("president", target);
		sign_and_execute(a, f);
		f = someRandomIntern.makeForm("free icecream", target);
		sign_and_execute(a, f);
	}
	catch (const Bureaucrat::GradeTooHighException &e)
	{
		std::cout << "Bureaucrat " << b_name
				  << " was not created : " << e.what() << "\n";
	}
	catch (const Bureaucrat::GradeTooLowException &e)
	{
		std::cout << "Bureaucrat " << b_name
				  << " was not created : " << e.what() << "\n";
	}
	catch (const AForm::GradeTooHighException &e)
	{
		std::cout << "ShrubberyCreationForm was not created : "
				  << e.what() << "\n";
	}
	catch (const AForm::GradeTooLowException &e)
	{
		std::cout << "ShrubberyCreationForm was not created : "
				  << e.what() << "\n";	
	}
	std::cout << "\n";
	return ;
}

int main()
{
	std::string cyan = "\033[36m";
	std::string reset = "\033[0m";

	std::cout << cyan << "INVALID BUREAUCRATS\n" << reset;
	test_forms("Sam", 0, "Home");
	test_forms("Tim", 200, "Home");

	std::cout << cyan << "UNABLE TO SIGN\n" << reset;
	test_forms("Steph", 150, "Home");
	test_forms("Tom", 146, "Home");

	std::cout << cyan << "ABLE TO SIGN, UNABLE TO EXECUTE\n" << reset;
	test_forms("Sally", 144, "Home");

	std::cout << cyan << "ABLE TO SIGN AND EXECUTE\n" << reset;
	test_forms("Ted", 1, "Home");
}