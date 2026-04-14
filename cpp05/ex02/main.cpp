#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
    std::cout << "\n===== TEST 1: Unsigned Form Execution =====" << std::endl;
    try
    {
        Bureaucrat boss("Martin", 150);
        ShrubberyCreationForm shrub("Backyard");
        // boss.signForm(shrub);

        std::cout << "Bureaucrat " << boss.getName() << " attempting to execute..." << std::endl;
        boss.executeForm(shrub); 
    }
    catch (std::exception &e)
    {
        std::cout << "Main caught: " << e.what() << std::endl;
    }
    std::cout << "\n===== TEST 2: Robotomy drilling (Failure/Success) =====" << std::endl;
    std::srand(std::time(NULL));
    try
    {
        Bureaucrat worker("Karl Max", 1);
        RobotomyRequestForm rob("Bender");
        worker.executeForm(rob);
        worker.signForm(rob);
        worker.executeForm(rob);
    }
    catch (const std::exception &e)
    {
        std::cout << "Main caught: " << e.what() << std::endl;
    }
    std::cout << "\n===== TEST 4: Double Sign =====" << std::endl;
    try
    {
        Bureaucrat boss("Martin", 1);
        ShrubberyCreationForm shrub("Backyard");
        boss.signForm(shrub);
        std::cout << "Trying to sign again..." << std::endl;
        boss.signForm(shrub);
    }
    catch (std::exception &e)
    {
        std::cout << "Main caught: " << e.what() << std::endl;
    }
    std::cout << "\n===== TEST 5: Copying and Assignment =====" << std::endl;
    try
    {
        PresidentialPardonForm original("Ford Prefect");
        PresidentialPardonForm copy(original);
        
        Bureaucrat president("Nolan", 1);
        president.signForm(copy);
        president.executeForm(copy);
    } catch (std::exception &e)
    {
        std::cout << "Main caught: " << e.what() << std::endl;
    }
    std::cout << "\n===== ALL TESTS COMPLETE =====" << std::endl;
    return (0);
}