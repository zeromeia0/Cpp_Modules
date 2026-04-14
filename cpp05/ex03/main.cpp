#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

static void run_test(const std::string& bureaucratName, int grade,
                     const std::string& formName, const std::string& target)
{
	try
	{
		Bureaucrat b(bureaucratName, grade);
		Intern intern;

		AForm* form = intern.makeForm(formName, target);
		if (!form)
			return;

		b.signForm(*form);
		b.executeForm(*form);
		std::cout << "Trying to sign again just for the sake of it :)\n";
		b.signForm(*form);
		delete (form);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	std::cout << '\n';
}

int main()
{
	std::cout << "\033[36mINVALID BUREAUCRATS\n\033[0m";
	run_test("Sam", 0, "Shrubery", "Home");
	run_test("Tim", 200, "Robotomy", "Home");
	std::cout << std::endl;
	std::cout << "\033[36mUNABLE TO SIGN\n\033[0m";
	run_test("Steph", 150, "Shrubery", "Home");
	run_test("Tom", 146, "Robotomy", "Home");
	std::cout << std::endl;

	std::cout << "\033[36mABLE TO SIGN, UNABLE TO EXECUTE\n\033[0m";
	run_test("Sally", 144, "Shrubery", "Home");
	std::cout << std::endl;

	std::cout << "\033[36mABLE TO SIGN AND EXECUTE\n\033[0m";
	run_test("Ted", 1, "president", "Home");
	run_test("Mahito", 1, "Shrubery", "Home");

	std::cout << std::endl;

	std::cout << "\033[36mINVALID FORM\n\033[0m";
	run_test("Ted", 1, "free icecream", "Home");

	return 0;
}